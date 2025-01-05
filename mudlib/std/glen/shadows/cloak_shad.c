#include <security.h>
#include <colors.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
int lev;

void add_exp(){
    message("info",CBOLD + CGREEN +
      "The cloak feeds off your soul.",
      who_shadowed);
}
void add_exp2(){
    message("info",CBOLD + CGREEN +
      "The cloak feeds off your soul.",
      who_shadowed);
}

void start_shadow(object who, int dur, string mesg) 
{
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    return;
}
int do_damage(string limb, int amt) 
{
    int res;
    object prev;

    if(previous_object() && living(previous_object()))
    {
	if(random(2) && who_shadowed->query_mp() > 0)
	{
	    message("info",CBOLD + CGREEN +
	      "The cloak absorbs the damage!.",who_shadowed);
	    message("info",CBOLD + CGREEN +
	      "Your hit seems to do nothing.", 
	      previous_object());
	    who_shadowed->add_hp(amt);
	    who_shadowed->add_mp(-1 * amt / 2);
	    return 0;
	}
    }
    res = (int)next_shadow()->do_damage(limb, amt);
    return res;
}

void expire_cloak() 
{
    remove();
    return;
}

