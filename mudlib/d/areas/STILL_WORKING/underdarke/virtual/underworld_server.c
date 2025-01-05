//    This is a server which handles the Darkemud world...it supports a variety of
//    terrains as well as things like mineral mining and dropping areas and
//    stuff on the filed.
//    Modded by Tailwind so we can have ourselves an underworld. -9/16/99

#define HIGH_COLUMN 39
#define HIGH_ROW 79
#define EXITS ({ "north", "south", "east", "west" })
#define TERRAIN_FILE "/d/underdarke/data/world_terrain.db"

#include <daemons.h>
#include <std.h>

inherit ROOM;
inherit "/std/virtual/compile";

mapping minerals;
string terrain_type;
int brook;

string get_night_long(string terrain, int z);
string get_day_long(string terrain, int z);
mapping get_items(string terrain);
int query_mineral(string what);
void clone_monster(string type);
string query_terrain();
string get_xtra_long(int *x, int *y);
string terrain_name(string letter);

void virtual_setup(string room) {
  int item_x, item_y, i, x, y, *exits_y, *exits_x;
  string *line, type;
  string *items_file, *words;
  string min_type;

  if(sscanf(room, "room_%d_%d", x, y) != 2) {
    write("BUG!  The room you tried to enter doesn't exist!\n" +
	  "Error in virtual world server.");
    return;
  }
/*
if(x == 12 && y == 12) 
add_exit("/d/damned/arena/booths_room", "arena");
*/
  exits_x = allocate(4);
  exits_y = allocate(4);
  exits_x[0] = x; exits_x[1] = x;
  exits_x[2] = (x >= HIGH_COLUMN)?0:(x + 1);
  exits_x[3] = (x == 0)?HIGH_COLUMN:(x - 1);
  exits_y[0] = (y == 0)?HIGH_ROW:(y - 1);
  exits_y[1] = (y >= HIGH_ROW)?0:(y + 1);
  exits_y[2] = y; exits_y[3] = y;
  for(i = 0; i < sizeof(EXITS); i++)
    add_exit(sprintf("/d/underdarke/virtual/room_%d_%d.underworld",
		     exits_x[i], exits_y[i]), EXITS[i]);
  line = explode(read_file(TERRAIN_FILE, y+1, 1), ":");
  type = line[x];
  terrain_type = type;
  if(random(10) == 3 && memory_info() < 5000000)
    clone_monster(terrain_type);
  brook = (type == lower_case(type));
  set("day long", get_day_long(capitalize(type),x+y) + 
	get_xtra_long(exits_x,exits_y));
  set("night long", get_night_long(capitalize(type),x+y) + 
	get_xtra_long(exits_x,exits_y));
  set_items(get_items(capitalize(type)));
  switch(capitalize(type)) {
  case "S":
    set("short", "A steamy swamp");
    set_smell("default", "The air is heavy with the stench of decay.");
    set_smell("gas", (: call_other, this_object(), "gas_func" :));
    break;
  case "T":
    set("short", "A cool tundra");
    break;
  case "P":
    set("short", "Savage plains");
    break;
  case "M":
    set("short", "Huge, untamed mountains");
    break;
  case "H":
    set("short", "Jagged hills");
    break;
  case "W":
    set("short", "Wild oceans");
    break;
  case "F":
    set("short", "Darke and mysterious forest");
    if(!random(2)) {
      set_smell("default", "The smell of Nightshades pervades your nostrils.");
      set_smell(({ "nightshade" , "nightshades" }), "The Nightshades smell very... different.");
    }
    break;
  case "J":
    set("short", "A hot jungle");
    break;
  case "D":
    set("short", "A blazingly hot desert");
    break;
  case "C":
    set("short", "The magnificent coast");
    set_listen("default", "You hear the gentle crashing of waves against the coast.");
    break;
  }
  if(brook) {
    set("day long", (string)query("day long") + "%^BOLD%^There is a rushing brook here.\n");
    set("night long", (string)query("night long") + "\nThere is a rushing brook here.\n");
    set_listen("brook", "You hear the loud gurgling of the brook.");
    add_item("brook", "It is a wild, but beautiful brook with rocks at the bottom");
  }
  items_file = explode(read_file("/d/underdarke/data/underworld_items.db"), "\n");
  i = sizeof(items_file);
  while(i--) {
    words = explode(items_file[i], ":");
    if(sizeof(words) > 4)
      words = ({ words[0], (words[1]+":"+words[2]), words[3], words[4] });
    if(sscanf(words[0], "%d_%d", item_x, item_y) != 2) continue;
    if(item_x == x) {
      if(item_y == y) {
	add_exit(words[1], words[2]);
	set("night long", (string)query("night long") + "%^BOLD%^" + words[3] + " is here.\n");
	set("day long", (string)query("day long") + "%^BOLD%^" + words[3] + " is here.\n");
	add_item(words[2], "You can enter it by typing '" + words[2] + ".'");
      }
      else if((item_y == y - 1) || (y == 0 && item_y == HIGH_ROW)) {
	set("night long", (string)query("night long") + "%^BOLD%^" + words[3] + " is seen to the north.\n");
	set("day long", (string)query("day long") + "%^BOLD%^" + words[3] + " is seen to the north.\n");
      }
      else if((item_y == y + 1) || (y == HIGH_ROW && item_y == 0)) {
	set("night long", (string)query("night long") + "%^BOLD%^" + words[3] + " is seen to the south.\n");
	set("day long", (string)query("day long") + "%^BOLD%^" + words[3] + " is seen to the south.\n");
      }
    }
    else if(item_y == y) {
      if((item_x == x - 1) || (x == 0 && item_x = HIGH_COLUMN)) {
	set("night long", (string)query("night long") + "%^BOLD%^" + words[3] + " is seen to the west.\n");
	set("day long", (string)query("day long") + "%^BOLD%^" + words[3] + " is seen to the west.\n");
      }
      else if((item_x == x + 1) || (x == HIGH_COLUMN && item_x == 0)) {
	set("night long", (string)query("night long") + "%^BOLD%^" + words[3] + " is seen to the east.\n");
	set("day long", (string)query("day long") + "%^BOLD%^" + words[3] + " is seen to the east.\n");
      }
    }
  }
if(x == 12 && y == 12) {
set("night long", (string)query("night long") + "%^BOLD%^A large "
"colloseum can be seen in the distance.%^RESET%^");
set("day long", (string)query("day long") + "%^BOLD%^A large "
"colloseum can be seen in the distance.%^RESET%^");
}
  items_file = get_dir("/d/underdarke/data/");
  i = sizeof(items_file);
  minerals = ([]);
#if 1 
  while(i--) {
    if(!sscanf(items_file[i], "mineral_%s.db", min_type)) continue;
    words = explode(read_file("/d/underdarke/data/"+items_file[i], y + 1, 1), ":");
    minerals[min_type] =  atoi(words[x]);
  }
#endif
}

string get_xtra_long(int *x, int *y) {
  string *line, desc;
  mapping dirs;
  int i, j;

  desc = "";
  dirs = ([]);
  for(i=0; i<4; i++) {
    line = explode(read_file(TERRAIN_FILE, y[i]+1, 1), ":");
    if(capitalize(line[x[i]]) != capitalize(terrain_type)) {
      if(undefinedp(dirs[terrain_name(line[x[i]])]))
	dirs[terrain_name(line[x[i]])] = ({});
      dirs[terrain_name(line[x[i]])] += ({ EXITS[i] });
    }
  }
  line = keys(dirs);
  i = sizeof(line);
  while(i--) {
    desc += "To the ";
    for(j = 0;j < sizeof(dirs[line[i]]); j++) {
      if(j == (sizeof(dirs[line[i]]) - 1)
	&& sizeof(dirs[line[i]]) > 1) desc += "and ";
      desc += dirs[line[i]][j];
      if(j == (sizeof(dirs[line[i]]) - 1) || 
	 sizeof(dirs[line[i]]) > 2) desc += ", ";
      else desc += " ";
    }
    desc += "you see " + line[i] + ".\n";
  }
  return desc;
}

string terrain_name(string letter) {
  letter = capitalize(letter);
  switch(letter) {
  case "F":
    return "a darke and mysterious forest";
  case "J":
    return "a hot jungle";
  case "P":
    return "a savage plain";
  case "W":
    return "the ocean";
  case "M":
    return "a massive mountain range";
  case "H":
    return "jagged hills";
  case "C":
    return "the coastline";
  case "D":
    return "a blazingly hot desert";
  case "S":
    return "a steamy swamp";
  case "T":
    return "a cool tundra";
  default:
    return "TERRAIN BUG!!!";
  }
}

int query_mineral(string what) {
  if(!minerals || undefinedp(minerals[what])) return 0;
  return minerals[what];
}

string gas_func() {
  this_player()->add_hp(-2);
  return "%^YELLOW%^The gas burns your lungs!";
}

int query_brook() { return brook; }

int query_water() {
  if(capitalize(terrain_type) == "W")
    return 1;
  else return 0;
}

void init() {
  ::init();
  if(capitalize(terrain_type) == "W")
    this_object()->damage_all();
  return;
}

int receive_objects() {
  object who;

  who = previous_object();
   if(!who || !living(who) || who->is_player() ||
      capitalize((string)this_object()->query_terrain()) != "W")
    return ::receive_objects();
  if((int)who->query_skill("swimming") > random(100)) return 1;
  if(who->query_flying()) return 1;
  return 0;
}

int living_filter(object who) {
  return who->is_player();
}

void damage_all() {
  object *who_here;
  int i, j;
  string *limbs;
  int flag;

  who_here = filter_array(all_inventory(this_object()), 
			  "living_filter", this_object());
  if(!who_here || !sizeof(who_here)) return;
  i = sizeof(who_here);
  while(i--) {
    limbs = (string *)who_here[i]->query_limbs();
    j = sizeof(limbs);
    flag = 0;
    while(j--)
      if(member_array("wing", explode(limbs[i], " "), 4) >= 0)
	flag = 1;
    if(flag) continue;
    if(who_here[i]->query_boat()) continue;
    if(who_here[i]->query_flying()) continue;
    if(random(100) >= (int)who_here[i]->query_skill("swimming")) {
      who_here[i]->add_hp(-(int)who_here[i]->query_max_hp() / 20);
      message("info", "%^BLUE%^You are drowning!", who_here[i]);
    }
  }
  remove_call_out("damage_all");
  call_out("damage_all", 5);
  return;
}

void create() {
  ::create();
    set_property("light", 2);
    minerals = ([]);
    return;
}

void reset() {
    if(random(28) == 4 && stringp(terrain_type) && memory_info() < 5000000)
      clone_monster(terrain_type);
  return;
}

string get_day_long(string terrain, int z) {
  string *descs;
  descs = allocate(3);
  switch(terrain) {
  case "S":
    descs[0] = "You find yourself in the middle of a steamy swamp.  The swamp gas is so thick that at times "+
      "you swear you are actually swimming in it.  You wade through the steaming water, and almost swear "+
      "that you see eyes looking at you.\n";
    descs[1] = "The swamp is interrupted by an occasional outgrowth of nightshade, which you can barely see "+
      "through the ever present swamp gas.  You wade nervously due to the many different types of creatures "+
	"lurking beneath the murky waters which you DON'T want to disturb.\n";
    descs[2] = "You push some branches aside as you wade through the swamp.  You proceed at a cautious pace "+
      "since the gas is so thick, you can hardly see well enough to avoid bumping into things.\n";
    break;
  case "T":
    descs[0] = "Unlike the tundras in the world above, it is just barely cold enough for it to snow.  "+
      "You see your breath as you exhale, and wonder just why it is so hot down below the surface of the "+
	"world.\n";
    descs[1] = "You nearly slip on a patch of ice, taking care to avoid more of the stuff.  "+
      "You pause to tighten your boots and continue into the vast frozen wasteland.\n";
    descs[2] = "It is a little uncomfortable to breathe as you scale the imposing snow dune before you.  "+
      "As you reach the top, the view of the frozen wastelands is impressive.  You pause to "+
	"admire the beautiful view for a bit, and then continue.\n";
    break;
  case "P":
    descs[0] = "You are in the middle of a savage and untamed plain.  The warm wind blows through "+
      "the black grass, making a long, mournful whistle.  The sun is bright, and you " +
      "can see various creatures making their way through the grass.\n";
    descs[1] = "It is a bit darker out now and shadows move quickly over the plains, giving " +
      "you a bit of a scare at times.  The wind picks up, but you sincerely doubt that rain is "+
      "in the future.\n";
    descs[2] = "The grass of the wild, dark plain is punctuated by a few large stones lying about. " +
      " A few small and fierce-looking insects, and large, brown... things scamper about.\n";
    break;
  case "F":
    descs[0] = "The sky is mostly obscured by the nightshade trees of this forest.  " +
      "Small animals regard you curiously as you walk through the dark foliage.\n";
    descs[1] = "Small animals hang about from the trees and squeak at you as you " +
      "pass by.  A mat of dead nightshade leaves lies about on the forest floor, and it crunches softly " +
	"as you walk about. It seems like something else has walked over them, too.\n";
    descs[2] = "You have reached a large clearing in the forest, created by a rampaging monster " +
      "of some sort.  The grass is all matted down from the garantuan foot steps..\n";
    break;
  case "J":
    descs[0] = "The jungle is almost unbearably hot.  Water drips from the tall trees, " +
      "and small critters scamper about below in the underbrush.\n";
    descs[1] = "Drops of water fall from the leaves of trees high above have almost turned into a waterfall. " +
      "A weird fog collects on the jungle floor, and you become unable to see your legs.\n";
    descs[2] = "The heat here is stifling.  You see a rather large brown and black beast watching "+
      "you with angry red eyes from a nearby tree.  You sense movement all around "+
	"you, and know you are far from alone.\n";
    break;
  case "M":
    descs[0] = "Climbing these mountains is a quite a job.  Nothing living pokes through "+
      "cracks in the rock, giving you very few handholds.  You can see that the peaks of some nearby " +
        "mountains are covered with snow - a very unusual occurance down here.\n";
    descs[1] = "You stand at the base of a massive mountain.  You can see others just like it in the "+
      "distance, and know you have a good climb ahead of you.\n";
    descs[2] = "Walking through a rocky pass in the mountains, you marvel at the beauty and size of " +
      "the seismic formations which are far above you.\n";
    break;
  case "D":
    descs[0] = "The desert seems to stretch on for miles.  Several exotic cacti puntuate the area, "+
      "but you wonder how they manage it, as it doesn't seem to have rained in years.\n";
    descs[1] = "Bizarre-looking plants and cacti are all about. The wind dies down, and you feel the "+
      "heat of the area beat down on you.\n";
    descs[2] = "You are in the middle of a small patch of razor cacti, an underground species which  "+
      "is known to be very dangerous if touched. You walk very carefully around them, and manage to " +
      "avoid them.\n";
    break;
  case "H":
    descs[1] = "The jagged hills are covered in rocks, making them somewhat difficult to climb.  "+
      "In some places, you can see grass, which makes you wonder how anything can grow here. "+
	"Now and then, an animal of some type runs by, intent on finding some food.\n";
    descs[0] = "The hills here are made of boulders, making them more a pile of rocks than a natural.  "+
      "feature of the land.\n";
    descs[2] = "You are walking in between two small hills.  The rest of the terrain is obscured by "+
      "their presence.  The hills are completely barren, with occasional blades of grass sticking up "+
	"from between the cracks.\n";
    break;
  case "C":
    descs[0] = "You are walking along the coast.  The carcasses of fish line the shore, "+
      "killed by either the heat of the underground ocean, or by something else...\n";
    descs[1] = "Walking along the underground coast, you tread lightly, as there is no sand underfoot. "+
      "All that lies between you and the water is a wall of sheer rock going down towards it.\n";
    descs[2] = "The coast is rough, but posses a wild, savage beauty.  The water sparkles, but you "+
      "cannot tell where the light is from.  The obsidian rocks that compose the shore greet the sea nearby.\n";
    break;
  case "W":
    return "You are in the middle of the ocean.  The water stretches out in all directions.\n";
    break;
  }
  return descs[z%3];
}

// Up to here is fine.

string query_terrain() { return terrain_type; }

string get_night_long(string terrain, int z) {
  string *descs;

  descs = allocate(3);
  switch(terrain) {
  case "S":
    return "The swamp is not the best place to be at night.  The swamp gas floats over the murky waters almost "+
      "as if it were alive.  Your only companion in this dark morass is the sound of the water as it is "+
	"parted by your stride.\n";
  case "T":
    return "Although the tundra isn't very cold during the day, things change at night.  As far as you "+
      "can see, which isn't very, the snow is cold, flat, and unrelenting.  Your shivers of cold are surpassed "+
	"only by the loneliness you feel, to be alone in an underground tundra.\n";
  case "P":
    return "At night, the black grass under you is completely invisible, giving you the sensation of "+
      "floating in space.  The only thing telling you that you are on solid ground is the faint rustling of "+
	"the wind through the ocassional nightshade trees.\n";
    break;
  case "F":
    return "The forest, while sinister enough during the day, is truly an intimidating place at night. " + 
      "Sounds echo out from near and far, filling you with the sensation of being watched.  You step " +
      "gingerly, careful not to upset the many deadly creatures known to lurk about at night.\n";
    break;
  case "J":
    return "You are filled with the sensation that this is not a good place to be after nightfall as you "+
      "notice angry red eyes peering at you through the darkness.\n";
    break;
  case "H":
    return "The faint glint of the moonlight off the jagged hills is a depressing sight.  You are "+
      "filled with a profound sense of futility as you look off into the distance and see the shattered " +
      "lands which make up this underground domain.\n";
  case "M":
    return "The mountains are an eerie and beautiful sight at night.  "+
      "They rise straight into the heavens, pillars of hope in a barren land.\n";
  case "D":
    return "The desert, dangerous during the day, is not a good place to be at night, either. "+
      "You narrowly avoid being sliced to ribbons by a patch of razor cacti.\n";
  case "C":
    return "In the darkness, you can barely make out the ocean. The slow crashing of waves is the "+
	"only indication that water is nearby. You step carefully to avoid falling in.\n";
  case "W":
    return "The dark loneliness you experience on the extremely warm water is almost overwhelming. \n";
  }
  return "oopsee, no long desc for nitew";
}

mapping get_items(string terrain) {
  switch(terrain) {
  case "F":
    return ([ ({ "tree", "trees", "nightshade" }) : "The nightshade trees are short, and sport no fruit" ]);
  case "D":
    return ([ ({ "cactus", "cacti" }) : "The cacti are black, and sport razor prickles" ]);
  case "T":
    return ([ "snow" : "The snow is tightly packed, and white as a dove." ]);
  case "C":
    return ([ ({ "carcass", "carcasses" }) : "Not exactly edible." ]);
  default:
    return ([]);
  }
}

// Up to here works as well.

void clone_monster(string terrain) {
  object mon;

  terrain = capitalize(terrain);
  seteuid(geteuid(this_object()));
  switch(terrain) {
  case "S":
  case "J":
    if(random(2)) mon = new("/d/underdarke/mon/python");
    else mon = new("/d/underdarke/mon/panther");
    break;
  case "D":
    mon = new("/d/underdarke/mon/lizard");
    break;
  case "M":
  case "H":
    mon = new("/d/underdarke/mountain_lion");
    break;
  case "T":
    mon = new("/d/underdarke/mon/mammoth");
    break;
  case "P":
    mon = new("/wizards/tailwind/virtual/mon/wolf");
    break;
  default:
    return;
  }
  if(objectp(mon))
    mon->move(this_object());
  return;
}
