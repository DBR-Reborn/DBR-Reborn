inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","ultimate elemental storm");
    set_property("skill","elementalism");
    set_property("casting time",10);
    set_property("base mp cost",453);
    set_property("dev cost",378);
    set_property("fast dev cost",530);
    set_property("spell level", 60);
    set_property("moon","warzau");
    set_property("caster message","You cast a ultimate elemental storm!");
    set_property("target message","$C casts a ultimate elemental storm!");
    set_property("observer message","$C casts a ultimate elemental storm.");
    set_property("spell type",({ "area damage", "area damage", "area damage", "area damage", "area damage" }));
    set_property("elemental spell", 1);
    set_property("must be present", 1);
    set_property("ele damage", 80+(this_player()->query_level())*10);
    set_property("damage multiplier", 10+(this_player()->query_level()/10));
    set_property("combat spell", 1);
    set_property("no target", 1);
    set_property("prereq", "extreme elemental storm");
    return;
}

void info() {
message("help",
"This spell, when cast, will strike all enemies with a force",
this_player());
}

