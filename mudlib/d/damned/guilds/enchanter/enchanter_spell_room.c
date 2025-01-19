//	Enchanter's Enchantment spell room  - Xavier Jul2020


inherit "/std/guilds/spell_room";

void create() {
  ::create();
  set("short", "The Enchanters' Enchantment Training Room");
  set("long", 
"This is where enchanters study the enchantment spells that enable them to make "+
"wonderous machines and imbue objects with magical energy.\n");
  set_property("light", 2);
  set_property("indoors", 1);
  set_join_room("/d/damned/guilds/join_rooms/enchanter_join");
  add_exit("/d/damned/guilds/enchanter/train_room", "east");
  add_exit("/d/damned/guilds/enchanter/enchanter_spell_room2", "down");

	add_spell("flame blade", 1);
	add_spell("minor puissance", 1);

	add_spell("fashion statue", 2);
    add_spell("sense aura", 2);
	
	add_spell("improve statue", 3);
	add_spell("minor fortification", 3);
  
	add_spell("enchanter mark", 4);
	add_spell("icy weapon", 4);
  
	add_spell("claimed weapon", 5);
	add_spell("minor accuracy", 6);
	add_spell("electric blade", 7);
	add_spell("fashion golem", 10);
  
	add_spell("improve golem", 11);
	add_spell("vacuum weapon", 12);
	
	add_spell("major puissance", 13);
	
	add_spell("activate powerstone", 15);
	add_spell("major fortification", 16);
	add_spell("firestorm blade", 17);
	add_spell("major accuracy", 19);
	add_spell("prepare spell", 20);
	add_spell("lock enchantment", 20);	
	add_spell("scribe scroll", 21);
	add_spell("fashion gargoyle", 22);

	add_spell("vacid weapon", 24);
	add_spell("improve gargoyle", 23);
	add_spell("true weapon", 25);
	add_spell("true armour", 25);

	add_spell("master puissance", 27);
	add_spell("mastered weapon", 28);
	add_spell("lightning blade", 29);
	  
	add_spell("master fortification", 30);
	add_spell("fashion dragon engine", 31);
	add_spell("improve dragon engine", 32);
	add_spell("master accuracy", 34);
	
	add_spell("cyclone weapon", 36);
    add_spell("extreme puissance", 39);

	add_spell("fashion tarrasque", 40);
  
	add_spell("improve tarrasque", 42);
    add_spell("extreme accuracy", 43);
//broken	//add_spell("imbue skill", 45);
  
    add_spell("extreme fortification", 47);
	add_spell("extreme weapon", 48);
//broken	//add_spell("imbue spell", 50);
  


  return;
}

void init() {
    ::init();
    add_action("train", "train");
}

int train(string str) {
    if(str == "fashion tarrasque" && this_player()->query_base_skill("enchantment") < 150 ) {
	message("info", "You must have at least 150% base skill in enchantment to train this spell.", this_player());
	return 1;
    }
    if(str == "improve tarrasque" && this_player()->query_base_skill("enchantment") < 160 ) {
	message("info", "You must have at least 160% base skill in enchantment to train this spell.", this_player());
	return 1;
    }
    if(str == "imbue skill" && this_player()->query_base_skill("enchantment") < 175) {
	message("info", "You must have at least 175% base skill in enchantment to train this spell.", this_player());
	return 1;
    }
    if(str == "extreme weapon" && this_player()->query_base_skill("enchantment") < 190) {
	message("info", "You must have at least 200% base skill in enchantment to train this spell.", this_player());
	return 1;
    }
    if(str == "imbue spell" && this_player()->query_base_skill("enchantment") < 200) {
	message("info", "You must have at least 200% base skill in enchantment to train this spell.", this_player());
	return 1;
    }
}

