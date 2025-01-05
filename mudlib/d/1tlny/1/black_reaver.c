#include <std.h>

inherit MONSTER;

create () {
object sword, plate, greaves, gauntlet, helm, bracer;
  ::create();
    set_name("Black Reaver");
    set_id( ({ "black reaver" }) );
    set_short("A big, burly, badass, guard");
     set("race", "high-man");
    set_long(
   "The guard stands in front of the stairs. Warning! This guy will "+ 
    "waste anyone!");
    set_body_type("human");
    set_level(18);
    set_exp(3000);
    set_overall_ac(20);
    set_max_hp(1200000);
    set_hp(300);
    set_property("handedness", "right hand");
    sword = new("/d/damned/virtual/scimitar_6.weapon");
    sword -> set_wc(50,"cutting");
    sword -> set_wc(20,"impaling");
    sword -> set_hit_bonus(40);
    sword -> set_parry_bonus(40);
    sword -> set_material("metal/iysaughton");
    sword -> set_auto_critical("disruption D");
    sword -> set_auto_critical("stun E");
    sword -> set_property("no decay",1);
    sword -> set_property("enchantment",40);
    sword -> set_enh_critical(7);
    sword -> set_("skill level", 160);
      sword -> move(this_object());
    plate = new("/d/damned/virtual/breast-plate.armour");
    plate -> set_material("metal/laen");
    plate -> set_ac(125);
    plate -> set_enh_critical(-4);
      plate -> move(this_object());
    helm = new("/d/damned/virtual/great-helm.armour");
    helm -> set_material("metal/laen");
    helm -> set_ac(125);
    helm -> set_enh_critical(-4);
      helm -> move(this_object());
    greaves = new("/d/damned/virtual/iron-greaves.armour");
    greaves -> set_material("metal/laen");
    greaves -> set_enh_critical(-4);
    greaves -> set_ac(125);
      greaves -> move(this_object());
    gauntlet =new("d/damned/data/virtual/gauntlet.armour");
    gauntlet -> set_material("metal/laen");
    gauntlet -> set_enh_critical(-4);
    gauntlet -> set_ac(125);
    gauntlet -> move(this_object());
    bracer = new("/d/damned/virtual/iron-bracer.armour");
    bracer -> set_material("metal/laen");
    bracer -> set_ac(125);
    bracer -> set_enh_critical(-4);
      bracer -> move(this_object());
    force_me("wear plate");
    force_me("wield sword in right hand");
    force_me("wear greaves");
    force_me("wear bracer on left arm");
}

