// unbreakable contract shadow by glen
#include <security.h>
#include <daemons.h>
#include <colors.h>

inherit "/std/spells/shadows/shadow";


object who_shadowed;
string exp_mesg;
int power;
int dam_block = 0;

int has_uc(){
    return 1;
}

void mesg(string msg){
    message("info", msg, who_shadowed);
}

void uc_die(){
    int i;
    who_shadowed->set("no stun", 0);
    dam_block = 0;
    who_shadowed->set("death save", 0);
    mesg(CBOLD + CRED +
      "Death takes its toll");
    for(i = 0; i < 1000 && who_shadowed->query_hp() > 0; i++)
	who_shadowed->do_damage("torso", 500);
    who_shadowed->set("no quit", 0);
    remove();
    return;
}

void save_from_death(object caster, object null) {
    if(!caster) return;
    who_shadowed->set("no quit", 1);
    caster->set_hp((int)caster->query_max_hp());
    caster->set_mp((int)caster->query_max_mp());
    DAMAGE_D->stop_cont_damage(caster);
    caster->remove_paralyzed();
    if(dam_block)  // dont make multiple calls
	return; 
    message("info", CBOLD + CRED +
      "Death pats you on the back, and says he will be back soon", 
      caster);
    call_out("mesg", power/2, CBOLD + CRED +
      "You have some time left.");
    call_out("mesg", power, CBOLD + CRED +
      "Your time is running out.");
    call_out("mesg", power*3/2, CBOLD + CRED +
      "Your time is almost gone, prepare for death.");
    call_out("uc_die", power*2);
    dam_block = 1;
    who_shadowed->set("no stun", 1);
    return;
}

void set_power(int x){ 
    power = x / 2 + 2; 
}

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    if(dur) call_out("expire_shad", dur, this_object());
    who->set("death save", (: call_other, this_object(),
	"save_from_death":));
    return;
}

void expire_shad(object me) {
    if(me != this_object()) {
	next_shadow()->expire_blur(me);
	return;
    }
    if(exp_mesg) message("info", exp_mesg, who_shadowed);
    remove();
    return;
}

void add_hp(int x) {
    object prev;

    if(dam_block && x < 1)
	return;

    next_shadow()->add_hp(x);
    return;
}

int do_damage(string limb, int amt) 
{
    if(dam_block)
	return 0;
    return (int)next_shadow()->do_damage(limb, amt);
}

