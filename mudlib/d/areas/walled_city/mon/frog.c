#include <std.h>

//Updated by Eos on 7/25/2020

inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange,xname;

        ::create();
        set_name("frog");
        set_id(({"frog", "toad", "The small frog"}));
        roll=random(10);
        switch(roll){
        case 0:zlevel=1;break;
        case 1:zlevel=2;break;
        case 2:zlevel=3;break;
        case 3:zlevel=4;break;
        case 4:zlevel=5;break;
        case 5:zlevel=6;break;
        case 6:zlevel=7;break;
        case 7:zlevel=8;break;
        case 8:zlevel=9;break;
        case 9:zlevel=10;break;
		
}		
		
	xname=random(6);
	switch(xname) {
	case 0:xname="["+zlevel+"]%^COLOR9%^red%^RESET%^%^COLOR40%^ frog%^RESET%^";break;
	case 1:xname="["+zlevel+"]%^COLOR10%^green%^RESET%^%^COLOR40%^ frog%^RESET%^";break;
	case 2:xname="["+zlevel+"]%^COLOR11%^yellow%^RESET%^%^COLOR40%^ frog%^RESET%^";break;
	case 3:xname="["+zlevel+"]%^COLOR208%^orange%^RESET%^%^COLOR40%^ frog%^RESET%^";break;
	case 4:xname="["+zlevel+"]%^COLOR11%^spot%^COLOR9%^ted%^RESET%^%^COLOR40%^ frog%^RESET%^";break;
	case 5:xname="["+zlevel+"]%^COLOR9%^sp%^COLOR15%^ot%^COLOR11%^ted%^RESET%^%^COLOR40%^ frog%^RESET%^";break;
		
}
	set_short(xname);
	set_long("The small green frog sits here eyeing you watchfully.");
	set_body_type("frog");
        set("race", "amphibian");
	set_level(zlevel);
        xskill=4*zlevel;
        set_skill("dodge", xskill);
        set_skill("melee", xskill);
        set_skill("attack", xskill);
		set_skill("perception", 5);
		set_stats("charisma", xskill);
        
	xchange=random(2);
	if(xchange)
        set_gender("male");
	else set_gender("female");
	
	set_languages( ({"common"}) );
	force_me("speak common");
	set_speech(10, "common", 
	({"Rrribbit", "Rrrunn", "Rrribbit", "Rrrayenth", "Search out the cave, rrribbit, there you will, rrribbit, find the truth."}),0); 
	
	set_emotes(10, ({
	"The frog spies a fly about to land on the rock",
	"The frog shifts it's head to watch you more closely",
	"The frog looks as though he has not a care in the world",
	"The frog croaks rribbit rribbit",
        "The frog snaps his toungue and snatches a fly from mid-air"}),0);
	
	set_achats(30,
                ({
                "The frogs hops around trying to dodge your attack.",
                "The frog whips you with it's tongue.",
                "The frog's eyes roll about wildly.",
                }) );
}
