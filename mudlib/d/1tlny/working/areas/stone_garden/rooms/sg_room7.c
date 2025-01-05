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
      set("short", "Well");
set("long","As you walk along the strange white pebbled path, you notice a well here. The grass around the well is quite green, however that is about the only noticeable difference. All the other plants, bushes and trees lining the path appear quite normal if not slightly marred. You see a flash of light in one of the trees, but then it dissapears.");
 add_item("well","As you examine the well closely, you can see that it has collapsed at the bottom. Rocks and rubble seem to fill the inner parts of the well, and the outside shell is all that remains. Water must however still seep up through the soil or rock, as by looking at the grass it is quite lush and tall in certain spots. The well is covered by a small circular stone roof, with the roof stones being covered in some kind of coating to ward off the rain.");
 add_item("rocks","The rocks fill in inner parts of the well. It appears as if the well has collapsed, or has been purposely filled in by some vandal. Such a shame, as water seems to be sorely needed here.");
 add_item("rubble","stone rubble and rocks fill in the inner chamber of the stone well. All of the rubble is moist but no water is to be seen.");
 add_item("shell","The outer shell of the well makes it look normal from the outside. It is a nicely made stone well, built of hewn stone blocks packed into a circle, with a stone roof supported by petrified wood beams.");
 add_item("plants","The plants that are here in the garden, apear to be made of stone. The small bushes appear quite thorny but quite firmly made of stone. No wonder all the other plantlife appears normal, they wouldnt need any.");
 add_item("trees","The trees overlooking the pebbled trail here, all appear to be petrfied, at least at the base. There strong branches spanning out stand totally still, as do their leaves. You begin to wonder where is the wind? You havent felt a breeze in this park anywhere. The air around you is cold and still.");
 add_item("light","You thought you saw a flash of light somewhere in the trees, you must have been mistaken, as you have seen the only 'living' creatures here seem to be creatures of death, and people employed to take care of the garden.");
 add_item("grass","The grass here provides a partial ground cover here, although the grass right next to the pebbled path appears worn. Next to the well however, the grass seems to be growing quite well.");
 add_item("beams","The petrified wood beams supporting the roof of the well look quite strong and thick.");
 add_item("bushes","The small bushes in this area of the park are extremely nice to look at. Upon closer inspection however, they seem to have quite thorny branches.");
 add_item("flash","You see a fast movement of color in the trees. Before you ccan focus on the exact position of the flash in the trees, it stops. Further attempts to try and see what is was are in vain.");
 add_item("path","The stone path has been reduced to a small collection of white rubble, smooth pebbled stones, worn away by weather and stress. This part of the path obviously needs some repair.");
  add_exit("sg_room8","north");
 add_exit("sg_room6","west");
}

 void reset() {
  ::reset();
  if((query_night()) && (!present("adult_basilisk"))) {
  new(MON_PATH+"adult_basilisk")->move(this_object());
   }
 }


