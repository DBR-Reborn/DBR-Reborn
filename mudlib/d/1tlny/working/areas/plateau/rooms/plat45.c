
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The Savanah Plateau");
   set_long( "\nYou are on a grassy plateau which stretches out to "
  "the south of you, and ends abruptly to the north of you in a deadly drop."
   " The jump down looks quite enticing, if you are in a hurry."
   " A sign here says Lookout Point, and you notice that the view from here"
   " is much clearer then anywhere else on the island. There is a telescope "
   "here, begging you to peer through it."
    );
    set_exits( ({  "plat40.c", "plat46.c", "plat44.c" }),
      ({"south",  "east", "west" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
    add_item("telescope", "A long thin contraption, with mirror's on both ends.");
  }

 void reset()   {
      ::reset(); 
	new(PLATMON + "ctft")->move(this_object());
      new(PLATMON + "ckid")->move(this_object());
	new(PLATMON + "ctmom")->move(this_object());
}


void init() {
  ::init();
   add_action("jump", "jump");
add_action("peer", "peer");
}

int jump(string str)  {
   if(str = str) {
   object player;
   int maxhp;
   player = this_player();
   maxhp = player -> query_max_hp();
   player -> move(PLATROOMS + "entrance.c");
   if(player -> query_flying() == 0)  {
   message("other action", "%^RED%^You take a suicidal leap off the edge, and fall to the ground!!!", player, this_object());
   message("other action", player -> query_cap_name() + "%^RED%^ takes a suicidal leap off the edge of the cliff!!!", this_object(), player);
   player -> add_hp( -((maxhp / 2) + random(50)));
   message("other action", player -> query_cap_name() + "%^RED%^ falls from above and lands at your feet in a pile with a sickening crunch.", PLATROOMS + "entrance.c", this_player());
      return 1;
}
   else {
   message("other action", player -> query_cap_name() + " jumps off the edge, and flies down to the earth.", this_object(), player);
   message("other action", "You jump off and fly down to the ground.", player, this_object());
   message("other action", player -> query_cap_name() + " floats gently down from above.", PLATROOMS + "entrance.c", this_player());
   return 1;
}}
}


int peer(string str)  {
     string longdesc, exits, living, items;
     longdesc = ("/d/damned/akkad/ak_center")->query_long();
    exits = ("/d/damned/akkad/ak_center")->query_long_exits();
    living = ("/d/damned/akkad/ak_center")->describe_living_contents(({}));
    items = ("/d/damned/akkad/ak_center")->describe_item_contents(({}));
    if(str=="telescope" || str == "through telescope") {
    message("room_desciption", longdesc, this_player(), this_object());
    message("room_exits", exits, this_player(), this_object());
    message("living_item", living, this_player(), this_object());
    message("inanimate_item", items, this_player(), this_object());
    message("other action", this_player()->query_cap_name() + " peers through the telescope.", this_object(), this_player());
    return 1;
     }
     else { return 0; }
}
