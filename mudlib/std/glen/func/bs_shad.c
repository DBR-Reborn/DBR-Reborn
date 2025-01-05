#include <security.h>
#include <std.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
int active = 0;

void bs_active(){
    active = 1;
}


void bs_inactive(){
    active = 0;
}

void create() {
    seteuid(getuid());
    return;
}

int start_shadow(object ob) {
    if(!objectp(ob)) return 0;
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    who_shadowed = ob;
    return 1;
}

int query_spell_level(string str){
    if(active)
	if(next_shadow()->query_spell_level(str) > 0)
	    return 0;
	else
	    return 0;
    return next_shadow()->query_spell_level(str);
}

int query_skill(string str){
    if(active)
	if(next_shadow()->query_skill(str) > 0)
	    return 5;
	else
	    return 0;
    return next_shadow()->query_skill(str);
}

