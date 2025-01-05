inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(15);
    set_fast_dev_cost(48);
}

void info() {
    message("help", "This skill is the prerequisite skill that is mandatory for the training of skills is in the Assassin Guild's training chamber of dueling. The base value of this skill, which is viewable with the command 'skills base', will determine what can be trained in the dueling chamber. The minimum base to train each skill is listed in the seperate individual help files.", this_player());
}
