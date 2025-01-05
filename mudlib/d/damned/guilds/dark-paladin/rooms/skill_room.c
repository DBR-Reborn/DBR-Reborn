inherit "/std/guilds/skill_room";
#include "/wizards/cythug/dark-paladin/dark-paladin.h"

void create() {
object ob;
::create();
set_short("The Dark Paladins' Training Room");
set_long("This is a the room where members of the Dark Paladin guild train the various skills that enhance their abilities. To the east you can see the guild treasury and to the west you see the spell training room. Directly north is a swirling shadow that appears to be a portal leading out of here.\n");
set_property("light", 2);
set_property("indoors", 1);
set_join_room("/d/damned/guilds/join_rooms/dark-paladin_join");
add_exit("/d/damned/guilds/join_rooms/dark-paladin_join", "south");
add_exit(ROOMS+"spell_room", "west");
add_exit("/d/damned/guilds/dark-paladin/treasury_room.c", "east");
add_exit(ROOMS+"shadow_room", "north");
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
add_skill("owedquar's will", 1);
add_skill("body block", 2);
add_skill("dodge", 3);
add_skill("empowerment", 3);
add_skill("shadow lore", 3);
add_skill("concentrate", 5);
add_skill("focus casting", 5);
add_skill("spell sense", 12);
add_skill("owedquar's weapon", 25);
add_pre_exit_function("east", "go_east");
add_pre_exit_function("west", "go_west");
return;
}

int go_east() {
if(this_player()->query_class() == "dark-paladin") {
write("The Guardian allows you to pass into the treasury.");
return 1;
}
write("The Guardian says in Common: Only Dark Paladins are permitted to access this room. Please leave now.");
return 0;
}
int go_west() {
return 1;
}
void reset() {
object ob;
::reset();
if(!present("guard")) {
ob = new("/d/damned/guilds/paladin/t_guard");
ob->set_short("An imposing dark armoured guardian");
ob->set_long("This enormous knight, covered in pitch black armour, is the sworn guardian of the Dark Paladin treasury. He stands here guarding the eastern exit.");
ob->set_level(50);
ob->set("id", ({ "guardian", "guard", "knight", "dark guardian", "imposing guardian", "imposing dark guardian", "armoured guardian", "dark armoured guardian", "imposing dark armoured guardian" }));
ob->set_skill("martial arts", 500);
ob->set_name("guardian");
ob->move(this_object());
return;
}
}
