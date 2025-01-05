inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "grand summon");
set_property("skill", "owedquar's will");
set_property("casting time", 10);
set_property("base mp cost", 680);
set_property("dev cost", 65535);
set_property("fast dev cost", 65535);
set_property("spell level", 100);
set_property("moon", "luna");
set_property("caster message", "You summon two powerful silver dragons to ravage your opponents!");
set_property("target message", "");
set_property("observer message", "$C opens a gateway and calls forth two horrifying silver dragons!");
set_property("spell type", ({ }));
set_property("no target", 1);
set_property("duration", "permanent");
return;
}

void info() {
message("help", "This is a spell exclusively for the Owedquar's Shadow mob. It summons two powerful silver dragons to attack all its enemies.", this_player());
}

void spell_func(object caster, int power) {
object ob;
seteuid(getuid());
ob = new("/d/areas/keep/mon/silver_dragon.c");
ob->set_up(power);
ob->move(environment(caster));
ob->force_me("cast *6 violent blaze");
ob->set_owner((string)caster->query_name());
ob = new("/d/areas/keep/mon/silver_dragon.c");
ob->set_up(power);
ob->move(environment(caster));
ob->force_me("cast *6 violent blaze");
ob->set_owner((string)caster->query_name());
remove();
return;
}
