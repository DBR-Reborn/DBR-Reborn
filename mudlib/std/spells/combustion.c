inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","combustion");
    set_property("skill", "energy manipulation");
    set_property("casting time", 10);
    set_property("base mp cost", 85);
    set_property("dev cost", 145);
    set_property("fast dev cost", 435);
    set_property("spell level", 29);
    set_property("moon","warzau");
    set_property("caster message","You cause $T to spontaneously combust.");
    set_property("target message","$C makes you spontaneously combust!");
    set_property("observer message","$C makes $T spontaneously combust.");
    set_property("can resist", 2);
    set_property("save mod", "constitution");
    set_property("can resist", 2);
    set_property("spell type",({ "damage" }));
    set_property("must be present", 1);
    set_property("damage types", ([ "plasma" : 90+this_player()->query_level(), "fire" : 90+this_player()->query_level() ]));
    set_property("damage multiplier", 17+this_player()->query_level()*2);
    set_property("combat spell", 1);
    set_property("target type", "living");
    set_property("prereq", "implosion");
    return;
}

void info() {
message("help",
"This spell causes target to spontaneously combust, with angry plasma flames all over!\n"
"This spell is more effective against mobs.",
this_player());
}

