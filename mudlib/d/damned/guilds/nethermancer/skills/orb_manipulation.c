inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(13);
    set_fast_dev_cost(37);
}

void info() {
    message("help", "This is the skill that is utilized in casting all Nethermancer spells dealing with sacrificing soul orbs or raising undead creatures from the souls contained within them. The higher the percentage value of this skill, the better chances of gaining power bonuses that in some cases can add power to the sacrifice or the raised undead once the spell is completed.", this_player());
}
