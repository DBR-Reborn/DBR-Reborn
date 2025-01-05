#include <colors.h>
#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;

int cont = 0;
int duration = 480;
int count = 0;
int innane = 0;
int trans_message = 0;

string disease_name = "leprosy";

int set_trans_msg(int x){
    trans_message = x;
}

int set_cont(int x){
    cont = x;
}

int set_innane(int x){
    innane = x;
}

int query_disease(string str){
    if(str == disease_name || strlen(str) < 1)
	return 1;
    else
	return next_shadow()->query_disease(str);
}

void start_shadow(object who, int dur, string mesg, int dsave) {
    if(who && who->query_disease(disease_name)){
	remove();
	return;
    }
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    set_heart_beat(1);

    if(!dsave && dur)
	duration = dur;

    if(dsave){
	innane = 1;
	who_shadowed->set("death save", (: call_other, this_object(), "death_disease_func":));
    }
    return;
}


void remove_disease(string str) {
    if(str == disease_name || !str || strlen(str) < 1){
	message("info", exp_mesg, who_shadowed);
	remove();
	return;
    }else
	next_shadow()->remove_disease(str);
}

void cure_disease(string str) {
    if(str == disease_name || !str || strlen(str) < 1){
	innane = 1;
	message("info", exp_mesg, who_shadowed);
    }
    next_shadow()->cure_disease(str);
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
	if(inv[i]->query_disease(disease_name))
	    continue;
	if(inv[i] == who_shadowed)
	    continue;
	ob=new("/std/glen/diseases/" 
	  + replace_string(disease_name, " ", "_"));
	ob->start_shadow(inv[i], 0, "you feel better");
	if (trans_message){
	    message("info",
	      CBOLD + CRED + "You were just infected by "+
	      who_shadowed->query_short(), inv[i]);
	    message("info",
	      CBOLD + CRED + "You just infected "+
	      inv[i]->query_short(),who_shadowed);
	}
    }
    return;    
}



void heart_beat() {
    int x = random(200);
    string limb;

    count++;

    if(innane)
	return;
    if(count > duration)
	cure_disease(disease_name);

    if(x % 50 == 0){
	limb = who_shadowed->return_target_limb();
	if(limb != "head" && limb != "torso")
	    who_shadowed->cripple_limb(limb, "sever"); 
    }
    if(x % 40 == 0){
	if(cont)
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

void death_disease_func()
{
    who_shadowed->set("death save", 0);
    do_contagious();
    who_shadowed->die();
    remove();
    return;
}
void revive() {
    next_shadow()->revive();
    remove();
    return;
}

