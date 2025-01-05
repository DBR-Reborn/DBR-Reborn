// Area:  Gobo cave
// Coders: Amel and Arctic
// May, 97
// Room: room6d.c
// Room A small cave 

#include <dirs.h> 
#include <std.h>
#include <def.h>
#include "../gobo.h" 
  
inherit "/d/areas/gobo/funs";
inherit ROOM; 
  
void create()
{
  ::create(); 
  set_property("indoors", 1); 
  set_property("light", 0); 
  set("short", "A small cave");  
  set("long",
"A small cave that has a little more light filtering in from a crack in "
"the wall.  The cave measures some thirty meters across in a generally "
"circular shape and looks remarkably clean given the state of the rest of "
"the caves you've been to. Some small threads lie scattered about the " 
"ground.  To the south there appears to be a passage leading into a "
"narrow crevice.");  
  set_items(([
({"thread","threads"}):"The threads are thin and seem to be quite long. "
"Most seem to reach up to the ceiling.", 
({"wall","walls","crack"}): "The solid stone walls tears at your clothes "
"as you touch thier rough surfaces. There appears to be a crack in the " 
"northeastern portion of the wall.. you might be able to fit through "
"it."])); 
set_exits((["south":GOBROOMS+"room6c","crack":GOBROOMS+"room14"]));
add_invis_exit("crack");
  add_invis_exit("crevice");  
  set_smell("default", 
"The air here smells refreshing, there must be an air shaft in the " 
"ceiling."); 
  set_listen("default","The echo of your footsteps can be heard all around "
             "you, almost covering a soft muttering sound."); 
  set_listen("noises",
"You hear the faint sound of water drops and a strange fluttering sound."); 
  set_listen("muttering","Sounds like there is a gobo talking just beyond "
             "a crack in the north eastern wall.");
}
 
void init()
{
  ::init();
  add_action("touch_sack",({"break","touch","feel","take","rip","bash"})); 
}
  
int touch_sack(string str)
{
  if(!str || str != "sack") 
  {
    write("What do you want to do?");
    return 1;
  }
  else
  {
    write("Trying to get it, you accidentally rip the sack.. and notice "
          "some movement overhead.\n"); 
    say(TPQCN+
" accidentally rips the sack.. you notice some movement overhead.\n"); 
    remove_item("ceiling"); 
    add_item("ceiling",
"A few broken strands of thread hang down from the ceiling.\n"); 
    remove_item("sack"); 
    delayed_call("load_spider", 4);
    return 1;
  }
}
 
void load_spider()
{
 
  write("A huge spider drops from the ceiling... and it looks hungry.\n"); 
  say("A huge spider drops from the ceiling... and it looks hungry.\n"); 
  new(GOBMONSTERS+"giant_spider")->move(TO); 
}  

void reset() 
{
  ::reset();  
  remove_item("ceiling"); 
  add_item("ceiling",
"The ceiling quickly launches to new unseen heights in the darkness, but " 
"you can see a sack about a meter in diameter supported some three meters "
"up a few threads."); 
  add_item("sack",
"The sack looks to woven from some kind of shiny thread though its hard "
"to tell without touching it."); 
}
