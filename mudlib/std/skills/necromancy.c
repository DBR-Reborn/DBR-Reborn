inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(15);
    set_fast_dev_cost(47);
}

void info() {
message("help",
"This spell casting skill deals with animating undeads.  ",
this_player());
}

