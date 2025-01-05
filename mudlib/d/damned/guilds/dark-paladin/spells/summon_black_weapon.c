inherit "/std/spells/spell";
#include "/d/damned//guilds/dark-paladin/dark-paladin.h"

void create() {
::create();
set_property("name", "summon black weapon");
set_property("skill", "shadow lore");
set_property("casting time", 15);
set_property("base mp cost", 80);
set_property("dev cost", 75);
set_property("fast dev cost", 225);
set_property("spell level", 14);
set_property("moon", "luna");
set_property("caster message", "You summon a powerful shadow immersed weapon to aid you in war!");
set_property("target message", "");
set_property("observer message", "$C summons a powerful shadow immersed weapon.");
set_property("spell type", ({ }));
set_property("no target", 1);
set_property("duration", "permanent");
set_property("prereq", "summon shadow weapon");
return;
}

void info() {
message("help", "This spell allows a Dark Paladin to summon a very powerful weapon into existence to aid him in combat. He/she can call four different types of two handed weapons with this magic, those being sword, spear, star, and hammer. The weapon created is non degrade and will last until reboot.\n\nSyntax: 'cast *6 summon black weapon at sword'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
object ob;
int skill;

skill = caster->query_skill(props["skill"]);

if(flag) {
message("info", "You fail to summon the weapon, and expend all of your magic power!", caster);
caster->set_mp(0);
remove();
return;
}
if(args == "sword") {
ob = new(WEAP+"black_sword.c");
ob->set_property("hit bonus", skill / 3);
ob->set_property("enchantment", skill / 5);
ob->set_wc(skill *2/3, "unholy");
ob->set_wc(skill *2/3, "cutting");
ob->set_wc(skill *2/3, "plasma");
ob->set_enh_critical(4);
ob->move(caster);
remove();
return;
}
if(args == "spear") {
ob = new(WEAP+"black_spear.c");
ob->set_property("hit bonus", skill / 3);
ob->set_property("enchantment", skill / 5);
ob->set_wc(skill *2/3, "unholy");
ob->set_wc(skill *2/3, "impaling");
ob->set_wc(skill *2/3, "plasma");
ob->set_enh_critical(4);
ob->move(caster);
remove();
return;
}
if(args == "star") {
ob = new(WEAP+"black_star.c");
ob->set_property("hit bonus", skill / 3);
ob->set_property("enchantment", skill / 5);
ob->set_wc(skill *2/3, "unholy");
ob->set_wc(skill *2/3, "strike");
ob->set_wc(skill *2/3, "plasma");
ob->set_enh_critical(4);
ob->move(caster);
remove();
return;
}
if(args == "hammer") {
ob = new(WEAP+"black_hammer.c");
ob->set_property("hit bonus", skill / 3);
ob->set_property("enchantment", skill / 5);
ob->set_wc(skill *2/3, "unholy");
ob->set_wc(skill *2/3, "crushing");
ob->set_wc(skill *2/3, "plasma");
ob->set_enh_critical(4);
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
