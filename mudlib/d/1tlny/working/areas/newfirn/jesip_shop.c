// Wizard: Gellor
// Jesip's General Shoppe
// jesip_shop.c
inherit "/std/vault";
private int open;
void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("jesip") && open) {
      new("/wizards/gellor/newfirn/shops/jesip.c")->move(this_object());
   }
}
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/wizards/gellor/newfirn/shops/jesip_storage.c", "north");
   add_exit("/wizards/gellor/newfirn/newfirn5.c", "south");
   set_door("wooden door","/wizards/gellor/newfirn/shops/jesip_storage.c",
            "north","jesip's shop storage");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   open = 1;
   set_lock_level("wooden door", 22);
   set("short","Jesip's General Shoppe");
   set("long","You're in Jesip's General Shoppe. Jesip, the "
   			  "shopkeeper, is usually willing to deal in just about "
              "anything. The shop is an impressive construction of "
              "large wooden beams and logs put together as a cabin. "
              "The floor is made of solid oak planks. You see no "
              "dedicated place for goods to be shelved or stored "
              "other than behind the wooden door to the north.");
   set_items( (["wooden door" : "It looks very sturdy."]) );
   reset();
}
