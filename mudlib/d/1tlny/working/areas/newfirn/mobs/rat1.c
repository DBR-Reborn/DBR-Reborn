//      Wizard:  Gellor
//      Rat 1
//      rat1.c
inherit "/std/monster";
void create() {
   object ob;
   ::create();
   set_name("rat");
   set("id", ({ "rat", "Rat" }));
   set("short", "A large ugly rat");
   set("long", "The rat has shiny brown fur, long twitching "
   			   "whiskers, a straight six inch tail, and has about "
               "eight inches in body length. It's eyes are shiny "
               "black beads on a small, pointy-nosed head. You can see "
               "that it's paws are adequate for handling small objects. "
               "and it's cheeks made for storing them.");
   set("aggressive", 0);
   set_level(1);
   set_body_type("quadruped");
   set_alignment(0);
   set("race", "rat");
   set_gender("female");
   set_emotes(2, ({"The rat stands on it's back legs and sniffs the air.",
                   "The rat squeaks quietly.",
                   "The rat licks it's fur thoroughly."}),0 );
}
