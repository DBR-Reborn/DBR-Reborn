inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(7);
    set_fast_dev_cost(23);
    set_property("prereq", "attack");
}

void info() {
message("help","This is skill with flail and chain-type one-handed weapons."
	, this_player());
}
