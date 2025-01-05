inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","garguth's pounding fist");
   set_property("skill", "energy manipulation");
    set_property("casting time", 6);
    set_property("base mp cost", 40);
    set_property("dev cost", 75);
    set_property("fast dev cost", 225);
    set_property("spell level", 14);
    set_property("moon","warzau");
    set_property("caster message","You cast Garguth's pounding fist at $T.");
    set_property("target message","A big FIST appears out of thin air ready to POUND you!");
    set_property("observer message","$C concentrates intently, and a big, clenched fist appears above $T...");
    set_property("combat spell", 1);
    set_property("can resist", 2);
    set_property("save mod", "dexterity");
    set_property("target type", "living");
    set_property("combat spell", 1);
    set_property("must be present", 1);
    set_property("spell type",({ "damage" }));
    set_property("damage multiplier", 8+this_player()->query_level() );
    set_property("damage types", ([ "impact" : 30 +this_player()->query_level() ]));
    set_property("prereq", "garguth's grasping hand");
    return;
}

void info() {
message("help",
"This spell causes the magical fist of Garguth the giant to "
"appear above the target and deliver a staggering punch!",
this_player());
}

