inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(12);
    set_fast_dev_cost(27);
}

void info() {
message("help",
"Scythe helps Fighter when they cleave multiple opponents, making it much more likely they will hit.",this_player());
}

