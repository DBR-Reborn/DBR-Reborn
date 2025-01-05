inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(23);
    set_fast_dev_cost(62);
}

void info() {
    message("help", "This skill serves as a measurement for a Nethermancer's mastery of moderately powerful nether arts, those of which are used to better manipulate a greater nexus for longterm spells of nether category two (see help files of specified longterm for its category). If this skill applies, its base value determines a time amount that will be deducted from the typical length of the longterm being performed.", this_player()); 
}
