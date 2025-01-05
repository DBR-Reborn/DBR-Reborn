// Drow Village
#include "../newshards.h"
inherit MONSTER;
 
void create() {
   ::create();
     set_name("mage");
     set("id", ({"mage"}) );
   set_level(18+random(3));
     set("short", "The Mage");
     set("long", "This old woman seems to carry the weight of the world on her shoulders, judging from her sad eyes. She seems to want to tell you something - maybe you should 'listen'."
   );
     set("race", "human");
   set_gender("female");
   set_alignment(0);
   set_money("silver", random(50)+150);
     set_body_type("humanoid");
   set_wielding_limbs( ({"right hand", "left hand"}) );
	set_skill("melee", 120);
	set_skill("parry", 100);
	set_skill("attack", 100);
	set_skill("dodge", 80);
	set_skill("block", 70);
set_lang_prof("common",5);
force_me("speak common");
}
 void init() {
    ::init();
    add_action("listen_fun", "listen");
}

int listen_fun() {
    write("The woman begins her story:\n\n'Welcome to New Shards. This is our home now. You see, when we sent the ring to the gnomes via a magic portal spell. Fortunately or unfortunately, depending on how you look at it, the last people remaining in Shards were shifted to another dimension, and apparently, a few hundred years into the future.'\n\n'The problem is,' she continues, 'is that this is the plane where the demons are from. It's quite dangerous here, and many have been killed by roaming beasts. Nowadays, we just try to eke out a living from the land and survive.'\n\n'However, we have found something of interest,' she says, pulling out a shiny gem. 'While our mines do not produce ore of any kind, they do produce gems. They are quite valuable, but we have not decided what we will do with them... yet. They seem to have some magical qualities.'");
    this_player()->move(ROOMS+"girlsroom");
    return 1;
}
