inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","implosion");
    set_property("skill", "energy manipulation");
    set_property("casting time", 8);
    set_property("base mp cost", 60);
    set_property("dev cost", 110);
    set_property("fast dev cost", 330);
    set_property("spell level", 24);
    set_property("moon","warzau");
    set_property("caster message","You open a hole inside $T.");
    set_property("target message","$C opens a hole inside you!");
    set_property("observer message","$C opens a hole inside $T.");
    set_property("can resist", 2);
    set_property("save mod", "constitution");
    set_property("can resist", 2);
    set_property("spell type",({ "damage" }));
    set_property("must be present", 1);
    set_property("damage types", ([ "vacuum" : 75+this_player()->query_level(), "fire" : 75+this_player()->query_level() ]));
    set_property("damage multiplier", 15+this_player()->query_level()*2);
    set_property("combat spell", 1);
    set_property("target type", "living");
    set_property("prereq", "garguth's pounding fist");
    return;
}

void info() {
message("help",
"This spell opens up a small hole inside the target, causing much discomfort!\n"
"This spell is more effective against mobs.",
this_player());
}

