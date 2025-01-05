//  Wizard: Shade Maelstorm
//  Area: Stone Garden
//  Theme: This is a stone garden, in which basilisks and other stoning
// creatures will play.

//  Monsters: The monsters will include caretakers, guards, gardeners, baby
//  basilisks, and other smaller insects, as well as some stone statues.

#include <std.h>
#include <stone_garden.h>

inherit ROOM;

int cut_count;


void init() 
{
  ::init();
  add_action("cut_grass","cut");
}

void create() {
  ::create();

  set_property("light", -4);
  set_property("indoors", 1);
  set("short", "Twisted Path");
  set("long","You emerge from the dense undergrowth continuing along the "
             "twisted stone path. The path seems to dissapear from " 
             "behind you as you enter, the passageway closing once " 
             "again. The grasses continue to grow quite high here, and "
             "the trees loom overhead, their thick leaves blocking out "
             "nearly all sunlight, leaving this area dank and cool. " 
             "There are a few statues here, and the land slopes downward "
             "further along.");
  add_item("undergrowth","The dense undergrowth here is entangled with " 
           "the tall grasses, creating a quite thick barrier to movement "
           "in any direction. All of the bushes appear quite thorny and "
           "touching one of the leaves reveals that they are all stone-"
           "like. The dense shrubs are rampant here and only serve to "
           "hinder progress it would seem.");
  add_item("bushes","The bushes here form part of the dense undergrowth. "
          "They are quite thick and tall, and mixed in with the grasses, "
          "make passage through this part of the garden extremely "
          "difficult.");
  add_item("shrubs","The shrubs are quite dense and thorny here. " 
          "They are quite numerous here, the small thorny branches " 
          "quite a hazard to adventurers wandering in this part of the "
          "garden.");
  add_item("grasses","The natural grasses that are growing here are " 
          "quite tall, covering a lot of the statues here, with only the "
          "top part of the statues showing. The grasses appear to be the " 
          "only things that arent stone in this garden, however they " 
          "still do not tend to move because there isnt a single breath "
          "of wind or breeze here.");
  add_item("passageway","The path which you were following just before " 
           "you came here, seems to have vanished in the undergrowth. "
           "The path seems to dissapear altogether here except for the "
           "stones you are currently standing on.");
  add_item("leaves","The leaves on the great stone trees here are " 
           "blocking out nearly all sunlight here, leaving this place " 
           "very dank and cool.");
  add_item("statues","The statues here are almost fully covered by " 
           "grasses here. All you notice is the tops of them, you can " 
           "tell a few seem to be guards of some decription due to spear "
           "shafts showing through the tops of the grasses.");
  add_item("stones","These are some of the stones that form the path "
           "running through this part of the garden. The stones get "
           "covered by dense grasses and other vegetation and you can " 
           "only barely see the ones which are right under you.");
  add_exit("sg_room18","south");
  add_exit("sg_room16","east");
}

 
int cut_grass(string str) 
{
  if(str != "grass" || !str)
  {
    notify_fail("Cut what?\n");
    return 0;
  }
  if(!present("scythe", this_player())) 
  {
    write("You need something more appropriate for cutting grass, " 
          "perhaps like a scythe.");
    return 1;
  }
  if(cut_count)
  {  
    write("The grass doesnt need any more cutting.");
    return 1;
  }
  if(random(10) == 1) 
  {
    write("You find a small rose growing alongside a statue in the far "
          "corner. It must be a wild rose, and was growing through the "
          "grass here.");
    cut_count = 1;
    return 1;
  }
  write("You cut the grass but dont find anything.\n");
  return 1;
}
 
void reset() 
{
  ::reset();
  cut_count=0;
  if(!query_night()) 
    new(MON_PATH+"adult_basilisk")->move(this_object());
}

