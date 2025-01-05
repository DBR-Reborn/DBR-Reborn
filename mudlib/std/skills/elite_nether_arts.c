inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(35);
    set_fast_dev_cost(101);
}

void info() {
    message("help", "This skill is a yardstick for a Nethermancer's prowess in using an elite and extremely powerful class of nether arts mandatory for working with a master nexus in hopes of gaining an advantage in performing longterms of nether category four (see help files for desired longterm to see its category). Should this skill apply, its base value will dictate a time bonus deducted from the normal amount of time initially destined to be spent executing the said longterm.", this_player());
}
