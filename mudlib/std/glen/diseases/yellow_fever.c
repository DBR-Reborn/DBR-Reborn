#include <colors.h>
#include <security.h>

inherit "/std/glen/diseases/leprosy";

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    set_heart_beat(1);
    if(dur)
	duration = dur;
    disease_name = "yellow fever";
    duration = 160;
    return;
}

void heart_beat() {
    int x = random(200);
    string limb;

    count++;

    if(innane)
	return;
    if(count > duration)
	remove_disease(disease_name);

    //    if(x % 15 == 0)
    //        do_contagious();

    if(x % 18 == 0){
	if(who_shadowed->query_paralyzed())
	    return;
	message("info", CBOLD + CBLUE +
	  "The floor splashes you!" + CRESET
	  , who_shadowed);
    }
    if(x % 19 == 0){
	if(who_shadowed->query_paralyzed())
	    return;
	message("info", CBOLD + CGREEN +
	  "You pray to your shoes." + CRESET, who_shadowed);
    }
    if(x % 17 == 0){
	if(who_shadowed->query_paralyzed())
	    return;
	message("info", CBOLD + CRED +
	  "Blood rains from the sky." + CRESET, who_shadowed);
    }
    if(x % 8 == 0){
	if(who_shadowed->query_paralyzed())
	    return;
	message("info", "You go into a seizure.", who_shadowed);
	message("info", who_shadowed->query_short() 
	  + " goes into a brief seizure.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
	who_shadowed->set_paralyzed(
	  random(random(4)+1),
	  CBOLD +
	  "You are having a seizure and can't move");
    }
    return;
}

