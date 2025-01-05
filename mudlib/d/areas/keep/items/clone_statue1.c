#include <std.h>

/* This is one of the five statues in the clone statue room of the black keep that carries a weapon. It cannot be carried away, and serves no special purpose but for decoration and observation for quest clues. The sixth statue in the room which does not carry a weapon does have an important part however */

inherit OBJECT;

void create() {
::create();
set_name("statue");
set("id", ({ "statue", "statue 1", "statue 2", "statue 3", "statue 4", "statue 6", "imposing statue", "imposing statue 1", "imposing statue 2", "imposing statue 2", "imposing statue 3", "imposing statue 4", "imposing statue 6", "stone statue", "stone statue 1", "stone statue 2", "stone statue 3", "stone statue 4", "stone statue 6", "imposing stone statue", "imposing stone statue 1", "imposing stone statue 2", "imposing stone statue 3", "imposing stone statue 4", "imposing stone statue 6" }));
set_short("An imposing stone statue");
set_long("This is a very large statue of an battle hardened warrior fashioned completely of stone, standing approximately eight feet tall. Its body is molded to appear as if it is wearing very well crafted armour, and an enormous polearm axe rests vertically in its left hand."); 
set_weight(10000000);
set_value(0);
}
