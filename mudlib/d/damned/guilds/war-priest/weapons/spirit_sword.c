inherit "/std/weapon";

void create() {
    ::create();
    set("id", ({ "sword", "sword of spirit", "spirit sword", "sword of the spirit" }));
    set_name("sword");
    set("short", "%^BOLD%^The Sword of the Spirit%^RESET%^");
    set("long", "This sword is crafted of a brilliant shiny metal, almost unearthly it its quality.");
    set_weight(70);
    set_type("two handed blade");
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

