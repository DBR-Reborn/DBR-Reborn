#include <std.h>
#include <colors.h>

inherit MONSTER;

create() {
    object ob, obw;
    ::create();
    set_name("monk");
    set_id( ({"undead", "monk"}));
    set_short("undead monk");
    set_long("This monk still practices his attack arts.  "
    );
    set("race", "undead");
    set_level(55+random(4));
    set_body_type("human");
    set("aggressive", 0);
    set_skill("necromancy", 120);
    set_spell_level("instill fear", 6);
    add_spell("instill fear", "$A");
    set_combat_chance(300);
    obw = new("/d/damned/virtual/quarter-staff_6.weapon");
    obw->set_short(CBOLD + CBLUE +
      "Sidepiece of Chemosh" + CRESET);
obw->set_material("metal/elrodnite");
    obw->add_wc(65,"cold");
    obw->set_parry_bonus(35);
    obw->set_property("brittle", 20);
    obw->move(this_object());
    force_me("equip");
    improve_weapon(200);
    set_skill("martial arts", 250);
    set_skill("parry",
      query_skill("parry") *3/2);
}

