
#include "../ruins.h"
#include <std.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("rat-man raider");
    set("id", ({"rat", "rat-man", "raider", "rat-man raider"}) );
    set("short", "rat-man raider");
    set("long", "This cloaked fingure walks around the room. You can not make out anything about what he looks like.");
    set_level(11);
    set("race", "rat");
    set_gender("neuter");
    // add_money("copper", 1);
    set_body_type("rat");
    set("aggressive", 1);
    set_skill("dual attack", 70);
    set_skill("blade", 70);
    set_skill("parry", 50);
    set_skill("dodge", 60);
    set_wielding_limbs( ({"left hand, right hand"}) );
    set_emotes(5, ({
	"The walls seem to move."
      }), 0);
    set_achats(30, ({
	"The rat whips his tail at its attacker.",
	"The rat jumps at empty space.",
	"The rat's eyes glow more brightly.",
      }) );
    new("/d/damned/virtual/long-sword_6.weapon")->move(this_object());
    new("/d/damned/virtual/long-sword_6.weapon")->move(this_object());
    new("/d/damned/virtual/leather-vest.armour")->move(this_object());
    new("/d/damned/virtual/cloak.armour")->move(this_object());
    force_me("wield sword 2 in right hand");
    force_me("wield sword in left hand");
    force_me("equip");
}
