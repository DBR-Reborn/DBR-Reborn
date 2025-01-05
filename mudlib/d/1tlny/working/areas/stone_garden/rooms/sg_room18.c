//  Wizard: Shade Maelstorm
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
    set_property("light", 1);
    set_property("indoors", 1);
      set("short", "Twisted path");
    set("long", "You are on a long twisting path winding through a darker section of the garden. Grasses as tall as 4ft are growing here, and there are a few statues in this section of the path, although you can really only see the top of them. Most of the other features of the statue are covered by thick grass and dense vegetation. The path seems to meander around but then dissapears off in the distance without a trace. Tall trees grow over the path, and block out most of the sunlight that would otherwise have shone down on this part of the garden.");
 add_item("path", "The paths twist around and dissappear behind some bushes. It is hard to tell where the path actually leads in any direction.");
 add_item("grass", "The grasses growing here are quite tall, and cover most of the path and statues here. In a few places, the grass appears to have been stomped on, as if someone has been here before.");
 add_item("bushes","The dense undergrowth here is quite remarkable, and the path seems to wind through all of it. The undergrowth itself appears quite thorny too.");
 add_item("bush","You examine one small bush forming part of the undergrowth here. It is extremely thorny, and is petrified. Being poisoned by one of those thorns would be an experience best left for someone else.");
 add_item("grasses", "The grasses around here are extremely tall, and deadly still. There are a few grasses which seem to have been pushed flat to the ground, as if someone has been tracing around here before you.");
 add_item("statues","The statues here are all standing on odd angles, and only the top of them is really visible. The rest are covered by long grasses.");
 add_item("vegetation","The vegetation here is very dense, and overgrows the path and most of the statues here, along with the grass. The bushes appear wierd though...");
 add_item("vegetation","The vegetation here is very dense, overgrowing the path and most of the statues here, along with the grass. The bushes appear wierd though...");
 add_item("features","Most of the features of the statues have been covered up by the long grasses here.");
add_item("trees","Tall trees are growing all around here, blocking out most of what little sunlight there is. The sunlight that eventually does reach the path is extremely dim, and barely does more than keep this part of the garden in total darkeness.");
add_item("tree","This one tree seems to be made of stone. Looking closer, you notice it is actually petrified wood. It has all the colours of wood, as the tree would have in life but it is as hard as rock. Its branches, and leaves look so real, from a distance you wouldnt notice it was any different. As you turn around, you suddenly notice all the trees appear to be petrified.");
 add_item("sunlight","The filtered sunlight that does reach the path here is nothing more than a dim torch light. The few patches of sky through the trees are very few and very small.");
 add_item("sky","You cant really see any sky, just small pinholes of light in the through the trees uppermost branches.");
 add_item("branches","The branches of the trees are thick, and spread outward, but strangely, dont appear to move at all. Whats more strange is that there doesnt appear to be any breeze here at all, giving this part of the park a porcelain look to it."); 
 add_item("sunlight","There are a few pinholes of light filtering through the dense tree canopy, but not enough to warm anything under canopy, and barely enough to give any sort of light at all.");
  add_exit("sg_room17","north");
  add_exit("sg_entrance","west");
}



