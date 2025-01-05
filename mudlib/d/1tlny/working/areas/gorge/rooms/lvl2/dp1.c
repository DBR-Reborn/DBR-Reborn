//   lvl2 demon gorge  by Sinclair//

inherit ROOM;
#include <std.h>
#include <def.h>

void create() {
     ::create();
     set_property("light",-4);
     set_property("indoors",1);
     set("short","A Dark tunnel");
     set("long","You enter the start of a winding tunnel.  The lack of light makes footing very hard.  The walls are dug out to a smooth rounded passageway.  The heat is subsiding a bit, but you can sense some form of power to the north.\n");
     add_item("wall", "The walls are smooth as if dug out by some kind of machin
e.\n");
     add_item("door", "The door you just walked through now is just an outline i
n the wall.  There is a sphere shaped hole in the center of the would be door.\n
");
     add_item("hole", "The hole seems like it would hold a sphere of some type")
;
     set_smell("default","You smell some kind of oil.");
     set_listen("default","You hear scratching sounds.\n");
     add_exit("tun2.c","north");
}

void init() {
     ::init();
     add_action("put_fun", "put");
}

int put_fun(string str) {
     object who, ob;
     who=this_player();
     if(!str) 
        return notify_fail("put what?\n");
     if(str != "sphere in hole")
        return notify_fail("You can't put that in the hole!\n");
     if(!present("sphere", who))
        return notify_fail("You don't have a sphere to put it in the hole!\n");
     if(str == "sphere in hole" && present("sphere", who)) {
        write("You place the sphere in the wall and the wall opens up revaling"
          " the exit to the east.");
     say(this_player()->query_cap_name() + " puts the sphere in the hole and"
          " the door opens.\n");
        add_exit("lever", "east");
        return 1;
     }
}
