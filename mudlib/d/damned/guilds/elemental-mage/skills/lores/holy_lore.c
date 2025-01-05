inherit "/std/skills/lore_skill";

void create() {
    ::create();
    set_property("element", "holy");
    set_dev_cost(42);
    set_fast_dev_cost(144);
}
