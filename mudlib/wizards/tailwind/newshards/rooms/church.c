#include "../newshards.h"
inherit "std/room";

void create() {
   ::create();
     set_property("light",3);
     set_property("night light", 2);
     add_exit(ROOMS+"street5","north");
     set("short","The Church");
     set("long","Even in this desolate, rugged land, the people of the town still put their trust in their gods. In this case, Lidfino. The inside of this church is plain and sparsely-decorated, but still looks lovingly built. A large altar stands in the center of the room for the devout to pray on.");
    set_property("no attack", 1);
    set_property("no steal", 1);
    set_property("no castle", 1);
    set_property("no spell", 1);
    set_property("no scry", 1);
    set_property("no summon", 1);
    set_property("no transport", 1);
// NO DRAIN ROOM FUNCTIONALITY ADDED BY THRACE MERIN
    set_property("no drain", 1);
      set_property("indoors", 1);
}

void init() {
    ::init();
    add_action("pray", "pray");
    add_action("print_list", "playerlist");
    add_action("use_block", "use");
}

int use_block(string str) {
    write("What?");
    return 1;
}

int pray() {
    if(!this_player()->query_ghost()) {
        notify_fail("You are already alive.\n");
        return 0;
    }
    this_player()->revive();
    this_player()->set_hp(10);
    this_player()->set_heart_beat(1);
    return 1;
}

int print_list(){
    mapping *tmp_arr;
    string *tmp;
    int i, max;
    
    tmp = ({ "    Name", "Class"});
    for(i=0,max=sizeof(tmp_arr=(mapping*)"/daemon/player_d"->query_player_list());i<max;i++) {
       tmp += ({ (i<9 ? " "+(i+1)+") " : (i+1)+") ")+capitalize(tmp_arr[i]["name"]) });
        if (tmp_arr[i]["class"]==0){
          tmp += ({ "None" });
        }
        if (tmp_arr[i]["class"]!=0){
          tmp += ({ capitalize(tmp_arr[i]["class"]) });
        }

    }
    message("info",format_page(tmp,2),this_player());
return 1;
}
