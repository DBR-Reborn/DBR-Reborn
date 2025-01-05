#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
int lev;

void set_power(int x) { lev = x; }

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    call_out("expire_just", dur, this_object());
    return;
}

int query_aura_flare() { return 1; }

varargs int weapon_hit(object targ, object from, int damage, int num_rounds) {
    int res;
    object prev;

    next_shadow()->weapon_hit(targ, from, damage, num_rounds);

    if(who_shadowed != targ)
	return;
    if(who_shadowed == from)
	return;


    if(random(12) < lev){
	do_base_critical(targ, from, ({ "fire "+
	    (({ "A","B", "C" })[random(3)]) }) );
	do_base_critical(targ, from, ({ "radiation "+
	    (({ "A","B","C" })[random(3)]) }) );
	do_base_critical(targ, from, ({ "plasma "+
	    (({ "A","B", "C" })[random(3)]) }) );
    }
    return res; 
}

void expire_just(object me) {
    if(me != this_object()) {
	next_shadow()->expire_just(me);
	return;
    }
    if(exp_mesg)
	message("info", exp_mesg, who_shadowed);
    remove();
    return;
}

