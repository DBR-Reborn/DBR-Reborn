inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "storm of ages");
set_property("skill", "oberon's will");
set_property("casting time", 10);
set_property("base mp cost", 450);
set_property("dev cost", 180);
set_property("fast dev cost", 550);
set_property("spell level", 30);
set_property("moon", "warzau");
set_property("caster message", "You will a petrifying void storm into existence.");
set_property("target message", "$C wills a petrifying void storm into existence!");
set_property("observer message", "$C wills a petrifying void storm into existence!");
set_property("spell type", ({ "area damage" }));
set_property("damage types", ([ "radiation" : 125, "stress" : 125, "vacuum" : 125 ]));
set_property("damage multiplier", 20);
set_property("must be present", 1);
set_property("combat spell", 1);
set_property("can resist", 1);
set_property("no target", 1);
set_property("prereq", "abyss blast");
return;
}

void info() {
message("help", "This is the most powerful offensive magic available to a follower of Oberon, available only to the worthy chosen by the void god himself. This spell calls forth a violent storm of radiation and vacuum energy, causing tremendous damage to anyone or anything unfortunate enough to be caught in its wake. When the storm passes, even the most seasoned warriors will most likely be turned into lifeless mutilated corpses.", this_player()); 
}
