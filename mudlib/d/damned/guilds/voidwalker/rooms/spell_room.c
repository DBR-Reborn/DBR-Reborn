inherit "/std/guilds/spell_room";
#include "/d/damned/guilds/voidwalker/voidwalker.h"

void create() {
::create();
set_short("The Voidwalker's Spell Training Room");
set_long("This is the small room where the Voidwalkers of the Rift practice their deadly magics to overthrow the reign of the divine gods over Daybreak Ridge. Countless inscriptions cover the walls instructing those worthy enough how to learn them.\n");
set_property("light", 2);
set_property("indoors", 1);
set_join_room("/d/damned/guilds/join_rooms/voidwalker_join");
add_exit("/d/damned/guilds/join_rooms/voidwalker_join", "east");
add_spell("vacuum blast", 1);
add_spell("mist cloud", 3);
add_spell("oberon's eyes", 3);
add_spell("summon vacuum weapon", 3);
add_spell("time ward", 4);
add_spell("blur vision", 7);
add_spell("anger charge", 7);

//8
add_spell("void weapon", 8);
//9
add_spell("vacuum edge", 9);
//10
add_spell("dark assault", 10);
//12
add_spell("void rage", 12);
add_spell("black cloud", 12);
//13
add_spell("lesser void field", 13);
//14
add_spell("summon void weapon", 14);
//15
add_spell("oberon's fury", 15);
//16
add_spell("oberon's might", 16);
//17
add_spell("black winds", 17);
//18
add_spell("void edge", 18);
//20
add_spell("void pact", 20);
add_spell("void field", 20);
//23
add_spell("summon voidmaker", 23);
//25
add_spell("abyss blast", 25);
//27
add_spell("absorption", 27);
add_spell("greater void field", 27);
//28
add_spell("abyss blade", 28);
//30
add_spell("storm of ages", 30);
add_spell("oberon's wrath", 30);
//31
add_spell("power of void", 31);
//35
add_spell("soul crush", 35);

return;
}

