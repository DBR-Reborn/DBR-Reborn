#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
int lev, skill;

void set_power(int x) { lev = x; }

void start_shadow(object who, int dur, string mesg) 
{
  seteuid(UID_SHADOW);
  begin_shadow(who);
  who_shadowed = who;
  if(who->query_skill("conjuration")<100) skill=(who->query_skill("conjuration") + lev);
  else skill = 100 + lev;
  seteuid(getuid());
  exp_mesg = mesg;
  call_out("expire_just", dur, this_object());
  return;
}

int query_mystic_shield() { return 1; }



int do_damage(string limb, int amt) 
{
  int res;
  object prev;

  if(previous_object() && living(previous_object()))
   {
       if(random(150) < skill)
       {
        message("info","Your shields deflect the damage.",who_shadowed);
        message("info","Your hit is blocked by a floating disk!", 
                previous_object());
        return 0;
       }
   }
   res = (int)next_shadow()->do_damage(limb, amt);
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

mixed query_property(string val) {
  if(val != "enhance criticals")
    return next_shadow()->query_property(val);
  if(previous_object() && living(previous_object()))
   {
       if(random(150) < skill)
       {
        message("info","Your shields deflect the critical hit.",who_shadowed);
        message("info","Your critical hit is blocked by a floating disk!", 
                previous_object());
        return -1000;
       }
   }
  return (int)next_shadow()->query_property(val);
}

