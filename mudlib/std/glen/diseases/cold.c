#include <colors.h>
#include <security.h>

inherit "/std/glen/diseases/leprosy";

void start_shadow(object who, int dur, string mesg, int dsave) {
    disease_name = "cold";
    duration = 300;
    ::start_shadow(who, dur, mesg, dsave);
    return;
}

int query_stats(string str) {
    int x;
    (int)next_shadow()->query_stats(str);
    x = (int)next_shadow()->query_stats(str);

    if(str == "constitution")
	x -= x / 2;
    if(str == "dexterity")
	x -= x / 3;
    if(str == "intelligence")
	x -= x / 3;
    if(str == "strength")
	x -= x / 2;
    return x;
}

int query_skill(string skill) {
    int res;
    res = (int)next_shadow()->query_skill(skill);

    if(skill == "perception")
	res -= res / 2;
    return res;
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

    if(x % 35 == 0){
	message("info", "You cough.", who_shadowed);
	message("info", who_shadowed->query_short() + " coughs.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
    }
    if(x % 44 == 0){
	message("info", "Your itchy eyes water.", who_shadowed);
    }
    if(x % 36 == 0){
	message("info", "You sneeze.", who_shadowed);
	message("info", who_shadowed->query_short() + " sneezes.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
    }
    return;
}

