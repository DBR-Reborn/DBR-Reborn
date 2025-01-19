//	A virtual object server that handles rooms in an inn.
//	Players can save their stuff there.

#include <std.h>
#include <security.h>
#include <daemons.h>
#define INN_ROOM "/d/damned/inn/main_room"

inherit "/std/vault_locker_room";
inherit "/std/virtual/compile";

static int has_error;

int query_is_locker_room() {
  if(has_error) return 0;
  return 1;
}

int do_save_filter(object ob){
    if(!ob->is_player() && !ob->query_auto_load() && !ob->query_property("no save"))
        return 1;
    else
        return 0;
}
//HONSPRON SAVE ROOM FOR CASTLES
void add_crash_items(object ob, int flag){
    string save_dir_r, save_dir, name, tmp, file, *inv2;
	object *inv;
    object a;
    int i;
    
    remove_call_out("add_crash_items");
	name = "room";
	
	save_dir_r = file_name(this_object());
	save_dir_r = replace_string(save_dir_r,"/","");
	save_dir = "/adm/save/objects/saveroom/"+save_dir_r;
    mkdir(save_dir);
	save_dir += "/";
	inv2 = get_dir(save_dir+name+"_*");
	for (i=0;i < sizeof(inv2);i++){
        file = save_dir+name+"_"+i+".o";
        rm(file);
    }
    inv = all_inventory(this_object());
    inv = filter_array(inv, "do_save_filter");
    for(i=0;i < sizeof(inv);i++){
        a=inv[i];
        a->save_me("saveroom/"+save_dir_r+"/"+name+"_"+i);
        if(virtualp(a)){
            tmp = save_dir+ name+"_"+i;
            rename(tmp + ".o", tmp + ".tmp");
            write_file(tmp+".o", "#"+base_name(a)+"\n", 1);
            file = read_file(tmp+".tmp");
            write_file(tmp+".o", file, 0);
            rm(tmp+".tmp");
        }
        if (flag) {
            a->remove();
        }
    }
    message("info", "%^BOLD%^%^RED%^Room Saved: %^RESET%^"+file_name(this_object()),
       find_player("honspron"));
   call_out("save_time", (60*60));
   	return;
}

void restore_crash_items(object ob){
    string file;
    string obj;
    int i;
    string *inv, name, save_dir_r, save_dir;
    
	//remove_call_out("restore_crash_items");
    name = "room";
    save_dir_r = file_name(this_object());
    save_dir_r = replace_string(save_dir_r,"/","");
    save_dir = "/adm/save/objects/saveroom/"+save_dir_r+"/";

    inv = get_dir(save_dir+name+"_*");
    for (i=0;i<sizeof(inv);i++){
        file = save_dir+inv[i];
        obj = replace_string(read_file(file, 1, 1), "#", "");
        obj = replace_string(obj, "\n", "");
        ob = new(obj);
        ob->restore_me("saveroom/"+save_dir_r+"/"+inv[i][0..(sizeof(inv[i])-3)]);
        ob->move(this_object());
        rm(file);
    }
    message("info", "%^BOLD%^%^MAGENTA%^Room Restored: %^RESET%^"+file_name(this_object()),
       find_player("honspron"));
    return;
}

void save_time(){
    /*if (file_name(this_object()) == "/std/save_room" || "/std/vault" || "/std/vault_locker_room" || "/std/locker_room" || "/d/damned/virtual/castle_server" || "/d/damned/virtual/mine_server" || "/d/damned/virtual/inn_server") return 0;
    else {*/
    remove_call_out("save_time");
    call_out("add_crash_items", 240);
    message("info", "%^BOLD%^%^YELLOW%^Save Time Started: %^RESET%^"+file_name(this_object()),
       find_player("honspron"));
    //}
}

void create() {
  ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    return;
}

void init() {
  ::init();
  if((string)this_player()->query_name() == (string)
     INN_ROOM->query_owner(file_name(this_object())))
    add_action("change_desc", "describe");
  add_action("pre_open", "open");
}

int pre_open(string str) {
  if(str) set_locked(str, 0);
  return ::OpenDoor(str);
}

void virtual_setup(string arg) {
  string room, file;
  int room_num;
  string hall_exit, owner;

  if(!sscanf(arg, "inn_%s", room)) {
    write("BUG in the inn server!");
    has_error = 1;
    return;
  }
  has_error = 0;
  set("short", "Inn room #"+room);
  set("long", "Upon entering this room, you can see it is of "+
	"appreciable quality.  While you stay here, you may customize "+
	"the room description, and that description will save for all "+
	"further stays in the inn.  You may also store chests, safes, "+
	"etc. in here for your items.  Also, if you're worried about "+
	"thieves, guards and certain monsters will save here over "+
	"reboots.\n"+
        "To customize the description, type 'describe room'.\n");
  if(!sscanf(room, "%d", room_num)) {
    write("BUG in the inn server!");
    return;
  }
  owner = (string)INN_ROOM->query_owner(sprintf("/d/damned/virtual/inn_%d.inn",
						room_num));
  seteuid(getuid());
  if(owner && file_exists(file = ("/open/inn_descs/"+owner)))
    set("long", read_file(file));
  hall_exit = sprintf("/d/damned/inn/hall_%d", (room_num / 10));
  set_door("door "+room, hall_exit, "out", "key "+room);
  set_lock_level("door "+room, 15);
  add_exit(hall_exit,"out");
  set_items(([ "door" : "It appears to be a sturdy door." ]));
  if(!stringp(base_name(this_object())) ||
     sscanf(base_name(this_object()), "%*sinn_%*s.inn") != 2)
	 call_out("re_create", 2, arg);
  return;
}

void re_create(string arg) {
	string save_dir_r;
  this_object()->create();
  this_object()->virtual_setup(arg);
  call_out("add_crash_items", 90);
  this_object()->restore_crash_items();
  save_dir_r = file_name(this_object());
  save_dir_r = replace_string(save_dir_r,"/","+");
  write_file("/adm/save/objects/saveroom/sinceboot/"+save_dir_r, "saved this boot");
  return;
}

int change_desc(string str) {
  string file;
  
  if(str != "room") return 0;
  write("Enter your desired description (10 lines max).\n"+
	"When you are finished, type a period on a blank line.");
  write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  seteuid(getuid());
  file = "/open/inn_descs/"+(string)this_player()->query_name();
  if(file_exists(file)) rm(file);
  printf("] ");
  input_to("add_line", 0, 0, file);
  return 1;
}

void add_line(string str, int num, string file) {
  if(num >= 10 || str == ".") {
    write("Finished!");
    set("long", read_file(file));
    return;
  }
  write_file(file, str + "\n");
  printf("] ");
  input_to("add_line", 0, num+1, file);
  return;
}













