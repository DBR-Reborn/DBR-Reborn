#include <std.h>

/* This is one of the three gems which serve the purpose of activating the arcane orbs present in the black keep, a major part of the areas quest. The red orb is located on the second floor of the keep through a false wall in the abandoned room, and once the gem is used by touching the orb, it is destroyed. To get this gem, a disciple must immerse the holy soul obtained from the librarian in the pool of life, and despite the lies of Owedquar's Shadow retrieve the gem as Lidfino's offering at the open palm statue in the opposite wing of the keep. */ 

inherit OBJECT;

void create() {
::create();
set_name("red gem");
set("id", ({ "gem", "red gem" }));
set_short("%^RED%^A red gem%^RESET%^");
set_long("This is a relatively shiny gem, a cross between dark and light red in color and solid without any different color present whatsoever. As you hold it in your hand you feel noticeably powerful surges of energy slightly vibrating in it."); 
set_property("no save", 1);
set_weight(50);
set_value(250000);
}
