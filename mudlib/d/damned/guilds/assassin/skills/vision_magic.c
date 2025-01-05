inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(13);
    set_fast_dev_cost(40);
}

void info() {
    message("help", "This skill is used in conjunction with casting all Assassin spells that deal with both enhancing and hampening vision. The base of this skill, which can be seen by typing 'skills base', determines which spells of that family can be trained for use with prerequisite values listed in the seperate spell help files.", this_player());
}
