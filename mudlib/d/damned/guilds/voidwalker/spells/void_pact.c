inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "void pact");
set_property("skill", "darkweaving");
set_property("casting time", 15);
set_property("base mp cost", 0);
set_property("dev cost", 105);
set_property("fast dev cost", 315);
set_property("spell level", 20);
set_property("moon", "ankh");
set_property("caster message", "You call forth the power of Oberon and make a dark pact.");
set_property("target message", "");
set_property("observer message", "$C makes a dark pact with Oberon.");
set_property("must be present", 1);
set_property("self cast", 1);
set_property("target type", "living");
return;
}

void info() {
message("help", "This is a very potent spell which allows a Voidwalker to make a pact with his god. When the pact is completed, a random number of the caster's MAX hit points are converted into magic points. Because of this, it is not wise to use this spell if you are not at or above full hp. This ability will prove very helpful in gathering magic to cast the strongest spells available to the Voidwalker Guild, but casting it carries a small risk of sudden death. The risk can be lowered however with high spell power.", this_player());
}

int can_exceed_max_mp() {
return 1;
}

void spell_func(object caster, object at, int power, string args, int flag) {
int a;
int b;
int c;

a = random(100);
if(a < (30/power)) {
message("info", "%^RED%^You fail to transfer your life force to magic power. You drop dead from the uncontrolled energy.%^RESET%^", caster);
at->die();
remove();
return;
}
if(flag) {
message("info", "%^RED%^You blast yourself with all of your own power, causing you to instantly drop lifeless to the floor!%^RESET%^", caster);
caster->die();
remove();
return;
}
b = caster->query_max_hp();
c = random(b);
caster->add_mp(c);
caster->add_hp(-c);
message("info", "You successfully convert "+c+" hit points into magic points!", caster);
return;
}
