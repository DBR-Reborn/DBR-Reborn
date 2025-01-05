inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","kill all");
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
    set_property("spell type",({ "area damage" }));
    set_property("must be present", 1);
    set_property("damage types", ([ "vacuum" : 60000, "holy" : 60000, "holy #2" : 60000, "holy #3" : 60000, "aether" : 60000, "disruption" : 60000, "unholy" : 60000  ]));
    set_property("damage multiplier", 10000);
    set_property("combat spell", 1);
    set_property("prereq", "");
    set_property("target type", "living");
    set_property("no target", 1);
    return;
}

void info() {
message("help",
"This spell kills stuff",
this_player());
}

