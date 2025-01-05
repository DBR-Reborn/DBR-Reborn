// Enchanter's Energy Manipulation spell room - Xavier July2020


inherit "/std/guilds/spell_room";

void create() {
  ::create();
  set("short", "The Enchanters' Energy Manipulation Training Room");
  set("long", 
"This is where enchanters study the energy manipulation spells that enable them to cast "+
"attack spells and protection shields, as well as put down powerful runes.\n");
  set_property("light", 2);
  set_property("indoors", 1);
  set_join_room("/d/damned/guilds/join_rooms/enchanter_join");
  add_exit("/d/damned/guilds/enchanter/enchanter_spell_room", "up");
  add_spell("garguth's open palm", 1);
  add_spell("garguth's grasping hand", 6);
  add_spell("garguth's pounding fist", 14);
  add_spell("poison rune", 3);

  add_spell("transmutation", 13);
  add_spell("dispel rune", 25);
  add_spell("exploding rune", 7);
  add_spell("healing rune", 15);
  add_spell("gate rune", 35);
  add_spell("summon rune", 30);
  add_spell("transport rune", 22);
  add_spell("delay rune", 17);
  add_spell("preserve rune", 18);
  add_spell("transport beacon", 22);
  add_spell("self power", 21);
  add_spell("implosion", 24);
  add_spell("energy shield", 9);
  add_spell("shield of ithian", 20);
  add_spell("armour of oblivion", 19);
  add_spell("force shield", 10);
  add_spell("rotten rune", 27);
  add_spell("combustion", 29);
  add_spell("destruction", 34);
  add_spell("annihilation", 40);
  add_spell("rotten rune", 27);
  add_spell("storm rune", 32);
  add_spell("prepare skill", 45);
  return;
}

void init() {
    ::init();
    add_action("train", "train");
}

int train(string str) {
    if(str == "annihilation" && this_player()->query_base_skill("energy manipulation") < 150) {
	message("info", "You must have at least 150% base skill in energy manipulation to train this spell.", this_player());
	return 1;
    }
    if(str == "annihilation" && this_player()->query_class() != "enchanter") {
	message("info", "You must be and Enchanter to train this spell.", this_player());
	return 1;
    }
    if(str == "prepare skill" && this_player()->query_class() != "enchanter") {
	message("info", "You must be and Enchanter to train this spell.", this_player());
	return 1;
    }
}





