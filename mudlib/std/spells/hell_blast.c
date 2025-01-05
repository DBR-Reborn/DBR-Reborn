inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "hell blast");
set_property("skill", "chaos magic");
set_property("casting time", 4);
set_property("base mp cost", 255);
set_property("dev cost", 288);
set_property("fast dev cost", 910);
set_property("spell level", 42);
set_property("moon", "warzau");
set_property("caster message", "You unleash a powerful blast of hellish energy at $T.");
set_property("target message", "$C unleashes a powerful blast of hellish energy at you!");
set_property("observer message", "$C unleashes a powerful blast of hellish energy at $T");
set_property("spell type", ({ "damage" }));
set_property("damage types", ([ "disruption" : 250+this_player()->query_level(), "disruption #2" : 250+this_player()->query_level(), "infernal" : 250+this_player()->query_level(), "infernal #2" : 250+this_player()->query_level() ]));
set_property("damage multiplier", 30+this_player()->query_level()*2);
set_property("must be present", 1);
set_property("combat spell", 1);
set_property("can resist", 1);
return;
}

void info() {
message("help", "This spell conjures up an extremely powerful mass of pure hellish energy and unleashes it upon the target, causing great damage.", this_player());
}
