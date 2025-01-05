inherit "/std/armour";

	create() {
	::create();
	set_name("body armour");
	set("id", ({"armour", "body armour", "jacket"}) );
	set_short("The Jacket of the Shaman");
	set_long("This loose jacket is made of only feathers and cloth, but you'd swear it was stronger than laen.");
        set_type("body armour");
        set_weight(10);
	set_value(0);
        set_limbs( ({"torso", "left arm", "right arm"}));
}

void init(){
   ::init();
        set_wear((: call_other,this_object(), "wear_equipment" :));
        set_remove((: call_other,this_object(), "remove_equipment" :));
}

int wear_equipment() {
    if((string)this_player()->query_class() != "shaman"){
write("As you try to don the armour, it seems to resist your attempts to wear it. It falls apart a moment later.");
    this_object()->remove();
 return 0;
}
write("The power of nature courses through your veins. You feel very protected.");
    return 1;
}

int remove_equipment(){
        write("As you remove the natural armour, you feel less protected.");
return 1;
}
