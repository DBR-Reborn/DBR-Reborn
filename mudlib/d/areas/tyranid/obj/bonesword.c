#include <std.h>

inherit "/std/weapon";

create() {
    ::create();
    set_ac(3);
    set("id", ({ "sword", "bone sword" }));
    set_name("sword");
    set("short", "Bone Sword");
    set("long", 
      "At first glance, this weapon looks like a simple sword.  On closer\n"
      +"inspection though, you realize that it is a complete, living organism!\n"
      +"The small body serves as the grip of the sword.  The large head, incased\n"
      +"in bony plates, serves as the handguard, and the five-foot blade is a\n"
      +"single razor sharp tooth!  As you touch the blade, the weapon's tiny\n"
      +"brain encases the blade in a shimmering field of psionic energy.\n");
    set_type("blade");
    set_quality(5);
    set_property("no decay",1);
    set_property("no add quality",1);
    set_wc(15, "cutting");
    set_wc(10, "impaling");
    set_wc(10, "stress");
    set_verb("slash");
    set_parry_bonus(5);
    set_weight(100);
    set_value(200);
    set_material("/misc/chitin");
    set_wield(
      "Bony plates in the 'hilt' shift to accomdate your grip.  Tiny tendrils\n"
      +"snake out from the gaps and wrap themselves securely around your fingers.\n"
      +"As the weapon begins to vibrate in your hand you are glad to have the\n"
      +"extra support.\n");
    set_unwield(
      "After several seconds of effort you manage to tear your fingers away\n"
      +"from the tiny tentrils which then withdraw into their bony housings.\n"
      +"Looking at your hands you notice rows of tiny bleeding holes on\n"
      +"your fingers...\n");
    return;
}
