inherit "/std/weapon";

void create() {
    ::create();
    set("id", ({ "hammer", "hammer of spirit", "spirit hammer", "hammer of the spirit" }));
    set_name("hammer");
    set("short", "%^BOLD%^The Hammer of the Spirit%^RESET%^");
    set("long", "This hammer is crafted of a brilliant shiny metal, almost unearthly it its quality. The handle is made from desper wood.");
    set_weight(70);
    set_type("blunt");
    set_material("blessed steel");
    set_ac(10);
    set_parry_bonus(10);
    set_property("no save", 1);
    set_quality(4);
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_decay_rate(1500);
    set_value(0);
    set_verb("repent");
}

