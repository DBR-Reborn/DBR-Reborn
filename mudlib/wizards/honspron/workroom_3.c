//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/save_room.c";

void create() {

  ::create();

    set("short", "The workroom of a new immortal");
    set("long", "This inherits from /std/vault_locker_room.c");
    set("night long", "It is night outside.\nA new immortal works here.\n");
    set("day long", "It is day outside.\nA new immortal works here.\n");

    set_property("light", 5);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
  

    set_exits( ({ "/wizards/honspron/workroom.c"}), ({"west"}) );
    
    /*if(!present("forge")) {
	 new("/wizards/diewarzau/obj/misc/greater_forge") ->move(this_object());
	}*/

  
  return;
}

