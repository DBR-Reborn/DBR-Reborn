#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
int lev, skill;


void start_shadow(object who, int dur, string mesg) 
{
  seteuid(UID_SHADOW);
  begin_shadow(who);
  who_shadowed = who;
  if(who->query_skill("tumble")<100) skill = (who->query_skill("tumble"));
  else skill = 100;
  seteuid(getuid());
  exp_mesg = mesg;
  call_out("expire_just", dur, this_object());
  return;
}

int query_tumbling() { return 1; }

int do_damage(string limb, int amt) 
{
  int res, xx;
  object prev;

  xx = random(150);
  if(previous_object() && living(previous_object()))
   {
       if(xx < (skill/4))
       {
        message("info","%^YELLOW%^You dive out of the way and avoid taking damage at all.",who_shadowed);
        message("info", "%^YELLOW%^"+who_shadowed->query_cap_name()+" dives out out of the way of your attack and avoids taking damage.", previous_object());
        return 0;
       }
       else if(xx < (skill/2))
       {
        message("info","%^YELLOW%^You dive out of the way and avoid taking the majority of the damage.",who_shadowed);
        message("info", "%^YELLOW%^"+who_shadowed->query_cap_name()+" dives out out of the way of your attack and avoids taking the majority of the damage.", previous_object());
        return (amt/4);
       }
       else if(xx < skill)
       {
        message("info","%^YELLOW%^You dive out of the way and avoid taking some of the damage.",who_shadowed);
        message("info", "%^YELLOW%^"+who_shadowed->query_cap_name()+" dives out out of the way of your attack and avoids taking some of the damage.", previous_object());
        return (amt/2);
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
  int xx;

  if(val != "enhance criticals") return next_shadow()->query_property(val);
  xx = random(150);
  if(previous_object() && living(previous_object()))
   {
       if(xx < (skill/4))
       {
        message("info","%^RED%^You quickly dive out of the way avoiding the critical hit completely",who_shadowed);
        message("info","%^RED%^"+who_shadowed->query_cap_name()+" dives out of the way avoiding your critical hit.", previous_object());
        return -1000;
       }
       else if(xx < (skill/2))
       {
        message("info","%^RED%^You quickly dive out of the way mostly avoiding the critical hit",who_shadowed);
        message("info","%^RED%^"+who_shadowed->query_cap_name()+" dives out of the way mostly avoiding your critical hit.", previous_object());
        return -6;
       }
       else if(xx < skill)
       {
        message("info","%^RED%^You quickly dive out of the way partially avoiding the critical hit",who_shadowed);
        message("info","%^RED%^"+who_shadowed->query_cap_name()+" dives out of the way partially avoiding your critical hit.", previous_object());
        return -4;
       }


   }
  return (int)next_shadow()->query_property(val);
}
