inherit "/std/skills/skill.c";

void create() {
::create();
set_stat("none");
set_dev_cost(20);
set_fast_dev_cost(60);
}

void info() {
message("help", "This skill is used to effectively wield the legendary chosen weapons of Owedquar, rumored to be among the most powerful in existence.", this_player());
}
