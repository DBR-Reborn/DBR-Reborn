#include <daemons.h>

inherit "/std/vault";

private int open;


void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/wizards/shade/stone_garden/rooms/temple7", "north");
  add_exit("temple9","south");
   set_door("stone door", "/wizards/shade/stone_garden/rooms/temple9", "south",
  "stone garden key");
   set_open("stone door", 0);
   set_locked("stone door", 1);

  add_pre_exit_function("south", "go_south");
   set("short","Sacred room");
   set("long",

 "You have entered a small room, which is adorned with all sorts of pictures on it. The walls of this room have been cleaned vigourously and the stonework has been brought to a nice shine. There is not a single piece of moss to be seen anywhere on these walls. There is a wood door to the south, but the door seems strange.");
 add_item("wood door","The wooden door to the south appears different somehow. Upon closer inspection, you notice why, it is petrified wood!. The whole door is as hard as stone, and probably just as heavy.");
 add_item("walls","The stone walls here are quite clean, large marble slabs have been used to tile the room and give quite an impressive finish. They also enhance the pictures which appear all over this room.");
 add_item("stonework","Large slabs of marble have been used to tile the walls of this room. The strength required to place them along the walls must have been immense, judging by the size of the tiles.");
 add_item("moss","The moss is non existant in this room. Someone has done a very good job at cleaning the walls here. They give off a slight irredescent glow of their own as well, must be something in the fluid used to clean it.");
 add_item("pictures","There are many gold inlaid pictures on all the walls here. They seem to form a mural almost, telling a story of events long past, but which appear to be one of which is highly revered by the inhabitants of this temple. Each wall seems to tell one part of the story, and you notice that all the walls are covered, even those with doors, have images going around the door recesses.");
 add_item("west wall","The west wall mural depicts life of long ago, there are many people with hoes and cultivating instruments, cultivating a garden. You remember the farming lands which were viewable from the window.... Maybe they were a group of farmers, who were planning to cultivate here. The people are busy and appear to be working hard to try and cultivate the land.");
 add_item("east wall","This wall's image portray a great time of sadness and woe. Many of the peasants appear to be dieing from something, and a small well is depicted in one of the images. The feeling of sadness eminating from these images is immense and the images all have violent storms in them. ");
 add_item("north wall","The north wall's images curve around the door recesses. The images portrayed here are of a large creature, black as night coming in and fiery red lights coming from its eyes. Many people are depicted as statues, and the already dieing seem to be begging the creature for help. The next series of images depict a happier time. A picture of a shrine is here, and the apparent illness which plagued the people seems to have gone. The people seem different somehow, and a few larger pictures depict the people lifting huge stone blocks, and erecting various small stone structures.");
 add_item("south wall","The images formed around the door on the south wall, depict a kindly creature, with black fur but with a green glow in its eyes. Several words are inscribed around this creature and in the foreground is a beautiful garden, with trees, bushes, and various stone structures.");
 add_item("bushes","Various bushes and plants are depicted on the south wall. There seems to be a picture of each plant with a description underneath, which you cannot decipher. In the middle is a large image of a grey rose."); 
add_item("trees","Various trees are depicted here, they seem to be of the same nature as the plants, and you notice a few of the trees depicted have fruit in their branches.");
 add_item("image","There are many images here, which are embedded on all the walls here. Perhaps you should try looking at a particular wall?");
 add_item("images","The images decorate all the walls in the room. Perhaps you should try looking at a particular wall?");
 add_item("stone structures","There are various stone structures depicted, the ones standing out are mainly a gazebo, a guard hut, a small gardening shed, and a large temple.");
 add_item("gazebo","There is a white gazebo pictured here. It is a small round open type of room, which appears to have a good view of surrounding lands. There is an odd decoration on the roof of the gazebo, which you cannot make out.");
 add_item("decoration","The decoration on the gazebo is too small to decipher. All you can tell its it appears to be a crouched creature, but it is quite small and hard to tell.");
 add_item("guard hut","There appears to be a hut, with a rose symbol on it. Next to the hut is depicted a soldier and he seems to be blocking passage past the hut. The face on the soldier is grim, and heavy set.");
 add_item("soldier","There is a picture of a soldier depicted on the guard hut picture.");
 add_item("rose symbol","As you notice the rose symbol, you remember seeing it appearing on a few other pictures. It appears to be in many pictures as a matter of fact. The rose however is not a red rose, but one of stark grey.");
 add_item("rose symbol","As you notice the rose symbol, you remember seeing it appearing on a few other pictures. It appears to be in many pictures as a matter of fact. The rose however is not a red rose, but one of stark grey.");
 add_item("creature","The creature appears to resemble a rather large basilisk. The pictures of it are predominant on the south wall.");
 add_item("basilisk","The basilisk seems to be a revered creature here. I wonder why?");
}

 void reset() {
 int i;
  ::reset();
  seteuid(geteuid());
  if(!present("disciple")) {
  i=2;
  while(i--)
  new("/wizards/shade/stone_garden/mon/acolyte_disciple")->move(this_object());
  }
  if(!present("rose_priest")) {
  new("/wizards/shade/stone_garden/mon/rose_priest")->move(this_object());
 }
 }

 int go_south() {
  if(present("disciple")) {
  write("The priest stops you. ""You cannot enter that sacred ground, fool! Begone!"".");
  return 0;
 }
 else return 1;
 }

