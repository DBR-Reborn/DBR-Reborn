#include <std.h>
#include "../keep.h"

/* This is the great hall of the black keep, the main intersection of the entire structure. There is a four way intersection present, plus a stairway leading down to the basement. To the west and east are the two large wings of the first floor. To the north is the room with the siatrway to the keeps upper level, and south leads back toward the keep's exit. This room plays a vital part in the areas quest, for it is the location of the Shadowforge, one of the only main artifacts of the keep still standing even after it was conquered. It is here a merchant with a blacksmith skill above 300% can forge the three blessed crystal shards found during the entirety of the quest up until this point of it into the Legend Key, required to access the chamber of the final boss. */

inherit ROOM;

object ob;

void init() {
::init();
add_action("forge", "forge");
}

int forge(string str) {
if(str == "key" && present("blessed power shard", this_player()) && present("blessed life shard", this_player()) && present("blessed terra shard", this_player()) && this_player()->query_skill("blacksmith") > 300) { 
message("my_action", "%^YELLOW%^You use your incredible forging skills to craft the three blessed shards into a key!%^RESET%^", this_player());
message("my_action", this_player()->query_cap_name() +" forges the three blessed shards into a key!", environment(this_player()));
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "Several striking voices are heard throughout the room.");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "Taul says in Common: %^RED%^You have accomplished what i did not believe was within you. You have sacrificed individuality for teamwork to complete your goal, and you now hold the Legend Key in your hand. Now you know what must be done. The ultimate challenge awaits you upstairs.");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "Lidfino says in Common: %^BLUE%^It is indeed impressive you have defeated the myriad of foes placed before you by the dark evil of Owedquar. Your destiny has been laid out in stone as of this day, you shall be the ones to defeat the dark master. Be wary however, his magic is extremely powerful and no one has ever survived an attempt to defeat him. Believe in yourselves, use every advantage your collective minds can assimilate, and you will win.");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "Sacrel says in Common: %^GREEN%^You have made me proud, moreso that i ever imagined possible from mortals. The final battle awaits you upstairs on the second floor. Take the Legend Key now in your hand and unlock the crystal door. Behind it are the obelisks harnessing the nexus power of this structure for the use of binding the dead and the living to serve the forces of evil. Owedquar's Shadow, the mysterious voice that has taunted you throughout your quest, awaits you there. If you defeat him, the dark god's power will be sealed away from this world and peace will return to the living. This will be the fight of your lives, and all life depends on you!");
present("blessed terra shard", this_player())->remove();
present("blessed life shard", this_player())->remove();
present("blessed power shard", this_player())->remove();
ob = new(ITEM+"legend_key.c");
ob->move(this_player());
return 1;
}
if(str != "key") {
message("my_action", "What?", this_player());
return 1;
}
if(str == "key" && (!present("blessed power shard", this_player()) || !present("blessed life shard", this_player()) || !present("blessed terra shard", this_player()))) {
message("my_action", "You do not possess the correct items and/or smithing skills to do this.", this_player());
return 1;
}
}

void create() {
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("%^YELLOW%^The Great Hall%^RESET%^");
set_long(@ext You now stand at an intimidating four way intersection. There is no visible light coming from either direction, therefore there is no indication which way leads to anything important, with the exception of the battered door leaning against the left wall in the south passage. On the four corners of the room, each corner between two passages, lies an empty torch bearing. There is also a large forge in the center of the room, and a staircase leading down in the rooms northwest corner.
    0   
    |   
 0--@--0
    |   down
    0
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint sounds coming from every direction.");
add_exit(ROOMS+"inside5", "north");
add_exit(ROOMS+"inside6", "west");
add_exit(ROOMS+"inside7", "east");
add_exit(ROOMS+"inside8", "down");
add_exit(ROOMS+"inside3", "south");
ob = new(MON+"vampiric_demon.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(ITEM+"shadowforge.c");
ob->move(this_object());
set_items(([
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough.",
({ "door" }) : "This door, somewhat grey in color, appears to be a beaten and broken vault door.",
({ "left wall" }) : "The wall is fashioned of rough black stone. A broken grey door is leaning against it.",
({ "south passage" }) : "The passage appears very dark and can lead to anywhere. A broken grey door is leaning against its left wall.",
({ "keep" }) : "The keep from within appears to be very dark and haunted.",
({ "intersection" }) : "This is a four way intersection leading to various areas of the keep. There is also a staircase in the rooms northwest corner.",
({ "corner" }) : "The corner between two exits of the intersection is square, with an empty torch bearing on it.",
({ "corners" }) : "The corners each between two exits of the intersection are square, with an empty torch bearing on each.",
({ "passage" }) : "The passage appears very dark and can lead to anywhere.",
({ "passages" }) : "The passages appear very dark and can lead to anywhere.",
({ "bearing" }) : "This is an empty torch bearing bolted into the corner.",
({ "stairwell" }) : "The stairwell contains a staircase circular in nature leading down.",
({ "staircase" }) : "The staircase is circular and leads down.",
({ "northwest corner" }) : "There is an empty torch bearing in this corner, as well as a staircase leading down starting there.",
]));
add_pre_exit_function("down", "go_down");
}

int go_down() {
write("You walk down the somewhat circular staircase to the lower floor.");
return 1;
}
