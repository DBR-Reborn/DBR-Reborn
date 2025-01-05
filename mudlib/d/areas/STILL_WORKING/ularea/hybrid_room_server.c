// hybrid room server by glen
#include <std.h>
#include "area.h"

inherit ROOM;

string local_path();
void   create_exits();

void create() {
    ::create();
    set_property("light", 2);

    switch(local_path()){
    case "entrance":
	set_short("Entrance to a gothic graveyard");
	set_long(
	  "The graveyard spreads out before you to the "+
	  "north.  It is shrouded in fog, making it difficult to see "+
	  "anything.");
	break;
    case "grave01":
	set_short("Gothic graveyard");
	set_long(
	  "A stone walkway goes east from here.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "A few old trees still stand here.");
	set_items( (["tombstone" : "Smear rests here." ]) );
	break;
    case "grave02":
	set_short("Gothic graveyard");
	set_long(
	  "A stone walkway runs east and west from here.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "An iron fence lies to the south.");
	set_items( (["tombstone" : "Kojin rests in peace." ]) );
	break;
    case "grave03":
	set_short("Gothic graveyard");
	set_long(
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "A large mound of dirt is to the east.");
	set_items( (["tombstone" : "Dakra rests here." ]) );
	break;
    case "grave04":
	set_short("Gothic graveyard");
	set_long(
	  "The graveyard spreads out before you to the south, "+
	  "north and east.  Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "To the west is a small stream.  ");
	set_items( (["tombstone" : "Arnhazzi rests here." ]) );
	break;
    case "grave05":
	set_short("Gothic graveyard");
	set_long(
	  "Dead end, an iron fence extends out, a distance around "+
	  "this lone tombstone, rememnants of a garden are seen.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "A lone tombstone sits here.");
	set_items( (["tombstone" : "Eospherous rests here." ]) );
	break;
    case "grave06":
	set_short("Gothic graveyard");
	set_long(
	  "A stone walkway runs east and west from here.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "A mound of dirt lies to the north.");
	set_items( (["tombstone" : "Fireforge rests here." ]) );
	break;
    case "grave07":
	set_short("Gothic graveyard");
	set_long(
	  "A stone walkway runs north and west from here.  "+
	  "The corner of the graveyard.  Iron fence lies east and "+
	  "south.  Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "A group of trees stand here.");
	set_items( (["tombstone" : "Bladestorm rests here." ]) );
	break;
    case "grave08":
	set_short("Gothic graveyard");
	set_long(
	  "A stone walkway runs south and east from here.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "A mound of dirt lies to the east.");
	set_items( (["tombstone" : "Glen rests here." ]) );
	break;
    case "grave09":
	set_short("Gothic graveyard");
	set_long(
	  "Corner of the graveyard, an iron fence lies north and west. "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "Some vines cover the ground here.  ");
	set_items( (["tombstone" : "Kinslayer rests here." ]) );
	break;
    case "grave10":
	set_short("Gothic graveyard");
	set_long(
	  "A walkway leads east and west of here.  "+
	  "Toward the south is a large mound of dirt.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "Some vines cover the ground here.  ");
	set_items( (["tombstone" : "Dalis rests here." ]) );
	break;
    case "grave11":
	set_short("Gothic graveyard");
	set_long(
	  "Toward the northeast is an old garden. "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "Some vines cover the ground here.  ");
	set_items( (["tombstone" : "Kesthro rests here." ]) );
	break;
    case "grave12":
	set_short("Gothic graveyard");
	set_long(
	  "A walkway leads east and north from here.  "+
	  "Toward the south is a large mound of dirt.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "Some vines cover the ground here.  ");
	set_items( (["tombstone" : "Diewarzau rests here." ]) );
	break;
    case "grave13":
	set_short("Gothic graveyard");
	set_long(
	  "A stone walkway runs west and east from here.  "+
	  "To the south is an iron fence.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "Some vines cover the ground here.  ");
	set_items( (["tombstone" : "Azura rests here." ]) );
	break;
    case "grave14":
	set_short("Gothic graveyard");
	set_long(
	  "Endge of the graveyard, north and west is an iron fence.  "+                
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "Some vines cover the ground here.  ");
	set_items( (["tombstone" : "Laz rests here." ]) );
	break;
    case "grave15":
	set_short("Gothic graveyard");
	set_long(
	  "This is part of an old garden.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "Some vines cover the ground here.  ");
	set_items( (["tombstone" : "Ted rests here." ]) );
	break;
    case "grave17":
	set_short("Gothic graveyard");
	set_long(
	  "Southwest corner of an old garden.  "+ 
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  "+
	  "Old garden plants still grow here.  ");
	break;
    case "grave18":
	set_short("Gothic graveyard");
	set_long(
	  "An old stone walkway leads east and west from here.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "Some vines cover the ground here.  ");
	set_items( (["tombstone" : "Ariel rests here." ]) );
	break;
    case "grave19":
	set_short("Gothic graveyard");
	set_long(
	  "Southeast corner of an old garden.  "+ 
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  "+
	  "Old garden plants still grow here.  ");
    case "grave20":
	set_short("Gothic graveyard");
	set_long(
	  "Northwest corner of an old garden.  "+ 
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  "+
	  "Old garden plants still grow here.  "
	);
	set_items( (["tombstone" : "K'thach rests here." ]) );
	break;
    case "grave21":
	set_short("Gothic graveyard");
	set_long(
	  "Northeast corner of an old garden.  "+ 
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  "+
	  "Old garden plants still grow here.  ");
	break;
    case "grave22":
	set_short("Gothic graveyard");
	set_long(
	  "A stone walkway runs west and east from here.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "Some vines cover the ground here.  ");
	set_items( (["tombstone" : "Mortdred rests here." ]) );
	break;
    case "grave23":
	set_short("Gothic graveyard");
	set_long(
	  "A stone walkway runs west and east from here.  "+
	  "Mist covers the area, but you can "+
	  "sense some movement within the mist.  Tombstones are "+
	  "visible vaguely through the mist.  Fog clouds the sky.  "+
	  "Some vines cover the ground here.  ");
	set_items( (["tombstone" : "Shinju rests here." ]) );
	break;
    case "grave24":
	set_short("Mausoleum");
	set_long(
	  "A stone walkway runs west and north from here.  "+
	  "Edge of the graveyard, an iron fence lies east. "+
	  "Mist covers the area, but you can sense some "+
	  "movement within the mist.  To the north lies a huge "+
	  "mausoleum of some sort.  The graveyard is to the south "+
	  "and west.");
	break;
    case "grave25":
	set_short("Mausoleum");
	set_long(
	  "There are no tomb stones, this is a clear grassy area.  "+
	  "Perhaps a field of some sort.  ");
    case "grave26":
	set_short("Mausoleum");
	set_long(
	  "There are no tomb stones, this is a clear grassy area.  "+
	  "Perhaps a field of some sort.  ");
	break;
    case "grave27":
	set_short("Mausoleum");
	set_long(
	  "There are no tomb stones, this is a clear grassy area.  "+
	  "Perhaps a field of some sort.  ");
	break;
    case "grave28":
	set_short("Mausoleum");
	set_long(
	  "Here lies a small well probably used for wattering the "+
	  "old gardens and lawns.");
	break;
    case "grave29":
	set_short("Mausoleum");
	set_long(
	  "A dark mausoleum, smells of death and animals.  You think "+
	  "you can sense movement in the darkness.  The walls are "+
	  "decorated with many elaborate works of art, this must "+
	  "be the tomb of some rich folk.");
	break;
    case "grave30":
	set_short("Mausoleum");
	set_long(
	  "A dark mausoleum, smells of death and animals.  You think "+
	  "you can sense movement in the darkness.  The walls are "+
	  "decorated with many elaborate works of art, this must "+
	  "be the tomb of some rich folk.");
	break;
    default:
	set_short("bug");
	set_long(local_path());
	break;
    }
    create_exits();
}

void reset() {
    ::reset();
    switch(local_path()){
    case "grave05":
	if(!present("monk"))
	    new(MON+"undead_monk")->move(this_object());
	break;
    case "grave01":
    case "grave04":
    case "grave06":
    case "grave07":
    case "grave19":
    case "grave21":
	if(!present("hound"))
	    new(MON+"undead_hound")->move(this_object());
	break;
    case "grave08":
    case "grave09":
    case "grave17":
	if(!present("page"))
	    new(MON+"undead_page")->move(this_object());
	if(!present("hound"))
	    new(MON+"undead_hound")->move(this_object());
	break;
    case "grave24":
    case "grave23":
    case "grave22":
	if(!present("noble")){
	    new(MON+"undead_noble")->move(this_object());
	    new(MON+"undead_noble")->move(this_object());
	}
	break;
    case "grave25":
    case "grave26":
    case "grave27":
	if(!present("noble"))
	    new(MON+"undead_noble")->move(this_object());
	if(!present("page")){
	    new(MON+"undead_page")->move(this_object());
	}
	break;
    case "grave28":
    case "grave29":
	if(!present("bear"))
	    new(MON+"undead_bear")->move(this_object());
	if(!present("priest"))
	    new(MON+"undead_priest")->move(this_object());
	break;
    case "grave30":
	if(!present("bear")){
	    new(MON+"undead_bear")->move(this_object());
	    new(MON+"undead_bear")->move(this_object());
	}
	break;
    }
    switch(local_path()){
    case "grave28":
	if(!present("well")){
	    new(OBJ+"well")->move(this_object());
	    break;
	}
    }
}

void create_exits(){
    switch(local_path()){
    case "entrance":
	add_exit(ROOMS+"grave01", "north");
	add_exit("/d/damned/virtual/room_23_23.world", "out");
	break;
    case "grave01":
	add_exit(ROOMS+"grave02", "east");
	add_exit(ROOMS+"grave04", "north");
	add_exit(ROOMS+"entrance", "south");
	break;
    case "grave02":
	add_exit(ROOMS+"grave03", "north");
	add_exit(ROOMS+"grave01", "west");
	add_exit(ROOMS+"grave06", "east");
	break;
    case "grave03":
	add_exit(ROOMS+"grave09", "north");
	add_exit(ROOMS+"grave04", "west");
	add_exit(ROOMS+"grave02", "south");
	break;
    case "grave04":
	add_exit(ROOMS+"grave05", "north");
	add_exit(ROOMS+"grave03", "east");
	add_exit(ROOMS+"grave01", "south");
	break;
    case "grave05":
	add_exit(ROOMS+"grave04", "south");
	break;
    case "grave06":
	add_exit(ROOMS+"grave02", "west");
	add_exit(ROOMS+"grave07", "east");
	break;
    case "grave07":
	add_exit(ROOMS+"grave08", "north");
	add_exit(ROOMS+"grave06", "west");
	break;
    case "grave08":
	add_exit(ROOMS+"grave11", "north");
	add_exit(ROOMS+"grave13", "east");
	add_exit(ROOMS+"grave07", "south");
	break;
    case "grave09":
	add_exit(ROOMS+"grave10", "east");
	add_exit(ROOMS+"grave03", "south");
	break;
    case "grave10":
	add_exit(ROOMS+"grave09", "west");
	add_exit(ROOMS+"grave14", "north");
	add_exit(ROOMS+"grave11", "east");
	break;
    case "grave11":
	add_exit(ROOMS+"grave10", "west");
	add_exit(ROOMS+"grave15", "north");
	add_exit(ROOMS+"grave12", "east");
	add_exit(ROOMS+"grave08", "south");
	break;
    case "grave12":
	add_exit(ROOMS+"grave11", "west");
	add_exit(ROOMS+"grave17", "north");
	break;
    case "grave13":
	add_exit(ROOMS+"grave08", "west");
	add_exit(ROOMS+"grave18", "east");
	break;
    case "grave14":
	add_exit(ROOMS+"grave15", "east");
	add_exit(ROOMS+"grave10", "south");
	break;
    case "grave15":
	add_exit(ROOMS+"grave14", "west");
	add_exit(ROOMS+"grave17", "east");
	add_exit(ROOMS+"grave11", "south");
	break;
    case "grave17":
	add_exit(ROOMS+"grave15", "west");
	add_exit(ROOMS+"grave20", "north");
	add_exit(ROOMS+"grave19", "east");
	add_exit(ROOMS+"grave12", "south");
	break;
    case "grave18":
	add_exit(ROOMS+"grave13", "west");
	add_exit(ROOMS+"grave22", "east");
	break;
    case "grave19":
	add_exit(ROOMS+"grave21", "north");
	add_exit(ROOMS+"grave17", "west");
	break;
    case "grave20":
	add_exit(ROOMS+"grave21", "east");
	add_exit(ROOMS+"grave17", "south");
	break;
    case "grave21":
	add_exit(ROOMS+"grave20", "west");
	add_exit(ROOMS+"grave19", "south");
	break;
    case "grave22":
	add_exit(ROOMS+"grave18", "west");
	add_exit(ROOMS+"grave23", "east");
	add_exit(ROOMS+"grave25", "south");
	break;
    case "grave23":
	add_exit(ROOMS+"grave22", "west");
	add_exit(ROOMS+"grave28", "north");
	add_exit(ROOMS+"grave24", "east");
	add_exit(ROOMS+"grave26", "south");
	break;
    case "grave24":
	add_exit(ROOMS+"grave23", "west");
	add_exit(ROOMS+"grave29", "north");
	add_exit(ROOMS+"grave27", "south");
	break;
    case "grave25":
	add_exit(ROOMS+"grave22", "north");
	add_exit(ROOMS+"grave26", "east");
	break;
    case "grave26":
	add_exit(ROOMS+"grave25", "west");
	add_exit(ROOMS+"grave23", "north");
	add_exit(ROOMS+"grave27", "east");
	break;
    case "grave27":
	add_exit(ROOMS+"grave26", "west");
	add_exit(ROOMS+"grave24", "north");
	break;
    case "grave28":
	add_exit(ROOMS+"grave23", "south");
	break;
    case "grave29":
	add_exit(ROOMS+"grave30", "north");
	add_exit(ROOMS+"grave24", "south");
	break;
    case "grave30":
	add_exit(ROOMS+"grave29", "south");
	add_exit("/d/damned/guilds/join_rooms/underlord_join",
	  "north");
	set_invis_exits(({ "north" }));
	break;
    }
}

string local_path(){
    string what, *ar;
    what = base_name(this_object());
    ar = explode(what, "/");
    what = ar[sizeof(ar)-1];
    return what;
}


