#include <shao.h>
inherit "/std/vault";

private int open;
object mon;

void init(){
::init();
add_action("read_sign","read");
}
void reset() {
    ::reset();
    seteuid(getuid());
    if (!present("christina") && open) {
mon = new(MON_PATH+"christina")->move(this_object());
    }
}

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",3);
    add_exit(PATH+"sr5","north");
add_exit(PATH+"cloth_store","south");
add_exit(PATH+"1st6","east");
set_door("wooden door",PATH+"cloth_store","south",
"master key");
    set_open("wooden door", 0);
    set_locked("wooden door", 1);
    open = 1;
set_door("south door",PATH+"sr5","north",
"leather shop");
set_door("west door",PATH+"1st6","east",
"cloth shop");
    set_open("south door", 1);
    set_locked("south door", 0);
set_open("west door", 1);
set_locked("west door", 0);
    set_lock_level("wooden door", 20);
set("short","Somebody's clothing store..");
    set("long",
      "A large sign reads:\n"
"%^RED%^--== Welcome to Sabrina's House of Leather ==--%^RESET%^\n"
"This is a small shop compared to most others, "
"but you feel as if you are standing in a kings palace.  "
"The floors are pure black marble, and in superb condition.  "
"You suspect the walls are stone, but are unsure since "
"they have been covered with large plates of padded "
"black leather.  "
      "On the walls you notice numerious items crafted from "
      "leather.  Not only clothing, but whips, masks, cat-suits, "
      "and in many different colours too.\n"
      "\n"
      "You notice a small sign attached to the front "
      "of a large oak counter.\n");
set_items( (["sign":"You glance at it, but decide you want to 'read' it",
	"wooden door" : "It looks very sturdy."]) );
    set_open_function("open_door", "5:00:00");
    set_close_function("close_door", "18:00:00");
}

void open_door() {
    set_locked("south door", 0);
set_locked("west door", 0);
    set_open("south door", 1);
set_open("west door", 1);
call_other(PATH+"sr5","set_locked",
"south door", 0);
call_other(PATH+"1st6","set_locked",
"west door", 0);
call_other(PATH+"sr5","set_open",
"south door", 1);
call_other(PATH+"1st6","set_open",
"west door", 1);
    open = 1;
    this_object()->reset();
    return;
}

void close_door() {
    object ob, *inv;
    int i;

    ob = present("sabrina", this_object());
    if(ob) {
	ob->move(find_object_or_load("/d/standard/void"));
	ob->remove();
    }
    inv = all_inventory(this_object());
    i = sizeof(inv);
    while(i--) {
	if(living(inv[i])) {
	    message("info", "The shop is closing now.  You must leave.", inv[i]);
inv[i]->move(find_object_or_load(PATH+"sr5"));
	}
    }
    set_open("south door", 0);
set_open("west door", 0);
    set_locked("south door", 1);
set_locked("west door", 1);
call_other(PATH+"sr5","set_open",
"south door", 0);
call_other(PATH+"1st6","set_open",
"west door", 0);
call_other(PATH+"sr5","set_locked",
      "south door", 1);
call_other(PATH+"1st6","set_locked",
"west door", 1);
    open = 0;
}
int read_sign(string str){
if(!str){
notify_fail("You wonder if you even KNOW how to read...\n"
"then you think 'hmmmm, what do I want to read...'\n");
return 0;
}
if(str == "sign"){
if(!present("sabrina")){
write("Fresh blood covers the sign and makes it too "
"hard to read.\n");
return 1;
}
else {
write("the sign reads : 'Welcome to my house of leather.\n"
"if you need help, tell me so, or say so, or ask to "
"see what I have to sell...\n"
"\n"
"there is also some smaller print but you'd need dam "
"good perception to make it out.\n");
return 1;
}
}
if(str == "fine print" || str == "smaller print" || 
str == "print" || str == "small print"){
if(this_player()->query_skill("perception") > 60) {
write("You can just make out the words :\n"
"'Ask sabrina about the back room'");
return 1;
}
write("you squint and stare but just can't make out what "
"it says.\n");
return 1;
}
}
