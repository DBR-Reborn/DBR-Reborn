//  Wizard: Shade Maelstorm
 // remove eldarin descrip later
//  Area: Stone Garden
//  Theme: This is a stone garden, in which basilisks and other stoning
// creatures will play.

//  Monsters: The monsters will include caretakers, guards, gardeners, baby
//  basilisks, and other smaller insects, as well as some stone statues.

#include <std.h>
#include <stone_garden.h>

inherit ROOM;


void create() {
 object ob;
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
      set("short", "Gazebo");
 set("long","You are in a small stone gazebo. Its walls seem to be made of the same material as the path, and is just as well designed. The gazebo gives a wonderous view of the surrounding landscape further down the hill. There is a small round table here, upon which there are many runes cut into it.");
 add_item("runes", "Various runes cover the marble tables surface, slightly marring the finely crafted tables surface.");
 add_item("view","The view from this gazebo is amazing. You can see many grassy plains further down the hill, and large woods in the distance. The snow capped mountains barely visible, provide a nice background to the whole picture.");
 add_item("mountains","The snow covered peaks of the mountain range near the garden are barely visible, and only just more than a blue hue is visible");
 add_item("plains","There appear to be farming plains further down the hill, outside of the garden. You can see people cultivating the land with plough and horse.");
 add_item("woods","There appears to be a thickly wooded area behind the farming plains. The woodland itself is rumoured to be haunted and is called 'Eldarins Forest', after an explorer who many years ago went searching for something in that forest for some magical object, and never returned.");
 add_item("eldarin","Eldarin was a mighty elven explorer who lived quite many years ago. He originally set out to explore all the lands around akkad, but became obsessed after hearing of a magical artifact which was rumoured to be held deep within the forest. He dissapeared shortly after entering the woods and was never seen. Some searches were made because of his highly respected stature but none would enter the forest.");
 add_item("landscape","The landscape gently slopes down the hill, and at the bottom are flat grazing lands. Beyond that is 'Eldarins Forest' and further still is the snow capped peaks of the nearby mountain range.");

 ob=new("/std/bboard");
 ob->set_name("board");
 ob->set("id",({"table"}));
 ob->set_board_id("stone_garden_gazebo");
 ob->set_max_posts(15);
 ob->set_location("/wizards/shade/stone_garden/rooms/sg_gazebo");
 ob->set("short","Stone table");
 ob->set("long","This small stone table stands in the center of the gazebo. The table rests about waist height and is marble coloured. There are many runes on its surface, marring the appearance of the table slightly."); 
 ob->set_property("no steal", 1);
 add_exit("sg_room5","out");
}

