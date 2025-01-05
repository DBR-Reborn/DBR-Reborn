#include "../shards.h"
#include <daemons.h>
#define CURRS ({ "mithril", "gold", "electrum", "copper", \
                "silver" })

inherit "/std/vault";

private int open;

void init() {
   add_action("read", "read");
   ::init();
}
void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("crystal")) {
      new(OBJ+"money_store_crystal")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"ak_marknw", "east");

   set("short","Money is Power...");
   set("long",
"Iron coins litter the floor of this building. You wonder why someone wouldn't have picked these up, till you realize that the price of iron has been depressed for hundreds of years. Indeed, you look closer, and see no other type of coin _but_ iron.");
   set_items( (["sign": (: call_other, this_object(), "money_rates" :),
              "coins" : "You'd have to pick up a few thousand pounds of these to make even a single silver."]) );
}

void money_rates() {
  int i, tmp;
  string line;
  float rate;

  write("The sign is titled 'Current Exchange Rates of Major "+
        "Currencies'.  It reads:\n");
  for(i=0; i<sizeof(CURRS); i++) {
    rate = ECONOMY_D->__Query(CURRS[i], "rate");
    if(rate < (float)ECONOMY_D->__Query("gold", "rate"))
      line = sprintf("%-30'.'s%-5.1f gold", capitalize(CURRS[i])+":",
                     (float)ECONOMY_D->__Query("gold", "rate")/rate);
    else
      line = sprintf("%-30'.'s%-5.1f copper", capitalize(CURRS[i])+":",
                     (float)ECONOMY_D->__Query("copper", "rate")/rate);
    write(line);
  }
   write("\nType 'help money' for help on exchanging.\n"
   "NOTE: Due to the flooded market, platinum is no "+
   "longer carried here.");
  return;
}

int read(string str) {
   if(str == "sign") {
      money_rates();
      return 1;
   }
   else
      return 0;
}
