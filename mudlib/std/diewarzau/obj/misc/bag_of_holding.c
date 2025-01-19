//    Bag of holding.

#include "/adm/include/std.h"
#include "/adm/include/daemons.h"
#include "/adm/include/move.h"
#include "/adm/include/dirs.h"
#include "/adm/include/security.h"

inherit "/std/bag_logic";
//inherit "/std/locker_logic";

int max_items;
void set_max_items(int x) { max_items = x; }
private int closed_weight;

void create() {
  set_possible_to_close(1);
  is_closed = 1;
  seteuid(getuid());
  ::create();
  set_max_internal_encumbrance(10000);
  set_max_items(30);
  set_property("no steal", 1);

  set_name("bag of holding");
  set_id( ({ "bag"}) );
  set_short("A bag of holding");
set("long",@ext This bag of holding may be used to store items, adding no weight to you.

Anything in this bag will only save if you close the bag.
ext);
  set_weight(100);
  set_value(14500);
  set_closed_long("This is a closed bag.\n");
  set_open_long("This bag of holding may be used to store items, adding no weight to you.\n");
}

int receive_objects() {
  if(!::receive_objects()) return 0;
  if(previous_object() && previous_object() == this_object()) return 1;
  if(!max_items) this_object()->set_max_items(10);
  if(sizeof(all_inventory(this_object())) >= max_items) {
      write("You cannot put more than "+max_items+" in this container.");
    return 0;
  }

  if(previous_object() && (previous_object()->query_property("no save") ||
			   !clonep(previous_object()))) {
    write("That item cannot be saved!");
    return 0;
  }
  return 1;
}

void load_bag(object ob){
    string file;
    string obj;
    int i;
    string *inv, name, save_dir_r, save_dir;

    name = "bag";
    save_dir_r = "bag_"+this_object()->query_property("bag number");
    save_dir = "/adm/save/objects/bags/"+save_dir_r+"/";

    inv = get_dir(save_dir+name+"_*");
    for (i=0;i<sizeof(inv);i++){
        file = save_dir+inv[i];
        obj = replace_string(read_file(file, 1, 1), "#", "");
        obj = replace_string(obj, "\n", "");
        ob = new(obj);
        ob->restore_me("bags/"+save_dir_r+"/"+inv[i][0..(sizeof(inv[i])-3)]);
        ob->move(this_object());
        rm(file);
    }
    message("info", "%^BOLD%^%^YELLOW%^Bag "+save_dir_r+ " Restored!%^RESET%^",
       find_player("honspron"));
    return;
}

void save_bag(object ob) {
    string save_dir_r, save_dir, name, tmp, file, *inv2;
	object *inv, a;
    int i;
    
	name = "bag";
	save_dir_r = "bag_"+this_object()->query_property("bag number");
	save_dir = "/adm/save/objects/bags/"+save_dir_r;
    mkdir(save_dir);
	save_dir += "/";
	inv2 = get_dir(save_dir+name+"_*");

  
   for (i=0;i < sizeof(inv2);i++){
        file = save_dir+name+"_"+i+".o";
        rm(file);
    }
    inv = all_inventory(this_object());
    for(i=0;i < sizeof(inv);i++){
        a=inv[i];
        a->save_me("bags/"+save_dir_r+"/"+name+"_"+i);
       if(virtualp(a)){
            tmp = save_dir+ name+"_"+i;
            rename(tmp + ".o", tmp + ".tmp");
            write_file(tmp+".o", "#"+base_name(a)+"\n", 1);
            file = read_file(tmp+".tmp");
            write_file(tmp+".o", file, 0);
            rm(tmp+".tmp");
        }
		a->remove(); 
    }
    message("info", "%^BOLD%^%^YELLOW%^Bag "+save_dir_r+ " SAVED!%^RESET%^",
       find_player("honspron"));
  return;
}

void init(){
	int i, num;
	object *inv;
	
	::init();
	
	num = this_object()->query_property("bag number");
  if (num >= 1){
      return;
  }else{  
     inv=get_dir("/adm/save/objects/bags/bag_*");
	for(i=0;i < sizeof(inv);i++){	
	}
	num = i+1;
	set_property("bag number", num);
	mkdir("/adm/save/objects/bags/bag_"+num);
    message("info", "%^BOLD%^%^RED%^Bag number %^RESET%^"+num+" created!",
       find_player("honspron"));	 
  }
}

int toggle_closed() {
if(!::toggle_closed()) return 0;
  seteuid(geteuid(this_object()));
  if(!is_closed) {
    if(closed_weight && !query_internal_encumbrance())
      add_encumbrance(closed_weight);
      this_object()->load_bag();
  } else {
      closed_weight = 0;
    this_object()->save_bag();
  }
  return 1;
}


/*
int move(mixed dest) {
  if(objectp(dest) && living(dest) && this_object()->query_locked()) {
    if(this_player()) write("It is chained to the ground.");
    return MOVE_NOT_ALLOWED;
  }

  return ::move(dest);
}*/
/*
int query_weight() {
  if(!is_closed) return ::query_weight() + query_internal_encumbrance();
  else return ::query_weight() + closed_weight;
}*/

int clean_up() { return 0; }

