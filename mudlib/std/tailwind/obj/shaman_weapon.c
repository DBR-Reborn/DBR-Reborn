inherit "/std/weapon";

	create() {
	::create();
	set_ac(0);
	set_name("staff");
	set("id", ({"staff", "shaman staff"}) );
	set_short("long, powerful-looking staff");
	set_long("This staff is the chosen weapon of Shamen. You doubt anyone but a true Shaman could wield it without dire consequences.");
        set_type("two handed staff");
	set_quality(6);
        set_weight(10);
	set_value(0);
	set_wc(7, "crushing");
	set_verb("ravage");
}

void init(){
   ::init();
   set_wield((: call_other, this_object(), "weapon_wield" :));
   set_unwield((: call_other, this_object(), "weapon_unwield" :));
}

int weapon_wield() {
    if((string)this_player()->query_class() != "shaman"){
write("You grab the weapon, and try to wield it. The weapon rejects you, and crumbles to dust in your very hands.");
this_object()->remove();
 return 0;
}
write("As you grip the weapon, the power of nature courses through your veins.");
    return 1;
}

int weapon_unwield() {
    write("The power of nature leaves you as you unwield the weapon.");
    return 1;
}
