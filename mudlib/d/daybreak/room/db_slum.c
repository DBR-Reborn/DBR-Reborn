#include "../daybreak.h"
#include <std.h>
#include <under.h>

inherit "std/room";

int x;
void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbns8","east");
    //HONSPRON 2020 Thief Guild is in Akkad Slums
    add_exit("/d/damned/guilds/thief/thief1","down");
    add_exit("/d/damned/guilds/join_rooms/dark-paladin_join.c","west");
        //add_exit("/d/daybreak/room/ntf/ntfkitchen", "south");
    set("short","Daybreak Ridge Slums");
    set("long","   \n   \nG--@--0\n   d\n   \nDaybreak Ridge Slum this place looks awful it is littered with trash and garbage everywhere! You wonder why on earth anyone would come to this horrible place. You see a rag used to wipe someones butt! You see many other items around");
set_items( ([
    "dagger" : "Looks like a rusted dagger just sitting here.. why!?",
"rag" : "dirty filthy rag that has been used!",
"bone" : "pile a of bones rats seem to be knawing on them",
"blood" : "pool of blood from a fresh kill",
"rat" : "filthy rats why they gotta be everywere!",
  ]) );
set_search("dagger","this is a throwing dagger kind of looks old and rusted looks like it has been used recently. it is very well balanced");
set_search("rag","This is some rag someone used to wipe their butt recently what the heck! you sniff it and it stinks!");
set_search("bones","these bones have been knawed on by some rats for a long time looks like a fresh corpse has layed her recently");
set_search("blood","blood red pool sitting here from a fresh kill");
set_search("rat","stupid rats!");
set_search("garbage","pile of garbage lots and lots of it");
set_search("trash","yup this is trash for sure");
set_search("pile","this is a pile of trash for sure!");
 set_search("default"," You see so many items everywere what a pile of stench and garbage! a butt rag some trash some of everything heck even a rusted old dagger is sitting here looks like someone used it recently and a pile a of blood as well as some rats that are knawing on some bones!");
x = 0;
}

void init(){
   ::init();
   add_action("throw_dagger","throw");
}
int throw_dagger(string str){
string clas;
  if(!str){
    write("throw what?");
    return 1;
  }
  if(str == "dagger"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You throw the dagger at the wall and as you do it seems to vanish into the wall and the whole north wall seems to disapear!\n");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || clas == "nightblade" ||wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"As the dagger passes through the wall the wall slowly vanishes");
            add_exit("/d/damned/guilds/join_rooms/assassin_join.c","north");
          delayed_call("close_door",20);
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
         tell_room(UNTHIEF+"thief_du","You hear a throw above you!\n"
          +this_player()->query_cap_name()+" falls through the opening in "
          "the ceiling and slams into the hard stone floor in a cloud "
          "of straw and dust!",this_player());
         this_player()->move(UNTHIEF+"thief_du");
         return 1;
        }
      }
      else {
       if(clas == "thief" || clas == "child" || clas == "nightblade" || wizardp(this_player()) || (this_player()) ){
         write("The wall becomes solid again!");
         remove_exit("down");
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
    say(this_player()->query_cap_name()+" Throws the dagger and it passes right through a solid wall!");
    return 1;
   }
}
void close_door(){
   remove_exit("north");
   tell_room(this_object(),"The wall to your astonishment becomes solid rock again!\n");
   x = 0;
   return;
}

