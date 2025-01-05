
#include <cave.h>
#include <clock.h>
#include <def.h>
#define rune "An %^BOLD%^MAGENTA%^Isa Jera%^RESET%^ rune is inscribed on the armour."

inherit "/std/armour";

int last_used, chanted, saved;
object owner;

int save_me(string file) {
   tell_room(find_player("joutei"),"Saved.....");
   if(!file_exists(LOG+"robe.log")) {
      write_file(LOG+"robe.log","LOADED");
   write("Log file written.");
   }
   owner = ENV(TO);
   write("owner: "+owner->query_name());
   return ::save_me(file);
}
 
int restore_me(string file) {
   owner = 0;
   write("Owner reset.");
   return ::restore_me(file);
}
 
void remove() {
   if(owner != previous_object()) 
      if(owner == ENV(TO)) ::remove();
      else {
         tell_room(find_player("joutei"),"%^RED%^REMOVED%^RESET%^");
         rm(LOG+"robe.log");
         ::remove();
      }
}
      
void init() {
   ::init();
   add_action("fun_chant","chant");
   add_action("fun_recite","recite");
}

void create() {
   mixed tmp;
   ::create();
   set_name("robe");
   set("id",({"robe","Robe",}));
   set("short","%^BOLD%^WHITE%^Pearl Robe%^RESET%^");
   set("long","This a robe encrested with pearls and many others rubies. Every"
     " parts of the robe crafted with great details. There is some mystical"
     " words finely crafted insdie the robe.  These words must have some"
     " special purpose for the robe.");
   set_type("robe");
   set_material("metal/laen");
   set_ac(10);
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
   write("The power from your armor fades away as you remove the robe.");
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
      notify_fail("The robe is already being chanted and it is filled with"
         " energy.\n");
      return 0;
   }
   if(sscanf(str,"%s at robe",incant) == 1) 
      if(incant != "nebulosus informis") {
         notify_fail("You can't chant on that!\n");
         chanted = 0;
         return 0;
      }
      else if(query_worn() != TP) {
              notify_fail("You must wear the robe to chant on it!\n");
              return 0;
           }
           else {
              write("The robe begins to vibrate violently on your body");
              write("An inscription suddenly appears on the robe.");
	      message("info","The robe on "+TPQCN+"'s body begins to vibrate"
                " violently as "+TP->query_subjective()+" chants at it.",
                ENV(TP),TP);
              message("info","An inscription suddenly appears on "+TPQCN+"'s"
                " pearl robe as "+TP->query_subjective()+" chants at it.",
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
   if(mesg != "isa jera" && mesg != "Isa Jera") {
      notify_fail("Nothing appear to happen.\n");
      return 0;
   }
   if(query_worn() != this_player()) {
      notify_fail("You must wear the robe to recite the inscription.\n");
      return 0;
   }
   if(time() - last_used < HOUR*2) {
     notify_fail("The robe is still recovering from massive energy drain.\n");
     return 0;
   }
   if(time() - last_used >= HOUR*2 || !last_used) {
      last_used = time();
      ob = new("/std/spells/blur");
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
