inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(12);
    set_fast_dev_cost(36);
}

void info() {
    message("info", "This is the prerequisite skill necessary for the training of all magics in the Assassin Guild. The base value of this skill, which can be seen by usage of the 'skills base' command, is the determining factor as to which spells may or may not be trained once they are available at their respective levels. Each prerequisite is listed in the individual help files for all spells.", this_player());
}
