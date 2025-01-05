inherit "/std/weapon";

/* This is a relatively powerful one handed sword dual wielded by the powerful death soldiers roaming the black keep. It carries respectable WC and is noticably more powerful than the manor chaotic longswords, however it still cannot compare to forged and chanted equipment since it cannot be runed. The weapon carries a random element, and it varies between fire, thunder, cold, wind, and the extremely rare aether, which only has a 1% chance of appearing on the death soldier. */   

int type;

void create() {
::create();
type=random(500);
set_ac(0);
set_wc(50, "cutting");
set_wc(50, "impaling");
set_weight(50);
set_value(5000);
set_material("bone");
set_type("blade");
set_quality(6);
if(type<125) {
set_name("fire sword");
set_verb("scorch");
set_wc(75, "fire");
set("id", ({ "sword", "fire sword" }));
set_short("%^RED%^fire %^RESET%^sword");
set_long("This sword, fashioned completely of bone, is wrapped in raging flames controlled about the terribly sharp blade.");
set_wield("Your hands feel very hot as you wield the sword.");
set_unwield("Your hands considerably cool off as you sheath the weapon.");
return;
}
if(type>=125 && type<250) {
set_name("ice sword");
set_verb("freeze");
set_wc(75, "cold");
set("id", ({ "sword", "ice sword" }));
set_short("%^BLUE%^ice %^RESET%^sword");
set_long("This sword, fashioned completely of bone, carries a blade almost completely frozen with ice. You feel the extreme cold even as far down as the handle.");
set_wield("Your hands feel extremely cold and nearly frostbitten as you equip the sword.");
set_unwield("Your hands considerably warm up as you unwield the sword.");
return;
}
if(type>=250 && type<375) {
set_name("thunder sword");
set_verb("shock");
set_wc(75, "electricity");
set("id", ({ "sword", "thunder sword" }));
set_short("%^YELLOW%^thunder %^RESET%^sword");
set_long("This sword, fashioned completely of bone, crackles loudly with thunder as powerful streams of electricity coarse throughout the blade.");
set_wield("You wield the sword and suddenly your entire body begins to vibrate from the weapon's electrical energy.");
set_unwield("You sheath the sword and quickly return to normal and cease vibrating.");
return;
}
if(type>=375 && type<500) {
set_name("wind sword");
set_verb("blast");
set_wc(75, "vacuum");
set("id", ({ "sword", "wind sword" }));
set_short("%^BOLD%^%^WHITE%^wind %^RESET%^sword");
set_long("This sword, fashioned completely of bone, shimmers with heavy winds circling the blade at an extreme speed.");
set_wield("As you wield the sword, powerful winds from the blade shake you, making it very difficult to keep the weapon balanced in your hand.");
set_unwield("As you unwield the weapon you feel your hand return to normal as you no longer need to balance it.");
return;
}
if(type==500) {
set_name("aether blade");
set_verb("dessicate");
set_wc(200, "aether");
set_property("brittle", 50);
set("id", ({ "blade", "aether blade", "sword", "aether sword" }));
set_short("%^BOLD%^%^CYAN%^Aether Blade%^RESET%^");
set_long("This is a horribly powerful sword. It is fashioned completely of bone and flashes endlessly with blinding lights, You see powerful creatures come out of and dive back into the razor sharp blade of the weapon almost every second. Just holding this in your hand fills your soul with extreme power.");
set_wield("You feel a terrifyingly powerful rush of power soar through your soul as you grasp this mighty blade.");
set_unwield("The massive power exits your soul as you relieve this powerful weapon from your hand.");
set_property("no add quality", 1);
set_property("no decay", 1);
return;
}
}
