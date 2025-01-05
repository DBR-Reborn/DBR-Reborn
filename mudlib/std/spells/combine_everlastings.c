inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","combine everlastings");
    set_property("skill","necromancy");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",331);
    set_property("dev cost", 195);
    set_property("fast dev cost", 505);
    set_property("spell level", 45);
    set_property("moon","luna");
    set_property("caster message","You begin to combine the everlastings.");
    set_property("target message","");
    set_property("observer message","$C begins to combine everlastings into one.");
    set_property("spell type",({ }));
	set_property("no target", 1);
	set_property("target type", "any");
    set_property("prereq", "animate everlasting");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell creates an undead dragon scale. You must cast it with 5 everlastings in the room.\n"
"The pets must all be *6 and and this spell only works as a *6\n"
"YOU MUST STAY IN THE ROOM WITH THE UNDEADS UNITL THE SPELL IS COMPLETED!!\n"
"Syntax: Cast *6 combine everlastings\n",
this_player());
}


void spell_func(object caster, object at, int power, string args, int flag) {
    int time;
    at=caster;
 		   
    	if(!present("everlasting" && "everlasting 2" && "everlasting 3" && "everlasting 4" && "everlasting 5", environment(caster))) { 
    	message("info", "You must cast this spell with all 5 everlastings in the room.", caster);
    	caster->add_mp(props["mp cost"]);
    	remove();
    	return;
  		}
  		if (present("everlasting" && "everlasting 2" && "everlasting 3" && "everlasting 4" && "everlasting 5", environment(caster))->query_owner() != (string)caster->query_name()) {
 		message("info", "You must own the Everlastings.", caster);
    	caster->add_mp(props["mp cost"]);
    	remove();
    	return;
  		}
  		if (present("everlasting", environment(caster))->query_max_hp() < 18000) {
  		message("info", "Everlasting 1 must be power 6.", caster);
   		caster->add_mp(props["mp cost"]);
    	remove();
    	return;
  		}
  		if (present("everlasting 2", environment(caster))->query_max_hp() < 18000) {
  		message("info", "Everlasting 2 must be power 6.", caster);
   		caster->add_mp(props["mp cost"]);
    	remove();
    	return;
  		}
  		if (present("everlasting 3", environment(caster))->query_max_hp() < 18000) {
  		message("info", "Everlasting 3 must be power 6.", caster);
   		caster->add_mp(props["mp cost"]);
    	remove();
    	return;
  		}
  		if (present("everlasting 4", environment(caster))->query_max_hp() < 18000) {
  		message("info", "Everlasting 4 must be power 6.", caster);
   		caster->add_mp(props["mp cost"]);
    	remove();
    	return;
  		}
  		if (present("everlasting 5", environment(caster))->query_max_hp() < 18000) {
  		message("info", "Everlasting 5 must be power 6.", caster);
   		caster->add_mp(props["mp cost"]);
    	remove();
    	return;
  		}
  		/*if (present("everlasting" && "everlasting 2" && "everlasting 3" && "everlasting 4" && "everlasting 5", environment(caster))->query_property("power") <6) {
  		message("info", "The Everlastings must be power 6.", caster);
   		caster->add_mp(props["mp cost"]);
    	remove();
    	return;
  		}*/
      
  if (power < 6) {
  message("info", "You must cast this spell at a power 6.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  if(flag) {
    message("info", "Your pets attack you!", caster);
    message("info", " all pets attack "+
          (string)caster->query_cap_name() + "!", environment(caster),
          ({ caster, at }));
  present("everlasting" && "everlasting 2" && "everlasting 3" && "everlasting 4" && "everlasting 5", environment(caster))->set_owner("asskicker");
  present("everlasting" && "everlasting 2" && "everlasting 3" && "everlasting 4" && "everlasting 5", environment(caster))->kill_ob(caster, 0);
    remove();
    return;
  }
  
  set_work_message("%^GREEN%^You work to combine the everlastings.");
  time = (1200);
  	if(archp(caster)) {
	time = 1;
	}
  start_work(caster, at, time, power);
  return;
}

void finish_work(object caster, object at, int power) {
  object ob;
   
  present("everlasting", environment(caster))->remove();
  present("everlasting", environment(caster))->remove();
  present("everlasting", environment(caster))->remove();
  present("everlasting", environment(caster))->remove();
  present("everlasting", environment(caster))->remove();
  
  message("info", "The everlastings combine into an undead dragon scale.", caster);
  message("info", (string)caster->query_cap_name() + " utters some " + "necromantic incantations, and the everlastings combine to form a dragon scale ", environment(caster), ({ caster }) );
  
  seteuid(getuid());
  ob = new("/std/diewarzau/obj/misc/undead_dragon_scale");
  ob->move(environment(caster));
  remove();
  return;
}
  