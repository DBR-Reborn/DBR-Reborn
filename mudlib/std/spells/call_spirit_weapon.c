inherit "/std/spells/spell";
#include "/d/damned//guilds/war-priest/war-priest.h"

void create() {
    ::create();
    set_property("name","call spirit weapon");
    set_property("skill","worship of k'thach");
    set_property("casting time",10);
    set_property("base mp cost",25);
    set_property("dev cost", 26);
    set_property("fast dev cost", 72);
    set_property("spell level", 5);
    set_property("moon","luna");
    set_property("caster message","You call the Weapon of the Spirit to your hands.");
    set_property("target message","");
    set_property("observer message","$C calls the Weapon of the Spirit into creation.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", "permanent");
    set_property("prereq", "call divine plate");
    return;
}

void info() {
message("help",
"This spell summons a Weapon of the Spirit into your possession.  The weapon is imbued with holy power. The weapon created is non degrade and will last until reboot. You can call six different types of weapons with this worship, those being: rapier, sword, flail, star, hammer and war-hammer.\n\nSyntax: 'cast *6 call spirit weapon at star'",
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
  ob = new(WEAP+"spirit_rapier.c");
  ob->set_wc(15, "cutting");
  ob->set_wc(8, "impaling");
  ob->set_wc(15, "holy");
  ob->set_auto_crits(([ "holy B" : 3 ]));
  ob->set_property("enchantment", 2);
  ob->set_enh_critical(1);
  ob->move(caster);
  remove();
  return;
}
  if(args == "sword") {
  ob = new(WEAP+"spirit_sword.c");
  ob->set_wc(15, "cutting");
  ob->set_wc(8, "impaling");
  ob->set_wc(15, "holy");
  ob->set_auto_crits(([ "holy B" : 3 ]));
  ob->set_property("enchantment", 2);
  ob->set_enh_critical(1);
  ob->move(caster);
  remove();
  return;
}
  if(args == "flail") {
  ob = new(WEAP+"spirit_flail.c");
  ob->set_wc(15, "cutting");
  ob->set_wc(8, "impaling");
  ob->set_wc(15, "holy");
  ob->set_auto_crits(([ "holy B" : 3 ]));
  ob->set_property("enchantment", 2);
  ob->set_enh_critical(1);
  ob->move(caster);
  remove();
  return;
}
  if(args == "star") {
  ob = new(WEAP+"spirit_star.c");
  ob->set_wc(15, "cutting");
  ob->set_wc(8, "impaling");
  ob->set_wc(15, "holy");
  ob->set_auto_crits(([ "holy B" : 3 ]));
  ob->set_property("enchantment", 2);
  ob->set_enh_critical(1);
  ob->move(caster);
  remove();
  return;
}
  if(args == "hammer") {
  ob = new(WEAP+"spirit_hammer.c");
  ob->set_wc(15, "cutting");
  ob->set_wc(8, "impaling");
  ob->set_wc(15, "holy");
  ob->set_auto_crits(([ "holy B" : 3 ]));
  ob->set_property("enchantment", 2);
  ob->set_enh_critical(1);
  ob->move(caster);
  remove();
  return;
}
  if(args == "war-hammer") {
  ob = new(WEAP+"spirit_warhammer.c");
  ob->set_wc(15, "cutting");
  ob->set_wc(8, "impaling");
  ob->set_wc(15, "holy");
  ob->set_auto_crits(([ "holy B" : 3 ]));
  ob->set_property("enchantment", 2);
  ob->set_enh_critical(1);
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
