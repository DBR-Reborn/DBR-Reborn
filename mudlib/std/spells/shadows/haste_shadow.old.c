#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
static int fumble;

void set_fumble() { fumble = 1; }

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    //  begin_shadow(who);
    shadow(who, 1);
    begin_shadow(who);
    who_shadowed = who;
    exp_mesg = mesg;
    if(dur) call_out("expire_haste", dur, this_object());
    seteuid(getuid());
    return;
}

int query_haste() { 
    int res = 1;
    if(fumble)
	res = 0;
    if(next_shadow())
	return((int)next_shadow()->query_haste() + res);
    return res;
}

void expire_haste(object me) {
    if(me != this_object()) {
	next_shadow()->expire_haste(me);
	return;
    }
    message("info", exp_mesg, who_shadowed);
    remove();
    return;
}

int query_num_rounds() {
    int res = 1;
    if(fumble)
	res = 0;
    if(next_shadow())
	return((int)next_shadow()->query_num_rounds() + res);
    return res;
}

