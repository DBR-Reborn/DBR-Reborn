//TLNY2020 added to /d/newbieville/mon/newbie
inherit "/std/armour";


void create() {
	::create();
	set_name("newbie robe");
	set("id", ({"newbie", "newbie robe", "robe" }) );
	set("short", "%^BOLD%^%^MAGENTA%^newbie robe%^RESET%^");
	set("long",
		"Long flowing strips of colourful strands that cover almost the entire body. from head to toe if you wear this you will look like a ridiculous clown! However, you will get bonuses on many skills to be able to distract the enemy and help you be able to hit them with ease."
	);
	set_type("test");
	set_ac(40);
	set_limbs( ({ "torso", "head", "left arm", "right arm", "left leg",
		"right leg", "left foot", "right foot", "left hand", "right hand" }) );
	set_value(400);
	set_weight(100);
	set_material("cloth");
    set_wear( (: call_other, this_object(), "add_bonus" :) );
    set_unwear( (: call_other, this_object(), "remove_bonus" :) );
    

   
}


void init() {
::init();
 add_action("remove_bonus2", "drop");
 add_action("remove_bonus3", "drop");
}


int add_bonus() {
   write("You feel the energy of the robe surge through your body. Ribbons of every %^BOLD%^%^CYAN%^c%^RED%^o%^BLUE%^l%^GREEN%^o%^MAGENTA%^r%^RESET%^ wrap around your body as you wear the robe you feel more skillful in every way but also you look and feel like a idiot");
   TP->add_skill_bonus("two handed staff", 40);
   TP->add_skill_bonus("blunt", 40);
   TP->add_skill_bonus("knife", 40);
   TP->add_skill_bonus("axe", 40);
   TP->add_skill_bonus("blade", 40);
   TP->add_skill_bonus("melee", 40);
   TP->add_skill_bonus("attack", 40);
   TP->add_skill_bonus("dodge", -50);
   TP->add_skill_bonus("parry", -50);
   TP->add_skill_bonus("block", -50);

    return 1;

}

int remove_bonus() {
      write("The energy from the robe is released from your body as you"
       " remove the robe. The power fades away from you.");
   TP->add_skill_bonus("two handed staff", -40);
   TP->add_skill_bonus("blunt", -40);
   TP->add_skill_bonus("knife", -40);
   TP->add_skill_bonus("axe", -40);
   TP->add_skill_bonus("blade", -40);
   TP->add_skill_bonus("melee", -40);
   TP->add_skill_bonus("attack",-40);
   TP->add_skill_bonus("dodge",  50);
   TP->add_skill_bonus("parry",  50);
   TP->add_skill_bonus("block",  50);
   return 1;
}

int remove_bonus2(string str) {

if(str == "robe"){
if(query_worn()) {
      write("The energy from the robe is released from your body as you"
       " remove the robe. The power fades away from you.");
   TP->add_skill_bonus("two handed staff", -40);
   TP->add_skill_bonus("blunt", -40);
   TP->add_skill_bonus("knife", -40);
   TP->add_skill_bonus("axe", -40);
   TP->add_skill_bonus("blade", -40);
   TP->add_skill_bonus("melee", -40);
   TP->add_skill_bonus("attack",-40);
   TP->add_skill_bonus("dodge",  50);
   TP->add_skill_bonus("parry",  50);
   TP->add_skill_bonus("block",  50);
//move(this_object(environment(this_player()));
move(environment(this_player()));
   return 1;
}
}
}

int remove_bonus3(string str) {

if(str == "all"){
if(query_worn()) {
      write("Because of the power of this object you must drop it first!. The drop all command must be ran again to drop your other items. The energy from the robe is released from your body as you"
       " remove the robe. The power fades away from you.");
   TP->add_skill_bonus("two handed staff", -40);
   TP->add_skill_bonus("blunt", -40);
   TP->add_skill_bonus("knife", -40);
   TP->add_skill_bonus("axe", -40);
   TP->add_skill_bonus("blade", -40);
   TP->add_skill_bonus("melee", -40);
   TP->add_skill_bonus("attack",-40);
   TP->add_skill_bonus("dodge",  50);
   TP->add_skill_bonus("parry",  50);
   TP->add_skill_bonus("block",  50);
move(environment(this_player()));
   return 1;
}
}
}


