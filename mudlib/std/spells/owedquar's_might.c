inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "owedquar's might");
set_property("skill", "owedquar's will");
set_property("casting time", 4);
set_property("base mp cost", 70);
set_property("dev cost", 85);
set_property("fast dev cost", 255);
set_property("spell level", 16);
set_property("moon", "warzau");
set_property("caster message", "You call upon the power of Owedquar to violently strike $T!");
set_property("target message", "$C calls upon the power of Owedquar to violently strike you!");
set_property("observer message", "$C calls upon the power of Owedquar to violently strike $T.");
set_property("spell type", ({ "damage" }));
set_property("must be present", 1);
set_property("can resist", 1);
set_property("damage types", ([ "unholy" : this_player()->query_level()/2, "crushing" : this_player()->query_level()/2 ]));
set_property("damage multiplier", this_player()->query_level()*2);
set_property("combat spell", 1);
set_property("target type", "living");
set_property("prereq", "dark assault");
return;
}

void info() {
message("help", "This spell allows a Dark Paladin to call forth the power of Owedquar to unleash a dangerous blow upon his enemy, far more than possible with dark assault.", this_player());
}
