 
#include <std.h>

inherit OBJECT;

 
void create() {
  string zcolor;
  ::create();
	set_name("bear");
	set_id(({"bear", "teddy bear"}));
	set_short("A teddy bear");
    switch(random(3)){
      case 0:zcolor="blue";break;
      case 1:zcolor="red";break;
      case 2:zcolor="green";break;
    }
	set_long("A cute, fuzzy "+zcolor+" teddy bear, from the city of Kislev.  For a loved one or a friend.");
    set_weight(1);
	set_value(5);
}

