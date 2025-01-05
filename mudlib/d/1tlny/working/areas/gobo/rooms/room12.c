// Area:  Gobo caves
// Coders: Amel and Arctic
// May, 97 
// Room: room12.c 
#include <dirs.h> 
#include <std.h> 
#include <def.h> 
#include "../gobo.h"  

inherit "/d/areas/gobo/funs";
inherit ROOM; 
  
int table_present; 
int torch_present;  

void create()
{
  ::create(); 
  set_property("indoors", 1); 
  set_property("light", 1); 
  set_property("night light", 0); 
  set("short", "A small cave."); 
  set("long", 
"The passage opens up here into a small cave a few metres across. There " 
"are passages to the west, south and northeast. In the centre from the " 
"room is a table. A mount for a torch is attached to one of the walls.");  
  set_items(([
({"wall","walls"}):"The stone here is solid and rough having never been "
"worked.",
"ceiling":"The ceiling is only a few meters high here and looks to have "
"been carved out a little.",
"mount":"The mount contains a flickering torch.",
"table":"A small wooden table that the gobo who stands watch here can use.",
"torch":"A standard torch sitting in a mount attached to the wall."]) ); 
  set_exits((["northeast":GOBROOMS+"room15","south":GOBROOMS+"room11",
              "west":GOBROOMS+"room13"])); 
  set_smell("default", 
"Apart from the smoke, it smells remarkably clean here."); 
    set_listen("default","It is awefully quite."); 
}  

void reset() 
{
  int rand; 
  ::reset(); 
  rand = random(3) + 1; 
/*  
  if(!present("gobo_champion"))
    new(GOBMONSTERS+"gobo_champion")->move(TO);  
  if(!present("gobo_malea") && rand == 3); 
    (while(rand > 0)
    {
      rand--;  
      new(GOBMONSTERS+"gobo_malea")->move(TO);
    }
*/ 
  torch_present = 1;
  table_present = 1;  
  remove_item("table"); 
  add_item("table",
"A small wooden table that the gobo who stands watch here can use.");
  remove_item("torch");
  add_item("torch",
"A standard torch sitting in a mount attached to the wall."); 
  remove_item("mount");
  add_item("mount","The mount contains a flickering torch.");
}  

void init()
{
  ::init(); 
  add_action("take_torch","get"); 
  add_action("smash_table","smash"); 
}
  
int take_torch(string str)
{
  if(!str || str != "torch" || !torch_present) 
    return 0;
  else if(present("goblin"))
  {
    write("The goblin screams: Leave me flamestick alone!\n");
    say("The goblin screams: Leave me flamestick alone!\n");
    return 1;
  }
  else
  {
    write("You take the torch from the stand in the wall.\n"); 
    say(TPQCN+" takes the torch from the wall.\n"); 
    remove_item("torch"); 
    remove_item("mount");
    add_item("mount","The torch mount is empty.");
    torch_present = 0;
    new(GOBMISC+"torch")->move(TP); 
    return 1;
  }
}  

int smash_table(string str) 
{
  if(!str || str != "table")
  {
    write("You want to smash what?\n");
    return 1; 
  }
  else if(table_present)
  {
    write(
"The wood chips fly as you smash the table into bits and pieces.\n"); 
    say(this_player()->query_cap_name()+
" flies into a rage smashing the table rack in to several pieces.\n"); 
    remove_item("table"); 
    add_item("table",
"It looks like someone has taken out their frustration on a table, all " 
"that is left is pieces of of broken wood.");  
    return 1;   
  }  
  else 
  {
    write("Someone else has already smash the table.\n");
    return 1;
  }
}

