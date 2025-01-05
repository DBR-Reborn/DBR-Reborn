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
    disease_name = "flu";
    duration = 200;
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
    if(str == "strength")
	x -= x / 2;
    return x;
}

int query_skill(string skill) {
    int res;
    res = (int)next_shadow()->query_skill(skill);

    if(skill == "attack")
	res -= res / 4 * 3;
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

    if(count %  7 == 0){
	message("info", "You feel sick.", who_shadowed);
	message("info", who_shadowed->query_short() 
	  + " looks a little pale.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
    }
    if(count % 17 == 0){
	message("info", "You puke.", who_shadowed);
	message("info", who_shadowed->query_short() 
	  + " pukes a hefty amount!", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
	who_shadowed->add_hp(-1*
	  who_shadowed->query_max_hp() / 4);
	who_shadowed->add_stuffed(-100);
	who_shadowed->add_quenched(-100);
    }
    return;
}

