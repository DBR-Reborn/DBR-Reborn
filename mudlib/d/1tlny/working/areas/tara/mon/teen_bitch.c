#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit MONSTER;

void create() {
  string var;
  ::create();
   set_name("teen");
   set("id", ({"halfling", "girl", "bitch", "teen", "teenager"}) );
   set_level(2);
   set("short", "A teenage girl");
   set("race", "halfling");
   set("long", @BITCH
Here is a stuck up teenager.  She spends most of her time, spending
the money of her parents shopping.  She wears an expensive dress,
tight fitting, and made to the current fashion.  Although she is
pretty, the spoiled look on her face removes her appeal.
BITCH
   );
   set_gender("female");
   set_money("silver", random(15)+50);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
     ({
      "The girl exclaims, 'Johny wore the same shirt he wore two "+
      "weeks ago, I would be so ashamed!",
      "The teenager ignores you as she examines her nails.",
      "The girl says, 'I'm too good for this town.'",
      "The halfling whines, 'Almost out of my favorate perfume.'",
      "The halfling teen looks over her hat rack.",
     }), 0);
   set_achats(20,
     ({
      "The teen shrieks as she breaks a nail.",
      "The girl yells for her parents.",
      "The halfling growls, 'Get out of my room!'",
      "The teenager tries to escape into her closet.",
     }) );
   new(TARAOBJ+"teen_dress")->move(this_object());
   force_me("wear dress");
   new(TARAOBJ+"girl_hat")->move(this_object());
   force_me("wear hat");
}
