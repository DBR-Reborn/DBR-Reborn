inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(46);
    set_fast_dev_cost(122);
}

void info() {
    message("help", "This skill measures a Nethermancer's talent in the inhumanely powerful nether arts required to access the deepest parts of the netherworld through a master nexus, and can provide a dear helping hand in performing the flabbergastingly time consuming longterms of nether category five (the category for longterms done on an owedquarian diamond to prepare an eternal darkness). If a longterm of nether category five is being attempted, the base percentage of this skill will deduct time from it based on how high it is trained.", this_player());
}
