//  The fabeled castle shop!

#include "../shards.h"
#include <security.h>
#include <rooms.h>
#define CASTLE_D "/daemon/castle_d"
#define MAX_SOUTH 79
#define MAX_EAST 39
#define DOORS ([ "wood door" : 20000, "iron door" : 81000, "steel door" : 540000, \
        "reinforced door" : 1160000, "vault door" : 2750000 ])
#define FEATURES ([ "no scry" : 470000, "no teleport" : 280000, \
        "no summon" : 370000, "healing room" : 90000, \
        "special exits" : 50000 ])

inherit "/std/room";

int pay(object tp, int plat);

int pay(object tp, int plat) {
  plat = to_int(to_float(plat) * currency_rate("mithril"));
  if((int)tp->query_money("mithril") < plat) {
    message("info", "You do not have enough mithril for that.",
          tp);
    return 0;
  }
  tp->add_money("mithril", -1*plat);
  return 1;
}

void reset() {
  ::reset();
  if(!present("crystal"))
    new(OBJ+"castle_crystal")->move(this_object());
}

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("The Castle Shop");
  add_exit(ROOMS+"ak_tavern2", "east");
  set("long",
  "Engraved into the western wall of this building is 'Ye Olde Castle Builders'. Extrapolating from that, you decide that someone here must have been a builder at one point. Now, they're long gone, and the building has fallen into disrepair. A sign lies on the southern wall wall.");
  add_item("sign", (: call_other, this_object(), "read_sign" :));
  return;
}

int read_sign() {
  string tmp;

  tmp =
"Welcome to the Castle Shop!\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-\n"
"In order to buy a castle, you must first select a plot of "
"land on the world map which does not already contain a castle.  "
"The plot comes with a free room.  Once you have selected a plot, "
"You may buy additional rooms (up to 20), doors, or features for "
"your castle.  You install these by going to your castle and "
"typing 'help castle'.\n\n"+
sprintf("plot of land               %d mithril (one free room!)\n", to_int(3020000.0*currency_rate("mithril")))+
sprintf("castle room                %d mithril\n", to_int(420000.0*currency_rate("mithril")))+
sprintf("wood door                  %d mithril\n", to_int(20000.0*currency_rate("mithril")))+
sprintf("iron door                  %d mithril\n", to_int(81000.0*currency_rate("mithril")))+
sprintf("steel door                 %d mithril\n", to_int(540000.0*currency_rate("mithril")))+
sprintf("reinforced door            %d mithril\n", to_int(1160000.0*currency_rate("mithril")))+
sprintf("vault door                 %d mithril\n", to_int(2750000.0*currency_rate("mithril")))+
"\n"
"Castle special features (good for one room only!):\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
sprintf("no scry                    %d mithril\n", to_int(470000.0*currency_rate("mithril")))+
"  ^ You cannot be scried in that room\n"+
sprintf("no teleport                %d mithril\n", to_int(280000.0*currency_rate("mithril")))+
"  ^ No one can teleport to that room.\n"+
sprintf("no summon                  %d mithril\n", to_int(370000.0*currency_rate("mithril")))+
"  ^ No one can be summoned from that room.\n"+
sprintf("healing room               %d mithril\n", to_int(90000.0*currency_rate("mithril")))+
"  ^ Any PLAYER in the room heals mp and hp at double rate.\n"+
sprintf("special exits              %d mithril\n", to_int(50000.0*currency_rate("mithril")))+
"  ^ Teleport exits to various useful places (church, shop, etc.)\n"
"\n"
"Buy any item with 'buy <item>'\n"
"\nNEW and IMPORTANT\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"Castle Upkeep!  You must now pay a monthly fee for your castle, which increases "
"if you have more rooms.  You may pay up to three months in advance (real time, "
"not mud months).  If you will be unable to play for more than three months, "
"contact an arch.\n"
"\n"
"upkeep cost................Tells you the monthly cost (in gold) of your upkeep.\n"
"upkeep time................Tells you the time left on your current payment.\n"
"                           If this time expires, your castle will be torn down.\n"
"                           NO reimbursement will be given unless you contacted\n"
"                           an arch IN ADVANCE with an explanation as to why\n"
"                           you couldn't pay the castle fees.  This rule is\n"
"                           NOT flexible.  If the castle is torn down, all\n"
"                           contents will be lost.\n"
"upkeep pay.................Pay one month's worth of castle upkeep.  Only gold\n"
"                           is accepted.\n";
  this_player()->more(explode(wrap(tmp, (int)this_player()->getenv("SCREEN")), "\n"));
  return 1;
}

void init() {
  ::init();
//  add_action("buy_item", "buy");
  add_action("read_it", "read");
//  add_action("upkeep_action", "upkeep");
  return;
}

   int read_it(string str) {
      if(str == "sign") {
         read_sign();
         return 1;
       }
       return 0;
   }
