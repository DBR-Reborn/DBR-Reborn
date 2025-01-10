inherit "/std/skills/skill.c";

void create() {
::create();
set_stat("intelligence");
set_dev_cost(15);
set_fast_dev_cost(46);
}

void info() {
message("help", "This spell grants the power of the void god Oberon to a Voidwalker willing to follow him. It is used in conjunction with casting most non body altering magics.", this_player());
}
