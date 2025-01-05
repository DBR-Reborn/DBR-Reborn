//          Wizard: Delsius
//          sign
//          May 97
 
#include <std.h>

inherit OBJECT;

void create() {
     ::create();
     set_name("sign");
     set_id( "sign" );
     set_short("sign");
     set_long("The %^GREEN%^moss%^RESET%^ covered sign points to the "
              "north.\n"+
              "Perhaps you should try and read it?");
     set_weight(9000);
   set_property("no clean",1);
     set_value(0);
}

int get()
{
  return 0;
}

void init() {
     ::reset();
     add_action("read_sign","read");
}

int read_sign(string str){
     if(str != "sign") return 0;
     write("%^RED%^Beware!%^RESET%^ Torch needed beyond this point!\n");
     return 1;
}
