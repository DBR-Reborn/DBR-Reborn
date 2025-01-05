inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","fireball");
    set_property("skill","conjuration");
    set_property("casting time",3);
    set_property("base mp cost",19);
    set_property("dev cost", 17);
    set_property("fast dev cost", 55);
    set_property("spell level", 3);
    set_property("moon","warzau");
    set_property("save mod", "dexterity");
    set_property("can save", 2);
    set_property("caster message","You cast a fireball at $T.");
    set_property("target message","$C casts a fireball at you!");
    set_property("observer message","$C casts a fireball at $T.");
    set_property("spell type",({ "damage" }));
    set_property("damage types", ([ "fire" : 22+this_player()->query_level() ]));
    set_property("damage multiplier",4.5+this_player()->query_level());
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("can resist", 2);
    set_property("save mod", "dexterity");
    set_property("target type", "living");
    return;
}

void info() {
message("help",
"This spell hurls a fireball at the target.",
this_player());
}

