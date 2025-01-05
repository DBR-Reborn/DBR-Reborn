inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(21);
    set_fast_dev_cost(64);
}

void info() {
    message("help", "This skill is a measuring tool in determining the talents of learning that a given Nethermancer has in gaining the most of the knowledge from casting relatively powerful long-term spells during various points in their guild tenure. Category three long-terms are affected by this skill (with the category of a long-term being listed in each seperate long-term helpfile), and higher base skill translates to significantly more experience points earned from all long-terms of the category at each timed tick.", this_player()); 
}
