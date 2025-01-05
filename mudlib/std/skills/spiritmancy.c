inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(25);
    set_fast_dev_cost(65);
}

void info() {
message("help",
"This spell casting skill deals with the nether spirits. This skill can only be obtained thru an orb sacrifice.",
this_player());
}

