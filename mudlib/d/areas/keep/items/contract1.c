#include <std.h>

/* This contract is a special version of the contract that is present in the assassins quarters of the black keep. This is the contract that is on display for players to read the information, but it cannot be taken due to the dagger in the room. When the dagger is removed, this contract will be removed and contract2.c, the obtainable one which contains all the quest information pertaining to the contract in its file, will be cloned in its place. */

inherit OBJECT;

void init() {
::init();
add_action("get", "get");
}

int get(string str) {
if(id(str)) {
message("my_action", "You cannot take the contract as long as the dagger is impaled through it.", this_player());
return 1;
}
}

void create() {
::create();
set_name("contract");
set("id", ({ "contract", "assassins contract" }));
set_short("An assassin's contract");
set_long("This is a contract written to an undisclosed assassin. It reads:\n\n     The immediate assassination of Merik the Dwarf is to be carried out upon viewing of this contract. This is to be done by means of placing a dagger through the back while he works on repairing structural damage in the keep of Clan Shadow-Keepers. He must be eliminated before the forces of Owedquar can move in and conquer the building, for he has connections that could potentially alert a great deal of the realm that the shadow of the master has arrived here. Such information must remain supressed at all costs until the secret of the keep can be completely harnessed. As payment for this assassination, you will recieve 25000 mithril in cash which will be transferred to the bank of Daybreak Ridge.\n\n          Rancid, Lord of Demon Masters.");
set_property("no get", 1);
set_weight(10);
set_value(100);
}
