#include <std.h>


inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange,xname;

	::create();
	set_name("castle knight");
	set("id",({"knight", "castle knight"}) );
	roll=random(10);
	
	switch(roll){
	case 0:zlevel=31;break;
	case 1:zlevel=33;break;
	case 2:zlevel=31;break;
	case 3:zlevel=32;break;
	case 4:zlevel=32;break;
	case 5:zlevel=33;break;
	case 6:zlevel=34;break;
	case 7:zlevel=34;break;
	case 8:zlevel=35;break;
	case 9:zlevel=35;break;
}
	set("race", "human");
	xname=random(10);
	switch(xname) {
	case 0:xname="["+zlevel+"]Castle Knight";break;
	case 1:xname="["+zlevel+"]DayBreak Knight";break;
	case 2:xname="["+zlevel+"]Strong Knight";break;
	case 3:xname="["+zlevel+"]Large Knight";break;
	case 4:xname="["+zlevel+"]Warrior Knight";break;
	case 5:xname="["+zlevel+"]Knight Warrior";break;
	case 6:xname="["+zlevel+"]Angry Knight";break;
	case 7:xname="["+zlevel+"]Rouge Knight";break;
	case 8:xname="["+zlevel+"]Knight";break;
	case 9:xname="["+zlevel+"]Brave Knight";break;
}
	set_short(xname);
	set_long("DayBreak Castle Knights were abandoned long ago with the Warriors who protected this castle. Now they have no one to serve other than themselves.");
	set_body_type("humanoid");
	set_level(zlevel);
	xskill=7*zlevel+25;
	set_skill("dodge", xskill);
	set_skill("melee", xskill);
	set_skill("parry", xskill);
	set_skill("attack", xskill);
	set_skill("blade", xskill);
	set_skill("blunt", xskill);
	set_skill("two handed blade", xskill);
	set_skill("two handed blunt", xskill);
	set_skill("axe", xskill);
	set_skill("two handed polearm", xskill);
	set_skill("two handed flail", xskill);
	set_skill("perception", 25);
	set_wielding_limbs( ({"right hand", "left hand"}));
	set_gender("male");
	set_alignment(-800);
	set_stats("strength", xskill);
	set_stats("dexterity", xskill+20);
	set_stats("intelligence", xskill);
	set_stats("constitution", xskill);
	set_stats("charisma", xskill+20);
	set_stats("wisdom", xskill);
	set_languages( ({"common", "yin"}));
	set_wimpy(3);
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

}
