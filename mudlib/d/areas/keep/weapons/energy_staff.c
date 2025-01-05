inherit "/std/weapon";

/* This is a two handed staff weapon that is wielded by the dark robed warlocks in the black keep. It is comparable in power to the sidepiece of chemosh staff found in the underlord graveyard area from the undead monk, possibly a little stronger. */

void create() {
::create();
set_ac(0);
set_name("energy staff");
set("id", ({ "staff", "energy staff", "pulsing energy staff" }));
set_short("pulsing energy staff");
set_long("This is a somewhat small staff, only four and a half feet in length from top to bottom. It contains a semicircular crystal surface at its top for the purpose of projecting magical power, and from there a plain straight pole descends to make up the rest of the weapon. The staff is constantly pulsing with a dark reddish light, suggesting great evil energy residing from within.");
set_type("two handed staff");
set_quality(6);
set_weight(200);
set_material("javednite");
set_value(20000);
set_wc(75, "crushing");
set_wc(75, "impact");
set_wc(75, "electricity");
set_verb("smash");
}
