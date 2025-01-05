#include <clock.h>
#include <def.h>
#define rune "A %^BOLD%^BLUE%^Ehwaz Mannaz%^RESET%^ rune is inscribed on the weapon."

inherit "/std/weapon";

int last_used,chanted;

void init() {
   ::init();
   add_action("fun_chant","chant");
   add_action("fun_recite","recite");
}

create() {
    ::create();
    set_name("sword");
    set("id", ({ "sword", "Sword","blade of justice","justice","Justice",
       "blade","Blade"}));
    set("short","%^BOLD%^GREEN%^Blade of Justice%^RESET%^");
    set("long", "This is a sword once used by a great hero name Davli.  The"
      " sword has sharp edges and glowing with blue aura around it.  It hmms"
      " as you hold it high in the air.  On the guard of the sword, it have"
      " some mystical words engraved on it.");
    set_type("blade");
    set_material("metal/platnite");
    set_quality(6);
    set_wc(20, "impaling");
    set_wc(15, "electricity");
    set_ac(10);
    set_decay_rate(1100);
    set_verb("lacerate");
    set_throwable(0);
    set_hit_bonus(15);
    set_parry_bonus(15);
    set_property("no add quality",1);
    set("skill level", 120);
    set_wield( (: call_other, this_object(), "add_bonus" :) );
    set_unwield( (: call_other, this_object(), "remove_bonus" :) );
    last_used = 0;
}

int add_bonus() {
   write("You feel the energy of the sword surge through your body. A inscription%^BOLD%^BLUE%^Ehwaz Mannaz %^RESET%^ materalizes on the sword");
   TP->add_skill_bonus("blade", 20);
   TP->add_skill_bonus("dodge", 10);
   TP->add_skill_bonus("parry", 10);
   chanted = 0;
    return 1;
}

int remove_bonus() {
   mixed tmp;
   if(chanted)
      write("The energy from the sword is released from your body as you"
       " unwield the sword.  The inscription '%^BOLD%^BLUE%^Ehwaz Mannaz"
       "%^RESET%^' on the sword fades away as the sword loses it's power.");
   TP->add_skill_bonus("blade", -20);
   TP->add_skill_bonus("dodge", -10);
   TP->add_skill_bonus("parry", -10);
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
      notify_fail("The sword is already being chanted at and it is"
         " filled with energy.\n");
      return 0;
   }
   if(sscanf(str,"%s at sword.",incant) == 1) 
      if(incant != "sanctus rabies") {
         notify_fail("You can't chant on that!\n");
         chanted = 0;
         return 0;
      }
      else if(query_wielded() != TP) {
              notify_fail("You must wield the weapon to chant at it!\n");
              return 0;
           }
           else {
              write("The sword begins to vibrate violently in your hand");
              write("An inscription suddenly appears on the sword.");
              message("info","The sword in "+TPQCN+"'s hand begins to vibrate"
                " violently as "+TP->query_subjective()+" chants at it.",
                ENV(TP),TP);
              message("info","An inscription suddenly appears on "+TPQCN+"'s"
                " blade as "+TP->query_subjective()+" chants at it.",
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
     if(mesg != "ehwaz mannaz" && mesg != "Ehwaz Mannaz") {
      notify_fail("Nothing appears to happen.\n");
      return 0;
   }
   if(query_wielded() != this_player()) {
      notify_fail("You must wield the weapon to recite the inscription.\n");
      return 0;
   }

   if(time() - last_used < HOUR) {
     notify_fail("The sword is still recovering from massive energy drain.\n");
     return 0;
   }
   if(time() - last_used >= HOUR || !last_used) {
      last_used = time();
      ob = new("/std/spells/holy_fury");
      ob->set_property("casting time",1);
      ob->set_property("base mp cost",0);
      ob->set_property("skill","temp casting");
      this_player()->set_skill("temp casting",100);
      ob->do_spell( (["caster":this_player(),"target":
         this_player()->query_name(),"power":6,"arg": 0]) );
      this_player()->delete_skill("temp casting");
      ob->spell_func(this_player(),this_player(),6,0,0);
      ob->remove();
      return 1;
   }

}
