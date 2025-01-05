inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "abyss blade");
set_property("skill", "empowerment");
set_property("casting time", 24);
set_property("base mp cost", 175);
set_property("dev cost", 145);
set_property("fast dev cost", 435);
set_property("spell level", 28);
set_property("moon", "warzau");
set_property("damage multiplier", 1);
set_property("caster message", "You cast %^BOLD%^%^RED%^abyss blade %^RESET%^at $T!");
set_property("target message", "");
set_property("observer message", "$C casts %^BOLD%^%^RED%^abyss blade %^RESET%^at $T.");
set_property("spell type", ({ }));
set_property("duration", 200);
set_property("must be present", 1);
set_property("stack key", "abyss blade");
set_property("stack num", 2);
set_property("no borrow", 1);
set_property("target type", "any");
return;
}

void info() {
message("help", "This is a sickeningly powerful spell that imbues tremendous evil power into any weapon, a combination of massive darkness, aether, and chaotic energy. To cast this however requires a highly considerable amount of mp and its duration is lower than that of most other spells of this type. It can be stacked on a weapon a total of two times, and due to its extreme power cannot be used in conjunction with the arcane-imbuer spell 'bind enchantment'.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
object ob;
object weap;

if(!at->is_weapon()) {
message("info", "You may only cast this magic upon weapons.", caster);
caster->add_mp(props["mp cost"]);
return;
}

ob = new("/std/spells/shadows/weapon_shadow");
message("info", "%^B_RED%^%^BOLD%^%^BLACK%^You imbue the weapon with mortifying evil power!%^RESET%^", caster);
ob->set_extra_wc(([ "unholy" : 15*power ]));
ob->set_extra_wc(([ "aether" : 15*power ]));
ob->set_extra_wc(([ "disruption" : 15*power ]));
ob->set_shadow_name("abyss blade");
ob->start_shadow(at, props["duration"], "%^RED%^An abyss blade spell wears off.%^RESET%^");
remove();
return;
}
