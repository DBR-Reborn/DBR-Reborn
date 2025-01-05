#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
  ::create();
  set_property("light", 3);
  set_property("indoors", 2);
  add_exit("/wizards/shakur/giants/rooms/village3", "west");
  set_short("The golden Mammoth Tavern");
  set("long",
  "This is the golden Mammoth Tavern, known for its generous"
  "rations of steaks and ale. In the back of the room is a huge"
  "stone bar and some citizens leans heavily on the benches."
  "There is a menu on the wall.");

    set_items(
        (["benches":"They seem to be made of stone.",
"menu":(: call_other, this_object(), "read", "menu" :),

         "citizens" : "Several look as though they've had a few too many."
]) );
}

void reset() {
  ::reset();
    if(!present("kasbar")) 
      new("/wizards/shakur/giants/mobs/kasbar.c")->move(this_object());
}

int read(string str) {

    object ob;
    int i;
   if(!str) return 0;
    if(lower_case(str) != "menu") return notify_fail("There is no '"+str+"'
here.\n");
    ob = present("kasbar");
    if(!ob) {
       write("You cannot read the menu, as it is splattered with blood.");
       return 1;
    }
    write("The following is served at the golden Mammoth tavern.");
   
write("--------------------------------------------------------------------
");
write(sprintf("%30s %d silver", "A tankard of mead",
(int)ob->get_price("mead")));
    write(sprintf("%30s %d silver", "A mug of ale",
(int)ob->get_price("al
e")));
    write(sprintf("%30s %d silver", "A shot of single malt whiskey",
(int)ob->get_price("whiskey")));
    write(sprintf("%30s %d silver", "A loaf of bread",
(int)ob->get_price("bread")));
    write(sprintf("%30s %d silver", "A leg of mutton",
(int)ob->get_price("mutton")));
    write(sprintf("%30s %d silver", "A dragon steak",
(int)ob->get_price("steak")));
    write("-----------------------------------------------------------");
    write("<buy item> gets you the food or drink.");
    return 1;
}
