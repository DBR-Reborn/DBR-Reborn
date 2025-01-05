#include <std.h>
#include "../keep.h"

/* This room serves as the jail room for the black keep. It is located in the basement of the area, and is only accessible through a path that requires two keys, namely the rusted iron key for the cell and the blood stained key for the red door blocking one of the two demon master rooms. The secret entrance to the basement is inside that room. Floating about in this room is a harmless mob called the energy mass. However, even though it cant fight and it cannot be attacked or killed, it constantly summons monsters to attack players at random intervals and never ever stops. There are three chests in this room as well, and all of them are locked without keys. The only way to open them is for a thief to pick them, and to do so he/she must have protection from a party to keep him from interrupting. Inside one of the chests is nothing, various money is inside another, and one of them contains a vital quest item, the blue gem needed to activate the blue arcane orb. To leave the room, the player must go north. */ 

inherit "/std/vault";

int b;

void create() {
int a;
object ob;
::create();
a = (random(2) + 1);
a = (random(5) + 1);
if(a==1) {
ob = new(ITEM+"jail_chest1.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest2.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest3.c");
ob->move(this_object());
}
if(a==2) {
ob = new(ITEM+"jail_chest1.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest3.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest2.c");
ob->move(this_object());
}
if(a==3) {
ob = new(ITEM+"jail_chest2.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest1.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest3.c");
ob->move(this_object());
}
if(a==4) {
ob = new(ITEM+"jail_chest2.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest3.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest1.c");
ob->move(this_object());
}
if(a==5) {
ob = new(ITEM+"jail_chest3.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest1.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest2.c");
ob->move(this_object());
}
if(a==6) {
ob = new(ITEM+"jail_chest3.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest2.c");
ob->move(this_object());
ob = new(ITEM+"jail_chest1.c");
ob->move(this_object());
}
set_property("light", -1);
set_property("indoors", 1);
set_short("A rot ridden jail");
set_long(@ext Horrible stenches of death fill your nostrils almost diseasing you as you look around this dark rotting room. The ceiling is relatively low, and the walls contain chained skeletons hanging with their jaws wide open. Many other bones and even partially deccomposed organs lay scattered about the dust covered floor, as do three well built chests resting at the back of the room. Hovering directly above the center of the room is a mass of high density purple energy, constantly pulsing without rest. The only visible way out of this wretched room is north back through the rusted jail cell.
    0   
    |   
    @
ext); 
set_smell("default", "The air smells absolutely horrid and disgusting.");
set_listen("default", "You hear constant sounds of moving energy coming from the mass in the center of the room.");
add_exit(ROOMS+"inside35", "north");
set_door("jail cell", ROOMS+"inside35", "north", "old key");
set_open("jail cell", 1);
set_locked("jail cell", 0);
set_lock_level("jail cell", 1000);
ob = new(MON+"energy_mass.c");
ob->move(this_object());
set_items(([
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the ceiling and floor is very smooth.",
({ "floor" }) : "The floor, black in appearance, is covered with disgusting bones and organs as well as quite a bit of dust. It is extremely smooth and appears to have been heavily traveled upon, likely by pacing prisoners",
({ "walls" }) : "The walls, fashioned of rough black stone, are decorated by several gruesome chained skeletons.",
({ "room" }) : "This room is littered with bones and organs, and decorated by chained skeletons on the walls. Three chests rest in the back while a pulsing mass of energy hovers above the center. The exit is back through the jail cell to the north.",
({ "bones" }) : "The bones on the floor appear very old and are starting to decompose.",
({ "organs" }) : "The partially decomposed organs lying on the floor are absolutely disgusting to view and give a truly replusive odor.", 
({ "skeletons" }) : "Several skeletons lay chained to the rough stone walls to serve as malicious decoration.",
({ "dust" }) : "The dust covers a great deal of the floor and most of the things resting on it.",
({ "chests" }) : "The three chests rest in a somewhat cluttered fashion at the back of the room.",
({ "skeleton" }) : "This skeleton lays chained to a rough stone wall to serve as malicious decoration.",
({ "bone" }) : "This bone on the floor appears to be very old and is starting to decompose.",
({ "organ" }) : "This partially decomposed organ lying on the floor is absolutely disgusting to view and gives a truly replusive odor.", 
({ "wall" }) : "This wall, fashioned of rough black stone, is decorated by gruesome chained skeletons.",
({ "jail cell" }) : "The jail cell serving as the exit from this sickening room is located to the north, and by appearance is heavily rusted.",
({ "cell" }) : "The jail cell serving as the exit from this sickening room is located to the north, and by appearance is heavily rusted.",
({ "exit" }) : "The exit from this morbid jail is located directly to the north back through the jail cell.",
({ "center" }) : "Directly above this location in the room floats an ever pulsing mass of high density energy.", 
({ "chains" }) : "The chains binding the skeletons to the walls appear very old and rusted.",
({ "rust" }) : "The rust on the jail cell and the chains holding the skeletons to the walls is extremely thick, signifying great age.",
({ "jaws" }) : "The jaws of the skeletons on the walls lay completely open.",
({ "jaw" }) : "The jaw of the skeleton on the wall lies completely open.",
]));
b = 0;
}

void init() {
::init();
if(b<1) {
write("%^BOLD%^%^GREEN%^Necromancer appears from the shadows.%^RESET%^");
write("Necromancer says in Common: %^MAGENTA%^Hello again. I like this room, for it is my favorite place to pass time. Glad to see you are enjoying your stay in the keep. I know i am, watching you play the masters little games.%^RESET%^");
write("%^BOLD%^%^GREEN%^Necromancer fades into the shadows.%^RESET%^");
b++;
return;
}
}
