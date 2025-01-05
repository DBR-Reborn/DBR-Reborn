// wizard:  Hood
// file: w_belt.c
//Shao-tan wardens belt

inherit "/std/armour";


void create() {
    ::create();
set_name("black-plated belt");
set("id",({"belt","plated belt","black-plated belt"}) );
set("short", "black-plated belt");
set("long", "A heavy belt of inter-locking black metal plates.\n");
    set_weight(160);
    set("value", 100);
    set_type("belt");
set_ac(40);
set_material("metal/mithril");
}


