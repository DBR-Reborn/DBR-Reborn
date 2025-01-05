// Elder Myconid
// Vishnu's mob

#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("Elder Myconid");
    set("id", ({"elder", "myconid", "elder myconid", "mushroom"}) );
    set("short", "Elder Myconid");
    set("long",
    "The Elder Myconid looks at you reverently.  His learned eyes scan you "
    "over.  You wonder what he's thinking about you.  He probably knows "
    "that you will try to kill him, but he is ready, you can tell."
    );
    set("race", "myconid");
    set_gender("neuter");
    set_level(10+random(5));
    set_money("gold", random(50)+30);
    set_body_type("human");
    set_wielding_limbs( ({"right hand", "left hand"}) );
    set_combat_chance(90);
    add_spell("fireball", "$A");
    set_spell_level("fireball", 6);
    set_skill("conjuration", 90);
    set_skill("necromancy", 90);
    set_skill("prepare corpse", 90);
    set_spell_level("animate zombie", 1);
    set_emotes(7,
    ({
      "The Elder eyes you suspiciously.",
     "The Elder converses with his fellow Myconids",
     "The Elder scratches his cap for a second.",
    }), 0);
    set_achats(30,
     ({
      "The Elder Bats you down forcefully.",
      "The Elder call for help!",
      "The Elder bats your weapon away gracefully.",
    }) );
new("/d/damned/virtual/two-handed-sword_3.weapon")->move(this_object());
new("/d/damned/virtual/breast-plate.armour")->move(this_object());
force_me("wear plate");
force_me("wield sword in left hand and right hand");
}
