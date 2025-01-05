inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "power of darkness");
set_property("skill", "shadow lore");
set_property("casting time", 20);
set_property("base mp cost", 0);
set_property("dev cost", 160);
set_property("fast dev cost", 480);
set_property("spell level", 31);
set_property("moon", "ankh");
set_property("caster message", "You summon the essence of Owedquar directly into your soul!");
set_property("target message", "");
set_property("observer message", "$C becomes one with the very essence of Owedquar.");
set_property("must be present", 1);
set_property("self cast", 1);
set_property("target type", "living");
set_property("prereq", "dark pact");
return;
}

void info() {
message("help", "This spell, which allows a Dark Paladin to become one with the very essence of Owedquar himself and immerse it within his own soul, is a noticeably more powerful version of the spell dark pact. Instead of draining a random amount of hit points and transforming them into magic points, this spell takes ALL but one hit point every time it is used and transfers it all to magic. If this spell is cast when the caster is not at max hp, he/she will die. It carries a small risk of death however like its prececessor, and also like the previous spell the risk can be reduced with higher power.", this_player());
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
c = (b - 1);
caster->add_mp(c);
caster->add_hp(-c);
message("info", "You successfully convert "+c+" hit points into magic points!", caster);
return;
}
