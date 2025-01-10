inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "abyss blast");
set_property("skill", "oberon's will");
set_property("casting time", 5);
set_property("base mp cost", 150);
set_property("dev cost", 130);
set_property("fast dev cost", 390);
set_property("spell level", 25);
set_property("moon", "warzau");
set_property("caster message", "You blast an earth shattering mass of void energy at $T!");
set_property("target message", "$C blasts an earth shattering mass of void energy at you!");
set_property("observer message", "$C blasts an earth shattering mass of void energy at $T.");
set_property("spell type", ({ "damage" }));
set_property("damage types", ([ "vacuum" : 90, "stress" : 90, "radiation" : 90 ]));
set_property("damage multiplier", 15);
set_property("must be present", 1);
set_property("combat spell", 1);
set_property("can resist", 1);
set_property("target type", "living");
set_property("prereq", "black winds");
return;
}

void info() {
message("help", "This spell conjures a shivering amount of vacuum, stress, and radiation energy into a compact swirling mass and angrily blasts it at the target, causing MAJOR and at most times fatal damage.", this_player());
}
