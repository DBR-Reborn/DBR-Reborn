// Area:  Gobo caves
// Coders: Amel and Arctic
// May, 97
// Room: room6 

#include <dirs.h> 
#include <std.h> 
#include <def.h>
#include "../gobo.h" 

inherit ROOM; 
inherit "/d/areas/gobo/funs";

int fly_present; 
int rat_present; 
  
void create()
{
  ::create(); 
  set_property("indoors", 1); 
  set_property("light", 1); 
  set_property("night light", 0);
  set("short", "A small cave.\n"); 
  set("long",
"A small cave with a vaulting ceiling that has a small firepit in the " 
"middle.  Some fifteen meters across the place smells like a dump.  The " 
"shadows cast from the flickering light of the pit dance across the room " 
"exposing the cracks and ruggedness of the cave walls. Scattered about " 
"the room are small holes and piles or trash and rags."); 
  set_items(([
({"holes","hole"}):"Small holes dug in the ground measuring only a foot "
"or so across are spaced about the caverns at irregular intervals.", 
({"trash", "rags"}):"It looks like a trash dumped from a sizeable " 
"community consisting mostly of pieces of leather and animal bones. It "
"is covered with small flying insects.",
({"wall","walls"}):"The walls are rough though is difficult to see the " 
"detail in the flickering light.",
"leather":"Worthless scraps of leather are scattered about the trash.",
"bones":"The bones of some small rodents and a few larger animals are " 
"scattered about the trash."])); 
  set_search("rags",(:call_other,TO,"search_trash":)); 
  set_search("trash",(:call_other,TO,"search_trash":)); 
  set_search("hole",(:call_other,TO,"search_hole":));
  set_search("holes",(:call_other,TO,"search_hole":));
  set_search("walls",(:call_other,TO,"search_wall":)); 
  set_search("wall",(:call_other,TO,"search_wall":)); 
  set_exits((["north":GOBROOMS+"room7","crevice":GOBROOMS+"room6a",
              "south":GOBROOMS+"room5"]));
  add_invis_exit("crevice"); 
  set_smell("default", "A foul odor invades your nostrils."); 
  set_smell("crevice","Cleaner air seems to be coming from here."); 
  set_listen("default","The buzz of insects is quite loud here."); 
  set_listen("crevice",
"The wind makes a soft whistling sound as it passes out of here."); 
  set_pre_exit_functions(({"north","crevice"}),({"leave_room"})); 
}
  
void reset() 
{
int counter; 
  ::reset(); 
  counter = 8; 
  fly_present = random(15); 
  rat_present = random(10);
  if(!present("gobo_male"))
  {
    while(counter > 0)
    {
      new(GOBMONSTERS+"gobo_male")->move(TO); 
      counter--;  
    }
}
}

void init() 
{
  ::init(); 
  add_action("take","get"); 
}  

void search_hole()
{
int rand_fly_found;  
  write("You reach in the hole feeling gobo feces.\n");  
  say(TPQN+" reaches in one of the holes.\n"); 
  if (fly_present > 0) 
  {
    rand_fly_found = random(5); 
    if (rand_fly_found > fly_present) 
      rand_fly_found = fly_present;
    write("Some flies are agravated by your intrusion and take flight.\n"); 
    say(TPQN+" reaches in a hole and some huge flies come out.\n"); 
    while (rand_fly_found > 0)
    {
      new(GOBMONSTERS+"cave_fly")->move(TO); 
      rand_fly_found--;  
    }
  }
}

void search_trash()
{
int number_of_rats_found; 
object mon; 
number_of_rats_found = random(5); 
  if (number_of_rats_found > rat_present)
      number_of_rats_found = rat_present; 
  if(number_of_rats_found == 0)
  {
    write(
"You search the trash for more rats and find only droppings.\n");
    say(this_player()->query_cap_name()+" searches the trash.\n"); 
  }else if(number_of_rats_found == 1)
  {
    write("You search the boulders and an angry rat scuries out."); 
    say(this_player()->query_cap_name()+
" searches the boulders and an angry rat scuries out.\n"); 
  }else
  {
    write("You search the boulders and some angry rats scury out."); 
    say(this_player()->query_cap_name()+
" searches the boulders and an angry rat scuries out.");
  } 
  rat_present -= number_of_rats_found; 
  while(number_of_rats_found > 0)
  { 
    mon = new(GOBMONSTERS + "rat");
    mon->move(this_object()); 
    number_of_rats_found--; 
  }    
  return;  
}
  
int search_wall() 
{
  write(
"You search the walls and you find a crevice you might squeeze into.\n");
  say(TPQN+" explores the west wall by hand.\n"); 
  return 1;
}

int take(string str)
{
  if(!str || str != "leather" || str != "bones")
    return 0;
  if(str == "leather") 
  {
    write("The leather crumbles as you pick up the small pieces.\n"); 
    say(TPQN+
" picks up some of the leather pieces that crumble in his hands.\n"); 
  return 1;
  }    
  if(str == "bones") 
  {
    write(
"You pick up a few small bones and seeing they are worthless toss them to " 
"the side.\n"); 
    say(TPQN+
" picks up some of the small bones and tosses them to the side.\n"); 
  return 1;
  }
}

void leave_room()
{
int falling_check, rand, falling_damage, size_of_stalactite; 
string desc_of_stalactite; 
    
  falling_check = random(100); 
  if(falling_check < 5)
    size_of_stalactite = random(2) + 2; 
  switch(size_of_stalactite)
  {
    case 1:desc_of_stalactite = "small shard or rock"; 
           break; 
    case 2:desc_of_stalactite = "good size piece of stone"; 
           break; 
    case 3:desc_of_stalactite = "medium boulder chiseled to a fine point";  
           break; 
  }
  if (skill_check("perception",30))
  {
    write("A "+desc_of_stalactite+" falls from the ceiling narrowly "
          "missing you.\n"); 
    say("A "+desc_of_stalactite+" falls from the ceiling narrowly missing "
        + TPQN + ".\n"); 
  }else
  {
    write("A "+desc_of_stalactite+" falls from the ceiling impaling you "
          "with its weight.\n"); 
    say(TPQN+" is hit by a "+desc_of_stalactite+" that falls from the "
        "darkness above.\n"); 
    rand = random(10); 
    falling_damage = size_of_stalactite * rand; 
    this_player()->add_hp(gen_rand_damage(falling_damage)); 
  }    
}
