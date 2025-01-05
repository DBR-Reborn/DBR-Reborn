//drizzt.c coder:Byon
#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("drizzt");
    set_id( ({"drizzt","drizzt do'urden","elf","drow"}) );
    set_short("Drizzt Do'Urden");
    set_level(30);
    set("long", "The legendary drow ranger, Drizzt Do'Urden");
    set_skill("dual attack", 200);
    set_skill("blade", 250);
    set_stats("dexterity", 400);
    set_gender("male");
    set("race", "drow-elf");
    set_property("ambidextry", 1);
    set_alignment(400);
    set_wielding_limbs( ({"right hand","left hand"}) );
    set_body_type("human");
    new("/wizards/byon/misc/twinkle.c")->move(this_object());
      force_me("wield scimitar in left hand");
    new("/wizards/byon/misc/icingdeath.c")->move(this_object());
      force_me("wield scimitar in right hand");
}
