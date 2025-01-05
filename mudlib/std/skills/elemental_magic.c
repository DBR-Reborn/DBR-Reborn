inherit "/std/skills/skill.c";

void create() {
::create();
set_stat("intelligence");
set_dev_cost(16);
set_fast_dev_cost(53);
}

void info() {
message("help", "This is the primary casting skill used in conjunction with casting all spells available to Elemental Mages.", this_player());
}
