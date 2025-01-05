inherit "/std/spells/spell";


void create() {
    ::create();
    set_property("name","destruction");
    set_property("skill", "energy manipulation");
    set_property("casting time", 12);
    set_property("base mp cost", 100);
    set_property("dev cost", 175);
    set_property("fast dev cost", 525);
    set_property("spell level", 34);
    set_property("moon","warzau");
    set_property("caster message","You focus your energy and destroy $T.");
    set_property("target message","$C utterly destroys you!");
    set_property("observer message","$C utterly destroys $T.");
    set_property("can resist", 2);
    set_property("must be present", 1);
    set_property("save mod", "constitution");
    set_property("combat spell", 1);
    set_property("target type", "living");
    set_property("spell type",({ "damage" }));
    set_property("damage types", ([ "plasma" : 105+this_player()->query_level(), "vacuum" : 105+this_player()->query_level(), "fire" : 105+this_player()->query_level() ]));
    set_property("damage multiplier", 19+this_player()->query_level()*2);
    set_property("prereq", "combustion");
    return;
}

int res_spell() { return 1; }

void info() {
message("help",
"This spell focuses your energy, allowing you to utterly destroy your target!\n"
"This spell is more effective against mobs.",
this_player());
}

