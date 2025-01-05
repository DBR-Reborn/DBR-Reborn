// Wizard : Hood
// file: jail.c
// Shao-tan Jail 
#include <shao.h>

inherit VAULT;


void init(){
::init();
}

void reset(){
::reset();
}

void create(){
::create();
set_property("indoors", 1);
set_property("light", 1);
set_property("no teleport",1);
set_property("no scry",1);
set_property("no summon",1);
set("short", "Shao-tan jail");
set("long","The room your standing in "
"appears to have been carved out of a solid piece "
"of stone. There are no windows, or "
"furniture except a single iron cot and "
"a small candle. A heavy vault door blocks"
" the exit.\n");

set_items(([
({"door","vault door"}):
"The door itself looks close to impregnable"
" and it's hinges are bolted right into the "
"solid rock.\n",
({"ceiling","floor","wall","walls"}):
"This entire room was carved into a solid "
"piece of stone.\n",
({"candle"}):
"Its the only provider of light to this small"
" cell. It sits on a peg jutting out from the "
"wall.\n",
({"cot","iron cot"}):
"Nothing more then an almost flat slab of "
"iron that is embedded into the rock wall. "
"Although it would be better then sleeping "
"on the concrete, it doesn't look to comfy.\n",
]));

add_exit("jail_cells","out");
set_door("cell1 vault door",PATH+"jail_cells","out","cell_key");
set_locked("cell1 vault door",1);
set_open("cell1 vault door",0);

}
