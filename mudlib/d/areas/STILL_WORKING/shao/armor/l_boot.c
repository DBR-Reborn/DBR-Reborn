// Wizard : Hood
// Black boots
// w_boots.c

inherit "/std/armour";

void create() {
    ::create();
set_name("black boot");
set("id",({"boot","black boot","spiked black boot","leather boot",
"spiked black leather boot","knee-high boot","knee high boot"}));
set("short","A knee-high leather boot");
set("long","This knee-high boot is crafted from a "
"soft black leather.  It has a six inch spiked heel and "
"a noticable point to the toe.\n");
    set_weight(10);
    set_value(60);
    set_type("leatehr foots");
set_limbs( ({ ({"right foot","left foot","first branch","second branch","third branch","fourth branch"})}) );
set_ac(10);
set_material("misc/leather");
}
