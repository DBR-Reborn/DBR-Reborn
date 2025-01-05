// Area:  Gobo caves
// Coders: Amel and Arctic
// May, 97
// Room: room14.c 

#include <dirs.h> 
#include <std.h> 
#include <def.h>
#include "../gobo.h"  

inherit "/d/areas/gobo/funs";
inherit ROOM;  

int table_present, vial_present, rug_present, exit_present; 
int tubing_present, torch_present; 
  
void create()
{
  ::create(); 
  set_property("indoors", 1); 
  set_property("light", 1); 
  set_property("night light", 0); 
  set("short", "A small cave."); 
  set("long",
"The passage opens to a small circular cave some tem meters across. " 
"There are passages to the west, south, and northeast from here.  The " 
"room is filled with pictures and a rug on one wall.  A table sits " 
"against the east wall with several vials on it and a strange arangement " 
"of copper tubing.  A torch mountis attached to the wall."); 
  set_items(([
({"wall","walls"}):"The stone here is smooth and covered with crude " 
"pictures. There is a crack in the south east corner.",
"ceiling":"The ceiling is only a few meters high here and looks to have "
"been carved out a little.",
"crack":"This looks like a natural crack in the stone that you might be " 
"able to squeeze through.",
"table":
"A small wood table cluttered with vials and some copper tubing. It "
"looks like an experiment that may have been successful.",
({"copper tubing","tubing"}):
"Several pieces of thin tubing made of copper run from one vial to the "
"next.",
"vial":"A small vial with some purple liquid in it.",
"rug": 
"A large wall rug with a picture of several small gobos fighting a huge "
"purple worm."]));
  set_exits((["south":GOBROOMS+"room13","crack":GOBROOMS+"room6d"])); 
  add_invis_exit("crack"); 
  set_smell("default", "Strange pungent smells abound here."); 
  set_listen("default",
"There are bubbling sounds coming from the vials on the table."); 
  set_smell("vial","You should probably take it off the table first."); 
}  

void reset() 
{ 
int rand; 
  ::reset(); 
  rand = random(3) + 1; 
/*
  if(!present("gobo_shaman")) new(GOBMONSTERS+"gobo_shaman")->move(TO); 
  if(!present("gobo_malea") && rand ==3)
    new(GOBMONSTERS+"gobo_malea")->move(TO);
*/  
  rug_present = 1; 
  tubing_present =1 ;  
  torch_present =1; 
  table_present = 1; 
  vial_present = 1; 
  exit_present = 0; 
  remove_item("vial");
  remove_item("liquid"); 
  remove_item("table"); 
  add_item("table",
"A small wood table cluttered with vials and some copper tubing. It "
"looks like an experiment that may have been successful."); 
  add_item("vial","A small vial with some purple liquid in it.\n"); 
  add_item(({"tubing","copper tubing"}),
"Several pieces of thin tubing made of copper run from one vial to the "
"next."); 
  add_item("rug",
"A large wall rug with a picture of several small gobos fighting a huge "
"purple worm."); 
  remove_exit("east"); 
}  

void init()
{
  ::init(); 
  add_action("take","get"); 
  add_action("smash_table","smash"); 
  add_action("pull_rug","pull"); 
  add_action("move_table","push"); 
  add_action("move_table","move"); 
  add_action("move_table","shove"); 
}  

int take(string str)
{
string *item_array = ({"torch", "tubing", "rug", "vial", "table"});
  
  if(!str || (member_array(str, item_array, 0) == -1))
    return 0;
  if(str == "torch" && torch_present)
  {
    write("You take the torch from the stand in the wall.\n"); 
    say(TPQCN+" takes the torch from the wall.\n"); 
    remove_item("torch"); 
    torch_present = 0;
    new(GOBMISC+"torch")->move(TP); 
    return 1; 
  }    
  else if(str == "tubing" && tubing_present)
  {
    write("You take the tubing from the table.\n"); 
    say(TPQCN+" takes the tubing from from the table.\n"); 
    remove_item(({"tubing","copper tubing"})); 
    tubing_present = 0; 
    new(GOBMISC+"tubing")->move(TP); 
    return 1;
  }    
  else if(str == "rug" && rug_present)
  {
    write(
"The rug seems to be pinned to the wall, perhaps you could pull it " 
"down.\n"); 
    say(TPQCN+" examines the rug for a moment.\n");
    return 1; 
  }    
  else if(str == "vial" && vial_present)
  {
    write("You take the vial from the table.\n"); 
    say(TPQCN+" takes the vial from the table.\n"); 
    remove_item("vial"); 
    new(GOBMISC+"vial")->move(TP);
    vial_present = 0;
    return 1;
  } 
  else if(str == "table" && table_present == 1)
  {
    write("The table is to heavy to lift.. \n"); 
    say(TPQCN+" tries to pick up the table, but it looks like it was to "
        "heavy.\n"); 
    return 1;
  }
  else if(str == "table" && table_present == -1)
  {
    write("You pick some pieces of the table.. \n"); 
    say(TPQCN+" picks up some pieces of the table.. \n"); 
    remove_item("table"); 
    table_present = 0; 
    new(GOBMISC + "tabledebris")->move(TP);
  }
  else if (str == "table" && !table_present)
  {
    write("All that is left are little splinters.\n");
    return 1;
  }
  else
    return 0;
}  

int smash_table(string str)
{
  if(!str || (str != "table") || (str != "vial"))
  { 
    write("You want to smash what?\n");
    return 1;
  } 
  if(str == "table" && table_present == 1)
  {
    write(
"The wood chips fly as you smash the table into bits and pieces.\n"); 
    say(this_player()->query_cap_name()+
" flies into a rage smashing the table rack in to several pieces.\n"); 
    remove_item("table"); 
    add_item("table",
"It looks like someone has taken out their frustration on a table, all " 
"that is left is pieces of of broken wood."); 
    table_present = -1; 
    if(rug_present == 1 && exit_present == 0) 
    {
      write("You hear the soft grinding noise of rock on rock. \n"); 
      say("You hear the soft grinding noise of rock on rock. \n"); 
      exit_present = 1; 
    }    
    else if(rug_present == 0 && exit_present == 0)
    {
      write(
"A section of the east wall swings away revealing a passage.\n"); 
      say(
"A section of the east wall swings away revealing a passage.\n"); 
      exit_present = 1;
      add_exit("east", GOBROOMS+"room15b"); 
    }     
    return 1;
  }
  else if(str == "table" && table_present == -1) 
  {
    write("It is already in pieces.. \n");  
    return 1;
  }
  else if(str == "vial" && vial_present == 1)
  {
    write("You smash the glass vial shattering it and scatering it and "
          "the liquid on the table and floor.\n"); 
    say(TPQCN+" smashes the vial into many small pieces.\n"); 
    remove_item("vial"); 
    add_item("vial","Some small pieces of glass are all that remain of a "
             "vial."); 
    add_item("liquid","Some purple liquid is splashed on the table and "
             "floor."); 
    vial_present =0;
    return; 
  }    
  else if(str == "vial" && vial_present == 0)
  {
    write("You stomp on the few pieces of glass left on the ground.\n"); 
    say(TPQCN+" crushes some glass on the ground.\n"); 
    return 1;  
  }
}

int pull_rug(string str)
{ 
  if(!str || str != "rug")
  { 
    write("You want to pull what?\n"); 
    return 1;
  }    
  else if(rug_present)
  {
    write("You pull the rug from the wall and it falls to the floor.\n"); 
    say(TPQCN+" pulls the rug from the wall allowing it to fall to the "
        "floor.\n");  
    new(GOBMISC+"rug")->move(TO); 
    remove_item("rug"); 
    rug_present = 0; 
    if((table_present < 1) && exit_present)
    {
      write(
"You have uncovered a passage behind the rug heading east.. \n"); 
      say(TPQCN+
" has uncovered a passageway behind the rug heading east.. \n"); 
      exit_present = 1; 
      add_exit("east", GOBROOMS+"room15b"); 
    }
    return 1;
  }
  else
  {
    write("The rug has been moved already.\n");
    return 1;
  }
}

int move_table(string str)
{ 
  if(!str || str != "table")
  {
    write("What do you want to do.. ?\n"); 
    return 1;
  }
  else if(table_present == -1)
  { 
    write("The table has been smashed into to many small pieces to " 
          "move.\n"); 
    return 1;
  }    
  else if(table_present == 0) 
  {
    write("There aren't even pieces of a table left here.\n"); 
    return 1;
  }    
  else if(table_present == 1 && exit_present == 0)
  {
    write("You shift the table a few feet and you hear the grinding sound "
          "of rock on rock.. \n"); 
    say(TPQCN+" shifts the table a few feet and you hear the grinding "
        "sound of rock on rock.. \n"); 
    exit_present = 1; 
    if(rug_present == 0)
    {
      add_exit(GOBMONSTERS+"room15b","east"); 
      write("You see a portion of the east wall swing back revealing a "
            "passage beyond.\n"); 
      say("You see a portion of the east wall swing back revealing a "
          "passage beyond.\n"); 
    } 
    return 1;    
  }      
}
