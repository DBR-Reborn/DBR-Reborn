inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(16);
    set_fast_dev_cost(46);
}

void info() {
    message("help", "This skill is used to cast all Assassin magic that can be considered miscellaneous and apart from stunning, blinding, or weapon enhancement. Its base value, which can be viewed by the 'skills base' command, is also important because it directly decides which spells that use this as their casting skill may be trained, with those prerequisites listed individually inside each of the seperate help files for the affected skills.", this_player());
}
