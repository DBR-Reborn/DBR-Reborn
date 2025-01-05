// Adult myconid
// By vishnu

#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("Adult Myconid");
    set("id", ( {"myconid", "adult", "adult myconid"} ) );
    set_level(8+random(4));
    set("short", "Adult Myconid");
    set("long",
    "This myconid seems busy with his own affairs. "
    "He wanders around, talking to the other myconids. "
    "You wonder what kind of stuff Myconids actually do."
    );
    set_moving(1);
    set_speed(20);
    set("race", "myconid");
    set_gender("neuter");
    set_combat_chance(60);
    add_spell("fireball", "$A");
    set_spell_level("fireball", 5);
    set_skill("conjuration", 80);
    set_money("silver", random(200)+200);
    set_body_type("human");
    set_wielding_limbs( ({"right hand"}) );
    set_emotes(8,
    ({
     "The myconid scurries around, chatting with his buddies.",
     "The myconid ponders for a second, then continues.",
     "The myconid looks you over.",
    "The myconid rubs his head.",
    }),
    0);
    set_achats(30,
       ({
    "The myconid sweats frantically!",
     "The myconid shrieks with pain!",
     "The myconid tries to escape, but is blocked in.",
    }) );
    new("/d/damned/virtual/short-sword_3.weapon")->move(this_object());
    force_me("wield sword in right hand");
    new("/d/damned/virtual/breast-plate.armour")->move(this_object());
    force_me("wear plate");
}
