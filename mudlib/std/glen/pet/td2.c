#include <std.h>
#include <colors.h>

inherit MONSTER;


query_num_rounds(){
    return -2;
}

int die(){
    return 0;
}

int do_damage(string limb, int amt) 
{
    int res;
    object prev;
    force_me("speak common");
    force_me("say " +
      "dam:" + amt + " " + limb);
    return 0;
}


create() {
    object ob, obw;
    ::create();
    set_name("testdummy");
    set_id(({"test", "dummy"}));
    set_short("test dummy");
    set_long("Smack me around for a good time");
    set_level(1);
    set_body_type("human");
    set("race", "human");
    set_gender("male");
    set_property("enhance criticals", -10);
}

void spell_cast(string spell, int skill, object who){
    force_me("say " +
      spell + " " + skill + " " +
      who->query_cap_name());
}
