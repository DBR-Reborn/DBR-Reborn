inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "owedquar's fury");
set_property("skill", "empowerment");
set_property("casting time", 14);
set_property("base mp cost", 90);
set_property("dev cost", 80);
set_property("fast dev cost", 240);
set_property("spell level", 15);
set_property("moon", "ankh");
set_property("caster message", "You call upon the power of Owedquar and explode into a vicious fury!");
set_property("target message", "");
set_property("observer message", "$C explodes into a vicious fury.");
set_property("self cast", 1);
set_property("spell type", ({ "skill mod" }));
set_property("skill dice", "10D1");
set_property("skills", ({ "attack", "dodge", "parry", "two handed blunt", "two handed blade", "two handed flail", "two handed polearm" }));
set_property("target type", "living");
set_property("must be present", 1);
set_property("duration", 160);
set_property("stack key", "anger charge");
set_property("stack num", 2);
set_property("prereq", "anger charge");
return;
}

void info() {
message("help", "This is a more powerful version of the spell 'anger charge'. With this magic, a Dark Paladin can call forth the power of his dark god Owedquar and channel it directly into his body, forcing him/her into a truly explosive fury. All attack and dodging skills will be significantly boosted for the duration. This spell is self cast and can be stacked a total of two times.", this_player());
}
