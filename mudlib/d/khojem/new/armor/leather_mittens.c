//  Wizard:  Khojem
//  Leather Mittens
//  leather_mittens.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("mitten");
    set("id", ({ "mitten", "cloth mitten" }) );
    set("short", "cloth mitten");
    set("long", "A pair of crudely-tanned, mitten.  It is grimey "+
      "and has a few holes.");
    set_weight(25);
    set_value(20);
    set_type("cloth hand");
    set_limbs( ({ ({ "right hand", "left hand", 
      "first branch", "second branch", "third branch", "fourth branch" }) }) );
    set_ac(5);
/*
        set_ac(0, "aether");
        set_ac(0, "depression");
        set_ac(1, "acid");
        set_ac(1, "vacuum");
        set_ac(2, "fire");
        set_ac(2, "cold");
        set_ac(2, "impact");
        set_ac(1, "stress");
        set_ac(1, "strike");
        set_ac(1, "electricity");
        set_ac(0, "time");
        set_ac(3, "crushing");
        set_ac(1, "disruption");
        set_ac(0, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
*/
        set_material("misc/cloth");
}
