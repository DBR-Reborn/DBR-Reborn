inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("wisdom");
    set_dev_cost(21);
    set_fast_dev_cost(52);
}

void info() {
message("help",
"This skill allows you to attempt to control the environment. It helps when casting spells that use this skill.",
this_player());
}

