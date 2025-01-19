#include <std.h>

inherit "/std/weapon";

create() {
    ::create();
    set_ac(3);
    set("id", ({ "spitter", "deathspitter" }));
    set_name("deathspitter");
    set("short", "Deathspitter");
    set("long",
      "This strange weapon is clearly alive!  It looks vaguely like a serpent\n"
      +"or lizard, the legs forming the grip, and the tail curling around your\n"
      +"arm for stability.  Needle-sharp teeth make up the striking end,\n"
      +"dripping with toxic looking secretions.  A nasty little weapon all in\n"
      +"all.\n");
    set_type("knife");
    set_quality(5);
    set_property("no decay",1);
    set_property("no add quality",1);
    set_wc(10, "impaling");
    add_poisoning(10+random(10));
    set_verb("nick");
    set_hit_bonus(10);
    set_weight(100);
    set_value(150);
    set_material("/misc/chitin");
    set_wield(
      "The tiny claws dig into the palm of your hand and the tail wraps tightly\n"
      +"around your wrist ensuring that your grip on this weapon is firm indeed.\n");
    set_unwield(
      "You carefully pry the claws from your skin and unwind the tail from your\n"
      +"wrist, being careful not to let the gnashing teeth catch you in the\n"
      +"process.\n");
    return;
}
