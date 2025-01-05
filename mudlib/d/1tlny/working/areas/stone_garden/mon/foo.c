#include <std.h>
inherit OBJECT;

void create(){
  ::create();
  set("short", "Tester");
  set("id", ({"foo", "tester"}));
  set_heart_beat(1);
}

void init(){
  ::init();
  add_action("my_body", "my_body");
}

int my_body()
{
mapping body;
string *limbs;
int foo;
  message("info", "being called", this_player());
  limbs = this_player() -> query_limbs();
  if(foo = sizeof(limbs))
    message("info", "You have : "+ foo + "limbs", this_player());
  //body = this_player() -> query_body();  
  return 1;
}

void heart_beat()
{
 message("info","You suck!", environment(this_object()));
 return;
}


