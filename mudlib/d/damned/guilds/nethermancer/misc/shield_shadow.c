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
int heal_damage() {
    damage = damage - (random(200) + 300);
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
    call_out("heal_func", 60);
    return;
}

int do_damage(string limb, int amt) {
    int res;

    if(damage >= damage_allowed)
	return(next_shadow()->do_damage(limb, amt));

    damage += amt;

    message("info", "%^CYAN%^Your shield neutralizes the enemy attack!%^RESET%^", who_shadowed);
    message("info", "%^CYAN%^The Death Dragon's shield neutralizes your attack!%^RESET%^", previous_object());


    if(damage >= damage_allowed){
	message("info", "%^GREEN%^The shield dissipates from all the damage it has received.%^RESET%^", who_shadowed);
	message("info", "%^GREEN%^The Death Dragon's shield dissipates.%^RESET%^", environment(previous_object()));
    }

    return amt;
}

mixed query_property(string val) {
    if(val != "enhance criticals")
	return next_shadow()->query_property(val);

    if(previous_object() && living(previous_object()) && damage < damage_allowed)
    {
	message("info", "%^CYAN%^Your shield neutralizes the enemy attack.%^RESET%^", who_shadowed);
	message("info", "%^CYAN%^The Death Dragon's shield neutralizes your attack!%^RESET%^", previous_object());
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

void heal_func() {
    if(damage > 0) {
	tell_room(environment(who_shadowed), "%^BLUE%^The shield surrounding the Death Dragon regains some of its lost glow.%^RESET%^");
    }
    damage = damage - (random(200) + 300);
    if(damage <= 0) {
	damage = 0;
    }
    call_out("heal_func", 60);
}

