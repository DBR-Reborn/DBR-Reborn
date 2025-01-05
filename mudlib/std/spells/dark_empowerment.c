inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "dark empowerment");
set_property("skill", "owedquar's will");
set_property("casting time", 5);
set_property("base mp cost", 608);
set_property("dev cost", 65535);
set_property("fast dev cost", 65535);
set_property("spell level", 100);
set_property("moon", "warzau");
set_property("caster message", "You call upon the dark power of the abyss to fill you with energy.");
set_property("target message", "$C fills you with powerful energy");
set_property("observer message", "$C calls upon the dark power of the abyss to fill him with energy");
set_property("must be present", 1);
set_property("target type", "living");
return;
}

void info() {
message("help", "This is a spell exclusively for the Owedquar's Shadow boss of the Black Keep. It gives between a 1-100000 hp bonus when casted.", this_player());
}

int can_exceed_max_hp() { return 1; }

void spell_func(object at) {
int a;
a = random(100000);
at->set_property("allow over max", 1);
at->add_hp(a);
}
