//      SAVE ROOM


#include "/adm/include/std.h"
#include "/adm/include/rooms.h"
#include "/adm/include/move.h"
#include "/adm/include/daemons.h"
#include "/adm/include/security.h"

inherit CONTAINER;
inherit "/std/room/senses";
inherit "/std/room/exits";
inherit "/std/room/items";


private int reset_number;

void reset();
void reinitiate();
void set_short(string str);
void set_long(string str);
string query_short();
string query_long(string str);
string query_extra_long();
int move(mixed dest);
int query_reset_number();

int do_save_filter(object ob){
    if(!ob->is_player() && !ob->query_auto_load() && !ob->query_property("no save"))
        return 1;
    else
        return 0;
}

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
    message("info", "%^BOLD%^%^MAGENTA%^Room Saved: %^RESET%^"+file_name(this_object()),
       find_player("test"));
   call_out("save_time", (60*60));
   	return;
}

void restore_crash_items(object ob){
    string file;
    string obj;
    int i;
    string *inv, name, save_dir_r, save_dir;

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
    call_out("add_crash_items", 150);
//   message("info", "%^BOLD%^%^YELLOW%^Save Time Started: %^RESET%^"+file_name(this_object()),
//       find_player("honspron"));
    //}
}

void create() {
    string save_dir_r;
    
    save_dir_r = file_name(this_object());
	save_dir_r = replace_string(save_dir_r,"/","+");
    container::create();
    exits::create();
    items::create();
    senses::create();
	//set_property("storage room", 1);
	this_object()->restore_crash_items();
    reset_number = 0;
    this_object()->reset();
    this_object()->save_time();
    write_file("/adm/save/objects/saveroom/sinceboot/"+save_dir_r, "saved this boot");
}

void reset() {
    reset_eval_cost();
    container::reset();
    reset_number++;
}

void init() {
    exits::initiate_exits();
    senses::initiate();
}

void set_short(string str) { container::set_short(str); }

void set_long(string str) { container::set_long(str); }

string query_short() { 
    return container::query_short();
}

string query_long(string str) {
    string ret;


    if(str) return describe(str);
    else {
	if(query_night() && query("night long")) ret = query("night long");
	else if(!query_night() && query("day long")) ret = query("day long");
else ret = container::query("long");
    }
    if( !ret ) ret = "";
    if(query_extra_long() != "") ret += query_extra_long();
    return ret;
}

string query_extra_long() {
    object *inv;
    string ret, tmp;
    int i;
    ret = "";
    i = sizeof(inv = all_inventory(this_object()));
    while(i--)
      if(tmp = (string)inv[i]->affect_environment()) ret += tmp;
    return ret;
}

void reinitiate() {
    object *inv;
    int i;
    i = sizeof(inv = all_inventory(this_object()));
    while(i--) {
	inv[i]->move(ROOM_VOID);
	inv[i]->move(this_object());
    }
}

int clean_up() { 
    return 0; 
}

int query_is_save_room() { return 1; }

int query_reset_number() { return reset_number; }

int move(mixed dest) { return MOVE_NOT_ALLOWED; }

string *query_id() { return items::query_id(); }

int id(string str) { return items::id(str); }

/*  Added by Misery 030696 so move.c would function properly */
nomask int query_room() { return 1; }
