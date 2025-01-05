#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;

void start_shadow(object who, int skill) {
  seteuid(UID_SHADOW);
  begin_shadow(who);
  who_shadowed = who;
  seteuid(getuid());
  if (skill >= 200) {
  return; } else {
   call_out("end_skill", skill , this_object());
  return; 
  }
}

void end_skill(object me) {
  if(me != this_object()) {
    next_shadow()->end_skill(me);
    return;
  }
  message("info", "%^COLOR220%^You slow back down.",
        who_shadowed);
  remove(this_object());
  return;
}

int query_num_rounds() {
  int rounds;
  
  rounds =  1;
  return (rounds > 2)?2:rounds;
}

