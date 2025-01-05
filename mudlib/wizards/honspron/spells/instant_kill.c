inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","instant kill");
    set_property("skill","conjuration");
    set_property("casting time",3);
    set_property("base mp cost",41);
    set_property("dev cost", 61);
    set_property("fast dev cost", 156);
    set_property("spell level", 95);
    set_property("moon","warzau");
    set_property("caster message","You obliterate $T.");
    set_property("target message","You get obliterated by $C!");
    set_property("observer message","$C obliterates $T.");
    set_property("can resist", 2);
    set_property("save mod", "dexterity");
    set_property("can resist", 2);
    set_property("spell type",({ "damage" }));
    set_property("must be present", 1);
    set_property("damage types", ([ "vacuum" : 600, "holy" : 600, "holy #2" : 600, "holy #3" : 600, "aether" : 600, "disruption" : 600, "unholy" : 600  ]));
    set_property("damage multiplier", 1000);
    set_property("combat spell", 1);
    set_property("prereq", "");
    set_property("target type", "living");
    return;
}

void info() {
message("help",
"This spell kills stuff",
this_player());
}

