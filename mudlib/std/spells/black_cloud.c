inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "black cloud");
set_property("skill", "oberon's will");
set_property("casting time", 5);
set_property("base mp cost", 70);
set_property("dev cost", 65);
set_property("fast dev cost", 195);
set_property("spell level", 12);
set_property("moon", "warzau");
set_property("caster message", "You summon a cloud of darkness!");
set_property("target message", "$C summons a cloud of darkness!");
set_property("observer message", "$C summons a cloud of darkness.");
set_property("spell type", ({ "area damage" }));
set_property("must be present", 1);
set_property("can resist", 1);
set_property("damage types", ([ "vacuum" : 40, "vacuum #2" : 40 ]));
set_property("damage multiplier", 5);
set_property("combat spell", 1);
set_property("no target", 1);
set_property("prereq", "dark assault");
return;
}

void info() {
message("help", "This spell creates a cloud of darkness covering the entire immediate vicinity of the caster. All targets present in the room at the time will be hurt by a fair amount of vacuum elemental damage.", this_player());
}
