//  Wizard:  Khojem
//  Shaman's Hood
//  shaman_hood.c

inherit "/std/armour";

void create() {
    ::create();
set_name("black helm");
set("id", ({"helm","helmet","black helm","karajm's helm"}) );
set("short","A black helmet");
set("long", "A scorched, blackened helmet.\n"
"A single silver horn protrudes out over the wearers forehead about "
"six inches.  The helmet provides good protection for the head "
"and also covers the wearers jaw and mouth.  A "
"grilled visor can be pulled down to further protect the eyes.\n");
    set_weight(20);
    set_value(50);
    set_type("metal head");
    set_limbs( ({ "head" }) );
    set_ac(10);
        set_ac(11, "aether");
        set_ac(11, "depression");
        set_ac(11, "acid");
        set_ac(2, "vacuum");
        set_ac(16, "fire");
        set_ac(16, "cold");
        set_ac(6, "impact");
        set_ac(12, "stress");
        set_ac(12, "strike");
        set_ac(4, "electricity");
        set_ac(1, "time");
        set_ac(6, "crushing");
        set_ac(12, "disruption");
        set_ac(8, "holy");
        set_ac(8, "plasma");
        set_ac(8, "infernal");
set_material("metal/mithril");
}
