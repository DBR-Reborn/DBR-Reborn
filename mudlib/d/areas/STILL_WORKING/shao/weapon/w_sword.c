
inherit "/std/weapon";

create() {
    ::create();
    set_ac(20);
set_name("blade");
set("id", ({"black blade", "blade", "unholy blade",
"an unholy black blade", "blade of shadows", 
"shadow blade", "sword"}) );
set("short", "An unholy black blade");
    set("long", 
"The blade it self is forged from some type of black metal.\n"
"Small bug sized teeth cover both edges of the blade, and appear"
" to be razor sharp.  Closer to the base of the blade, near the "
"hilt a design has been carved into the black metal.  "
"The scorched bone hilt of the blade has been made "
"to resemble to serpents.\n");
   set_type("blade");
    set_quality(6);
    set_property("no add quality",1);
    set_property("no decay", 1);
   set_wc(30,"cutting");
    set_wc(15, "impaling");
    set_verb("slice");
    set_parry_bonus(5);
    set_property("hit bonus", 15);
    set_property("enchantment",15);
    set_enh_critical(1);
   set_weight(250);
    set_value(1000);
set_hit( (: call_other, this_object(), "weapon_hit" :));
set_wield( (: call_other, this_object(), "wield_blade" :));
}
int wield_blade(){
if((string)this_player()->query_class()=="paladin"){
write("The unholy aura of this weapon burns your soul.\n"
"A sharp and burning pain travels up your arm, causing you "
"to let go.\n");
this_player()->add_hp(-60);
this_player()->set_mp(10);
return 0;
}
write("%^RED%^Unholy energy surges through your body as you "
"grasp the onyx hilted black blade.\n");
return 1;
}

