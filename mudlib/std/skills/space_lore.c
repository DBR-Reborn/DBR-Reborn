inherit "/std/skills/lore_skill";

void create() {
    ::create();
    set_property("element", "space");
    set_dev_cost(44);
    set_fast_dev_cost(150);
    set_property("prereq", "gravity lore");
}
