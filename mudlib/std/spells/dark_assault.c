inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "dark assault");
set_property("skill", "oberon's will");
set_property("casting time", 2);
set_property("base mp cost", 35);
set_property("dev cost", 55);
set_property("fast dev cost", 165);
set_property("spell level", 10);
set_property("moon", "warzau");
set_property("damage multiplier", 8);
set_property("caster message", "You blast $T with void energy!");
set_property("target message", "$C blasts you with void energy!");
set_property("observer message", "$C blasts $T with void energy.");
set_property("spell type", ({ "damage"}));
set_property("damage types", ([ "vacuum" : 40 ]));
set_property("combat spell", 1);
set_property("must be present", 1);
set_property("can resist", 1);
set_property("target type", "living");
set_property("prereq", "vacuum blast");
return;
}

void info() {
message("help", "This spell unleashes void power upon the target, moreso than vacuum blast.", this_player());
}
