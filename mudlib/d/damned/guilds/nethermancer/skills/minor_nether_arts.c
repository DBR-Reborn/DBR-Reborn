inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(18);
    set_fast_dev_cost(50);
}

void info() {
    message("help", "This skill gauges a Nethermancer's talent with the nether arts needed to use a lesser nexus and grants him or her aid in performing all long terms of the first nether category (see help files of said longterm to see its category). If applicable, the base value of this skill determines an amount of time deducted from the normal length of the longterm.", this_player());
}
