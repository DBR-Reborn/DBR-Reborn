#include <std.h>

inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange,xname;

	::create();
	set_name("beastman");
	set_id( ({"beastman"}));
	roll=random(10);
	switch(roll){
	case 0:zlevel=31;break;
	case 1:zlevel=31;break;
	case 2:zlevel=31;break;
	case 3:zlevel=32;break;
	case 4:zlevel=32;break;
	case 5:zlevel=32;break;
	case 6:zlevel=32;break;
	case 7:zlevel=32;break;
	case 8:zlevel=33;break;
	case 9:zlevel=34;break;
}
	set("race", "gnoll");
	xname=random(10);
	switch(xname) {
	case 0:xname="["+zlevel+"]large slobbering beastman";break;
	case 1:xname="["+zlevel+"]bull headed, nose ringed beastman";break;
	case 2:xname="["+zlevel+"]dark fur, red eyed beastman";break;
	case 3:xname="["+zlevel+"]sharp toothed, violent beastman";break;
	case 4:xname="["+zlevel+"]goat horned, grey furred beastman";break;
	case 5:xname="["+zlevel+"]big fisted, dirty nailed beastman";break;
	case 6:xname="["+zlevel+"]clean, arrogant beastman";break;
	case 7:xname="["+zlevel+"]well muscled, body pierced beastman";break;
	case 8:xname="["+zlevel+"]scruffy pimple infested beastman";break;
	case 9:xname="["+zlevel+"]tall overpowering beastman";break;
}
	set_short(xname);
	set_long("Beastmen are wild and brutish creatures who care little for other creatures and despise humans above all else.  They have bodies that are half-man and half beast, ususally with the horned head of a goat.  IN battle they combine ferocity with savage lack of discipline, fighting and battling amongst themselves in their eagerness to get at the enemy.");
	set_body_type("humanoid");
	set_level(zlevel);
	xskill=6*zlevel;
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
	set_skill("perception", 20);
	set_wielding_limbs( ({"right hand", "left hand"}));
	set_property("melee damage", (["slashing" : xskill]));
	set_gender("male");
	set_alignment(-600);
	set_stats("strength", xskill);
	set_stats("dexterity", xskill);
	set_stats("intelligence", xskill);
	set_stats("constitution", xskill);
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
	force_me("wield sword in lfet hand and right hand");
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
