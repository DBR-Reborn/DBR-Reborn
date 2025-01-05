#include <colors.h>
#include <security.h>

inherit "/std/glen/diseases/leprosy";

void start_shadow(object who, int dur, string mesg, int dsave) {
    disease_name = "bone_rot";
    duration = 15;
    ::start_shadow(who, dur, mesg, dsave);
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

    limb = who_shadowed->return_target_limb();
    message("info", CBOLD + CRED + "The bone rots eats you up!.", 
      who_shadowed);
    if(limb != "head" && limb != "torso")
	who_shadowed->cripple_limb(limb, "sever"); 
    return;
}

