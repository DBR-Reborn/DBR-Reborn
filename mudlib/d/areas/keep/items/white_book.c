#include <std.h>

/* This is one of the spellbooks that resides in the arch mage room of the black keep. This book discusses the arch mages ability to lock scries, summon, and teleport. This is also a secret that is required to proceed in the keep's quest. When this book is taken to the keep's librarian in the basement level, he will give the player the holy soul item needed to continue the quest. */

inherit OBJECT;

void create() {
::create();
set_name("spellbook");
set("id", ({ "book", "spellbook", "white book", "white spellbook" }));
set_short("A white spellbook");
set_long("You open the white spellbook and flip a few pages.\n\n     An Arch Mage in addition to their offensive prowess with magical energy, possesses a power shared with the dark assassins, the ability to transport to and summon various targets from anywhere in the known realm. However, this is impossible to do without intensive preparation. Most aspiring magi think that telekinesis is required for this task based on their studies in speaking power words, but in truth it plays no part. To prevail in this art, a magical target lock called a scry is required to eliminate all uncertainty. To achieve a scry, an Arch Mage must deeply focus time energy, enough to distort space time, and leave their body to search the alternate identical frozen realm for the target. Once the target is found, the Arch Mage returns with the knowledge of the location. With the scry in place, the Arch Mage once again gathers energy to disrupt time and carries the new knowledge to complete the teleport or summon with no factor of uncertainty.");
set_weight(200);
set_value(50000);
}
