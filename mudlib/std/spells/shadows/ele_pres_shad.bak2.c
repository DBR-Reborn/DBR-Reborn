#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
int lev;
string *dmg;

void set_power(int x) { lev = x; }

void set_damage(string *p) { dmg = p; }

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    call_out("expire_just", dur, this_object());
    return;
}

int query_ele_pres() { return 1; }

varargs int weapon_hit(object targ, object from, int damage, int num_rounds) {
    int res, i, j, lev, rounds;
    object prev;

    next_shadow()->weapon_hit(targ, from, damage, num_rounds);

    if(who_shadowed != targ)
	return;
    if(who_shadowed == from)
	return;


    i = sizeof(dmg);

    //    lev = (random(num_rounds) + random(num_rounds))/2;
    lev = random(num_rounds);
    if(random(100) > damage)
	lev++;
    if(lev > 4)
	lev = 4;

    rounds = num_rounds;

    if(damage > 0)
	for(j = 0; j < num_rounds; j += random(1)+1)
	    do_base_critical(targ, from, dmg[random(sizeof(dmg))]+" "+ (({ "A","B","B","C","C"})[lev]));

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


