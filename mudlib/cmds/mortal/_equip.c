/*  /cmds/mortal/_equip.c
 *  Made for DarkeMUD
 *  Created by Geldron 030996
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */
// Modified heavily by Drizzt 10/15/96
// It is actually worth a shit now!

inherit DAEMON;

int cmd_equip(string arg) {
    object *tmp;
    int i;
    string hand, race;

    if(arg) {
	write(syntax("equip"));
	return 1;
    }
    write("You begin power equipping...");
    hand = (string)this_player()->query_property("handedness");
    race = (string)this_player()->query_race();
    tmp = all_inventory(TP);
    for(i = 0; i < sizeof(tmp); i++) {
	if(tmp[i]->is_weapon()) {
	    if(strlen((string)tmp[i]->query_type()) > 10 && ((string)tmp[i]->query_type())[0..9] == "two handed") {
    TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in right hand and left hand");
	}
	    else {     	      
     if(hand == "left hand") {
    TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in left hand");
    TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 2 in right hand");
       }  else {
     TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in right hand");
     TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 2 in left hand");
	 }
	    }
	}
	if(tmp[i]->is_armour())
	    if((string)tmp[i]->query_type() == "shield") {
	      if(hand == "right hand") {
		TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on left hand");
		TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
	    }  
    else {
		TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
		TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on left hand");
	   }
	    }
        if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "wood arm") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right arm");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left arm");
	    } 
        if(tmp[i]->is_armour())
	    if((string)tmp[i]->query_type() == "wood hand") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left hand");
	    }  
        if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "metal arm") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right arm");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left arm");
	    } 
        if(tmp[i]->is_armour())
	    if((string)tmp[i]->query_type() == "metal hand") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left hand");
	    }
    if(tmp[i]->is_armour())
	    if((string)tmp[i]->query_type() == "chain hand") {
      TP->force_me("wear chain glove on right hand");
      TP->force_me("wear chain glove 2 on left hand");
	    }
    if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "leather head") {
        TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2");
	    }
    if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "wood head") {
        TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2");
	    }
    if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "metal head") {
        TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2");
	    } 
    if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "leather torso") {
        TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2");
	    } 
    if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "wood torso") {
        TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2");
	    } 
    if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "metal torso") {
        TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2");
	    } 
    if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "leather foots") {
        TP->force_me("wear leather boots");
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2");
	    } 
    if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "wood foots") {
         TP->force_me("wear stumps");
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2");
	    } 
    if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "metal foots") {
        TP->force_me("wear metal boots");
        //TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2");
	    } 
        if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "leather arm") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right arm");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left arm");
	    } 
        if(tmp[i]->is_armour())
	    if((string)tmp[i]->query_type() == "leather hand") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left hand");
	    }
        if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "cloth arm") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right arm");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left arm");
	    } 
        if(tmp[i]->is_armour())
	    if((string)tmp[i]->query_type() == "cloth hand") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left hand");
	    }
else if(tmp[i]->is_armour()) {
        TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
		}
    }        
    write("Done Equiping.");
    return 1;
}
	

void help() {
    message("equip_help", syntax("equip") + "\n\n"
      "Equips all your armour and weapons in order.  It isn't "
      "very accurate as to getting things worn the best possible way.", TP);
}
