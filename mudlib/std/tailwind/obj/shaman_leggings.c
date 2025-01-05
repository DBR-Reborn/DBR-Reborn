inherit "/std/armour";

	create() {
	::create();
	set_name("leggings");
	set("id", ({"armour", "leggings"}) );
	set_short("The Leggings of the Shaman");
	set_long("These loose breeches are made of simple cloth, and have multi-colored feathers attached at various points. It feels sturdier than any cloth could be, though...");
        set_type("pants");
        set_weight(10);
	set_value(0);
        set_limbs( ({"left leg", "right leg"}));
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
