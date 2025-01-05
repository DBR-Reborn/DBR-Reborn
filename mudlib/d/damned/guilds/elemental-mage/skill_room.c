//	The Elementalists skill training room.
//	DarkeLIB 0.1
//	orginal code by Diewarzau, remodelsing by Mushroom.

inherit "/std/guilds/skill_room";

void create() {
  object ob;
  ::create();
 
ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({"board","elemental-mage_board"}) );
  ob->set_board_id("elemental-mage_board");
  ob->set_max_posts(25);
  ob->set_location("d/damned/guilds/elemental-mage/skill_room");
  ob->set("short","elemental-mage Board");
  ob->set("long",
	"A board upon which messages are posted for others to read.\n");

  set("short", "The Elemental-mage's Training Room");
  set("long", 
	"You have entered the sacred training ground of the elemental-mage. "
	"In this large room, you see young elemental-mage learning from those "
	"who are learned. In one corner of the room you see old masters "
	"lecturing to their students about different lores. On the other side "
	"of the room you see some of the more physicaly fit elemental-mage "
	"hone their physical skills just as an aid in their journey to "
	"becoming one of the masters.\nThere are three exits to this room. "
	"To the west you see what seems to be a storage room. To the east, "
     "a vast library. And to the north you see the entrance to the guild.\n");
  set_items(([ "elemental-mage" : "They are clothed in ornate robes." ]));

  set_property("light", 2);
  set_property("indoors", 1);
  set_join_room("/d/damned/guilds/join_rooms/elemental-mage_join");
 // set_exits( ([
//	"north" : "/d/damned/guilds/join_rooms/elemental-mage_join",
//	"east" : "/d/damned/guilds/elemental-mage/spell_room",
//	"west" : "/d/damned/guilds/elemental-mage/ele_treas" ]));
        add_exit("/d/damned/guilds/join_rooms/elemental-mage_join", "north");
        add_exit("/d/damned/guilds/elemental-mage/spell_room", "east");
        add_exit("/d/damned/guilds/elemental-mage/ele_treas", "west");
  
  add_skill("knife", 1);
  add_skill("two handed staff", 1);
  //add_skill("elementalism", 1);
  //add_skill("focus of elements", 1);
  add_skill("fire lore", 1);
  add_skill("focus casting", 5, 1);
  add_skill("fast casting", 12, 1);
  add_skill("electricity lore", 7);
  add_skill("earth lore", 1);
  add_skill("water lore", 1);
  add_skill("air lore", 1);
  add_skill("wind lore", 4);
  add_skill("cold lore", 3);
  add_skill("concentrate",5);
  add_skill("ice lore", 5);
  add_skill("inertia lore", 7);
  add_skill("prospecting", 1, 1);
  add_skill("vacid lore", 12);
  add_skill("plasma lore", 12);
  add_skill("aether lore", 20);
  add_skill("nexus lore", 25);
  add_skill("chaos lore", 15);
  add_skill("detect magic", 5);
  add_skill("perception", 1, 1);
  add_skill("swimming",1);
  add_skill("consider", 1);
  add_skill("attack", 1);
  add_skill("dodge", 5, 1);
  add_skill("spell sense", 16);
  add_skill("melee", 1, 1);
  add_skill("trade lore", 1, 1);
//add new

  add_skill("elemental focus", 1);
  add_skill("elemental magic", 1);
  add_skill("elemental power", 7);
  //add_skill("focus of elements", 1);
  add_skill("grand elemental gathering", 15);
  add_skill("mass properties", 1);
  //add_skill("acid lore", 12);
  //add_skill("darkness lore", 12);
  //add_skill("disruption lore", 10);
  //add_skill("holy lore", 14);
  //add_skill("impact lore", 8);
  //add_skill("infernal lore", 8);
 // add_skill("radiation lore", 13);
 // add_skill("reflection lore", 15);
  //add_skill("royal lore", 15);
 // add_skill("sonic lore", 15);
  //add_skill("stress lore", 6);
 // add_skill("strike lore", 7);
  //add_skill("vacuum lore", 9);
  return;
}


void reset() {
  if(!present("guard"))
    new("/d/damned/guilds/elemental-mage/t_guard")->move(this_object());
  return;
}

