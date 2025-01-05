// hybrid room server by glen
#include <std.h>

inherit "/std/virtual/compile";
inherit ROOM;

void   create_exits();

string *demons = ({
  "/std/glen/pet/small_demon",
  "/std/glen/pet/normal_demon",
  "/std/glen/pet/greater_demon",
  "/std/glen/pet/lord_demon",
  "/std/glen/pet/prince_demon"});

string name;
int x, y;

virtual_setup(string str){
    if(!str)
	return;
    set_property("light",3);
    set_property("night light", 2);
    set_short("The Demon Plane");
    set_long("This is an outer realm of the demon plane.  "+
      "It is very hard to understand this place.  "+
      "Movement is difficult, the gravity and terrain "+
      "are very different here.  Demons can be seen "+
      "and heard in nearly every direction.  ");
    sscanf(str, "room_%d_%d", x, y);
    name = str;
    create_exits();
}

void reset() {
    int i, k;
    object ob;
    if(!name)
	return;

    k = random(7) + random(7) + random(7);
    if(!present("demon"))
	for(i = 0; i < k; i++){
	    ob = new(demons[random(5)]);
	    ob->set_up(random(300));
	    ob->move(this_object());
	    ob->set_aggr_status(random(2));
	    ob->materialize();
	    ob->set_perm(1);
	}

}

void create_exits(){
    string path = "/std/glen/rooms/room";

    add_exit(sprintf("%s_%d_%d.demon_plane",
	path,x, y-1),"north");
    add_exit(sprintf("%s_%d_%d.demon_plane",
	path,x, y+1),"south");
    add_exit(sprintf("%s_%d_%d.demon_plane",
	path,x+1, y),"east");
    add_exit(sprintf("%s_%d_%d.demon_plane",
	path,x-1, y),"west");
}

