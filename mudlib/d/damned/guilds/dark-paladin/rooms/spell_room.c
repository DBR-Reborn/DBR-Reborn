inherit "/std/guilds/spell_room";
#include "/wizards/cythug/dark-paladin/dark-paladin.h"

void create() {
::create();
set_short("The Dark Paladins' Spell Training Room");
set_long("This is the small room where the Dark Paladins of Owedquar practice their deadly magics to overthrow the reign of the divine gods over Daybreak Ridge. Countless inscriptions cover the walls instructing those worthy enough how to learn them.\n");
set_property("light", 2);
set_property("indoors", 1);
set_join_room("/d/damned/guilds/join_rooms/dark-paladin_join");
add_exit("/d/damned/guilds/join_rooms/dark-paladin_join", "south");
add_spell("shadow bolt", 1);
add_spell("mist cloud", 3);
add_spell("owedquar's eyes", 3);
add_spell("summon shadow weapon", 3);
add_spell("holy ward", 4);
add_spell("curse vision", 7);
add_spell("anger charge", 7);
add_spell("dark assault", 10);
add_spell("dark weapon", 12);
add_spell("unholy rage", 12);
add_spell("black shroud", 12);
add_spell("lesser shadow field", 15);
add_spell("summon black weapon", 14);
add_spell("owedquar's fury", 20);
add_spell("owedquar's might", 22);
add_spell("black fire", 24);
add_spell("black edge", 28);
add_spell("shadow field", 30);
add_spell("dark pact", 30);
add_spell("cause weakness", 35);
add_spell("summon holy bane", 37);
add_spell("abyss blast", 39);
add_spell("absorption", 42);
add_spell("greater shadow field", 45);
add_spell("abyss blade", 48);
add_spell("storm of ages", 50);
add_spell("owedquar's wrath", 50);
add_spell("power of darkness", 52);
add_spell("soul crush", 57);
return;
}
