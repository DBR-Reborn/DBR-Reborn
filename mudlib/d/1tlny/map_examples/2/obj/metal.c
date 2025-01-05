#include <std.h>
#include "../a1.h"
inherit OBJECT;
string mtlname;
void init() {
    ::init();
    add_action("mold","mold");
}
void create() {
    ::create();
    set_name("metal");
    set_id( ({ "metal" }) );
    set_short("a chunk of metal");
    switch(random(3)){
      case 0:mtlname="mithril";break;
      case 1:mtlname="elrodnite";break;
      case 2:mtlname="platnite";break;
    }
    set_long("A small chunk of "+mtlname+" maybe you should try to mold it?.");
    set_weight(30);
    set_value(50);
}
int mold(string str) {
    if(str != "metal") {
    notify_fail("What do you wish to mold?\n");
    return 0;
    }
     if(!present("pick-axe")) {
       notify_fail("You must have a pick-axe to do that.\n");
       return 0;
       }
      else {
      write("You mold the metal into a "+mtlname+" ingot!");
      message("other_action",(string)this_player()->query_name()+" molds "+
       "a chunk of metal into an ingot.");
        new(OBJ+""+mtlname+"_ingot.c")->
        move(this_player());
        remove()->this_object("metal");
        return 1;
}
}
