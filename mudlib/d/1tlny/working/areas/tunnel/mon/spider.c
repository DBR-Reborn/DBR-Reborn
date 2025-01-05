//          Wizard: Delsius
//          spider
//          June 97

#include <std.h>
#include <daemons.h>
inherit MONSTER;

void init() {
   ::init();
   if(this_player()->query_npc() && this_player()->query_name() == "Tunnel worker")
      force_me("kill worker");
}
create() {
   string var;
   ::create();
   set_name("spider");
   set_id(({"spider","hairy spider","poisonous spider","arachnid"}));
   set("race", "arachnid");
   set_level(15 + random (3));
   switch(random(2)) {
     case 0: var = "female"; break;
     case 1: var = "male"; break;
}
   set_gender(var);
   switch(random(3)) {
     case 0: var = "A hairy spider"; break;
     case 1: var = "A poisonous spider"; break;
     case 2: var = "A creepy spider"; break;
}
   set("short", var);
   set_long("This long legged spider crawls slowly through the tunnels.  "
           "It's hairy legs and abdomen are quite large while it's "
            "massive fangs drip %^BOLD%^%^GREEN%^venom%^RESET%^ profusely.  It seems quite "
            "content with it's home it made here in the tunnels.");
   set_moving(1);
   set_speed(120);
   set("gang bang", 0);
   set_emotes(5, ({"The spider inches towards you.",
                   "The spider climbs up the tunnel wall.",
                   "The spider spins a small web."}));
}
   void remove() {
   MOB_TRACK_D->mob_minus("tunnel spider");
   ::remove();
}
