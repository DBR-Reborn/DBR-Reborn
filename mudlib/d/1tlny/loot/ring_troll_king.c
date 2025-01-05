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
    set_short("A %^COLOR3%^glowing%^RESET%^ ring of power");
	set("long","This finely made ring looks like an excellent target for a thief. it appears like nothing but maybe if you did the commad %^YELLOW%^'ring summon troll'%^RESET%^ somthing might happen\n");
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
     if(mesg != "summon troll" && mesg != "Summon Troll") {
      notify_fail("Nothing appears to happen you are probably try to use it wrong.\n");
      return 0;
   }

   if(time() - last_used < HOUR*12) {
     notify_fail("The ring is still recovering from massive energy drain.\n");
     return 0;
   }
   if(time() - last_used >= HOUR*12 || !last_used) {
      last_used = time();
       message("info", "You invoke the power of the ring "
            "A mystical cloud enshourds the area and a creature"
			"emerges which immediately walks up to its "
			"new master.", this_player());
		message("info", (string)this_player()->query_cap_name()+
			"Invokes the power of thr ring.  A pet emerges from "
			"the ring.", environment(this_player()),
			({ this_player() }) );
		seteuid(getuid());
        ob = new("/d/1tlny/loot/summon/troll_king");
		ob->set_up();
		ob->set_owner((string)this_player()->query_name());
		ob->move(environment(this_player()));
      return 1;
   }

}
