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
    set_property("light", 2);
    set_property("indoors", 1);
      set("short", "Stone Garden Nursery");
 set("long","The nursery path continues along the north here, and what seems to suprise you is the constant 'crackle' as you walk along. Flowers line the paths here, and many of them appear to be rosebushes, yet still appear immature, unfortunately with no roses yet. There are other plants but by far the majority seem to be rose bushes."); 
 set("long","As you walk along through the nursery, you begin to notice the flowers which line the paths here, many of them appear to be rosebushes, yet still appear immature, unfortunately with no roses yet. There are other plants but by far the majority seem to be rose bushes but not a single rose to be found. The nursery stone path continues to the east and north here."); 
 add_item("flowers","There are many small bushes here, however it must be the wrong time for flowering as none of them seem to have flowers on them. Rose bushes are also here, and they seem to be in greater number than the other plant types, but also dont have any flowers on them.");
 add_item("plants","Small plants are arranged in various formations following the path along. Apparently there are gardeners of some description here, who care for this small nursery.");
 add_item("rosebushes","You can tell they are rosebushes by the thorny long stems, and tell tale appearance. These ones dont seem to have any roses on them, perhaps you should come back here in like next season?.");
 add_item("path","The broken stone path continues through the nursery, and dissapears to the north being obscured from view by all the trees which fill this area.");
 add_item("trees","The trees here are different to what are in the rest of the garden. Their trunks are not as wide, and they tend to form long straight lines. There spacing is uniform and the trees all seem around the same height.");

 add_item("path","The path is made of broken stone and winds through the stone nursery. Looking closely at the road, you see small pieces of something. Looks like small stone insect pieces, small stone wings and other crumpled insect parts, all made of stone. Whoever made stone insect statues and put them right on the path, must have had an amazing lack of foresight.");
 add_item("rat","There is a small rat statue frozen to the side of a tree trunk here. Its teeth are bared, and it looks ready to leap, although there is absolutely nothing in front of it.");
 add_item("pieces","Small insect parts made of stone are what has been making that crackling sound you heard. It seems the baby basilisks have been running around here, zapping poor litle creatures and insects.");
 add_item("wings","These small stone wings appear to be part of a large wasp. The wasps reflexes must be slower than the basilisks it seems.");
 add_item("statues","Barely visible on the ground are insect statues littering the path here. Wasps, and various other insects even a rat it seems is not safe, as you notice a rat statue, hugging close to one of the nearby trees.");
 set_listen("default","You hear a crackling sound as you walk along.");
  add_exit("sg_garden2","east");
  add_exit("sg_garden4","north");
}

  void reset() {
    ::reset();
    if(!present("baby_basilisk")) {
    new(MON_PATH+"baby_basilisk")->move(this_object());

}

    if(!present("troll_gardener")) {
    new(MON_PATH+"troll_gardener")->move(this_object());
    }
}
