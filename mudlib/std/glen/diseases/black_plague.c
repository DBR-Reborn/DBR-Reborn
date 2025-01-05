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
    disease_name = "black plague";
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
    if(str == "intelligence")
	x -= x / 2;
    return x;
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

    if(x % 13 == 0){
	message("info", "You feel faint.", who_shadowed);
	message("info", who_shadowed->query_short() 
	  + " looks like he is about to die.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
    }
    if(x % 31 == 0){
	message("info", "You bleed internally.", who_shadowed);
	message("info", who_shadowed->query_short() 
	  + " seems to grow more pale, likely to die soon.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
	who_shadowed->add_hp(-1* who_shadowed->query_hp() / 2);
	who_shadowed->add_mp(-1* who_shadowed->query_mp() / 2);
    }
    if(x % 32 == 0){
	message("info", "Your body takes extensive damage.", who_shadowed);
	message("info", who_shadowed->query_short() 
	  + " curls up in the fetal position crying.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
	who_shadowed->add_hp(-1* who_shadowed->query_max_hp() / 3);
	who_shadowed->add_mp(-1* who_shadowed->query_mp() / 2);
	who_shadowed->cripple_limb("left hand", "cripple");
	who_shadowed->cripple_limb("left foot", "cripple");
    }
    if(x % 71 == 0){
	message("info", "Your important organs rot away.", who_shadowed);
	message("info", who_shadowed->query_short() 
	  + " slumps to the ground involountarily.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
	who_shadowed->add_hp(-1* who_shadowed->query_max_hp());
	who_shadowed->add_mp(-1* who_shadowed->query_mp());
    }
    if(x % 37 == 0){
	message("info", "Your muscles rot.", who_shadowed);
	message("info", who_shadowed->query_short() 
	  + " claws at his own flesh as if delirous.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
	who_shadowed->add_hp(-1* who_shadowed->query_hp() / 3);
	who_shadowed->add_mp(-1* who_shadowed->query_mp() / 3);
    }
    return;
}

