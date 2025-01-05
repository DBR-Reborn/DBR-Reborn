inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(14);
    set_fast_dev_cost(42);
}

void info() {
    message("help", "This is the skill used to execute casting of all Assassin spells related to stunning. The base value of this skill, viewable by typing the command 'skills base', directly determines which of those stunning family spells are permitted to be trained with the prerequisite values listed in each individual skill help file.", this_player());
}
