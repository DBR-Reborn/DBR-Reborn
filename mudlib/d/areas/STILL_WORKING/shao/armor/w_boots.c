// Wizard : Hood
// Black boots
// w_boots.c

inherit "/std/armour";

void create() {
    ::create();
set_name("black boots");
set("id", ({"boots", "black boots"}) );
set("short","black boots");
set("long", "%^BOLD%^Although in very good condition, the "
"boots seem have been somehow burned to the point of "
"turning them a very dark black colour.\n");
    set_weight(40);
    set_value(60);
    set_type("metal foots");
    set_limbs( ({ "right foot", "left foot" }) );
set_ac(40);
set_material("metal/mithril");
}
