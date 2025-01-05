// cloak of shadows by glen
// surrounds target in confusing shadows
#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
int power;

int has_shadow_cloak(){
    return 1;
}

void set_power(int x){ 
    power = x; 
}

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    if(dur) call_out("expire_blur", dur, this_object());
    return;
}

void expire_blur(object me) {
    if(me != this_object()) {
	next_shadow()->expire_blur(me);
	return;
    }
    if(exp_mesg) message("info", exp_mesg, who_shadowed);
    remove();
    return;
}

int do_damage(string limb, int amt) 
{
    int res;
    object prev;

    if(previous_object() && living(previous_object()))
    {
	if(random(20) < power)
	    return 0;
    }
    res = (int)next_shadow()->do_damage(limb, amt);
    return res;
}

int query_ac(string limb, string type) {
    int tmp;
    tmp += (int)next_shadow("query_ac")->query_ac(limb,type);
    if(random(35) < power)
	tmp += 10000;
    return tmp;
}

int sight_adjustment(object who) {
    if(random(power+4) < power)
	return power*100; 
    else
	return power*4;
}

int query_blurred() { return 1; }



