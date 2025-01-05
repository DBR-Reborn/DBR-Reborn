inherit "/std/barkeep";

create() {
  ::create();
  set_name("");
  set_id( ({ "Kasbar", "tavern keeper" }) );
  set_short("Kasbar, the Tavern Keeper");
  set("aggressive", 0);
  set_property("enhance criticals", -10);
  set_level(15);
  set_hp(100000);
  set_max_hp(200000);
  set_exp(600000);
  set_long(@TEXT
Kasbar is huge even for a storm-giant. His battleworn 
face tells you this isn't a man to start any trouble 
with. Yet he has a friendly smile as he looks at you, 
ready to serve.
TEXT
);
   set_gender("male");
   set("race", "storm-giant");
   add_money("platinum", random(200));
   set_property("melee damage", ([ "impact" : 80 "electricity" : 80 ]));  
   set_skill("melee",200);
   set_combat_chance(80);
   set_body_type("human");
   set_currency("silver");
   set_menu( ({
        "ale", 
        "mead", 
        "whiskey", 
        "bread", 
        "mutton", 
        "steak",
        }),({ 
        "alcoholic", 
        "drink_in",  
        "drink_in", 
        "food", 
        "dine_in", 
        "dine_in",
        }),({ 
        5, 10, 15,
        6, 11, 16,
        }) );
    set_my_mess(
       ({
       "The ale is smooth with a hoppy aftertaste.\n",
       "The mead is pleasantly sweet.\n",
       "So smooth!\n",
       "The bread is soft and tasty.\n",
       "The mutton is moist and tender.\n",
       "With little exception, this is one of the best steaks you've ever had.\n"
       })
    );
    set_your_mess(
       ({
       "chugs a mug of ale.\n",
       "quaffs a tankard of mead.\n",
       "throws back a shot of whiskey.\n",
       "eats a loaf of bread.\n",
       "eats a leg of mutton.\n",
       "eats a dragon steak.\n"
       })
    );
    set_menu_short(
       ({
       "A mug of ale",
       "A tankard of mead",
       "A shot of single malt whiskey",
       "A loaf of bread",
       "A leg of mutton",
       "A dragon steak",
       })
    );
    set_menu_long(
       ({
       "The ale is brown with a thick head.\n",
       "The mead is honey golden and looks quite tasty.\n",
       "The whiskey smells strong and well-made.\n",
  "The loaf is freshly baked by Golg's wife.\n",
       "This is a juicy leg of mutton.\n",
  "This is a huge, very choice cut of USDA Choice Dragon!\n",
    }) );
}> 
