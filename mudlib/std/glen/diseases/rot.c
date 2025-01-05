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
    disease_name = "rot";
    duration = 80;
    return;
}

void heart_beat() {
    int dam = who_shadowed->query_hp() / 12;
    int x = random(200);
    string limb;

    count++;

    if(innane)
	return;
    if(count > duration)
	remove_disease(disease_name);

    limb = who_shadowed->return_target_limb();

    if(count % 3 == 0){
	message("info", 
	  CBOLD + CGREEN + "The rots eats you up!.", 
	  who_shadowed);
    }
    who_shadowed->do_damage(limb, dam);
    who_shadowed->check_on_limb(limb);

    return;
}

