#include <security.h>
#include <std.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string *affected_skills = ({});

int query_is_crippled(){
    return 1;
}

void create() {
    seteuid(getuid());
    return;
}

string * query_af_skills(){
    return affected_skills;
}

void setup_skills(){
    string *skills;
    string sname;
    int i, j;
    int ob;
    string *skf = ({"dexterity", "strength", "constitution"});
    skills = who_shadowed->query_all_skills();

    for(i = 0; i < sizeof(skills); i++){
	sname = "/std/skills/" + skills[i];
	if (find_object(sname))
	    for(j = 0; j < sizeof(skf); j++)
		if(find_object(sname)->query_stat() == skf[j])
		    affected_skills += ({skills[i]});
    }
}

int start_shadow(object ob) {
    if(!objectp(ob)) return 0;
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    who_shadowed = ob;
    setup_skills();
    return 1;
}

int query_skill(string str){

    if(member_array(str, affected_skills))
	return (next_shadow()->query_skill(str)*2/3);

    return next_shadow()->query_skill(str);

}

void revive() {
    next_shadow()->revive();
    remove();
    return;
}

