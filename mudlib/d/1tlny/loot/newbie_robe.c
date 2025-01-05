//TLNY2020 added to /d/newbieville/mon/newbie
inherit "/std/armour";


void create() {
	::create();
	set_name("newbie robe");
	set("id", ({"newbie", "newbie robe", "robe" }) );
	set("short", "%^BOLD%^%^MAGENTA%^newbie robe%^RESET%^");
	set("long",
		"Long flowing strips of colourful strands that cover almost the entire body only low level players may use this item. from head to toe if you wear this you will look like a ridiculous clown! However, you will get bonuses on many skills to be able to distract the enemy and help you be able to hit them with ease."
	);
	set_type("robe");
	set_ac(40);
	set_limbs( ({ "torso", "head", "left arm", "right arm", "left leg",
		"right leg", "left foot", "right foot", "left hand", "right hand" }) );
	set_value(400);
	set_weight(100);
	set_material("cloth");
    set_wear( (: call_other, this_object(), "add_bonus" :) );
    set_remove( (: call_other, this_object(), "off_bonus" :) );
//set_wear(TP->add_skill_bonus("attack", 40));

//set_remove("off");
   
}

/*
void init() {
::init();
    set_wear( (: call_other, this_object(), "add_bonus" :) );
    set_remove( (: call_other, this_object(), "remove_bonus" :) );
}
*/

int add_bonus() {

// if(this_player()->is_player() && (int)this_player()->query_level() > 10) {
     //write("%^BOLD%^Only low level players of 10 or less may use this item.");
    //return 0;
//}

   write("You feel the energy of the robe surge through your body. Ribbons of every %^BOLD%^%^CYAN%^c%^RED%^o%^BLUE%^l%^GREEN%^o%^MAGENTA%^r%^RESET%^ wrap around your body as you wear the robe you feel more skillful in every way but also you look and feel like a idiot. ALL known your combat skills have been increased");


   TP->add_skill_bonus("attack", 40);
   TP->add_skill_bonus("two handed blade", 40);
   TP->add_skill_bonus("two handed blunt", 40);
   TP->add_skill_bonus("two handed flail", 40);
   TP->add_skill_bonus("two handed polearm", 40);
   TP->add_skill_bonus("two handed staff", 40);
   TP->add_skill_bonus("axe", 40);
   TP->add_skill_bonus("blade", 40);
   TP->add_skill_bonus("blunt", 40);
   TP->add_skill_bonus("knife",  40);
   TP->add_skill_bonus("flail", 40);
   TP->add_skill_bonus("melee", 40);

   TP->add_skill_bonus("parry", 40);
   TP->add_skill_bonus("dodge", 40);
   TP->add_skill_bonus("block", 40);

    return 1;
}

int off_bonus() {
      write("The energy from the robe is released from your body as you remove the robe. The power fades away from you and your skills go back to normal.");
   TP->add_skill_bonus("attack", -40);
   TP->add_skill_bonus("two handed blade", -40);
   TP->add_skill_bonus("two handed blunt", -40);
   TP->add_skill_bonus("two handed flail", -40);
   TP->add_skill_bonus("two handed polearm", -40);
   TP->add_skill_bonus("two handed staff", -40);
   TP->add_skill_bonus("axe", -40);
   TP->add_skill_bonus("blade", -40);
   TP->add_skill_bonus("blunt", -40);
   TP->add_skill_bonus("knife",  -40);
   TP->add_skill_bonus("flail", -40);
   TP->add_skill_bonus("melee", -40);

   TP->add_skill_bonus("parry", -40);
   TP->add_skill_bonus("dodge", -40);
   TP->add_skill_bonus("block", -40);
   return 1;
}

