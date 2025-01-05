inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "lesser shadow field");
set_property("skill", "empowerment");
set_property("casting time", 15);
set_property("base mp cost", 70);
set_property("dev cost", 70);
set_property("fast dev cost", 210);
set_property("spell level", 13);
set_property("moon", "ankh");
set_property("caster message", "You summon a powerful thick shimmering shadow to encase $T!");
set_property("target message", "You become enveloped in a dense shadow.");
set_property("observer message", "$T becomes enveloped in a dense shadow.");
set_property("spell type", ({ "protection" }));
set_property("target type", "living");
set_property("protection types", ([ "impaling" : 10, "crushing" : 10, "impact" : 10, "strike" : 10, "cutting" : 10, "time" : 10, "unholy" : 10, "infernal" : 10, "stress" : 10, "aether" : 10, "holy" : 10, "disruption" : 10, "cold" : 10, "vacuum" : 10, "plasma" : 10, "electricity" : 10, "fire" : 10 ]));
set_property("duration", 60);
set_property("stack key", "shadow field");
set_property("stack num", 1);
set_property("must be present", 1);
return;
}

void info() {
message("help", "This spell allows a Dark Paladin to create a relatively dense shadow around a living being. The shadow will provide a fair amount of protection against enemy offensives during its duration.", this_player());
}
