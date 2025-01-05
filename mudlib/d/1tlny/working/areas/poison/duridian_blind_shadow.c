#include <security.h>
 
inherit "/std/spells/shadows/shadow";
 
object who_shadowed;
string exp_mesg;
 
void create() {
   seteuid(getuid());
   return;
}
 
void start_shadow(object who, int dur, string mesg) {
   seteuid(UID_SHADOW);
   begin_shadow(who);
   who_shadowed = who;
   seteuid(getuid());
   exp_mesg = mesg;
   if(dur) call_out("expire_blind", dur, this_object());
   return;

}
 
int query_sight_bonus() { return -100; }
 
void revive() {
  next_shadow()->revive();
  remove();
  return;
}
 
void expire_blind(object me) {
  if(me != this_object()) {
     next_shadow()->expire_blind(me);
     return;
  }
  if(exp_mesg) message("info", exp_mesg, who_shadowed);
  remove();
  return;
}

