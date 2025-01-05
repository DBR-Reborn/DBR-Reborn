#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

inherit OBJECT;

void create() {
  ::create();
   set_name("tabacco");
   set_id( ({ "tabacco", "tabac" }) );
   set_short("A pouch of fine tabacco");
   set_long("This is a pouch of tabacco made my the halflings of "+
   "Tara.  They take great pride in their tabacco, ensuring that "+
   "this is quality stuff.  It is ready to be packed into a "+
   "pipe.");
   set_weight(20);
   set_float_value(50);
   set_property("no save", 1);
}
