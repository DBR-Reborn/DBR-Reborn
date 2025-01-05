inherit "/std/skills/skill.c";

void create() {
::create();
set_stat("intelligence");
set_dev_cost(15);
set_fast_dev_cost(46);
}

void info() {
message("help", "This spell grants the power of the dark god Owedquar to a Dark Paladin willing to follow him. It is used in conjunction with casting most non body altering magics.", this_player());
}
