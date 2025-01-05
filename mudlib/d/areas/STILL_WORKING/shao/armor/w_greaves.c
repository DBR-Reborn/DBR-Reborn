//  Wizard:  Khojem
//  rag pants
//  rag_pants.c

inherit "/std/armour";

void create() {
    ::create();
set_name("black greaves");
set("id",({"greaves","black greaves"}) );
set("short","black greaves");
set("long","The thin dark cloth is very comfortable,"
" and provides good flexibility.  The numerious black "
"metal plates look to provide very good protection.\n");
    set_weight(140);
    set_value(1);
    set_type("cloth legs");
    set_limbs( ({ "right leg", "left leg" }) );
set_ac(40);
        set_ac(40, "aether");
        set_ac(40, "depression");
        set_ac(40, "acid");
        set_ac(40, "vacuum");
        set_ac(40, "fire");
        set_ac(40, "cold");
        set_ac(40, "impact");
        set_ac(40, "stress");
        set_ac(40, "strike");
        set_ac(40, "electricity");
        set_ac(40, "time");
        set_ac(40, "crushing");
        set_ac(40, "disruption");
        set_ac(40, "holy");
        set_ac(40, "plasma");
        set_ac(40, "infernal");
set_material("metal/mithril");
}
