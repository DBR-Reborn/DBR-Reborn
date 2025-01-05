//      Wizard:  Khojem
//      area entry
//      entry.c

#include <std.h>

inherit ROOM;

void reset(){
  object mon;
  ::reset();
  if(!present("rat")) {
    new("/d/khojem/new/mon/rat")->move(this_object());
    new("/d/khojem/new/mon/rat")->move(this_object());
    new("/d/khojem/new/mon/rat")->move(this_object());
    new("/d/khojem/new/mon/rat")->move(this_object());
    new("/d/khojem/new/mon/rat")->move(this_object());
    new("/d/khojem/new/mon/rat")->move(this_object());
    new("/d/khojem/new/mon/rat")->move(this_object());
    new("/d/khojem/new/mon/rat")->move(this_object());
    }
}  

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "A wooded path");
    set("day long", "The trees grow "+
      "all around, but allow a great deal of sunlight through the "+
      "leaves and branches.  It is really pleasant here.  Off to the "+
      "side you see a few squirrels scampering about.  The trail "+
      "extents west from here.  A large rock is to the trail's side.\n    \n     \n0--@   \n     \n   \n"
    );
    set("night long", "The trees grow "+
      "all around, but allow much of the night's light through the "+
      "leaves and branches.  It is really pleasant here.  Off to the "+
      "side you see a few squirrels scampering about.  The trail "+
      "extents west from here.  A large rock is to the trail's side.\n    \n     \n0--@   \n     \n   \n"
    ); 
    add_exit("/d/khojem/new/room/entry","west");
    set_items(([
     ({ "squirrel","squirrels" }) :
        "Two gray squirrels appear to be playing tag.  They chase each "+
        "other back and forth through and around the trees.  They keep "+
        "there distance from you and are much too quick for your attack "+
        "or magic capabilities.",
     ({ "tree","trees", "woods" }) :
        "The trees are large, healthy trees filled with foliage.",
     ({ "leaf","leaves" }) :
        "The leaves sway in the breeze, but still allow much light by them.",
     ({ "trail","path" }) :
        "Although the trees are widely scattered about you still can "+
        "make out the definite signs of a trail or path here.  The "+
        "ground appears slightly worn and the leaves on the ground "+
        "are not as frequent here.  The trail appears frequently used."

    ]));
    set_smell("default", "The smell of growth and decaying wood is everywhere.");
    set_listen("default", "The birds are singing in the trees.");
}
