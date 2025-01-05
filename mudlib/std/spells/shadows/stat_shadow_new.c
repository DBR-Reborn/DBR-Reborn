//	A user shadow that can be cloned and used to temporarily 
//	modify a player stat.  Configured so it is cumulative with other
//	such shadows.
//	DarkeLIB 0.1
//	Diewarzau 3/27/94
// TLNY2020 REMADE to work with crit tables

#include <security.h>
inherit "/std/spells/shadows/shadow";

string stat;
string mesg;
string stack_key;
int mod;
object who_shadowed;

void create() {
	seteuid(getuid());
	stat = "";
	mod = 0;
}

void set_expire_message(string message) { mesg = message; }

void set_stat(string arg) { stat = arg; }

void set_mod(int arg) { mod = arg; }


void set_stack_key(string str) { stack_key = str; }

int query_stack(string key) {
  int res;
  
  if(key != stack_key || !stack_key) return (int)next_shadow()->query_stack(key);
  res = (int)next_shadow()->query_stack(key);
  if(res) res++;
  else res = 1;
  return res;
}
/*
int start_shadow(object ob, int duration, string expire_msg) {
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    mesg = expire_msg;
    if(!mesg) mesg = "A spell just expired.";
    who_shadowed = ob;
    if(duration)
    delayed_call("remove",duration,this_object());
    return 1;
}
*/
void start_shadow(object ob, int duration) {
    if(!ob || !duration) return;
    seteuid(UID_SHADOW);
    shadow(ob,1);
    seteuid(getuid());
    who_shadowed = ob;
  delayed_call("remove", duration, this_object());
    return;
}


int query_stats(string str) {
    if(!stat || stat != lower_case(str)) return
	(int)next_shadow()->query_stats(str);
    return (int)next_shadow()->query_stats(str) + mod;
}

/*
void remove() {
    if(!::remove()) { return;
    message("info", mesg, who_shadowed);
}
    if(mesg && stringp(mesg))
      message("info",mesg,who_shadowed);
    remove();
    return;    
}

*/

void remove(object ob) {
    if(ob != this_object()) {
        next_shadow()->remove(ob);
	return;
    }
    if(mesg && stringp(mesg))
      message("info",mesg,who_shadowed);
    if(!::remove()) return;
}

/*
void remove() {
    if(!::remove()) return;
    if(mesg && stringp(mesg))
      message("info",mesg,who_shadowed);
    remove();

}

*/
