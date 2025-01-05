//TLNY2020 added to Goblin boss room d/camps/goblin/areas/s/m2
#include <clock.h>
#include <def.h>
#define rune "An %^BOLD%^MAGENTA%^Isa Maxima%^RESET%^ rune is inscribed on the armour."

inherit "/std/armour";

int last_used, chanted, saved;
object owner;

      
void init() {
   ::init();
   add_action("fun_chant","chant");
   add_action("fun_recite","recite");
}

void create() {
   mixed tmp;
   ::create();
   set_name("dwarven mail");
   set("id",({"mail","dwarven mail",}));
   set("short","%^BOLD%^WHITE%^Dwarven Mail%^RESET%^");
   set("long","This Dwarven armour with finely crafted links on every"
     " part of the armour. There is some mystical"
     " words finely crafted insdie the armour the inscription says nebulosus maximus. These words must have some"
     " special purpose for the armour.");
   set_type("metal torso");
   set_material("metal/inniculmoid");
   set_ac(75);
   set_limbs( ({"torso","right arm","left arm","right leg","left leg"}) );
   set_weight(110);
   set_value(800);
   set_remove((: call_other, this_object(), "extra_removing" :));
   set_property("enchantment",20);
   tmp = ({ ({"Fortification: %^CYAN%^20%^RESET%^.","detect magic"}) });
   set_property("extra long",tmp);
   chanted = 0;
}

int extra_removing() {
   mixed tmp;

   chanted = 0;
   write("The power from your armor fades away as you remove the dwarven mail.");
   tmp = this_object()->query_property("extra long");
   if(pointerp(tmp)) tmp -= ({ rune });
   else if(stringp(tmp)) tmp = ({});
   this_object()->set_property("extra long", tmp);
   return 1;
}

int fun_chant(string str) {
   string incant;
   mixed tmp;

   if(!str) {
      notify_fail("Chant what?\n");
      return 0;
   }
   if(chanted) {
      notify_fail("The dwarven mail is already being chanted and it is filled with"
         " energy.\n");
      return 0;
   }
   if(sscanf(str,"%s at dwarven mail",incant) == 1) 
      if(incant != "nebulosus maximus") {
         notify_fail("You can't chant on that!\n");
         chanted = 0;
         return 0;
      }
      else if(query_worn() != TP) {
              notify_fail("You must wear the dwarven mail to chant on it!\n");
              return 0;
           }
           else {
              write("The dwarven mail begins to vibrate violently on your body");
              write("An inscription suddenly appears on the dwarven mail.");
	      message("info","The dwarven mail on "+TPQCN+"'s body begins to vibrate"
                " violently as "+TP->query_subjective()+" chants at it.",
                ENV(TP),TP);
              message("info","An inscription suddenly appears on "+TPQCN+"'s"
                " pearl dwarven mail as "+TP->query_subjective()+" chants at it.",
                ENV(TP),TP);
              tmp = this_object()->query_property("extra long");
              if(pointerp(tmp)) tmp += ({ rune });
              else if(stringp(tmp)) tmp = ({ tmp, rune });
                   else tmp = ({ rune });
              this_object()->set_property("extra long",tmp);
              chanted = 1;
              return 1;
           }
}

int fun_recite(string mesg) {
   object ob;

   if(!mesg) {
      notify_fail("You can't recite that!\n");
      return 0;
   }
   if(!chanted) {
      notify_fail("You can't recite without knowing the inscription!\n");
      return 0;
   }
   if(mesg != "isa maxima" && mesg != "Isa Maxima") {
      notify_fail("Nothing appear to happen.\n");
      return 0;
   }
   if(query_worn() != this_player()) {
      notify_fail("You must wear the dwarven mail to recite the inscription.\n");
      return 0;
   }
   if(time() - last_used < HOUR*2) {
     notify_fail("The dwarven mail is still recovering from massive energy drain.\n");
     return 0;
   }
   if(time() - last_used >= HOUR*2 || !last_used) {
      last_used = time();
      ob = new("/std/spells/divine_might");
      ob->set_property("casting time",1);
      ob->set_property("base mp cost",0);
      ob->set_property("skill","temp casting");
      this_player()->set_skill("temp casting",100);
      ob->do_spell( (["caster":this_player(),"target":
         this_player()->query_name(),"power":5,"arg": 0]) );
              write("You cast *5 divine might");
      this_player()->delete_skill("temp casting");
      ob->remove();
      return 1;
   }
}
