#include <std.h>

inherit MONSTER;

create() {
    ::create();
    set_name("demon");
    set_id( ({"demon", "king", "demon king", "warlord"}));
    set("race", "demon");
    set_level(70);
    set_body_type("winged-humanoid");
    set_property("physical resistance",
      ([ "default" : 80, "raysorite" : -30, "holy" : "-50" ]));
    set_short("The Demon King");
    set_long("This demon king must have opened the demonic gate! He's the biggest demon you've seen yet - fifteen feet of red-skinned, muscular fury. His claws and teeth are almost monomolecular at their edges, and he looks impervious to normal attacks. His powerful wings scare you, too.");
    set("aggressive", 0);
    set_skill("parry", 375);
    set_skill("dodge", 375);
    set_skill("melee", 450);
    set_skill("attack", 450);
    set_lang_prof("common",10);
    force_me("speak common");
    set_speech(10, "common", 
      ({
	"Those accursed gnomes have destroyed my plans again! The ring is not here anymore, and the gate lacks the power to send more troops through! NOW WHERE IS THE RING? THOSE GNOMES SHALL PAY DEARLY!"
      }), 0);
}
