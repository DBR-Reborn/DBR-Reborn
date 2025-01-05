//      Wizard:  Myrddin
//      village_05.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
  if(!present("mother.c")) {
         new(HIV_MON+"mother_01")->move(this_object());
         new(HIV_MON+"child_01")->move(this_object());
         new(HIV_MON+"child_02")->move(this_object());
 }  
}

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Forest Path");
    set("long",
	"The number of frightened villagers heading south has "
              "dropped off.  It looks like the last of them are passing you "
              "now.  You get the feeling that you will not run into anyone "
              "else on the path for some time.  From the north, you can "
              "see nothing threatening, but the villagers are not fleeing "
              "for no reason. The surrounding forest looks quite old, and "
              "you can't help but staring at it out of worry about its "
              "hidden dangers.\n" );
    set("night long",
             "The path continues to the north and to the south.  In the "
             "dark, with most of the frightened villagers past, the forest "
             "seems quite threatening and ominous.\n");
    set_smell("default", "The smells of the forest are mingled with the "
             "stink of the unwashed villagers.");
    set_listen("default", "The villagers cry softly, and quietly talk "
             "among themselves.");
    set_items(([
     ({ "forest", "woods", "trees", "depths" }) :
        "The forest is thick, filled with ancient trees.  Though not at "
        "their oldest, you still feel a bit smaller in the presence of the "
        "nearby trees.",
     ({ "path" }) :
        "It continues to the north and to the south.",
     ({ "band", "travelers", "villagers" }) :
        "They look warn, weary, and frightened.  Perhaps you will be "
        "able to help them overcome whatever hardship forced them "
        "from their homes.",
]));
     set_exits((["north":HIV_ROOMS+"village_06.c",
                      "south":HIV_ROOMS+"village_04.c"])); 


     add_exit(HIV_ROOMS+"village_100", "northwest");
     add_invis_exit("northwest");


}

