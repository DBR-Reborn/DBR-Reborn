#include <security.h>
#include <std.h>
#include <colors.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string *affected_skills = ({});

int mod = 75;

void create() {
    seteuid(getuid());
    return;
}

set_power(int x){mod = x;}

string * query_af_skills(){
    return affected_skills;
}

void setup_skills(){
    string *skills;
    int i;
    int ob;
    skills = who_shadowed->query_all_skills();

    for(i = 0; i < sizeof(skills); i++){
	affected_skills += ({skills[i]});
    }
}

void end_curse(object me) {
    if(me != this_object()) {
	next_shadow()->end_curse(me);
	return;
    }

    message("info", 
      CBOLD + CMAGENTA + 
      "The curse wears off.",
      who_shadowed);
    remove();
    return;
}

int start_shadow(object ob, int duration) {
    if(!objectp(ob)) return 0;
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    who_shadowed = ob;
    setup_skills();
    call_out("end_curse", duration, this_object());

    return 1;
}

int query_skill(string str){
    if(member_array(str, affected_skills) != -1)
	return (next_shadow()->query_skill(str) 
	  * mod / 100);
    return next_shadow()->query_skill(str);

}

void revive() {
    next_shadow()->revive();
    remove();
    return;
}


