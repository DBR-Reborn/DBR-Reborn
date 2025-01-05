// Wizard: Gellor
// Faelana's Greenhouse
// faelana_shop.c
inherit "/std/vault";
private int open;
void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("faelana") && open) {
      new("/wizards/gellor/newfirn/shops/faelana.c")->move(this_object());
   }
}
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/wizards/gellor/newfirn/shops/faelana_storage.c", "west");
   add_exit("/wizards/gellor/newfirn/newfirn9.c", "east");
   set_door("wooden door","/wizards/gellor/newfirn/shops/faelana_storage.c",
            "north","faelana's shop storage");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   open = 1;
   set_lock_level("wooden door", 22);
   set("short","Faelana's Greenhouse");
   set("long","This is the shop portion of Faelana's Greenhouse. It is a "
   			  "small room offering no more room than is necessary for "
              "carrying out interaction with customers. There is a table "
              "in the center of the room, Faelana stands on one side of "
              "it while you stand on the side opposite her. The building "
              "itself is made of old logs of impressive proportions "
              "constructed like a cabin. The floor is soil covered by some "
              "lush carpet-like moss which is comfort for your feet.");
   set_items( (["wooden door" : "It looks very sturdy."]) );
   reset();
}
