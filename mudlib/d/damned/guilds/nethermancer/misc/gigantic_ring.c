#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("circular ring");
    set_id(({ "ring", "gigantic ring", "circular ring", "gigantic circular ring", "master nexus ring" }));
    set_short("A gigantic circular ring");
    set_long("This is an extraordinarily huge ring, large enough that the word gigantic could be appropriate for describing it. It is fashioned of a massively rare and perfectly finished marble which seems to glow endlessly with a faint and dark light. On the large top section of the ring most of the center is cut very deeply into a circular formation that by inference looks to be a place for liquid to be contained, and the main marble ring itself would serve as the method of transporting it. The entire circular object is covered almost completely by inscriptions so well engraved that the legendary inscriber truly must have intended it to be given to a legendary recipient for what can only be concieved as the most powerful rituals known to man.");
    set_property("nexus type", 3);
    set_weight(1100);
    set_value(100000);
    return;
}
