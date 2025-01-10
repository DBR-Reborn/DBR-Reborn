inherit "/std/guilds/skill_room";
#include "/d/damned/guilds/voidwalker/voidwalker.h"

void create() {
object ob;
::create();
 ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id(({ "board", "voidwalker_board" }));
    ob->set_board_id("voidwalker_board");
    ob->set_max_posts(25);
    ob->set_location("/d/damned/guilds/voidwalker/skill_room");
    ob->set_short("voidwalker Board");
    ob->set_long("A board where the Voidwalkers of the Rift Guild can post various different messages.\n");
set_short("The Voidwalker's Training Room");
set_long("This is a the room where members of the Voidwalker guild train the various skills that enhance their abilities. To the east you can see the guild treasury and to the west you see the spell training room. Directly north is a swirling shadow that leads to the treasury.\n");
set_property("light", 2);
set_property("indoors", 1);
set_join_room("/d/damned/guilds/join_rooms/voidwalker_join");
add_exit("/d/damned/guilds/join_rooms/voidwalker_join", "south");
//add_exit(ROOMS+"spell_room", "west");
  add_exit("/d/damned/guilds/voidwalker/p_treas", "north");
//add_exit("/d/damned/guilds/dark-paladin/treasury_room.c", "east");
//add_exit(ROOMS+"shadow_room", "north");
add_skill("swimming", 1);
add_skill("two handed blade", 1);
add_skill("attack", 1);
add_skill("parry", 1);
add_skill("trade lore", 1);
add_skill("two handed polearm", 1);
add_skill("perception", 1);
add_skill("two handed blunt", 1);
add_skill("prospecting", 1);
add_skill("two handed flail", 1);
add_skill("consider", 1);
add_skill("melee", 1);
add_skill("oberon's will", 1);
add_skill("assaying", 2);
add_skill("body block", 2);
add_skill("dodge", 3);
add_skill("empowerment", 3);
add_skill("void lore", 3);
add_skill("concentrate", 5);
add_skill("focus casting", 5);
add_skill("spell sense", 12);
add_skill("oberon's weapon", 23);
//add_pre_exit_function("east", "go_east");
//add_pre_exit_function("west", "go_west");
return;
}

int go_north() {
if(this_player()->query_class() == "voidwalker") {
write("The Guardian allows you to pass into the treasury.");
return 1;
}
write("The Guardian says in Common: Only Voidwalkers are permitted to access this room. Please leave now.");
return 0;
}
/*
int go_west() {
return 1;
}
*/
void reset() {
object ob;
::reset();
if(!present("guard")) {
ob = new("/d/damned/guilds/voidwalker/t_guard");
ob->set_short("An imposing dark armoured guardian");
ob->set_long("This enormous knight, covered in pitch black robe, is the sworn guardian of the Voidwalker treasury. He stands here guarding the northern exit.");
ob->set_level(50);
ob->set("id", ({ "guardian", "guard", "knight", "dark guardian", "imposing guardian", "imposing dark guardian", "armoured guardian", "dark armoured guardian", "imposing dark armoured guardian" }));
ob->set_skill("martial arts", 300);
ob->set_name("guardian");
ob->move(this_object());
return;
}
}
