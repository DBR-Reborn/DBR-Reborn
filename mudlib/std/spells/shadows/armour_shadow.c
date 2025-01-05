// generic armour shadow
// by glen

#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string expire_mesg;
mapping extra_ac;
int extra_enchant;
string stack_key;

mixed query_property(string what);

void set_stack_key(string str) {
    stack_key = str;
}

int query_stack(string key) {
    int res;

    res = (int)next_shadow()->query_stack(key);
    if(key != stack_key) return res;
    if(!res) res = 1;
    else res++;
    return res;
}

void set_enchantment(int x) { extra_enchant = x; }

void set_extra_ac(mapping ac) { extra_ac = ac; }

void add_extra_ac(string type, int amt) {
    if(!extra_ac) extra_ac = ([]);
    if(!extra_ac[type]) extra_ac += ([ type : amt ]);
    else extra_ac[type] = amt + extra_ac[type];
    return;
}

mapping query_all_ac() {
    mapping tmp;
    int i;
    string *ac_keys;

    tmp = (mapping)next_shadow()->query_all_ac();
    if(!tmp) tmp = ([]);
    if(!extra_ac) return tmp;
    i = sizeof(ac_keys = keys(extra_ac));
    while(i--) {
	if(tmp[ac_keys[i]]) tmp[ac_keys[i]] += extra_ac[ac_keys[i]];
	else tmp += ([ ac_keys[i] : extra_ac[ac_keys[i]] ]);
    }
    // add in enchantment
    ac_keys = keys(tmp);
    for(i = 0; i < sizeof(ac_keys); i++)
        tmp[ac_keys[i]] += extra_enchant;

    return tmp;
}
string *query_ac_types() {
    if(!mapp(extra_ac)) return (string *)next_shadow()->query_ac_types();
    return distinct_array(keys(extra_ac) + (string*)next_shadow()->query_ac_types());
}

int query_ac(string type) {
    int res;

    res = (int)next_shadow()->query_ac(type);
    if(extra_ac && extra_ac[type]) res += extra_ac[type];
    return res + extra_enchant;
}

varargs void start_shadow(object what, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(what);
    who_shadowed = what;
    seteuid(getuid());
  if(dur) call_out("expire_weap", dur, this_object());
    if(mesg) expire_mesg = mesg;
    return;
}

void expire_weap(object me) {
    object who;

    if(me != this_object()) {
	next_shadow()->expire_weap(me);
	return;
    }
    if(objectp(who = who_shadowed->query_worn()) && expire_mesg)
	message("info", expire_mesg, who);
    remove();
    return;
}


