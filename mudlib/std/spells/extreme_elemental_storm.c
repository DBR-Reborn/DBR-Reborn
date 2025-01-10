inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","extreme elemental storm");
    set_property("skill","elementalism");
    set_property("casting time",8);
    set_property("base mp cost",353);
    set_property("dev cost",278);
    set_property("fast dev cost",430);
    set_property("spell level", 40);
    set_property("moon","warzau");
    set_property("caster message","You cast a extreme elemental storm!");
    set_property("target message","$C casts a extreme elemental storm!");
    set_property("observer message","$C casts a extreme elemental storm.");
    set_property("spell type",({ "area damage", "area damage", "area damage", "area damage" }));
    set_property("elemental spell", 1);
    set_property("must be present", 1);
    set_property("ele damage", 20+(this_player()->query_level()*10));
    set_property("damage multiplier", 10+(this_player()->query_level()/10));
    set_property("combat spell", 1);
    set_property("no target", 1);
    set_property("prereq", "greater elemental storm");
    return;
}

void info() {
message("help",
"This spell, when cast, will strike all enemies with a force",
this_player());
}

