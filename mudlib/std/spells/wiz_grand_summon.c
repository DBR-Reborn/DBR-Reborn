inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "wiz grand summon");
set_property("skill", "owedquar's will");
set_property("casting time", 10);
set_property("base mp cost", 10);
set_property("dev cost", 65535);
set_property("fast dev cost", 65535);
set_property("spell level", 100);
set_property("moon", "luna");
set_property("caster message", "You summon two powerful dragons to ravage your opponents!");
set_property("target message", "");
set_property("observer message", "$C opens a gateway and calls forth two horrifying dragons!");
set_property("spell type", ({ }));
set_property("no target", 1);
set_property("duration", "permanent");
return;
}

void info() {
message("help", "This is a spell exclusively for the Owedquar's Shadow mob. It summons two powerful dragons to attack all its enemies.", this_player());
}

void spell_func(object caster, int power) {
object ob;
seteuid(getuid());
ob = new("/std/spells/summon/gold_dragon_pet.c");
ob->set_up(power);
ob->move(environment(caster));
//ob->force_me("cast *6 violent blaze");
ob->set_owner((string)caster->query_name());
ob = new("/std/spells/summon/silver_dragon_pet.c");
ob->set_up(power);
ob->move(environment(caster));
//ob->force_me("cast *6 violent blaze");
ob->set_owner((string)caster->query_name());
remove();
return;
}
