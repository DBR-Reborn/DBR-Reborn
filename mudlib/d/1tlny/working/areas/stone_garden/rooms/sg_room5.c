//  Wizard: Shade Maelstorm
 // reminder: descrips dont seem to change for some reason at night
//  Area: Stone Garden
//  Theme: This is a stone garden, in which basilisks and other stoning
// creatures will play.

//  Monsters: The monsters will include caretakers, guards, gardeners, baby
//  basilisks, and other smaller insects, as well as some stone statues.

#include <std.h>
#include <stone_garden.h>

inherit ROOM;


void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
      set("short", "Secluded Area.");
 set("long","You find yourself in a small secluded area of the west end of the garden. It seems quite tranquil here, there are many trees and you notice a gazebo here. There seems to be some sort of decoration on the roof of the gazebo.");

 add_item("gazebo","It is a small stone hut, circular in shape and with a good view of the lands further down the hill. It has a rather odd decoration on it.");
 add_item("decoration","The decoration upon closer inspection appears to be of a huge gargoyle resting on the roof at the entrance of the gazebo. It is in a crouched position, and has a wicked grin on its face. Something about it makes you very nervous...");
 add_item("gargoyle","The gargoyle statue is quite large, and is resting on the gazebo roof. Its wings are folded and it is facing the path leading to the gazebo.");
 add_item("trees","There are quite a few trees around here, but it appears as if the ones right near the gazebo have been chopped down, so as to not obstruct the wonderous view the gazebo has over the land further down the hill.");
  add_exit("sg_room4","east");
 add_exit("sg_gazebo","gazebo");
 set_listen("default","There is an errie silence here as with the rest of the garden. Occaisionally, you think you hear a noise perhaps of a bird chirping, but it abruptly stops so you cannot be sure.");
}


  void reset() {
   
    ::reset();
    seteuid(geteuid());
   if(!query_night()) {
       new(MON_PATH+"caretaker")->move(this_object());
}
   if(query_night()) {
   new(MON_PATH+"gargoyle")->move(this_object());
 add_item("gargoyle","What gargoyle? There isnt any gargoyle here.");
 remove_item("decoration");
 set("long", "You find yourself in a small secluded area of the west end of the garden. It seems quite tranquil here, there are many trees and you notice a gazebo here. There seems to be some sort of decoration on the roof of the gazebo.");
 add_item("gazebo","It is a small stone hut, circular in shape and with a good view of the lands further down the hill.");
     }
   }

