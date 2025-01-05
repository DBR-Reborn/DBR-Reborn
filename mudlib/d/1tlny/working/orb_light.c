#include <std.h>
#include <clock.h>
#include <def.h>

inherit OBJECT;

int last_used;

void init() {
   ::init();
   add_action("fun_orb","orb");
}
void create() {
    ::create();
    set_name("glass orb");
    set_id(({ "orb", "glowing orb" }));
    set_short("A%^B_ORANGE%^glowing%^RESET%^orb");
    set_long("This is a perfectly spherical glowing orb approximately nine inches in diameter. it appears like nothing but maybe if you did the commad%^YELLOW%^'orb fury'%^RESET%^somthing might happen\n");
    set_weight(10);
    set_value(1);
    return;
}


int fun_orb(string mesg) {
   object ob;

   if(!mesg) {
      notify_fail("orb what?\n");
      return 0;
   }
     if(mesg != "light" && mesg != "Light") {
      notify_fail("Nothing appears to happen.\n");
      return 0;
   }
  // if(query_wielded() != this_player()) {
     // notify_fail("You must wield the weapon to recite the inscription.\n");
     // return 0;
   //}

   if(time() - last_used < HOUR) {
     notify_fail("The orb is still recovering from massive energy drain.\n");
     return 0;
   }
   if(time() - last_used >= HOUR || !last_used) {
      last_used = time();
      ob = new("/std/spells/light");
      ob->set_property("casting time",1);
      ob->set_property("base mp cost",0);
      ob->set_property("skill","temp casting");
      this_player()->set_skill("temp casting",100);
      ob->do_spell( (["caster":this_player(),"target":
         this_player()->query_name(),"power":1,"arg": 0]) );
      this_player()->delete_skill("temp casting");
      ob->spell_func(this_player(),this_player(),6,0,0);
      ob->remove();
      return 1;
   }

}
