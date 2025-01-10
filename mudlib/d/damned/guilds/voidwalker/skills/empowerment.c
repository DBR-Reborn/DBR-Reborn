inherit "/std/skills/skill.c";

void create() {
::create();
set_stat("intelligence");
set_dev_cost(16);
set_fast_dev_cost(52);
}

void info() {
message("help", "This skill is used by a Voidwalker of the Rift to cast magic that alters the power of living beings or non living objects.", this_player());
}
