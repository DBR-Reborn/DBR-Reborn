inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(14);
    set_fast_dev_cost(40);
}

void info() {
    message("help", "This is the skill used to cast all Nethermancer longterm spells. The higher the skill, the better the chances of recieving power bonuses that in some cases can bring about better results than usual from the final longterm product.", this_player());
}
