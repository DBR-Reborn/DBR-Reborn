//    A lesser demon.
#include <colors.h>

inherit "/std/pet";
int power;
int material = 0;
int rtime;
int pos = 0;
int controlled = 0;


int query_posessed(){
    return pos;
}

int query_is_demon(){
    return 1;
}

void materialize(){
    set_id(({"demon", "small demon", "smaller demon"}));
    set_short("Smaller Demon");
    material = 1;
    message("info", CRED + "A demon materializes.",
      environment());
    if(controlled)
	set_id( query_id() + ({ "lesser controlled"}) );
}

int set_owner(string str){
    if(str != "rogue"){
	set_id( query_id() + ({ "lesser controlled"}) );
	controlled = 1;
    }
    return ::set_owner(str);
}


int set_up(int pow);

void create() {
    ::create();
    set_save(0);
    set_attack(1);
    set_carry(0);
    set_can_change_aggr(0);
    set_name("demon");
    set_id(({ "small spirit", "small presence", "small demonic presence"}));
    set_short("Small Demonic Presence");
    set("race", "demon");
    set_body_type("winged-humanoid");
    set_long(
      "This is a smaller demon.  They are about the size of a goblin, " +
      "yet they are very fierce.  ");
    set_name("demon");
    set_up(random(101));
    return;
}

set_up(int pow) {
    power = pow;
    set_level(3+pow/30);
    set_max_hp(150 + pow*3);
    set_hp(150 + pow*3);
    set_skill("melee", 30 + pow/10);
    set_skill("chaos magic", 40 + pow/25);
    set_max_mp(150 + 70*pow);
    set_mp(150 + 70*pow);
    set_melee_damage(([ "disruption" : 20 + pow/2 ]));
    set_spell_level("disruption bolt", 1+pow/20);
    add_spell("disruption bolt", "$A");
    set_combat_chance(50);
    if(!query_owner())
	set_owner("rogue");
    return;
}

int query_demon_type(){
    return 1;
}

int query_power() { 
    return power; 
}

void set_dur(int dur) {
    call_out("expire", dur);
    return;
}


void expire() {
    if(pos)return;
    message("info", CRED + "A demon returns to his plane.",
      environment());
    remove();
    return;
}

void run(){
    if(!material){
	heal(query_max_hp());
	add_mp(query_max_mp());
	remove_paralyzed();
	message("info", CBOLD+CGREEN+ "The spirit fades away briefly.",
	  environment());
	run_away();
    }
}

int do_damage(string where, int x){
    if(!material){
	if(time() <=  rtime + 2)return;
	rtime = time();
	call_out("run", 1);
	return 0;
    }
    return ::do_damage(where, x);
}

void die(){
    if(!material){
	if(time() <=  rtime + 2)return;
	rtime = time();
	call_out("run", 1);
	return 0;
    }
    message("info", CRED + "A demon returns to his plane.",
      environment());
    remove();
}

void posess(object at){
    string *shrt;
    int skip = 0;
    if(!at || !at->is_corpse())
	return;

    // strip "a" and "an"
    shrt = explode(at->query_old_short(), " ");
    if( lower_case(shrt[0]) == "a" || lower_case(shrt[0]) == "an")
	shrt = exclude_array(shrt, 0);
    shrt = implode(shrt, " ");

    set_short(shrt);      
    set_long(at->query_old_long() +
      CRED + "This creature seems demonic.\n");
    set("race", at->query_old_race());
    set_id(query_id() + ({ at->query_old_name() }) ) + at->query_old_id();
    at->move(this_object());
    at->remove();
    force_me("equip");
    pos = 1;
}

