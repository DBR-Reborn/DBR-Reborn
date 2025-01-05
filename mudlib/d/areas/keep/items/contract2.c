#include <std.h>

/* This is a contract containing information pertaining to an assassination to be carried out by a trusted minion of Owedquar. It is located in the assassins quarters in the middle of the black keep's east wing, and is impaled into an oak table by a death dagger. Due to the passage of time, the dagger has become almost molded into the table and virtually impossible to pull out and release the contract. In order to do so, a strength stat of 350-400 is required. To obtain this, both a disciple and a paladin giving spellups is required. The contract itself is a quest item, but unlike the other items it is not used inside the area itself. It is taken to a reclusive dwarf hiding in mount nelfton along with the black axe also located in the keep to recieve the green gem for the green arcane orb. */

inherit OBJECT;

void create() {
::create();
set_name("contract");
set("id", ({ "contract", "assassins contract" }));
set_short("An assassin's contract");
set_long("This is a contract written to an undisclosed assassin. It reads:\n\n     The immediate assassination of Merik the Dwarf is to be carried out upon viewing of this contract. This is to be done by means of placing a dagger through the back while he works on repairing structural damage in the keep of Clan Shadow-Keepers. He must be eliminated before the forces of Owedquar can move in and conquer the building, for he has connections that could potentially alert a great deal of the realm that the shadow of the master has arrived here. Such information must remain supressed at all costs until the secret of the keep can be completely harnessed. As payment for this assassination, you will recieve 25000 mithril in cash which will be transferred to the bank of Daybreak Ridge.\n\n          Rancid, Lord of Demon Masters.");
set_weight(10);
set_value(100);
}
