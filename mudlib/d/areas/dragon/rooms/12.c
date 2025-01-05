//#define NORTHEAST "03"
//#define NORTHWEST "03"
#define NORTH "11"
//#define SOUTH "12"
//#define EAST "13"
#define WEST "38"
//#define SOUTHEAST "04"
//#define SOUTHWEST "02"
//#define UP "entry"
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
    if(!present("dragon")) {
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

int go_south() {
    return 1;
}
//end
