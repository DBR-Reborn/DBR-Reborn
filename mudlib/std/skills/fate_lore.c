inherit "/std/skills/lore_skill";

void create() {
    ::create();
    set_property("element", "fate");
    set_dev_cost(44);
    set_fast_dev_cost(150);
    set_property("prereq", "time lore");
}
