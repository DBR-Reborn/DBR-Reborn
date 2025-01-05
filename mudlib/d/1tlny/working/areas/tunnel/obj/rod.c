//          Wizard: Delsius
//          rod
//          Jul 97
 
#include <std.h>

inherit OBJECT;

void create() {
     ::create();
     set_name("rod");
     set_id(({"rod","steel rod"}));
     set_short("A steel rod");
     set_long("This long steel rod is somewhat heavy but would "
              "probably be useful to pry something with.");
     set_weight(100);
     set_value(50);
}
