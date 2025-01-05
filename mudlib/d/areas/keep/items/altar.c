#include <std.h>

/* This is the altar which materializes in the center of the temple outside Daybreak Ridge once the player has the Ultima Umbra. To get the Ultima Umbra, the item advertised in the quest shop as the final quest item, the player must defeat the ultra powerful Owedquar's Shadow in the black keep after completing the entirety of the quest for the area. When the staff is brought to the temple the altar rises from the ground and the gods ask the player to renounce it. In order to do so, the player must be at least level 50. This is to prevent just any char from getting the quest reward due to its value. Upon renouncing, the staff disappears and the quest reward is granted, and the extremely long and difficult epic ends. */ 

inherit OBJECT;

object ob;

void init() {
::init();
add_action("renounce", "renounce");
}

int renounce(string str) {
if(str == "staff" || str == "spear" || str == "spear staff" || str == "ultima umbra") {
if(present("ultima umbra", this_player())) {
if(this_player()->query_level() >= 50) {
if(this_player()->query_property("ultima umbra")) {
message("my_action", "You have already renounced this staff at a previous point in your life, you do not have the power to do it again.", this_player());
return 1;
}
message("my_action", "You hold the Ultima Umbra above your head as you walk up to and stand directly in the center of the magnificent altar.", this_player());
message("my_action", this_player()->query_cap_name() +" holds the Ultima Umbra above his head at the center of the altar.", environment(this_object()));
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "%^YELLOW%^A %^RED%^POWERFUL%^YELLOW%^ blast of inhuman energy strikes the weapon as the ceiling of the temple explodes from its force during its journey from the skies. The Ultima Umbra begins to glow bright white as countless amounts of hellish power is released into the air from it almost immediately. After an extraordinarily bright blinding flash of light knocks you to the floor, you hear an explosion and as the light clears you can see the shattered remains of the choice weapon of Owedquar.%^RESET%^");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "Taul says in Common: %^RED%^You have prevailed over the darkest evil. Against the strongest odds you have defeated the shadow of Owedquar and brought the legendary Ultima Umbra to its final resting place. You are indeed a legend, and one never to be forgotten.%^RESET%^");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "Lidfino says in Common: %^BLUE%^Fortune smiles upon you this glorious day. The realm is at last free of the power of Owedquar, and peace and tranquility can finally return to all the living. I believed in you from the day i first saw you in the keep, and you have made me proud.");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "Sacrel says in Common: %^GREEN%^For the first time in my existence, i can honestly say i am in the presence of true heroism. You defeated the shadow of the dark god, the most feared enemy of all existing realms, and stand alive to speak of the incredible feat. The dark power contained inside the Ultima Umbra has been released and destroyed, cementing the defeat of Owedquar for a long time. On behalf of myself and the divine gods, i give you this as sincere gratitude from the heavens thanking you for what you have done for all of Daybreak Ridge. Regardless of what may happen in the future, this will never be forgotten.");
tell_room(environment(this_object()), "");
message("my_action", "Congratulations! You have completed the Ultima Umbra Quest!!!", this_player());
present("ultima umbra", this_player())->remove();
this_player()->set_property("ultima umbra", 1);
ob = new("/std/diewarzau/obj/misc/ingot.c");
ob->set_material("durithium");
ob->move(this_player());
ob = new("/std/diewarzau/obj/misc/ingot.c");
ob->set_material("durithium");
ob->move(this_player());
return 1;
}
message("my_action", "You hold the Ultima Umbra above your head as you walk up to and stand directly in the center of the magnificent altar. Nothing happens however, for you are not powerful enough to renounce this legendary weapon.", this_player());
return 1;
}
}
}

void create() {
::create();
set_name("divine altar");
set("id", ({ "altar", "divine altar", "extravagant altar", "extravagant divine altar" }));
set_short("%^BOLD%^%^YELLOW%^An extravagant divine altar%^RESET%^");
set_long("This large altar is fashioned of stone crafted into various shapes with skill appearing to be beyond this realm. Three statues, one each of Lidfino, Taul, and Sacrel rise from three sections equidistant from the center, somewhat of a nexus as various different energies flow about it. Nearly the entire room is covered by this enormous wonder of the world.");
set_weight(10000000);
set_value(0);
}
