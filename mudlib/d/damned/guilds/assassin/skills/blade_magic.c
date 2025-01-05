inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(15);
    set_fast_dev_cost(44);
}

void info() {
    message("help", "This is the primary skill used in the casting of Assassin magic directly related to weapon enhancement. The base of this skill, which can be seen through the command 'skills base', decides what may and may not be trained from the blade magic spell family, with the prerequisite value for each respective spell listed in the seperate help files.", this_player());
}
