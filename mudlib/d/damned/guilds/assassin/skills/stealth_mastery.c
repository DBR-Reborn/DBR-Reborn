inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(10);
    set_fast_dev_cost(33);
}

void info() {
    message("help", "This is the prerequisite skill required to train skills in the training chamber of stealth in the Assassin's Guild. The base of this skill, not final skill after boostings, is used to determine what skills in that chamber the Assassin may train. The requirements are listed in the help files of the individual skills.", this_player());
}
