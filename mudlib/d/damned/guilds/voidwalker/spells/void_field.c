inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "void field");
set_property("skill", "empowerment");
set_property("casting time", 25);
set_property("base mp cost", 150);
set_property("dev cost", 105);
set_property("fast dev cost", 315);
set_property("spell level", 20);
set_property("moon", "ankh");
set_property("caster message", "An extremely dense shadow encases your entire body.");
set_property("target message", "You summon an enormously thick shadow into your surroundings.");
set_property("observer message", "An extremely dense shadow encases $T's entire body.");
set_property("spell type", ({ "protection" }));
set_property("target type", "living");
set_property("protection types", ([ "impaling" : 20, "crushing" : 20, "strike" : 20, "impact" : 20, "cutting" : 20, "time" : 20, "royal" : 20, "acid" : 20, "reflection" : 20, "infernal" : 20, "stress" : 20, "aether" : 20, "holy" : 20, "disruption" : 20, "cold" : 20, "vacuum" : 20, "radiation" : 20, "plasma" : 20, "electricity" : 20, "fire" : 20 ]));
set_property("duration", 40);
set_property("stack key", "void field");
set_property("stack num", 1);
set_property("self cast", 1);
set_property("must be present", 1);
set_property("prereq", "lesser void field");
return;
}

void info() {
message("help", "With the power of this spell, a Voidwalker can tap directly into the pure power of Oberon and cover himself in an extraordinarily dense shadow. While encased in it, the loyal follower of the void god will experience incredible boosts in protection. This spell can only be used for the casters benefit.", this_player());
}
