//      Wizard:  Khojem
//      Main Gallery
//      gallery.c

#include <std.h>
#include <under.h>

inherit ROOM;

void reset() {
	::reset();
	if (!present("king")) {
	  new("/d/khojem/new/mon/king")->move(this_object());
	}
}

int x;
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A broad gallery");
    set("long", "You are standing within a large gallery.  The vaulted, ceiling "+
      "is trussed with large, wooden beams.  This is a place where the wood-elf "+
      "king conducts affairs of state.  Your footsteps echo through the large "+
      "chamber. On the north wall you see a%^YELLOW%^throne%^RESET%^\n   0\n   |\n   @   \n   | \n   0\n"
    );
    add_exit("/d/khojem/new/room/foyer.c","south");    
    //add_exit("/d/khojem/new/room/s/s1","north");
    set_items(([
     ({ "ceiling","beams", }) :
        "Large, beams carved from the trunks of trees in the surrounding forest "+
        "support the large, vaulted ceiling and roof.",
     ({ "gallery" }) :
        "The gallery is void of any furnishings.  A few paintings adorn the walls.",
     ({ "paintings", "painting" }) :
        "Several cheap oil paintings of the king as a proud, young man decorate "+
        "the walls.  Hmm.. the king has a lousy taste for art.",
     ({ "throne" }) : "The large throne sits in front of the north wall you should probably%^YELLOW%^search throne%^RESET%^"
     ]));
    set_smell("default", "The gallery smells of perfumed waters and herbs.");
    set_listen("default", "You hear people murmuring in the distance.");
  set_search("throne","You find a throne set not to firmly maybe if you%^YELLOW%^push%^RESET%^it out of the way you can see what is behind it");
 set_search("default"," You see a%^YELLOW%^throne%^RESET%^. Maybe if you search throne you might notice somthing more.");
 x = 0;


}
void init(){
   ::init();
   add_action("push_throne","push");
}
int push_throne(string str){
string clas;
  if(!str){
    write("push what?");
    return 1;
  }
  if(str == "throne"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You push the throne out of the way");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"A The Throne moves and a passage to the north opens in the wall!");
          add_exit("/d/1tlny/complete/fir_boss_room/s/s1.c","north");
          delayed_call("close_door",10);
          x = 1;
        }
        else {
          write("You feel the grate vibrate slightly and suddenly your "
            "dropping through the thick air!!\nYou slam into a stone "
             "floor after dropping through the darkness. As you glance "
            "up you see the grate far above slam shut!");
         say(this_player()->query_cap_name()+" pulls something in the "
           "grate and gasps as the grate collaspes and "+
            this_player()->query_possessive()+" body falls into the "
            "opening!");
         tell_room(UNTHIEF+"thief_du","You hear a scream above you!\n"
          +this_player()->query_cap_name()+" falls through the opening in "
          "the ceiling and slams into the hard stone floor in a cloud "
          "of straw and dust!",this_player());
         this_player()->move(UNTHIEF+"thief_du");
         return 1;
        }
      }
      else {
       if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
         write("You pull the lever and the secret door slides shut!");
         remove_exit("north");
         remove_delayed_call("close_door");
         x = 0;
       }
       else {
          write("You feel the grate vibrate slightly and suddenly your "
            "dropping through the thick air!!\nYou slam into a stone "
             "floor after dropping through the darkness. As you glance "
            "up you see the grate far above slam shut!");
         say(this_player()->query_cap_name()+" pulls something in the "
           "grate and gasps as the grate collaspes and "+
            this_player()->query_possessive()+" body falls into the "
            "opening!");
          this_player()->move(UNTHIEF+"thief_du");
          return 1;
        }
    }
    say(this_player()->query_cap_name()+" Pushes the throne to the side.");
    return 1;
   }
}
void close_door(){
   remove_exit("north");
   tell_room(this_object(),"The Throne slides back into place!\n");
   x = 0;
   return;
}
