 // Monster file: Created by Shade Maelstorm
 
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
   set_name("disciple");
   set("id", ({"disciple", "acolyte"}));
   set_level(20);
   set("short", "Stone Death Disciple");
   set("long",
 "Before you stands a feverishly devoted disciple of the Stone Death Order. He "
 "looks at you , and is curious at your presence in this holy temple. Duty "
 "however forbids him to do anything unless the priest he is guarding commands "
 "it, and you can see it in your eyes, that he will die for his beliefs. ");
   set("race", "stone human");
   set_gender("male");
   set_money("gold", 100+random(25));
   set_body_type("human");
}
 
void catch_tell(string str) {
   string a, b;
   object ob1;
   if(sscanf(str, "%s attacks %s", a, b) == 2) {
      a = lower_case(a);
      ob1 = present(a, environment(this_object()));
      if(ob1) {
         if(interact("Priest", b)) {
            force_me("kill "+a);
            return;
         }
      }
   }   
}
