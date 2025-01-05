inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","wind of death");
    set_property("skill","black magic");
    set_property("casting time",4);
    set_property("base mp cost",30);
    set_property("dev cost",95);
    set_property("fast dev cost", 285);
    set_property("spell level",18);
    set_property("moon","warzau");
    set_property("caster message","You cast death wind at");
    set_property("target message","$C casts death wind at you!");
    set_property("observer message","$C casts death wind at $T");
    set_property("spell type",({ "area damage" }));
    set_property("damage types",([ "cold":30+this_player()->query_level(), "unholy":30+this_player()->query_level(), "disruption":30+this_player()->query_level(), "vacuum":20+this_player()->query_level()]));
    set_property("damage multiplier", 8+this_player()->query_level()*2);
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("target type", "living");
    set_property("prereq", "cold blast");
    set_property("no target", 1);
    return;
}

void info() {
message("help",
 "This spell fires a freezing, gust of wind at all enemies in the area.",
this_player());
}


