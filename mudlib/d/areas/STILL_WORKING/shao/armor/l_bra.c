// Wizard: Hood
// l_bra.c
// I believe the first "Bra" invented on darkemud?

inherit "/std/armour";

void create() {
    ::create();
set_name("bustia");
set("id",({"bra","bustia","mini corset","brassiere"}));
set("short","A black leather bra");
set("long","This odd garmet almost resembles a "
"corset.  Except it is much smaller and only covers"
" partialy cover the breasts.  It is made out of a "
"soft black leather, and could almost be mistaken for "
"a head band or blind fold.\n");
set_weight(4);
    set_value(1);
    set_type("misc");
set_limbs( ({"torso"}) );
set_ac(4);
set_material("misc/leather");
}
