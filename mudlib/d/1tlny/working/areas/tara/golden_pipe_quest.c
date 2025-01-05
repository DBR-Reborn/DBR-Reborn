inherit "std/quest_ob";

void create() {
   set_name("golden pipe");
   set_id( ({ "golden pipe", "quest_object", "pipe" }) );
   set_short("The quest for a golden pipe");
   set_long(
"Donny, one of Tara's most wealthy halflings, has lost his "+
"valuable golden pipe.  At his request, the sheriff sent word "+
"to Akkad that whoever can help recover the stolen pipe would "+
"gain a handsome reward, no questions asked.\n"+
"Quest ration: Newbie party, or Apprentice+\n"
   );
   set_quest_points(16);
}
