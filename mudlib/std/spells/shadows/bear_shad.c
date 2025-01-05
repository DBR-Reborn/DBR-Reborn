#define REAL_CAP ({ "/cmds/mortal/_tell", "/cmds/mortal/_reply" })
#define REAL_SHORT ({ "/cmds/mortal/_who" })

#include <security.h>
inherit "/std/spells/shadows/shadow";

object who_shadowed;
int pow;
string message;
static int fumble;

void set_fumble() { fumble = 1; }

void create() {
    seteuid(getuid());
    return;
}

string query_cap_name() {
    int i = 0;
    object ob;

    while(ob=previous_object(i++)) if(member_array(base_name(ob), REAL_CAP) >= 0) return (string)next_shadow()->query_cap_name();
    return "Bear"; 
}

string query_short() {
    int i = 0;
    object ob;

      while(ob=previous_object(i++)) if(member_array(base_name(ob), REAL_SHORT) >= 0) return (string)next_shadow()->query_short();
    return "A bear";
}

int start_shadow(object ob, int dur, string msg) {
    if(!objectp(ob)) return 0;
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    who_shadowed = ob;
    message = msg;
    call_out("expire_me", dur, this_object());
    return 1;
}

void expire_me(object what) {
    if(what != this_object()) {
        next_shadow()->expire_me(what);
        return;
    }
    if(message) message("info", message, who_shadowed);
    remove();
}

int query_num_rounds() {
    int res = 1;
    if(fumble) res = 0;
    if(next_shadow()) return((int)next_shadow()->query_num_rounds() + res);
    return res;
}
