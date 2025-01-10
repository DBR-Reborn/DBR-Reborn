inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "oberon's wrath");
set_property("skill", "empowerment");
set_property("casting time", 30);
set_property("base mp cost", 350);
set_property("dev cost", 155);
set_property("fast dev cost", 465);
set_property("spell level", 30);
set_property("moon", "ankh");
set_property("caster message", "Using inhuman prowess, you create a tunnel into the Void and imbue your soul with %^RED%^unspeakable %^RESET%^power from the very realm of Oberon!");
set_property("target message", "");
set_property("observer message", "$C creates a tunnel into the void and from it imbues himself with SICK power!");
set_property("self cast", 1);
set_property("no borrow", 1);
set_property("spell type", ({ "skill mod" }));
set_property("skill dice", "20D1");
set_property("skills", ({ "attack", "dodge", "parry", "two handed blunt", "two handed blade", "two handed flail", "two handed polearm", "oberon's weapon" }));
set_property("target type", "living");
set_property("must be present", 1);
set_property("duration", 60);
set_property("stack key", "anger charge");
set_property("stack num", 1);
set_property("prereq", "oberon's fury");
return;
}

void info() {
message("help", "This is an insanely powerful spell which allows a Voidwalker to rip a hole in the space time continum and open a small rift directly into Oberon's world. Using that rift, the follower of the void god can imbue himself with absolutely unimaginable power which will place him/her into a rage never before seen by mortals. All attack and dodging skills, including the powerful skill oberon's weapon, are given tremendous boosts during its duration, but it requires an extreme amount of mp to cast and the duration is not long. This magic is self cast and cannot be stacked.", this_player());
}
