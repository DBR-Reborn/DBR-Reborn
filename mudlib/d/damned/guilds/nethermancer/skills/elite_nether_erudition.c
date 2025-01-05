inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(26);
    set_fast_dev_cost(77);
}

void info() {
    message("help", "This skill is used latently as a virtual scale to evaluate a Nethermancer's prowess in comprehension of the incredible knowledge that comes from the performances of extremely powerful long-term magic. The spells that are altered by this skill are those of category four (check the help files of all individual long-term spells to see their category), with the base skill value being a strong factor in the final experience gained after each time displaying long-term tick.", this_player());
}
