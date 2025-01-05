inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "mist cloud");
set_property("skill", "shadow lore");
set_property("casting time", 5);
set_property("base mp cost", 25);
set_property("dev cost", 20);
set_property("fast dev cost", 60);
set_property("spell level", 3);
set_property("moon", "luna");
set_property("caster message", "You summon a thick cloud of mist to surround you.");
set_property("target message", "");
set_property("observer message", "$C summons a thick cloud of mist.");
set_property("spell type", ({ }));
set_property("no target", 1);
set_property("duration", 200);
return;
}

void info() {
message("help", "This spell calls forth a very thick cloud of mist, which will noticeably hamper the vision of all present in the room.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
object ob;

ob = new("/std/spells/shadows/light_shad");
ob->set_light(flag?2:-5);
ob->set_shadow_name("darkness");
ob->start_shadow(caster, props["duration"], "The mist cloud encircling you dissipates.");
return;
}
