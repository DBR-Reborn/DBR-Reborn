inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(7);
    set_fast_dev_cost(21);
    set_property("prereq", "attack");
}

void info() {
message("help","This is skill with two-handed blunt weapons."
	, this_player());
}

