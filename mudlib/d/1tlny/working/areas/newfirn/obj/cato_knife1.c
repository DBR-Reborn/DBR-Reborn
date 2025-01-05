#pragma strict_types
inherit "/std/weapon";
void create() {
        ::create();
        set_name("odd knife");
        set("id",({ "knife" }));
        set("short","odd knife");
        set("long", "The blade of this knife is about seven inches "
        				  "long with a handle length of about four inches. "
                    "The handle is carved of wood and in it is the "
                    "catoetine blade which is curved, not back like "
                    "a cutlass, but slightly forward giving it a "
                    "slightly awkward feel. However adept users of "
                    "this knife know it's true potential.");
        set_weight(60);
        set_value(1000);
        set_ac(7);
        set_wc(9,"cutting");
        set_wc(9,"impaling");
        set_type("knife");
        set_quality(2);
        set_hit_bonus(25);
        set_verb("slice");
                set_material("/metal/catoetine");
}
