inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "shadow bolt");
set_property("skill", "owedquar's will");
set_property("casting time", 1);
set_property("base mp cost", 15);
set_property("dev cost", 10);
set_property("fast dev cost", 30);
set_property("spell level", 1);
set_property("moon", "warzau");
set_property("damage multiplier", 3);
set_property("caster message", "You shoot a bolt of darkness at $T.");
set_property("target message", "$C shoots a bolt of darkness at you!");
set_property("observer message", "$C shoots a bolt of darkness at $T.");
set_property("spell type", ({ "damage"}));
set_property("damage types", ([ "unholy" : 15 ]));
set_property("combat spell", 1);
set_property("must be present", 1);
set_property("can resist", 1);
set_property("target type", "living");
return;
}

void info() {
message("help", "This spell casts a bolt of darkness at its target, causing minor damage.", this_player());
}
