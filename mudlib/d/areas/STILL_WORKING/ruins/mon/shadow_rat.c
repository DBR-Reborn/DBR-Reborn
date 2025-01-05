
#include "../ruins.h"
#include <std.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("shadow rat");
    set("id", ({"shadow", "rat", "shadow rat"}) );
    set_level(15+random(5));
    set("short", "shadow rat");
    set("long", "This cloaked fingure walks around the room. You can not make out anything about what he looks like.");
    set("race", "rat");
    set_gender("neuter");
    // et_money("silver", random(300)+200);
    set_body_type("rat");
    set ("aggressice", 2);
    set_skill("dual attack", 70);
    set_skill("invisibility art", 100);
    set_skill("blade", 70);
    set_skill("parry", 50);
    set_skill("dodge", 60);
    set_wielding_limbs( ({"left hand, right hand"}) );
    set_emotes(2, ({
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
