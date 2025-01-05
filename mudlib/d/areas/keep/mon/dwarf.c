#include <std.h>
#include "../keep.h"

/* This is the gnome that is living alone in Mount Nelfton. It is extremely far away from the black keep, but it plays a vital role in the areas quest. A player cannot fight this mob, but he/she can listen when it speaks about Merik the Dwarf. Merik is the dwarf ordered to be slain in the contract present in the black keep's assassins quarters. If the contract is given to the dwarf, he will ask for proof it was carried out. That proof is a hidden black axe in the hallway of the keep basement leading to the library. When the axe is brought to the dwarf, he will reward the player with the green gem required to activate the green arcane orb. */

inherit MONSTER;

object ob;

void init() {
::init();
add_action("give", "give");
}

int give(string str) {
if(str == "contract to dwarf" || str == "contract to dirty dwarf" || str == "contract to old dwarf" || str == "contract to old dirty dwarf" || str == "assassins contract to dwarf" || str == "assassins contract to old dwarf" || str == "assassins contract to dirty dwarf" || str == "assassins contract to old dirty dwarf") {
if(present("assassins contract", this_player())) {
present("assassins contract", this_player())->remove();
ob = new(ITEM+"contract2.c");
ob->move(this_object());
message("my_action", "You hand the contract over to the dwarf. Upon reading it he becomes very shocked.", this_player());
message("my_action", this_player()->query_cap_name() +" gives An assassins contract to Old Dwarf.", environment(this_object()));
tell_room(environment(this_object()), "Old Dwarf says in Common: Dear God! This is a contract asking for the murder of Merik! I simply cannot believe it could have been carried out though, Merik is very smart and knows how to dodge assailants. I will never believe he is dead until I am shown proof, his black builders axe apart from his body for it never leaves his side even in sleep.");
return 1;
}
return 1;
}
if(str == "axe to dwarf" || str == "axe to dirty dwarf" || str == "axe to old dwarf" || str == "axe to old dirty dwarf" || str == "black axe to dwarf" || str == "black axe to old dwarf" || str == "black axe to dirty dwarf" || str == "black axe to old dirty dwarf") {
if(present("black axe", this_player())) {
present("black axe", this_player())->remove();
ob = new(WEAP+"black_axe.c");
ob->move(this_object());
message("my_action", "You give the black axe to the dwarf. The look on his face almost immediately turns to disbelief.", this_player());
message("my_action", this_player()->query_cap_name() +" gives A fine black axe to Old Dwarf.", environment(this_object()));
tell_room(environment(this_object()), "Old Dwarf says in Common: So it is indeed true. Merik has been slain by the forces of Owedquar. He was my best friend for over twenty years, and never once was I not by his side until the day i was injured and had to stay behind while he was put to work on constructing that keep. If I was only there he would still be alive! ARRRRGGHHHHH! I beg of you with my soul, PLEASE destroy the ones who did this to him. I can aid you in this task by giving you my most prized possession, this %^GREEN%^green gem%^RESET%^. I was told when I recieved it so long ago that its sole use was against the power of Owedquar.");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "%^BOLD%^%^YELLOW%^As it sheds tears the old dirty dwarf slowly walks away down the pass, its destination uncertain at best.%^RESET%^");
ob = new(ITEM+"green_gem.c");
ob->move(this_player());
//this_object()->move("/wizards/cythug/workroom.c");
remove();
return 1;
}
return 1;
}
}

void create() {
::create();
set_name("old dwarf");
set("id", ({ "dwarf", "old dwarf", "dirty dwarf", "old dirty dwarf" }));
set_property("no kill", 1);
set_property("no kill msg", "Old Dwarf says in Common: Please! I do not want to fight! Just leave me in peace.");
set_level(50);
set_short("[50]old dirty dwarf");
set_long("This dwarf appears very old and covered with dirt, appearing as if it hasnt bathed in an extremely long time. It stands about five feet tall and has a dark grey beard extending halfway down its body. He rests here on the mountain very lonely awaiting the return of his long lost friend.");
set("race", "dwarf");
set_gender("male");
set_body_type("humanoid");
set_alignment(0);
return;
}

void heart_beat() {
int a;
int b;
::heart_beat();
a = random(100);
if(a<10) {
b = random(3);
if(b<1) {
tell_room(environment(this_object()), "Old Dwarf says in Common: Have you seen my friend Merik? He hasnt returned from his construction assignment building that one keep.");
return;
}
if(b>0 && b<2) {
tell_room(environment(this_object()), "Old Dwarf says in Common: Ever since that day I was injured in the mines, I have never been the same. I was not allowed to work with my friend of more than twenty years and I am now here alone, waiting for his return.");
return;
}
if(b>1) {
tell_room(environment(this_object()), "Old Dwarf says in Common: My time is coming soon. I am not long for this cruel world.");
return;
}
}
}
