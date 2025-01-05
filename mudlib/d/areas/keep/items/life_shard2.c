#include <std.h>

/* This crystal shard is the blessed shard recieved when a Disciple of Lidfino places the original shard obtained from the blue arcane orb in the pool of life. With this shard, and the blessed shards of terra and power, a high enough merchant can forge them into the legend key. The legend key is required to face the master of the black keep, Owedquar's Shadow, on the second floor. */

inherit OBJECT;

void create() {
::create();
set_name("blessed life shard");
set("id", ({ "shard", "crystal", "crystal shard", "shard of life", "crystal shard of life", "life shard", "blessed life shard" }));
set_short("%^BOLD%^%^WHITE%^Crystal Shard of Life%^RESET%^ (blessed)");
set_long("This shard is a relatively small piece of pure one hundred percent delicate crystal. It is completely clear, and is very fiercely glowing white from the inside with the blessing of Lidfino soaring within.");
set_property("no save", 1);
set_weight(50);
set_value(500000);
}
