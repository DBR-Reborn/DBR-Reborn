#include <std.h>
inherit MONSTER;

void create() {
       string var;
       int HPBASE, LEV;
       object cloak, hammer;

       HPBASE = 80;

       ::create();
       seteuid(geteuid());
       set_name("slave");
       set("id", ({"slave", "quarry slave" }) );
       set_level(9 + random(3));
       switch(random(8)) {
               case 0: var = "A muscular slave"; break;
               case 1: var = "A hard-working slave"; break;
               case 2: var = "An ugly slave"; break;
               case 3: var = "A strong slave"; break;
               case 4: var = "A working slave"; break;
               case 5: var = "A dirty slave"; break;
               case 6: var = "A dusty slave"; break;
               case 7: var = "A fierce slave"; break;
       }
       this_object()->set("short", var);
       set("long", @EndText
This is one of the quarry slaves. Bulky muscles show
that he has been working very hard for a long time in
this place. He is not looking undernourished though,
so the storm-giants must be feeding him decently.
EndText
);
       switch(random(9)) {
               case 0: var = "drow-elf"; break;
               case 1: var = "half-ogre"; break;
               case 2: var = "half-orc"; break;
               case 3: var = "wraith"; break;
               case 4: var = "troll"; break;
               case 5: var = "ogre"; break;
               case 6: var = "half-troll"; break;
               case 7: var = "dark-tribe"; break;
               case 8: var = "gerudan"; break;
       }
       this_object()->set("race", var);
       set_gender("male");
       set_body_type("human");
       set_wielding_limbs( ({"right hand", "left hand"}) );
       set_class("fighter");
       
       set_hp(HPBASE * (int)this_player()->query_level());
       set_max_hp(HPBASE * (int)this_player()->query_level());

       LEV = (int)this_player()->query_level();
       set_skill("blunt", LEV * 6);
       set("aggressive", 0);
       set("gang bang", 0);
       cloak = new("/d/damned/virtual/cloak.armour");
       cloak -> move(this_object());
       cloak -> set("short", "A slave cloak");
       cloak -> set("long", "This is a cloak worn by the slaves of the storm-giant quarry.");
       command("wear cloak");
       hammer = new("/d/damned/virtual/hammer_3.weapon");
       hammer -> move(this_object());
       hammer -> set("long", "This is a hammer used for working with rock.");
       command("wield hammer in left hand");
       set_emotes(1, ({"A slave pounds the rock with his hammer.","A slave eyes you suspiciously.", "A slave points at you with his hammer." }), 0 );
}

int chk_my_mob() {
       return 1;
}

