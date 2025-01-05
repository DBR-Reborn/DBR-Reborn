#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
string tick_mesg;
int met_rate;
int count;

int query_metabolism() { return 1; }

void set_met_rate(int x) { met_rate = x; }

void set_mesg(string str) { tick_mesg = str; }

void create() {
    met_rate = 0;
    count = 0;
}

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    set_heart_beat(1);
    call_out("expire_met", dur, this_object());
    return;
}

void heart_beat() {
    count++;
    next_shadow()->heart_beat();
    if((count % met_rate) == 0 && objectp(who_shadowed)){
	who_shadowed->do_healing(who_shadowed->calculate_healing());
	if(stringp(tick_mesg))
	    message("info", tick_mesg, who_shadowed);
    }
    return;
}

void expire_met(object me) {
    if(me != this_object()) {
	next_shadow()->expire_met(me);
	return;
    }
    message("info", exp_mesg, who_shadowed);
    remove();
    return;
}

