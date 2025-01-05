#include <security.h>
#include <colors.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
int lev;

void set_power(int x) { lev = x; }

void start_shadow(object who, int dur, string mesg) 
{
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    call_out("expire_just", dur, this_object());
    return;
}

int query_vigilance() { return 1; }

void do_vigilance(){
    object from = who_shadowed->query_current_attacker();
    int hp;

    hp = from->query_max_hp() / (12 / lev);
    message("info", CBOLD + CGREEN +
      "Your life is drained and given to "+
      who_shadowed->query_name(),
      from);
    message("info", CBOLD + CGREEN +
      from->query_name() +" is drain of "+
      hp+" life which is given to you!",
      who_shadowed);

    from->add_hp(-1 * hp);
    who_shadowed->add_hp(hp);
    remove();
}

int do_damage(string limb, int amt) 
{
    int res;
    object prev;
    res = (int)next_shadow()->do_damage(limb, amt);

    if(who_shadowed->query_hp() < who_shadowed->query_max_hp() / 4 
      && who_shadowed->query_current_attacker())
	do_vigilance();
    return res;
}

void expire_just(object me) 
{
    if(me != this_object()) 
    {
	next_shadow()->expire_just(me);
	return;
    }
    if(exp_mesg)
	message("info", exp_mesg, who_shadowed);
    remove();
    return;
}


