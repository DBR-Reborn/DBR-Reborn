#include <std.h>

/* This is one of the several spellbooks located in the arch mage room of the black keep. It discusses the nature of single target magic and has no special use. */

inherit OBJECT;

void create() {
::create();
set_name("spellbook");
set("id", ({ "book", "spellbook", "green book", "green spellbook" }));
set_short("A green spellbook");
set_long("You open the green spellbook and flip a few pages.\n\n     The Arch Mage is the chosen being to carry the greatest single element focusing power, even more so than an elementalist. Nearly all conventional elements can be used for this purpose, however the greatest ones such as aether and nexus cannot. Some powers the Arch Mage can harness is the ability to call forth powerful lightning from the sky to strike anyone anywhere in the world. They can also compact fire into balls that can be fired directly at an attacker, the same true with ice being shaped into daggers. If honed enough, the greatest Arch Mages can even summon fire from think air inside someone, destroying them from within."); 
set_weight(200);
set_value(50000);
}
