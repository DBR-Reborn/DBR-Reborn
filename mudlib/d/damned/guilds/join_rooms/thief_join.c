//  Maxwell's UnderGround Mudlib
//  Thief Guild Joining Room

#include "/d/damned/guilds/thief/under.h"
inherit "/std/guilds/join_room";

void create() {
  set_class_name("thief");
  ::create();
  set_property("light",1);
  set_property("indoors", 1);
  set("short", "The Thieves Guild Joining Room");
  set("long", 
    "You are standing in an old temple room. The crumbling walls are "
    "covered in dust and filled with cracks. Huge columns are evenly "
    "spaced along the edge of the circular room. Some of them have begun "
    "to split and look unstable.\n"
    "Three arches lead out of the room, one to the north, one to the west "
    "and another to the east. A side passage leads to the south, back to "
    "the sewers.\n");
  set_exits( ({ UNTHIEF+"thief4",UNTHIEF+"train_room",UNTHIEF+"thief5",
                UNTHIEF+"thief14" }),
             ({ "doorway","west","north","east" }) );
//   set_pre_exit_functions(({"north" }), ({"class_check"}) );
  set_items( ([
    "column"   : "The thick columns stretch up and support the ceiling.",
    "doorway"  : "The small doorways is hidden among the shadows.",
  ]) );

//Guildmaster Settings
  set("guildmaster", "/d/damned/guilds/thief/thief_gm");  
  set_guild_obj("/d/damned/guilds/thief/thief_obj");
//Guild Properties
  set_property("base hp regen", 8);
  set_property("base mp regen", 2);
  set_property("hp advance", 32);
  set_property("mp advance", 10);
  set_property("guild mods", ([ "dexterity" :  10, "charisma" : 10 ]) );
//Misc Code
  new("d/damned/guilds/join_rooms/tcan")->move(this_object());
//TLNY2024 Change for dual training
/*  
    set_related_guilds(({ "tinker", "assassin", }));
    //Other:      "fighter", "nightblade" 
    set_odd_guilds(({ "necromancer", "nethermancer", "chaotic-lord", "sword-mage", "paladin" }));
    set_hated_guilds(({ "cleric", "war-priest", }));
    set_no_guilds(({ "arch-mage", "elementalist", "enchanter",  "dark-paladin", "elemental-mage", }));
*/	
  this_object()->reset();
  return;
}
int class_check(){
  if(this_player()->query_class() != "thief" && !wizardp(this_player()) ){
    write("A magical force stops you from going that way!");
    return 0;
  }
  else
   return 1;
}

