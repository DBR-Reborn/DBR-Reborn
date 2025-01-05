// Wizard: Gellor
// Schtel's Metal Works
// schtel_shop.c
inherit "/std/vault";
private int open;
void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("schtel") && open) {
      new("/wizards/gellor/newfirn/shops/schtel.c")->move(this_object());
   }
}
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/wizards/gellor/newfirn/shops/schtel_storage.c", "north");
   add_exit("/wizards/gellor/newfirn/newfirn36.c", "south");
   set_door("wooden door","/wizards/gellor/newfirn/shops/schtel_storage.c",
            "north","schtel's shop storage");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   open = 1;
   set_lock_level("wooden door", 22);
    set("short", "Schtel's Metal Works");
    set("long", "You have reached Schtel's Metal Works. This is the "
    				 "to go for affordable metal products such as ingots, "
                "blanks, and even some equipment. The place is a cubic "
                "shaped construction of fine cedar logs and roof. The "
                "floor is made of extremely heavy slabs of roughed up "
                "marble. A large forge is in the back of the place, "
                "behind a wall-to-wall counter. Also a brick chimney "
                "rises out of the back of the building." );
   set_items( (["wooden door" : "It looks very sturdy."]) );
   reset();
}
