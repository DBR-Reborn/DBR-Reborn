inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(13);
    set_fast_dev_cost(40);
}

void info() {
    message("help", "This skill serves the purpose of being a gauge for a Nethermancer's talents in learning from the beginniner long-term magics he or she executes during the course of their career. This skill affects category one long-term spells (see the help file for a longterm to discover its category), and the higher the base value of this skill the more experience points that will be gained after each 67 second long-term tick.", this_player());
}
