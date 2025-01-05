inherit "/std/spells/spell";
#include "/d/damned//guilds/war-priest/war-priest.h"

void create() {
    ::create();
    set_property("name","call weapon of faith");
    set_property("skill","worship of k'thach");
    set_property("casting time",10);
    set_property("base mp cost",35);
    set_property("dev cost", 52);
    set_property("fast dev cost", 151);
    set_property("spell level", 10);
    set_property("moon","luna");
    set_property("caster message","You call the Weapon of Faith to your hands.");
    set_property("target message","");
    set_property("observer message","$C calls the Weapon of Faith into creation.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", "permanent");
    set_property("prereq", "call spirit weapon");
    return;
}

void info() {
message("help",
"This spell summons a Weapon of Faith into your possession.  The weapon is imbued with great holy power and as such can only be wielded by dedicated worshipers. The weapon created is non degrade and will last until reboot.You can call six different types of weapons with this worship, those being: rapier, sword, flail, star, hammer and war-hammer. \n\nSyntax: 'cast *6 call weapon of faith at rapier'",
this_player());
}
  
void spell_func(object caster, object at, int power, string args, int flag) {
object ob;
int skill;

skill = caster->query_skill(props["skill"]);

if(flag) {
    message("info", "The fumble causes you to be drained of "
      "half of your remaining mp!", caster);
    caster->add_mp(-1 * (int)caster->query_mp() / 2);
    remove();
    return;
}
  if(args == "rapier") {
  ob = new(WEAP+"faith_rapier.c");
  ob->set_wc(25, "cutting");
  ob->set_wc(20, "impaling");
  ob->set_wc(25, "holy");
  ob->set_auto_crits(([ "holy B" : 4 ]));
  ob->set_property("enchantment", 3);
  ob->set_enh_critical(2);
  ob->move(caster);
  remove();
  return;
}
  if(args == "sword") {
  ob = new(WEAP+"faith_sword.c");
  ob->set_wc(25, "cutting");
  ob->set_wc(20, "impaling");
  ob->set_wc(25, "holy");
  ob->set_auto_crits(([ "holy B" : 4 ]));
  ob->set_property("enchantment", 3);
  ob->set_enh_critical(2);
  ob->move(caster);
  remove();
  return;
}
  if(args == "flail") {
  ob = new(WEAP+"faith_flail.c");
  ob->set_wc(25, "cutting");
  ob->set_wc(20, "impaling");
  ob->set_wc(25, "holy");
  ob->set_auto_crits(([ "holy B" : 4 ]));
  ob->set_property("enchantment", 3);
  ob->set_enh_critical(2);
  ob->move(caster);
  remove();
  return;
}
  if(args == "star") {
  ob = new(WEAP+"faith_star.c");
  ob->set_wc(25, "cutting");
  ob->set_wc(20, "impaling");
  ob->set_wc(25, "holy");
  ob->set_auto_crits(([ "holy B" : 4 ]));
  ob->set_property("enchantment", 3);
  ob->set_enh_critical(2);
  ob->move(caster);
  remove();
  return;
}
  if(args == "hammer") {
  ob = new(WEAP+"faith_hammer.c");
  ob->set_wc(25, "cutting");
  ob->set_wc(20, "impaling");
  ob->set_wc(25, "holy");
  ob->set_auto_crits(([ "holy B" : 4 ]));
  ob->set_property("enchantment", 3);
  ob->set_enh_critical(2);
  ob->move(caster);
  remove();
  return;
}
  if(args == "war-hammer") {
  ob = new(WEAP+"faith_warhammer.c");
  ob->set_wc(25, "cutting");
  ob->set_wc(20, "impaling");
  ob->set_wc(25, "holy");
  ob->set_auto_crits(([ "holy B" : 4 ]));
  ob->set_property("enchantment", 3);
  ob->set_enh_critical(2);
  ob->move(caster);
  remove();
  return;
}
  else {
  message("info", "You cannot summon that type of weapon with this spell.", caster);
  message("info", (string)caster->query_cap_name()+"'s spell fails.", environment(caster), ({ "caster" }));
  remove();
  return;
}
}
