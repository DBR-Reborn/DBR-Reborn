#include <security.h>
#include <colors.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
int heal_bat;
int damage;
int perc;
int power;
int no_heal;

void check_heal();

void check_heal() {
    int roll, i;

    if(!who_shadowed) {
	remove();
	return;
    }
    if(no_heal) return;
    if((100 * (int)who_shadowed->query_hp())/(int)who_shadowed->query_max_hp() < perc) {
	roll = 0;
	for(i = 0; i < 10;i++) roll += power+random(power);
	roll *= power;
	damage += roll;
	who_shadowed->heal(roll);
	if(damage >= heal_bat) {
	    if(exp_mesg) message("info", exp_mesg, who_shadowed);
	    remove();
	    return;
	} else {
	    message("info", 
	      CBOLD + CGREEN +
	      "You are healed.\n" + CBOLD + CMAGENTA + 
	      "Healing left: "+ 
	      sprintf(
		"%d percent full.", (100*(heal_bat-damage))/heal_bat)
	      +CRESET,who_shadowed);
	}
    }
    return;
} 

int query_auto_heal2() { return 1; }

void create() {
    power = 1;
    heal_bat = 0;
    damage = 0;
    no_heal = 0;
    perc = 1;
}

void set_ch_perc(int x) { perc = x; }
void set_ch_pow(int x) { power = x; }
void set_ch_damage(int x) { damage = x; }
void set_heal_bat(int x){ heal_bat = x; }

int query_heal_bat() { return heal_bat; }

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    heal_bat = dur;
    exp_mesg = mesg;
    return;
}

int do_damage(string limb, int amt) {
    int res;

    res = (int)next_shadow()->do_damage(limb, amt);
    check_heal();
    return amt;
}

void heal(int x) {
    next_shadow()->heal(x);
    if(x>=0) return;
    check_heal();
    return;
}

void add_hp(int x) {

    next_shadow()->add_hp(x);
    if(x >= 0) return;
    check_heal();
    return;
}

