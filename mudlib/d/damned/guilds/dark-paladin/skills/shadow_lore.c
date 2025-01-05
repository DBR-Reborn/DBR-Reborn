inherit "/std/skills/skill.c";

void create() {
::create();
set_stat("intelligence");
set_dev_cost(18);
set_fast_dev_cost(58);
}

void info() {
message("help", "This skill is used while casting various Dark Paladin magics that do not involve the infliction of damage or the additions of power.", this_player());
}
