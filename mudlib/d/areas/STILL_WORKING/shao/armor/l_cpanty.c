//  Wizard:  Khojem
//  rag pants
//  rag_pants.c

inherit "/std/armour";

void create() {
    ::create();
set_name("leather panties");
set("id",({"panties","black panties","black leather panties","leather panties"}) );
set("short","black leather panties");
set("long","This tiny article of clothing is crafted "
"from a soft black leather. It is made to cover the pelvic "
"area of the wearers body as well as the butt.  "
"This item appears to be missing a section of the crotch"
", unpractical but 'easy access'\n");
    set_weight(2);
    set_value(1);
    set_type("cloth legs");
    set_limbs( ({ "right leg", "left leg" }) );
set_ac(5);
set_material("misc/leather");
}
