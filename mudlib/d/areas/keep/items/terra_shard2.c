#include <std.h>
#include "../keep.h"

/* This is one of the three shards obtained from the arcane orbs required to forge the legend key in the black keep. This shard is retrieved by activating the green arcane orb with the green gem found from the dwarves far away on mount nelfton. The shard once obtained is taken to the paladin temple room of the black keep and offered to Sacrel by a paladin. However, unlike the offerings for the shards of Power and Life, when the shard is first offered a powerful monster called the Icefire Hydra appears as a mini boss. Only when this creature is defeated can the shard be offered again and then blessed. After being blessed the playe recieved terra_shard2.c, and the shard is taken to the Shadowforge in the center of the keep and forged by a merchant into the legend key. */

inherit OBJECT;

void create() {
::create();
set_name("terra shard");
set("id", ({ "shard", "crystal", "crystal shard", "shard of terra", "crystal shard of terra", "terra shard", "blessed terra shard" }));
set_short("%^BOLD%^%^WHITE%^Crystal Shard of Terra%^RESET%^ (blessed)");
set_long("This shard is a relatively small piece of pure one hundred percent delicate crystal. It is completely clear, and is fiercely glowing white from the inside with the blessing of Sacrel soaring within.");
set_property("no save", 1);
set_weight(50);
set_value(500000);
}
