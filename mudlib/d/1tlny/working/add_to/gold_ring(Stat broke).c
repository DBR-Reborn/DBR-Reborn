// /wizards/excelsior/armor/gold_ring
#include <std.h>
#include <clock.h>
#include <def.h>

inherit "/std/armour";

int last_used;

void init() {
   ::init();
   add_action("fun_ring","ring");
    set_wear( (: call_other, this_object(), "add_bonus" :) );
    set_remove( (: call_other, this_object(), "remove_bonus" :) );
}

void create() {
	::create();
	set_name("ring");
	set("id",({"gold ring","ring"}) );
    set_short("A %^YELLOW%^glowing%^RESET%^ ring of power");
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
      write("You cast *6 divine transformation");
      this_player()->delete_skill("temp casting");
      ob->remove();
      return 1;
   }

}

int add_bonus() {
   write("You feel the energy of the robe surge through your body. Ribbons of every %^BOLD%^%^CYAN%^c%^RED%^o%^BLUE%^l%^GREEN%^o%^MAGENTA%^r%^RESET%^ wrap around your body as you wear the robe you feel more skillful in every way but also you look and feel like a idiot");
   TP->add_skill_bonus("two handed staff", 40);
   TP->add_skill_bonus("blunt", 40);
   TP->add_skill_bonus("knife", 40);
   TP->add_skill_bonus("axe", 40);
   TP->add_skill_bonus("blade", 40);
   TP->add_skill_bonus("melee", 40);
   TP->add_skill_bonus("attack", 40);
   TP->add_skill_bonus("dodge", -50);
   TP->add_skill_bonus("parry", -50);
   TP->add_skill_bonus("block", -50);

    return 1;
}

int remove_bonus() {
      write("The energy from the robe is released from your body as you"
       " remove the robe. The power fades away from you.");
   TP->add_skill_bonus("two handed staff", -40);
   TP->add_skill_bonus("blunt", -40);
   TP->add_skill_bonus("knife", -40);
   TP->add_skill_bonus("axe", -40);
   TP->add_skill_bonus("blade", -40);
   TP->add_skill_bonus("melee", -40);
   TP->add_skill_bonus("attack",-40);
   TP->add_skill_bonus("dodge",  50);
   TP->add_skill_bonus("parry",  50);
   TP->add_skill_bonus("block",  50);
   return 1;
}
