#include <std.h>
#include "../ruins.h"

inherit MONSTER;

create() {
    object money;
    int    zskill;
    ::create();
    set_name("rat-man shaman");
    set_id( ({ "rat-man shaman","shaman" }) );
    set_level(6);
    set_short("rat-man shaman");
    set_long("The dark, robed rat-man shaman stands before you. A hood is drawn up over his head and shadows his face from view. He is a short, stocky rat-man but you are wary of his powers." 
    );
    set("race", "rat");
    set_gender("male");
    set_body_type("human");
    set_property("melee damage", ([ "crushing" : 15]));
    zskill=random(3)*10+60;
    set_skill("melee",zskill);
    set_skill("dodge",zskill);
    set_stats("intelligence", 120);
    set_stats("wisdom", 120);
    money=new("std/obj/coins");
    // money->set_money("silver",random(zskill)+200);
    money->move(this_object());
    set_wimpy(0);
    set_alignment(-600);
    set_emotes(10, ({
	"The rat-man shaman crosses his arms.",
	"The rat-man shaman cocks his head slightly."
      }),1);
    set_class("mage");
    set_casting_chance(0);
    set_combat_chance(95);
    add_spell("magic missile","$A");
    set_spell_level("magic missile",6);
    add_spell("burning hands","$A");
    set_spell_level("burning hands",6);
    add_spell("fireball","$A");
    set_spell_level("fireball",2);
    set_skill("conjuration",85);
    set_fingers(5);
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :) );
    new("/d/damned/virtual/quarter-staff_6.weapon")->move(this_object());
    force_me("wield staff in right hand and left hand");
    new(ITEM+"shaman_robe")->
    move(this_object());
    force_me("wear robe");
    new(ITEM+"slippers")->
    move(this_object());
    force_me("wear slippers");
    new(ITEM+"shaman_hood")->
    move(this_object());
    force_me("wear hood");      
}

int chk_my_mon() { return 1;}


int no_other_monsters(object who) {
    if(who->is_player()) return 1;
    else return 0;
}


