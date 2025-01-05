#include <clock.h>
#include <def.h>
#define rune "A %^BOLD%^GREEN%^Inguz Dagaz%^RESET%^ rune is inscribed on the weapon."

inherit "/std/weapon";

int last_used,chanted;

void init() {
   ::init();
   add_action("fun_chant","chant");
   add_action("fun_recite","recite");
}

create() {
    ::create();
    set_name("Dagger");
    set("id", ({ "dagger", "Dagger"}));
    set("short","%^B_RED%^BLACK%^Lengendary black dagger of Sagan%^RESET%^");
    set("long", "This is a dagger once used by lengendary master thief, Sagan."
       " The dagger's tempered point is sparking with it sharp edges.  It make"
       " 'hmming' sounds as you wield the dagger.  At the buttcap of the dagger"
       " there is some mystical words engraved on it.");
    set_type("knife");
    set_material("metal/mithril");
    set_quality(6);
    set_wc(10, "strike");
    set_wc(15, "fire");
    set_ac(10);
    set_decay_rate(1500);
    set_verb("thrust");
    set_throwable(0);
    set_hit_bonus(25);
    set_parry_bonus(10);
    set_property("no add quality",1);
    set("skill level", 120);
    set_wield( (: call_other, this_object(), "add_bonus" :) );
    set_unwield( (: call_other, this_object(), "remove_bonus" :) );
    last_used = 0;
}

int add_bonus() {
   write("You feel the energy of the dagger surge through your body.");
   TP->add_skill_bonus("back stab", 20);
   TP->add_skill_bonux("dodge", 10);
   chanted = 0;
   return 1;
}

int remove_bonus() {
   mixed tmp;
   if(chanted)
      write("The energy from the dagger is released from your body as you"
         " unwield the dagger.  The inscription '%^BOLD%^GREEN%^Inguz Dagaz"
         "%^RESET%^' on the dagger fades away as the dagger lose it's power.");
   TP->add_skill_bonus("back stab", -20);
   TP->add_skill_bonus("dodge", -10);
   tmp = this_object()->query_property("extra long");
   if(pointerp(tmp)) tmp -= ({ rune });
   else if(stringp(tmp)) tmp = ({});
           this_object()->set_property("extra long", tmp);
   chanted = 0;
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
      notify_fail("The dagger is already being chanted and it is filled with"
         " energy.\n");
      return 0;
   }
   if(sscanf(str,"%s at dagger",incant) == 1) 
      if(incant != "silogous biretine") {
         notify_fail("You can't chant on that!\n");
         chanted = 0;
         return 0;
      }
      else if(query_wielded() != TP) {
              notify_fail("You must wield the weapon to chant at it!\n");
              return 0;
           }
           else {
              write("The dagger begins to vibrate violently in your hand");
              write("An inscription suddenly appears on the dagger.");
	      message("info","The dagger in "+TPQCN+"'s hand begins to vibrate"
                " violently as "+TP->query_subjective()+" chants at it.",
                ENV(TP),TP);
              message("info","An inscription suddenly appears on "+TPQCN+"'s"
                " dagger as "+TP->query_subjective()+" chants at it.",
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
   string tmp;

   if(!mesg) {
      notify_fail("You can't recite that!\n");
      return 0;
   }
   if(!chanted) {
      notify_fail("You can't recite without knowing the inscription!\n");
      return 0;
   }
   if(mesg != "inguz dagaz" && mesg != "Inguz Dagaz") {
      notify_fail("Nothing appear to happen.\n");
      return 0;
   }
   if(query_wielded() != this_player()) {
      notify_fail("You must wield the weapon to recite the inscription.\n");
      return 0;
   }
   if(time() - last_used < HOUR) {
     notify_fail("The dagger is still recovering from massive energy drain.\n");
     return 0;
   }
   if(this_player()->query_invis()) {
     notify_fail("You are already invisible fool!\n");
     return 0;
   }
   if(time() - last_used >= HOUR || !last_used) {
      message("info","%^BOLD%^GREEN%^You suddenly fades into shadow."
         "%^RESET%^",TP);
      message("info","%^BOLD%^GREEN%^"+TPQCN+" suddenly fades into shadow."
         "%^RESET%^",ENV(TP),TP);
      last_used = time();
      this_player()->set_invis(1);
      call_out("vis_player",420 + random(181));
      return 1;
   }
}

int vis_player() {
   message("info","%^BOLD%^GREEN%^You suddenly become visible.%^RESET%^",TP);
   message("info","%^BOLD%^GREEN%^"+TPQCN+" appears before you.%^RESET%^",
     ENV(TP),TP);
   if(this_player()->query_invis())
      this_player()->set_invis(0);
   return 1;
}
