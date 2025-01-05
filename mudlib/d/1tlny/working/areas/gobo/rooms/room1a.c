#include <dirs.h>
#include <std.h>
#include <gobo.h>


inherit ROOM; 
inherit "/d/areas/gobo/funs";

int snake_present, money_there;

void create()
{
  ::create(); 
  set_property("indoors", 0);  /* outdoors */
  set_property("light", 0); 
  set("short","A narrowing canyoun."); 
  set("day long",
"The pass narrows as the two hills seem to lean towards each other. "
"Looking up, the sides grow much steeper and the shadows much deeper. As "
"you travel down the pass you notice  a large boulder lying to one side "
"of the trail. Other than that all you notice are a few broken weapons "
"lying near the tracks heading north."); 
    set("night long",
"You travel into the darkness and find yourself even more cut off from "
"the light.  The small gravel that crunches beneath your feet "
"echos softly down the canyoun and you can feel the pressing weight of "
"darkness about you."); 
    set_items( ([ 
"tracks":"The tracks look old and faded but it doesn't look "
         "like anything to big made them.", 
"hill":"The sides of the hills get much steeper here. Small rocks " 
       "occasionally tumble down the slopes.",
"boulder":"A large boulder that seems to have been moved here since "
         "it is to large to have fallen here naturally.  It appears to "
         "be partially covering a medium sized hole.",
"hole":"Some small bones lie near the hole but it is to dark to see "
       "anything in there.", 
"weapons":"The broken remains of some iron weapons lie about."]));  
  set_exits( (["north":"room1b", "south":"room1"]) );
  set_smell("default", 
            "The smell of decaying trash and feces fills the air."); 
  set_search("hole", (:call_other,this_object(), "search_hole" :));
  set_listen("default", "The buzz of insects hums in the air." ); 
  set_listen("boulder",(:call_other,this_object(),"listen_boulder":)); 
  set_listen("hole",(:call_other,this_object(),"listen_hole":)); 
} 
 
void init()
{ 
  ::init(); 
  add_action("push_fun","push"); 
}  

void reset()
{
  ::reset();
  money_there = 1;
  snake_present = 1; 
}

void search_hole()
{
object money;
int iskill;
  if(snake_present)
  {
    write(
"As you rummage around in the hole, you notice a flickering of movement. "
"Suddenly you feel a sharp sting in your hand. Something bit you. OUCH!!\n");
    say(TPQCN + 
        " rummages around in the hole. Letting out a startled yelp " +
        this_player()->query_subjective() + "pulls out "+ 
        this_player()->query_possessive() + 
        " hand. Small droplets of blood can be seen on it.\n");
    this_player()->add_hp(-20);
    this_player()->add_poisoning(10);
    return;
  }   
  else if((skill_check("perception", 50) == 1) && money_there)
  {
    money = new("std/obj/coins");
    money->set_money("gold",100);
    money->move(this_object());
    write(
"You rummage around in the hole and find a small pile of coins.\n");
    say(TPQCN + " rummages around in the hole.\n");
    money_there = 0;
    return;
  }
  else 
  {
    write(
"You rummage around in the hole but dont seem to find anything.\n");
    say(TPQCN + " rummages around in the hole.\n");
    return;
  }
}

int push_fun(string str)
{
  object mon;
  if(!str)
  {
    write("What would you like to push?\n"); 
    return 1;
  }else if(str != "boulder")
    return 0;
  else
  {    
    write("You rock the heavy boulder a bit...\n"); 
    say(this_player()->query_cap_name()+" rocks the boulder...\n");
    if(snake_present)
    {
      write("It is very heavy but you hear movement..\n");  
      mon = new(GOBMONSTERS + "snake")->move(this_object()); 
      write("A giant snake slithers out from under the boulder..\n"); 
      say("A giant snake slithers out from under the boulder..\n");
      snake_present = 0; 
    }
    return 1;
  }
}  

void listen_boulder()
{
  if(snake_present)
  {
    write(
"You hear a soft rattling coming from the hole beneath the boulder\n"); 
    say(this_player()->query_cap_name()+" puts his ear to the boulder.\n"); 
  }else
  { 
    write("You hear only silence..");
    say(this_player()->query_cap_name()+" puts his ear to the boulder.\n");
  }
  return;
}  

void listen_hole()
{
  if(snake_present)
  {
    write("You hear a soft rattling coming from the hole..\n"); 
    say(this_player()->query_cap_name()+" puts his ear near the hole.\n"); 
  }else
  { 
    write("You hear only silence.."); 
    say(this_player()->query_cap_name()+" puts his ear near the hole.\n"); 
  }
  return; 
}
