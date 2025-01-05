#include <std.h>

/* This is one of many spellbooks that are placed in the black keep's arch mage room. This book discusses the nature of area spells, and has no special use */

inherit OBJECT;

void create() {
::create();
set_name("spellbook");
set("id", ({ "book", "spellbook", "brown book", "brown spellbook" }));
set_short("A brown spellbook");
set_long("You open the brown spellbook and flip a few pages.\n\n     A well trained Arch Mage beyond the skill of an intermediate has the ability to spread his or her magic to assault multiple targets, and keep the full effects of their total magical powers. Some examples of this are the ability to summon a ball of fire just as if it was going to be used as a typical fireball to be fired against a single enemy, and then make it violently explode striking more enemies equally. Another example is the power to call forth multiple daggers of ice, and instead of firing them directly in a horizontal direction, to shatter them in mid air creating a vicious blizzard. The most powerful example however of harnessing power against many targets is calling meteors from the space above the realm, calling them to crash and explode where he wishes in a storm that appears to come from a nightmare.");
set_weight(200);
set_value(50000);
}
