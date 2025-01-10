inherit "/std/skills/skill.c";

void create() {
::create();
set_stat("none");
set_dev_cost(22);
set_fast_dev_cost(68);
}

void info() {
message("help", "This skill is used to effectively wield the legendary chosen weapons of Oberon, rumored to be among the most powerful in existence.", this_player());
}
