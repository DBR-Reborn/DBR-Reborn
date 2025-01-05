//#define NORTHEAST "30"
#define NORTHWEST "42"
#define NORTH "40"
//#define SOUTH "41"
//#define EAST "38"
//#define WEST "39"
//#define SOUTHEAST "30"
//#define SOUTHWEST "30"
#include "base_mighty.c"

void reset() {
object ob;
string drag;
    ::reset();
    switch(random(3)){
    case 0:drag="mighty";break;
    case 1:drag="cursed";break;
    case 2:drag="buff";break;
    //case 3:drag="skinny";break;
}

    if(!present("dragon"))
    {
	i = random(2)+1;
	while(i--)
	{
	    ob= new(MON+drag+"_dragon");
        ob->set("aggressive", 1);
        ob->move(this_object());
	}
  }
if(!present("skinny"))
    {
	i = random(2)+1;
	while(i--)
	{
	    ob= new(MON+"skinny_dragon");
        ob->set("aggressive", 1);
        ob->move(this_object());
	}
  }
}

int go_north() {
    if(wizardp(this_player())) { 
    return 1;
    }
    if(this_player()->query_ghost()) { 
    return 1;
    }
    if(!present("mighty")) {
	return 1;
    }
    if(!present("cursed")) {
	return 1;
    }
    if(!present("buff")) {
	return 1;
    }
    if(!present("skinny")) {
	return 1;
    }
    message("blocking",
      "The Dragon roars at you, it quickly leaps in front of you blocking your path.\n",
      this_player());
    message("blocking",
      "The Dragon roars blocking "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 0;
}
int go_east() {
    return 1;
}
int go_west() {
    return 1;
}

int go_south() {
    return 1;
}
//end
