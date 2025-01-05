
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The Savanah Plateau");
   set_long( "\nYou are on a grassy plateau which stretches out in "
   "front of you, and ends abruptly to the west of you in a deadly drop."
   " The jump down looks quite enticing, if you are in a hurry."
   " The air has a very eerie quality here, with spirits flitting around constantly"
   ", and you get the feeling they want you to%^RED%^ jump off!!!!"
    );
    set_exits( ({  "plat29.c", "plat27.c", "plat15.c" }),
      ({"north",  "east", "south" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
  }


void init() {
  ::init();
   add_action("jump", "jump");
}

int jump(string str)  {
   if(str = str) {
   object player;
   int maxhp;
   player = this_player();
   maxhp = player -> query_max_hp();
   player -> move(PLATROOMS + "jump1.c");
   if(player -> query_flying() == 0)  {
   message("other action", "%^RED%^You take a suicidal leap off the edge, and fall to the ground!!!", player, this_object());
   message("other action", player -> query_cap_name() + "%^RED%^ takes a suicidal leap off the edge of the cliff!!!", this_object(), player);
   player -> add_hp( -((maxhp / 2) + random(50)));
   message("other action", player -> query_cap_name() + "%^RED%^ falls from above and lands at your feet in a pile with a sickening crunch.", PLATROOMS + "jump1.c", this_player());
}
   else {
   message("other action", player -> query_cap_name() + " jumps off the edge, and flies down to the earth.", this_object(), player);
   message("other action", "You jump off and fly down to the ground.", player, this_object());
   message("other action", player -> query_cap_name() + " floats gently down from above.", PLATROOMS + "jump1.c", this_player());
   return 1;
}}
}

