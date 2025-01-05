//  Wizard:  Shade Maelstorm
 
  //Thorny bush
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("thorny branch");
  set_heart_beat(1);
   set_id( ({"thorny branch", "branch"}) );


    set_short("thorny branch");
 set_long("A clipping of some branches from a hedge. It is extremely thorny and looks poisonous.");
    set_weight(20);
    set_value(5);
}

 void heart_beat() {
  write("The branch shifts slightly, and scratches you.");
 return;
 }
