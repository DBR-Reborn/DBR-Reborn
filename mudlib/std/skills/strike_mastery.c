inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(13);
    set_fast_dev_cost(42);
}

void info() {
    message("help", "This skill decides which skills an Assassin may train in the training chamber of assassination. The base value of this skill, viewable by the command 'skills base', determines the skills that Assassin is permitted to learn. The individual requirements for each skill are listed in the seperate help files.", this_player());
}
