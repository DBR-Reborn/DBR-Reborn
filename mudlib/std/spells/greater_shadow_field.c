inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "greater shadow field");
set_property("skill", "empowerment");
set_property("casting time", 40);
set_property("base mp cost", 200);
set_property("dev cost", 140);
set_property("fast dev cost", 420);
set_property("spell level", 27);
set_property("moon", "ankh");
set_property("caster message", "A mystifying shadow completely covers your body, making you feel seemingly invincible.");
set_property("target message", "You call forth into your presence a mindblowingly dense shadow from the realm of Owedquar!");
set_property("observer message", "$T becomes completely immersed within a pitch black shadow. He now looks seemingly untouchable.");
set_property("spell type", ({ "protection" }));
set_property("target type", "living");
set_property("protection types", ([ "impaling" : 40, "crushing" : 40, "strike" : 40, "impact" : 40, "cutting" : 40, "unholy" : 40, "infernal" : 40, "stress" : 40, "aether" : 40, "holy" : 40, "disruption" : 40, "cold" : 40, "vacuum" : 40, "plasma" : 40, "electricity" : 40, "fire" : 40 ]));
set_property("duration", 25);
set_property("stack key", "shadow field");
set_property("stack num", 1);
set_property("self cast", 1);
set_property("no borrow", 1);
set_property("must be present", 1);
set_property("prereq", "shadow field");
return;
}

void info() {
message("help", "This is THE single most powerful protection spell available to a mortal in Daybreak Ridge. Using its great power, a Dark Paladin can tear open a rift between realms and call forth a terrifyingly dense pitch black shadow from the distant realm of Owedquar. The protection granted will make the Dark Paladin essentially invincible, but it has an extremely short duration. Only the caster of this spell can recieve its awesome power, and it is non stackable.", this_player());
}
