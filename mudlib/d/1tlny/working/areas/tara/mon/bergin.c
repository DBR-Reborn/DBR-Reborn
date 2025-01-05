inherit "/std/barkeep";
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_name("bergin");
   set_id( ({ "bergin", "tavern keeper", "halfling" }) );
   set_short("Bergin, the halfling Tavern Keeper");
   set_level(11);
   set_gender("male");
   set("race", "halfling");
   set_body_type("human");
   set("long",
"Bergin is the successful owner and tavern keeper of Tara's "
"Tavern.  He does his job well, serving alcoholic beverages and good "
"food to fill those drunk stomaches.  He stands behinds his bar.");
   add_money("silver", random(300));
   set_currency("silver");
   set_menu( ({
    "stew",
    "ale",
    "wine",
    "beef",
    "tequila",
    "cheese",
    }),({
    "dine_in",
    "alcoholic",
    "drink_in",
    "dine_in",
    "drink_in",
    "food",
    }),({
      6, 6, 16,
      20, 25, 10,
    }) );
   set_my_mess(
    ({
    "The bowl of stew is very good, the perfect mix of herbs and spices.\n",
    "The halflings ale isnt the best, but it does the job.\n",
    "Cheers.\n",
    "A bit dry, but pretty filling.\n",
    "The tequila is strong, and very sour.\n",
    "The cheese is fresh and delicious.\n"
    })
   );
   set_your_mess(
    ({
    "wolfs down a bowl of stew.\n",
    "drinks down a mug of ale.\n",
    "toasts, then drinks some wine.\n",
    "eats a big portion of beef.\n",
    "downs some tequila, and gets a sour look on his face.\n",
    "eats a hunk of cheese.\n"
    })
   );
   set_menu_short(
    ({
    "A bowl of stew",
    "A mug of halfling ale",
    "A glass of wine",
    "A large portion of beef",
    "A shot of tequila",
    "A chunk of cheese",
    })
   );
   set_menu_long(
    ({
    "The thick stew steams in its bowl.\n",
    "The mug of ale looks second-class.\n",
    "A fancy glass of wine, great for celebrating.\n",
    "The large ammount of beef appears somewhat dry.\n",
    "Very strong tequila, this is the good stuff.\n",
    "Cheese made in the outlying farms, and sold directly to Bergin.\n",
   }) );
}
