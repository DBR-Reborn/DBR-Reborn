inherit "/std/spells/spell";


void create() {
    ::create();
    set_property("name","annihilation");
    set_property("skill", "energy manipulation");
    set_property("casting time", 14);
    set_property("base mp cost", 120);
    set_property("dev cost", 205);
    set_property("fast dev cost", 615);
    set_property("spell level", 40);
    set_property("moon","warzau");
    set_property("caster message","You call upon all energy and completely annihilate $T.");
    set_property("target message","$C completely annihilates you!");
    set_property("observer message","$C completely annihilates $T.");
    set_property("can resist", 2);
    set_property("must be present", 1);
    set_property("save mod", "constitution");
    set_property("combat spell", 1);
    set_property("target type", "living");
    set_property("spell type",({ "damage" }));
    set_property("damage types", ([ "plasma" : 125+this_player()->query_level(), "vacuum" : 125+this_player()->query_level(), "fire" : 125+this_player()->query_level(), "stress" : 90+this_player()->query_level() ]));
    set_property("damage multiplier", 21+this_player()->query_level()*2);
    set_property("prereq", "destruction");
    return;
}

int res_spell() { return 1; }

void info() {
message("help",
"This spell takes great concentration, as you gather all your enchanter training and energy into completely annihilating your target!\n"
"This is the most powerful attack spell for enchanters. Only the most dedicated enchanter may train this spell.\n"
"A base skill of 150% is necessary to train this spell.\n"
"This spell is more effective against mobs.\n"
"==>This spell can only be used by members of the ENCHANTER guild<==",
this_player());
}


