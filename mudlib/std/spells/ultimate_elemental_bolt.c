inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","ultimate elemental bolt");
    set_property("skill","elementalism");
    set_property("casting time",5);
    set_property("base mp cost",234);
    set_property("dev cost",251);
    set_property("fast dev cost",423);
    set_property("spell level", 60);
    set_property("moon","warzau");
    set_property("caster message","You cast a ultimate elemental bolt at $T!");
    set_property("target message","$C casts a ultimate elemental bolt at you!");
    set_property("observer message","$C casts a ultimate elemental bolt at $T.");
    set_property("spell type",({ "damage" }));
    set_property("elemental spell", 1);
    set_property("must be present", 1);
    set_property("ele damage", 80+(this_player()->query_level())*10);
    set_property("damage multiplier", 8+(this_player()->query_level()/8));
    set_property("combat spell", 1);
    set_property("target type", "living");
    set_property("prereq", "greater elemental bolt");
    return;
}

void info() {
message("help",
"This spell fires a ultimate elemental bolt at a single target.  This is an "
"elemental spell (see 'help spellsys'), and must be used with an elemental lore "
"skill.",
this_player());
}

