inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "ice breath");
set_property("skill", "conjuration");
set_property("casting time", 0);
set_property("base mp cost", 350);
set_property("dev cost", 65535);
set_property("fast dev cost", 65535);
set_property("spell level", 100);
set_property("moon", "warzau");
set_property("caster message", "You breathe powerful ice at $T.");
set_property("target message", "$C breathes biting winds of %^BLUE%^ice%^RESET%^ at you!");
set_property("observer message", "$C breathes biting winds of %^BLUE%^ice%^RESET%^ at $T.");
set_property("spell type", ({ "damage" }));
set_property("damage types", ([ "cold" : 250+this_player()->query_level(), "cold #2" : 250+this_player()->query_level(), "cold #3" : 250+this_player()->query_level() ]));
set_property("damage multiplier", 15+this_player()->query_level()*2 );
set_property("must be present", 1);
set_property("combat spell", 1);
set_property("can resist", 1);
return;
}
