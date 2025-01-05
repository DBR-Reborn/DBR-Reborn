inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "whelp summon");
set_property("skill", "elementalism");
set_property("casting time", 12);
set_property("base mp cost", 10);
set_property("dev cost", 65535);
set_property("fast dev cost", 65535);
set_property("spell level", 100);
set_property("moon", "luna");
set_property("caster message", "You summon some baby dragons to ravage your opponents!");
set_property("target message", "");
set_property("observer message", "$C cracks open a few eggs and calls forth baby dragons!");
set_property("spell type", ({ }));
set_property("no target", 1);
set_property("duration", "permanent");
return;
}

void info() {
message("help", "This is a spell exclusively for the Ancient dragons mob. It summons baby  dragons to attack all its enemies.", this_player());
}

void spell_func(object caster, int power) {
object ob;
seteuid(getuid());
ob = new("/std/spells/summon/whelp_dragon.c");
ob->set_up(power);
ob->move(environment(caster));
ob->force_me("cast *6 blizzard");
ob->set_owner((string)caster->query_name());
ob = new("/std/spells/summon/whelp_dragon.c");
ob->set_up(power);
ob->move(environment(caster));
ob->force_me("cast *6 meteor storm");
ob->set_owner((string)caster->query_name());
remove();
return;
}
