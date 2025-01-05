// /wizards/excelsior/armor/gold_ring
#include <std.h>
#include <clock.h>
#include <def.h>

inherit "/std/armour";

int last_used;

void init() {
   ::init();
   add_action("fun_ring","ring");
}

void create() {
	::create();
	set_name("ring");
	set("id",({"gold ring","ring"}) );
    set_short("A %^COLOR2%^glowing%^RESET%^ ring of power");
	set("long","This finely made ring looks like an excellent target for a thief. it appears like nothing but maybe if you did the commad %^YELLOW%^'ring divine'%^RESET%^ somthing might happen\n");
	set_type("ring");
	set_ac(4);
	set_limbs( ({"finger"}) );
	set_weight( 7 );
	set_value( 1 );
    return;
}

int fun_ring(string mesg) {
   object ob;

   if(!mesg) {
      notify_fail("ring what?\n");
      return 0;
   }
     if(mesg != "divine" && mesg != "Divine") {
      notify_fail("Nothing appears to happen.\n");
      return 0;
   }

   if(time() - last_used < HOUR) {
     notify_fail("The ring is still recovering from massive energy drain.\n");
     return 0;
   }
   if(time() - last_used >= HOUR || !last_used) {
      last_used = time();
      ob = new("/std/spells/divine_transformation");
      ob->set_property("casting time",1);
      ob->set_property("base mp cost",0);
      ob->set_property("skill","temp casting");
      this_player()->set_skill("temp casting",100);
      ob->do_spell( (["caster":this_player(),"target":
         this_player()->query_name(),"power":6,"arg": 0]) );
      say(this_player()->query_cap_name()+" activates the power of their ring\n");
      write("You cast *6 divine transformation");
      this_player()->delete_skill("temp casting");
      ob->remove();
      return 1;
   }

}
