#include <colors.h>
#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;


void create() {
}

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    set_heart_beat(1);
    return;
}


void expire_leprosy() {
    message("info", exp_mesg, who_shadowed);
    remove();
    return;
}

int targets(object ob){
    return living(ob);
}

void do_anti_disease(){
    object *inv, ob;
    int i;

    inv=all_inventory(environment(who_shadowed));
    inv=filter_array(inv,"targets");

    i=sizeof(inv);
    while(i--){
	if(inv[i]->query_leprosy())
	    continue;
	inv[i]->expire_leprosy();
    }
    return;    
}



void heart_beat() {
    int x = random(200);
    string limb;

    if(x % 10 == 0){
	do_anti_disease();
    }
    return;
}

