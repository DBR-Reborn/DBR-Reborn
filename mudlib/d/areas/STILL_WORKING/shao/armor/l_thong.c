//  Wizard:  Khojem
//  rag pants
//  rag_pants.c

inherit "/std/armour";

void create() {
    ::create();
set_name("leather thong");
set("id",({"thong","black thong","black leather thong","leather thong"}) );
set("short","black leather thong");
set("long","This tiny article of clothing is crafted "
"from a soft black leather. It only covers a small part "
"of the pelvic area, leaving the wearers butt cheeks close "
"to totaly exposed.  Unpractical but dam sexy!\n");
    set_weight(2);
    set_value(1);
    set_type("misc");
    set_limbs( ({ "right leg", "left leg" }) );
set_ac(5);
set_material("misc/leather");
}
