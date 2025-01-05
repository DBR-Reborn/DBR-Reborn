//          Wizard: Delsius
//          statue
//          June 97

#include <std.h>
#include </wizards/delsius/defs/defs.h>
inherit MONSTER;

create () {
   ::create();
   set_name("statue");
   set_id(({"statue","figure"}));
   set("race","golem");
   set_short("A stone statue");
  set_long("This huge statue is made of solid rock.  It's age is apparent "
            "for it bears numerous cracks and imperfections.  It almost "
            "seems like the slightest touch or sound would cause it "
            "to crumble.");
   set_emotes(10, ({"A piece of the statue crumbles to the floor.",
                    "The statue bellows, 'Please, don't yell!'",
                    "The statue shifts position."}));
   set_level(19);
  set_body_type("human");
  new(TUN_OBJ+"rod")->move(TO);
}

void catch_tell(string str) {
   string mesg, tmp1, tmp2;

   if(sscanf(str,"%s yells in %s %s",tmp1, tmp2, mesg) == 3)
      if(mesg == "eutats") {
         message("info","%^BOLD%^GREEN%^
As you scream the strange word at the top of your lungs, the statue cocks
it's head and glares at you in horror.  The once small cracks begin to 
widen and chunks of stone fall ferociously to the ground.  In a matter of
seconds, the gigantic statue is reduced to a pile of dust and rubble.
%^RESET%^",TP);
         message("info","%^BOLD%^GREEN%^
As "+TPQCN+" screams the strange word at the top of "+TP->query_possessive()+" lungs, the statue
cocks it's head and glares at "+TP->query_objective()+" in horror.  The once small cracks begin
to widen and chunks of stone fall ferociously to the ground.  In a matter
of seconds, the gigantic statue is reduced to a pile of dust and rubble.
%^RESET%^",ENV(TP),TP);
         all_inventory(TO)->remove();
         new(TUN_OBJ+"rubble")->move(ENV(TO));
         remove();
      }
}

int query_lang_prof() { return 10; }
