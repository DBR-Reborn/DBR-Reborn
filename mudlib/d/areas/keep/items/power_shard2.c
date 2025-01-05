#include <std.h>

/* This is the blessed crystal shard that is created once the original shard obtained from the red arcane orb on the second floor of the black keep. If this shard is combined with the other two shards of life and terra at the shadowforge in the center of the keep at the great hall by a merchant, the legend key that can unlock the way to Owedquar's Shadow in the master room of the second floor is formed. */ 

inherit OBJECT;

void create() {
::create();
set_name("blessed power shard");
set("id", ({ "shard", "crystal", "crystal shard", "shard of power", "crystal shard of power", "power shard", "blessed power shard" }));
set_short("%^BOLD%^%^WHITE%^Crystal Shard of Power%^RESET%^ (blessed)");
set_long("This shard is a relatively small piece of pure one hundred percent delicate crystal. It is completely clear, and is very fiercely glowing white from the inside with the blessing of Taul soaring within.");
set_property("no save", 1);
set_weight(50);
set_value(500000);
}
