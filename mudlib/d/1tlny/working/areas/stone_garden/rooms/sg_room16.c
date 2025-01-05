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
    set_property("light", -4);
    set_property("indoors", 1);
      set("short", "Descending steps");
 set("long","As you push your way through the dense vegatation, you definately notice the slope of the land now. There are small steps leading down the hillside here, but they vanish from view about halfway down the hill, where the dense scrub becomes thickest. The statues, from what you can see of them all appear to be horizontally aligned somehow, standing upright against the sloping ground. The trees which continue to envelope the path, grass and shrubs in almost utter darkness continue in all directions.");
  add_exit("sg_room14","steps");
 add_item("steps","There are steps going down the hillside in a northerly direction, but they vanish under immensely thick grasses and bushes, and you cannot be sure if they actually lead anywhere now or are totally blocked off now by the conquering plant life.");
add_item("vegetation","The vegatation here thins out a little at the top of the hill, but gaining number about halfway down the hill where the steps seem to stop. It seems to surround much of the path, if not as thick as before, and you are thankful for this meager blessing, even though the trees still loom overhead like giant stone omens.");
 add_item("land","The land slopes down from south to north here. ");
 add_item("grasses","The grasses are really long in this garden, they could use a good cutting you think.");
 add_item("statues","The few stone statues that line the path and the steps, are of various forms, some are knights, guards just to name but a few.");
 add_item("path","The path seems to stop here, and narrow stone steps lead down further into the darkness of the hillside's base.");
add_item("knights","There is one statue of a knight here. Its stone sword is raised unto heaven, as if the knight was calling on some divine interference, perhaps preparing for battle. It seems his preparation was not quick enough, you notice, his stone form now a permanent feature in the garden.");
 add_item("guards","A few stone statues of soldiers are resting here. All at attention, they appear fine except for a horrid face, one which seems to express extreme fear. Whoever made these statues, has an extremely sick mind, or else there is something more to this than may first appear.");
add_item("hill","The hill slopes down south to north here, with steps going down its slope. The grasses are still growing everywhere if not as high, and the brush have thinned out quite a bit in this area. You wish you could tell if there was sun outside or not, but it is extremely hard to tell giving the dense canopy overhead which continues to follow the path overhead.");
 add_item("hill","The hill slopes down south to north here, with steps going down its slope. The grasses are still growing everywhere if not as high, and the brush have thinned out quite a bit in this area. You wish you could tell if there was sun outside or not, but it is extremely hard to tell giving the dense canopy overhead which continues to follow the path overhead.");
 add_item("grass","The grass is quite tall here, and tangles in with the other vegetation making passage difficult.");
 add_item("shrubs","The shrubs seem to be less frequent here at the top of the hill, but become more dense further down. The bushes which you just came through seemed to have enveloped the path you just came from, leaving no trace of the path, and if you stand still for a moment, you can almost sense the bushes closing in on this place.");
  add_exit("sg_room17","west");

 set_listen("default","You hear the small trickling sound of water coming from down the hill.");
}

  void reset() {
  if((query_night()) && (!present("adult_basilisk"))) {
  new(MON_PATH+"adult_basilisk")->move(this_object());
 }
}


