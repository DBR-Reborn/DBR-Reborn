#include <colors.h>
#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;


int do_damage(string limb, int amt) 
{
    int res, xx;
    object prev;
    object ob, at;
    at = who_shadowed->query_current_attacker();

    if(at && random(100) == 17){
	if(!at->query_leprosy()){
	    ob = new("/std/glen/shadows/leprosy");
	    ob->start_shadow(at, 0, "you feel better");
	}
    }

    res = (int)next_shadow()->do_damage(limb, amt);
    return res;
}


int query_leprosy(){
    return 1;
}

void create() {
}

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    set_heart_beat(1);
    return;
}


void expire_leprosy() {
    message("info", exp_mesg, who_shadowed);
    remove();
    return;
}

int targets(object ob){
    return living(ob);
}

void do_contagious(){
    object *inv, ob;
    int i;

    inv=all_inventory(environment(who_shadowed));
    inv=filter_array(inv,"targets");

    i=sizeof(inv);
    while(i--){
	if(inv[i]->query_leprosy())
	    continue;
	if(inv[i] == this_player())
	    continue;
	ob=new("/std/glen/shadows/leprosy");
	ob->start_shadow(inv[i], 0, "you feel better");
	message("info",
	  CBOLD + CRED + "You were just infected by "+
	  who_shadowed->query_short(), inv[i]);
    }
    return;    
}



void heart_beat() {
    int x = random(200);
    string limb;

    if(x % 50 == 0){
	limb = who_shadowed->return_target_limb();
	if(limb != "head" && limb != "torso")
	    who_shadowed->cripple_limb(limb, "sever"); 
    }
    if(x % 40 == 0){
	do_contagious();
    }

    if(x % 35 == 0){
	message("info", "You cough.", who_shadowed);
	message("info", who_shadowed->query_short() + " cough repeatedly.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
    }
    if(x % 20 == 0){
	message("info", "You itch.", who_shadowed);
	message("info", who_shadowed->query_short() + " itches repeatedly.", 
	  all_inventory(environment(who_shadowed)), who_shadowed);
    }

    return;
}

