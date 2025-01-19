inherit "/std/spells/spell";
#include "/d/damned//guilds/voidwalker/voidwalker.h"

void create() {
	::create();
	set_property("name", "summon voidmaker");
	set_property("skill", "darkweaving");
	set_property("casting time", 75);
	set_property("base mp cost", 150);
	set_property("dev cost", 120);
	set_property("fast dev cost", 360);
	set_property("spell level", 23);
	set_property("moon", "luna");
	set_property("caster message", "%^BOLD%^%^YELLOW%^You summon the Legendary Voidmaker!%^RESET%^");
	set_property("target message", "");
	set_property("observer message", "%^BOLD%^%^YELLOW%^$C summons the Legendary Voidmaker.%^RESET%^");
	set_property("spell type", ({ }));
	set_property("no target", 1);
	set_property("duration", "permanent");
	return;
}

void info() {
message("help", "This spells calls forth what is quite possibly THE most powerful weapon in all of Daybreak Ridge, the Voidmaker, into the hands of a Voidwalker. When summoned, the weapon lasts till reboot and carries multiple elemental properties with intensities determined by the level of the darkweaving skill when cast. The Voidmaker requires the skill 'oberon's weapon' to wield, an expensive skill available to train at level 25, and is non enchantable due to its power. When casting the spell, no target need be supplied.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
object ob;
int skill;

skill = caster->query_skill(props["skill"]);

if(flag) {
message("info", "You fail to summon the weapon, and expend all of your magic power!", caster);
caster->set_mp(0);
remove();
return;
}
ob = new(WEAP+"voidmaker.c");
ob->set_property("enchantment", skill / 5);
ob->set_wc((skill/6)*power, "vacuum");
ob->set_wc((skill/6)*power, "time");
ob->set_wc((skill/6)*power, "radiation");
ob->set_wc((skill/6)*power, "infernal");
ob->set_wc((skill/6)*power, "stress");
ob->set_enh_critical(5);
ob->move(caster);
remove();
return;
}
