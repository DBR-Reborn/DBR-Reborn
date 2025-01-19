inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(5);
    set_fast_dev_cost(14);
    set_property("prereq", "attack");
}

void info() {
message("help","This is skill with knives and other stabbing weapons."
	, this_player());
}

