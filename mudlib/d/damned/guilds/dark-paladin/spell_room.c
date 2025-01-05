inherit "/std/guilds/spell_room";
#include "/d/damned/guilds/dark-paladin/dark-paladin.h"

void create() {
::create();
set_short("The Dark Paladins' Spell Training Room");
set_long("This is the small room where the Dark Paladins of Owedquar practice their deadly magics to overthrow the reign of the divine gods over Daybreak Ridge. Countless inscriptions cover the walls instructing those worthy enough how to learn them.\n");
set_property("light", 2);
set_property("indoors", 1);
set_join_room("/d/damned/guilds/join_rooms/dark-paladin_join");
add_exit("/d/damned/guilds/join_rooms/dark-paladin_join", "east");
add_spell("shadow bolt", 1);
add_spell("mist cloud", 3);
add_spell("owedquar's eyes", 3);
add_spell("summon shadow weapon", 3);
add_spell("holy ward", 4);
add_spell("curse vision", 7);
add_spell("anger charge", 7);

//8
add_spell("dark weapon", 8);
//9
add_spell("shadow edge", 9);
//10
add_spell("dark assault", 10);
//12
add_spell("unholy rage", 12);
add_spell("black shroud", 12);
//13
add_spell("lesser shadow field", 13);
//14
add_spell("summon black weapon", 14);
//15
add_spell("owedquar's fury", 15);
//16
add_spell("owedquar's might", 16);
//17
add_spell("black fire", 17);
//18
add_spell("black edge", 18);
//20
add_spell("dark pact", 20);
add_spell("shadow field", 20);
//23
add_spell("summon holy bane", 23);
//25
add_spell("abyss blast", 25);
//27
add_spell("absorption", 27);
add_spell("greater shadow field", 27);
//28
add_spell("abyss blade", 28);
//30
add_spell("storm of ages", 30);
add_spell("owedquar's wrath", 30);
//31
add_spell("power of darkness", 31);
//35
add_spell("soul crush", 35);

return;
}

