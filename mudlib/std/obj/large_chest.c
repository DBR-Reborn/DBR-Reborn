//    A large chest for save rooms

#include "/adm/include/std.h"
#include "/adm/include/daemons.h"
#include "/adm/include/move.h"
#include "/adm/include/dirs.h"
#include "/adm/include/security.h"

inherit "/std/bag_logic";

int max_items;
void set_max_items(int x) { max_items = x; }
private int closed_weight;
int query_is_locker() { return 1; }

void create() {
	set_possible_to_close(1);
    is_closed = 1;
	seteuid(getuid());
  ::create();
    set_name("chest");
    set_id( ({ "chest", "large" }));
    set_long("It is a large, well-built chest.\n");
    set_value(26000);
    set_weight(650);
    set_short("A large chest");
    set_max_items(10);
    set_max_internal_encumbrance(3200);
    return;
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

void load_chest(object ob){
    string file;
    string obj;
    int i;
    string *inv, name, save_dir_r, save_dir;

    name = "chest";
    save_dir_r = "chest_"+this_object()->query_property("chest number");
    save_dir = "/adm/save/objects/chests/"+save_dir_r+"/";

    inv = get_dir(save_dir+name+"_*");
    for (i=0;i<sizeof(inv);i++){
        file = save_dir+inv[i];
        obj = replace_string(read_file(file, 1, 1), "#", "");
        obj = replace_string(obj, "\n", "");
        ob = new(obj);
        ob->restore_me("chests/"+save_dir_r+"/"+inv[i][0..(sizeof(inv[i])-3)]);
        ob->move(this_object());
        rm(file);
    }
    message("info", "%^BOLD%^%^YELLOW%^Chest "+save_dir_r+ " Restored!%^RESET%^",
       find_player("honspron"));
    return;
}

void save_chest(object ob) {
    string save_dir_r, save_dir, name, tmp, file, *inv2;
	object *inv, a;
    int i;
    
	name = "chest";
	save_dir_r = "chest_"+this_object()->query_property("chest number");
	save_dir = "/adm/save/objects/chests/"+save_dir_r;
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
        a->save_me("chests/"+save_dir_r+"/"+name+"_"+i);
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
    message("info", "%^BOLD%^%^YELLOW%^Chest "+save_dir_r+ " SAVED!%^RESET%^",
       find_player("honspron"));
  return;
}

void init(){
	int i, num;
	object *inv;
	
	::init();
	
	num = this_object()->query_property("chest number");
  if (num >= 1){
      return;
  }else{  
     inv=get_dir("/adm/save/objects/chests/chest_*");
	for(i=0;i < sizeof(inv);i++){	
	}
	num = i+1;
	set_property("chest number", num);
	mkdir("/adm/save/objects/chests/chest_"+num);
    message("info", "%^BOLD%^%^GREEN%^Chest number %^RESET%^"+num+" created!",
       find_player("honspron"));	 
  }
}

int toggle_closed() {
if(!::toggle_closed()) return 0;
  seteuid(geteuid(this_object()));
  if(!is_closed) {
    if(closed_weight && !query_internal_encumbrance())
      add_encumbrance(closed_weight);
      this_object()->load_chest();
  } else {
      closed_weight = 0;
    this_object()->save_chest();
  }
  return 1;
}

int move(mixed dest) {
  if(objectp(dest) && living(dest) && this_object()->query_locked()) {
    if(this_player()) write("It is chained to the ground.");
    return MOVE_NOT_ALLOWED;
  }

  return ::move(dest);
}
/*
int query_weight() {
  if(!is_closed) return ::query_weight() + query_internal_encumbrance();
  else return ::query_weight() + closed_weight;
}*/

int clean_up() { return 0; }


