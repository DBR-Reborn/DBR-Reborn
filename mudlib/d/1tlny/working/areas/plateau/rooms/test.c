#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit PLATROOMS + "jumpoff.c";

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "The Savanah Plateau");
    set_long( "\nYou are on a grassy plateau which stretches out in front of"
      " you, and ends abruptly behind you in a deadly drop. There are many hoof"
      " prints scattered all over the ground, leading off in different"
      " directions. The jump down looks quite enticing, if you are in a hurry."
    );
    set_exits( ({ "top", "plat11", "plat5", "plat3" }),
      ({ "down", "north",  "east", "west" })
    );
   set_items( ([
    ({"hoof prints","prints"}): "Hoof prints of the centaur variety, which seem"
      " to have been made in a hurry."
     ]) );
   set_smell("default", "The air smells like freshly dug up dirt.");
   set_listen("default", "The galloping of horses is deafening.");
}

void reset()   {
   ::reset(); 
   new(PLATMON + "ctft")->move(this_object());
   new(PLATMON + "ckid")->move(this_object());
   new(PLATMON + "ctmom")->move(this_object());
}