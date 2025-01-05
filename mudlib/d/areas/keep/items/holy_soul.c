#include <std.h>
#include "../keep.h"

/* This is the holy soul item that is obtained from the black keep librarian in the basement. To get it from him, the player must give him the white spellbook from the arch mage chamber in the keeps east wing. This item serves two purposes. If a non-disciple uses it at the pool of life deep in the keeps west wing, their hp and mp will be completely restored to maximum. However, if a disciple uses it, the power of Lidfino will be released throughout the water and the offering of Lidfino will be granted, which is the red gem required to activate the red arcane orb. However, the gem appears clear on the other side of the keep at the open palm statue which recieved Lidfino's offerings. If the soul is used for healing, it can be retrieved from the water. But if its used in the quest for the red gem is dissipates. */

inherit OBJECT;

object ob;

void init() {
::init();
add_action("immerse", "immerse");
}

int immerse(string str) {
if(id(str)) {
if(present("pool of life", environment(this_player())) && this_player()->query_class() == "disciple") {
message("my_action", "You take the white globe and immerse it in the sacred water. Upon doing so all the water begins to glow an extremely bright white, and the eyes on the head bust of Lidfino do as well. Not long after a powerful voice echoes through the room.", this_player());
tell_room(environment(this_player()), "A powerful voice speaks in Common: %^BLUE%^You have released the holy power and returned it to the sacred water where it belongs. I shall now reward you with my offering.%^RESET%^");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "The eyes on the statue for an instant glow blinding white. However once the light vanishes you do not notice anything significant to have happened except for the globe having dissipated.");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "A mysterious voice says in Common: %^CYAN%^How foolish you are. Lidfino's offering is a lie, for it does not exist. I am glad you enjoyed my powers of illusion as I give you my sincere greeting. Welcome to my keep mortals, I do hope you enjoy it because you will never leave here alive.");
ob = new(ITEM+"palm_statue2.c");
ob->move(ROOMS+"inside29");
remove();
return 1;
}
if(present("pool of life", environment(this_player())) && this_player()->query_class() != "disciple") {
message("my_action", "You take the white globe and immerse it in the sacred water. The globe glows white for an instant, filling you with health, then it becomes normal again and dissipates.", this_player());
message("my_action", this_player()->query_cap_name() +" immerses the white globe in the water. It flashes white for an instant and then stops shortly before it dissipates.", environment(this_player()));
if(this_player()->query_hp() > this_player()->query_max_hp()) {
if(this_player()->query_mp() > this_player()->query_max_mp()) {
remove();
return 1;
}
if(this_player()->query_mp() <= this_player()->query_max_mp()) {
this_player()->set_mp(this_player()->query_max_mp());
remove();
return 1;
}
return 1;
}
if(this_player()->query_hp() <= this_player()->query_max_hp()) {
this_player()->set_hp(this_player()->query_max_hp());
if(this_player()->query_mp() > this_player()->query_max_mp()) {
remove();
return 1;
}
if(this_player()->query_mp() <= this_player()->query_max_mp()) {
this_player()->set_mp(this_player()->query_max_mp());
remove();
return 1;
}
return 1;
}
return 1;
}
if(!present("pool of life")) {
message("my_action", "What?", this_player());
return 1;
}
}
}

void create() {
::create();
set_name("holy soul");
set("id", ({ "globe", "white globe", "shiny globe", "shiny white globe", "soul", "holy soul" }));
set_short("A shiny white globe");
set_long("This is a very shiny perfectly sphere globe, about four inches in diameter. If you look at it very closely you can see a small amount of energy coarsing about it, almost as if something is inside.");
set_weight(100);
set_value(50000);
}
