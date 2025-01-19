// base inherit for demon class
#include <colors.h>

inherit "/std/pet";

int power;
int material = 0;
int rtime;
int pos = 0;
int controlled = 0;
int demon_type = 1;
int perm = 0;

// materialized ids
string *mat_ids = ({"demon", "small demon", "smaller demon"});
// controlled ids
string *cont_ids = ({ "lesser controlled"});
// initial ids
string *initial_ids = ({ "small spirit", 
  "small presence", "small demonic presence"});
// initial short
string initial_short = "Small Demonic Presence";
// materialized shot
string mat_short = "Smaller Demon";
// materialize info message
string mat_desc = "A demon materializes.";
// long description
string long_desc = "This is a smaller demon.  They are about the size of a
goblin, " +
"yet they are very fierce.  ";

int query_posessed(){
    return pos;
}

int query_is_demon(){
    return 1;
}

void materialize(){
    set_id(mat_ids);
    set_short(mat_short);
    material = 1;
    message("info", CRED + mat_desc,
      environment());
    if(controlled)
        set_id( query_id() +  cont_ids );
}

int set_owner(string str){
    if(str != "rogue"){
        set_id( query_id() + cont_ids );
        controlled = 1;
    }
    return ::set_owner(str);
}

void set_perm(int x){ perm = x; }

int set_up(int pow);

void create() {
    ::create();
    set_save(0);
set_property("no save", 1);
    set_attack(1);
    set_carry(0);
    set_can_change_aggr(0);
    set_change_ownership(0);
    set_name("demon");
    set_id(initial_ids);
    set_short(initial_short);
    set("race", "demon");
    set_body_type("winged-humanoid");
    set_long(long_desc);
    set_name("demon");
    set_up(random(101));
    return;
}

set_up(int pow) {
    power = pow;
    set_overall_ac(query_overall_ac() / 2);
    set_skill("attack", query_skill("attack") * 4/3);
    set_skill("melee", query_skill("melee") * 4/3);
    return;
}

int query_demon_type(){
    return demon_type;
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

void die(){
    if(!material){
        if(time() <=  rtime + 2)return;
        rtime = time();
        call_out("run", 1);
        materialize();
        return 0;
    }
    if(!perm){
        message("info", CRED + "A demon returns to his plane.",
          environment());
        remove();
    }
    ::die();
}

void posess(object at){
    string *shrt;
    int skip = 0;
    if(!at || !at->is_corpse())
        return;

    shrt = explode(at->query_old_short(), " ");
/*  taken out by ophelia so that short is identical
    if( lower_case(shrt[0]) == "a" || lower_case(shrt[0]) == "an")
        shrt = exclude_array(shrt, 0);
    shrt = implode(shrt, " ");
*/

    set_short(shrt);      
    set_long(at->query_old_long() +
      CRED + "This creature seems demonic.\n");
    set("race", at->query_old_race());
    set_id(query_id() + ({ at->query_old_name() }) ) + at->query_old_id();
    at->move(this_object());
    at->remove();
    force_me("equip");
    pos = 1;
    set_bodyguard(1);
    set_intelligent(1);
}

int enemies_fun(object who){
    string *enemies;
    string name;
    if(who->query_class() == "demon-master"){
        kill_ob(who, 0);
        return 1;
    }
    if(who->query_level() < 6)
        return 0;
    if(random(100) < 35){
        kill_ob(who, 0);
        return 1;
    }

    return 0;
}


void set_aggr_status(int x){
    if(x)
        set("aggressive", (: call_other, this_object(), "enemies_fun" :) );
}


