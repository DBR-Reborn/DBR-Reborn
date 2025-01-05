// glen, this is a "charge" shield
// it will absorb X amount of damage before quitting out
// derived from holy mission

#include <security.h>
inherit "/std/spells/shadows/shadow";

object who_shadowed;
object mission_ob;
string exp_mesg;
int f_flag;
int damage;
int damage_allowed = 1;

int query_invulnerable() { return 1; }

void set_damage_allowed(int x){
    damage_allowed = x;
}

int query_damage_allowed() {
    return damage_allowed;
}

int query_damage_total() {
    return damage;
}

void create() {
    f_flag = 0;
    damage = 0;
}

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    mission_ob = this_object();
    call_out("expire_mission", dur, this_object());
    return;
}

int do_damage(string limb, int amt) {
    int res;

    if(damage >= damage_allowed)
	return(next_shadow()->do_damage(limb, amt));

    damage += amt;

    message("info", "%^BOLD%^" + "%^GREEN%^" +
      "Your shield deflects the damage.",who_shadowed);
    message("info", "%^BOLD%^" + "%^GREEN%^" +
      "Your blow is deflected by an inpenetrable shield.", 
      previous_object());


    if(damage >= damage_allowed){
	message("info", "%^BOLD%^" + "%^RED%^" +
	  "Your shield takes all the damage it can, it crumbles to dust."
	  ,who_shadowed);
	message("info", "%^BOLD%^" + "%^RED%^" +
	  "The shield crumbles under your attack.", 
	  previous_object());
    }

    return amt;
}

mixed query_property(string val) {
    if(val != "enhance criticals")
	return next_shadow()->query_property(val);

    if(previous_object() && living(previous_object()) && damage < damage_allowed)
    {
	message("info","%^BOLD%^" + "%^GREEN%^" +
	  "Your shield deflects the critical hit.",who_shadowed);
	message("info","%^BOLD%^" + "%^GREEN%^" +
	  "Your critical hit is blocked by an impregnable shield!", 
	  previous_object());
	return -1000;
    }
    return (int)next_shadow()->query_property(val);
}

void expire_mission(object me) {
    if(me != this_object()) {
	next_shadow()->expire_mission(me);
	return;
    }
    message("info", exp_mesg, who_shadowed);
    remove();
    return;
}

