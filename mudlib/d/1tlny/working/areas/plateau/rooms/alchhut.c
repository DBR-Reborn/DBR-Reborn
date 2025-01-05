
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Alchemists Hut");
     set_long(
             "The hut is littered all about with little knick knacks, and trinkets, that look totally useless. There is debris all over the place, and the walls are covered with gadgets. The roof is weighed down by the myriads of little bird looking things, that are suspended with string. Over in one corner, isolated from the chaos of the rest of the hut, is a pedastal and on the pedastal is a telescope.");
    set_listen("default", "The noise that abounds on the rest of the plateau seems to have stopped at the door.");
     set_smell("default", "There is no identifiable smell here.");
     add_exit("plat34", "out");
  }


void init() {
  ::init();
add_action("peer", "peer");
   if(!present("alchemist"))
         new(PLATMON + "ctalch")->move(this_object());
}



int peer(string str)  {
     string longdesc, exits, living, items;
        object peered, peerer;
      if(!present("alchemist"))   {
        if(find_player(str))      {
         peered = find_player(str);
         peerer = this_player();
          if(peerer->query_level() > peered->query_level() - 4)   {
     longdesc = environment(peered)->query_long();
    exits = environment(peered)->query_long_exits();
    living = environment(peered)->describe_living_contents(({}));
    items = environment(peered)->describe_item_contents(({}));
    message("room_desciption", longdesc, this_player(), this_object());
    message("room_exits", exits, this_player(), this_object());
    message("living_item", living, this_player(), this_object());
    message("inanimate_item", items, this_player(), this_object());
    message("other action", this_player()->query_cap_name() + " peers through the telescope.", this_object(), this_player());
     message("info", peerer->query_cap_name() + "%^RED%^ just used the magic telescope to peer at you!!!", peered);
    return 1;
     }
    else {
        write("You are too weak to use the magic telescope at that player");
        message("info", peerer->query_cap_name() + " just tried to use the magic telescope to peer at you but was too weak.", peered);
        return 1;
         }
   }  else {
         write("That player is not currently alive");
         return 1;
      }
      } else {
       write("The centaur alchemist yells, LEAVE THAT ALONE, and jumps between you and the telescope");
       message("info", "The centaur alchemist yells, LEAVE THAT ALONE!!", this_object(), this_player());
        return 1;
      }
}
