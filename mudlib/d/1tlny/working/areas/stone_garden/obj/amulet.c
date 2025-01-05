//  Wizard:  Shade Maelstorm
// A beautiful amulet
 
#include <std.h>

inherit OBJECT;
 
void create() {
 add_action("check_get","get");
  ::create();
    set_name("amulet");
 set_id( ({ "amulet" }) );
 set_short("amulet");
set_long("This is a beautiful wild rose, many a maiden would swoon over such a gift.");
    set_weight(20);
    set_value(5);
}

 int check_get(string str) {
 if(str == "amulet" && if(present("elf guardian"))) {
 write("The Guardian yells: That is MINE! and blocks you.");
return 0;

 } else {
 return 1;
}
}
