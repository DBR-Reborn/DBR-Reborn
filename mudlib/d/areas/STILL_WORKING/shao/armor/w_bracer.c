//  Wizard:  Khojem
//  Leather Bracer
//  leather_bracer.c

inherit "/std/armour";

void create() {
    ::create();
set_name("black arm-guard");
set("id",({"arm-guard","black arm-guard","guard",
"black guard","arm guard","black arm guard"}) );
set("short", "black arm-guard");
set("long","Thin darke leather has been totaly covered "
"with interlocking black metal plates.  It would appear "
"this is an arm guard of superior quality and protection.\n");
    set_weight(50);
    set("value", 60);
    set_type("metal arm");
set_limbs( ({ ({ "right arm", "left arm", 

"first branch","second branch","third branch","fourth branch"})
}) );
set_ac(40);
}
