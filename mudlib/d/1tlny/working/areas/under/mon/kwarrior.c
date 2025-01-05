#include <std.h>

inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange,xname;

	::create();
	set_name("drow warrior");
	set_id( ({"warrior", "drow", "drow warrior"}));
	roll=random(10);
	switch(roll){
	case 0:zlevel=7;break;
	case 1:zlevel=7;break;
	case 2:zlevel=7;break;
	case 3:zlevel=6;break;
	case 4:zlevel=6;break;
	case 5:zlevel=6;break;
	case 6:zlevel=6;break;
	case 7:zlevel=7;break;
	case 8:zlevel=8;break;
	case 9:zlevel=10;break;
}
	set("race", "drow");
	xname=random(10);
	switch(xname) {
	case 0:xname="Dark drow warrior";break;
	case 1:xname="Fearsome drow warrior";break;
	case 2:xname="Bloodthirsty drow warrior";break;
	case 3:xname="Stealthy drow warrior";break;
	case 4:xname="Dexterous drow warrior";break;
	case 5:xname="Nimble drow warrior";break;
	case 6:xname="Evil drow warrior";break;
	case 7:xname="Skinny drow warrior";break;
	case 8:xname="Agile drow warrior";break;
	case 9:xname="Determined drow warrior";break;
}
	set_short(xname);
	set_long("As you gaze upon the drow warrior you can see that he is one of the humble inhabitants of the city.  He does not belong to any of the noble houses of the underdark, but is only in the drow city to protect it.  He wears a light chainmail armour.");
	set_body_type("humanoid");
	set_level(zlevel+3);
	xskill=7*level+20;
	set_skill("dodge", xskill);
	set_skill("melee", xskill+15);
	set_skill("parry", xskill);
	set_skill("attack", xskill+15);
	set_skill("blade", xskill);
	set_skill("blunt", xskill);
	set_skill("two handed blade", xskill);
	set_skill("two handed blunt", xskill);
	set_skill("axe", xskill);
	set_skill("two handed polearm", xskill);
	set_skill("two handed flail", xskill);
	set_skill("perception", 20);
	set_wielding_limbs( ({"right hand", "left hand"}));
	set_gender("male");
	set_alignment(-800);
	set_stats("strength", xskill+20);
	set_stats("dexterity", xskill);
	set_stats("intelligence", xskill);
	set_stats("constitution", xskill);
	set_stats("charisma", xskill);
	set_stats("wisdom", xskill);
	set_languages( ({"common", "yin"}));
	set_wimpy(5);
	set_class("fighter");
	xchange=random(18);
	switch(xchange){
	case 0:xchange=1;break;
	case 1:xchange=1;break;
	case 2:xchange=1;break;
	case 3:xchange=1;break;
	case 4:xchange=1;break;
	case 5:xchange=2;break;
	case 6:xchange=2;break;
	case 7:xchange=2;break;
	case 8:xchange=2;break;
	case 9:xchange=2;break;
	case 10:xchange=2;break;
	case 11:xchange=2;break;
	case 12:xchange=2;break;
	case 13:xchange=3;break;
	case 14:xchange=3;break;

	case 15:xchange=3;break;
	case 16:xchange=4;break;
	case 17:xchange=5;break;
}
	switch(random(18)){

	case 0:new("/d/damned/virtual/footman's-mace_"+xchange+".weapon")->
	move(this_object());
	force_me("wield mace in left hand");
	break;
	case 1:new("/d/damned/virtual/battle-axe_"+xchange+".weapon")->
	move(this_object());
	force_me("wield axe in left hand");
	break;
	case 2:new("/d/damned/virtual/hand-axe_"+xchange+".weapon")->
	move(this_object());
	force_me("wield axe in left hand");
	break;
	case 3:new("/d/damned/virtual/footman's-flail_"+xchange+".weapon")->
	move(this_object());
	force_me("wield flail in left hand and right hand");
	break;
	case 4:new("/d/damned/virtual/military fork_"+xchange+".weapon")->
	move(this_object());
	force_me("wield fork in left hand and right hand");
	break;
	case 5:new("/d/damned/virtual/glaive_"+xchange+".weapon")->
	move(this_object());
	force_me("wield glaive in left hand and right hand");
	break;
	case 6:new("/d/damned/virtual/halberd_"+xchange+".weapon")->
	move(this_object());
	force_me("wield halberd in left hand and right hand");
	break;
	case 7:new("/d/damned/virtual/long-sword_"+xchange+".weapon")->
	move(this_object());
	force_me("wield sword in left hand");
	break;
	case 8:new("/d/damned/virtual/bastard-sword_"+xchange+".weapon")->
	move(this_object());
	force_me("wield sword in left hand and right hand");
	break;
	case 9:new("/d/damned/virtual/short-sword_"+xchange+".weapon")->
	move(this_object());
	force_me("wield sword in left hand");
	break;
	case 10:new("/d/damned/virtual/two-handed-sword_"+xchange+".weapon")->
	move(this_object());
	force_me("wield sword in left hand and right hand");
	break;
	case 11:new("/d/damned/virtual/broad-sword_"+xchange+".weapon")->
	move(this_object());
	force_me("wield sword in left hand");
	break;
	case 12:new("/d/damned/virtual/great-axe_"+xchange+".weapon")->
	move(this_object());
	force_me("wield axe in left hand and right hand");
	break;
	case 13:new("/d/damned/virtual/morning-star_"+xchange+".weapon")->
	move(this_object());
	force_me("wield star in left hand");
	break;
	case 14:new("/d/damned/virtual/war-hammer_"+xchange+".weapon")->
	move(this_object());
	force_me("wield hammer in left hand");
	break;
	case 15:new("/d/damned/virtual/hammer_"+xchange+".weapon")->
	move(this_object());
	force_me("wield hammer in left hand");
	break;
	case 16:new("/d/damned/virtual/military-pick_"+xchange+".weapon")->
	move(this_object());
	force_me("wield pick in left hand and right hand");
	break;
	case 17:new("/d/damned/virtual/spear_"+xchange+".weapon")->
	move(this_object());
	force_me("wield spear in left hand and right hand");
	break;
}
	new("/wizards/blial/chaos/obj/heavyarmor.c")->
	move(this_object());
	force_me("wear armor");
}
