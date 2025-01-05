#include <security.h>

inherit "/std/spells/shadows/shadow";

string exp_mesg;

object who_shadowed;
int dark_level = 1;

int is_dark_shadow(){
    return 1;
}

void add_dark_level(int x){
    dark_level += x;
}

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    call_out("expire_just", dur, this_object());
    return;
}

int query_light(){
    return(next_shadow()->query_light() - dark_level);
}

mixed query_property(string what){
    if(what == "light")
	return(next_shadow()->query_property(what) - dark_level);
    return(next_shadow()->query_property(what));
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


