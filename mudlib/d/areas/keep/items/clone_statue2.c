#include <std.h>
#include "../keep.h"

/* This is the lone stone statue of the six in the clone statue room of the black keep that does not carry a weapon. It is impossible to pick up as are the other statues. The player can see this if he looks over all the statues and notices the difference in long descriptions. A grand axe from the armory in the eastern wing of the keep is required to arm the statue, and then with the command 'arm statue', the player equips it and the blue key will emerge in the room as all six statues glow blue, as will four death soldiers to block exits and defend the secret quest item. */

inherit OBJECT;

object ob;

void init() {
::init();
add_action("arm", "arm");
}

int arm(string str) {
if(str == "statue 5") {
if(present("grand axe", this_player())) {
message("my_action", "You place the towering grand axe in the slightly open hand of the stone statue.", this_player());
tell_room(environment(this_object()), "%^BLUE%^The six statues, now completely identical upon the arming of the empty handed statue, begin to glow bright blue. After a few moments the statues return to normal and a small object materializes in the direct center of the room.");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "A few seconds barely pass before a malicious echo coarses the large room.");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "A mysterious voice says in Common: %^CYAN%^I have been waiting for you. Prove yourself to me.");
tell_room(environment(this_object()), "%^RED%^Four vicious looking skeletal demons simultaneously appear in a flash of light!");
ob = new(MON+"death_soldier.c");
ob->set("aggressive", 1);
ob->set_property("see invis", 1);
ob->move(environment(this_object()));
ob->force_me("kill "+(string)this_player()->query_cap_name());
ob = new(MON+"death_soldier.c");
ob->set("aggressive", 1);
ob->set_property("see invis", 1);
ob->move(environment(this_object()));
ob->force_me("kill "+(string)this_player()->query_cap_name());
ob = new(MON+"death_soldier.c");
ob->set("aggressive", 1);
ob->set_property("see invis", 1);
ob->move(environment(this_object()));
ob->force_me("kill "+(string)this_player()->query_cap_name());
ob = new(MON+"death_soldier.c");
ob->set("aggressive", 1);
ob->set_property("see invis", 1);
ob->move(environment(this_object()));
ob->force_me("kill "+(string)this_player()->query_cap_name());
ob = find_object("grand axe");
present("grand axe", this_player())->remove();
ob = new(ITEM+"blue_key.c");
ob->move(environment(this_object()));
ob = new(ITEM+"clone_statue1.c");
ob->move(environment(this_object()));
remove();
return 1;
}
message("my_action", "You do not possess the correct weapon required to arm the statue.", this_player());
return 1;
}
}

void create() {
::create();
set_name("statue");
set("id", ({ "statue", "imposing statue", "stone statue", "imposing stone statue" }));
set_short("An imposing stone statue");
set_long("This is a very large statue of an battle hardened warrior fashioned completely of stone, standing approximately eight feet tall. Its body is molded to appear as if it is wearing very well crafted armour, and it carries no weapon.");
set_weight(10000000);
set_value(0);
}
