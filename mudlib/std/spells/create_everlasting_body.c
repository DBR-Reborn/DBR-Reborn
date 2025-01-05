inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","create everlasting body");
    set_property("skill","necromancy");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",331);
    set_property("dev cost", 195);
    set_property("fast dev cost", 505);
    set_property("spell level", 40);
    set_property("moon","luna");
    set_property("caster message","You begin to create the body.");
    set_property("target message","");
    set_property("observer message","$C begins to create an everlasting body.");
    set_property("spell type",({ }));
	set_property("no target", 1);
	set_property("target type", "any");
    set_property("prereq", "animate nethergeist");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell creates an everlasting body. You must cast it with a dracolich, abomination and nethergeist in the room.\n"
"The pets must all be *6 and and this spell only works as a *6\n"
"YOU MUST STAY IN THE ROOM WITH THE UNDEADS UNITL THE SPELL IS COMPLETED!!\n"
"Syntax: Cast *6 create everlasting body\n",
this_player());
}


void spell_func(object caster, object at, int power, string args, int flag) {
    int time;
    //object ob;
    at=caster;

//     if(!present("Skeleton" && "Zombie" && "Ghoul" && "ghast" && "vampire" && "death knight" && "lich" && "demilich" && "dracolich" && "abomination" /*&& "nethergeist"*/, environment(caster))) {
     if(!present("dracolich" && "abomination" && "nethergeist", environment(caster))) {
    
    message("info", "You must cast this spell with all necessary pets in the room.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  if (power < 6) {
  message("info", "You must cast this spell at a power 6.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  
  if (present("dracolich", environment(caster))->query_property("power") < 6) {
  message("info", "The Dracholich must be power 6.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  if (present("nethergeist", environment(caster))->query_property("power") < 6) {
  message("info", "The Nethergeist must be power 6.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  if (present("abomination", environment(caster))->query_property("power") < 6) {
  message("info", "The Abomination must be power 6.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
   if (present("dracolich", environment(caster))->query_owner() != (string)caster->query_name()) {
  message("info", "You must own the Dracholich.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  if (present("nethergeist", environment(caster))->query_owner() != (string)caster->query_name()) {
  message("info", "You must own the Nethergeist.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  if (present("abomination", environment(caster))->query_owner() != (string)caster->query_name()) {
  message("info", "You must own the Abomination.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  
  if(flag) {
    message("info", "Your pets attack you!", caster);
    message("info", " all pets attack "+
          (string)caster->query_cap_name() + "!", environment(caster),
          ({ caster, at }));
  present("dracolich", environment(caster))->set_owner("asskicker");
  present("dracolich", environment(caster))->kill_ob(caster, 0);
  present("abomination", environment(caster))->set_owner("asskicker");
  present("abomination", environment(caster))->kill_ob(caster, 0);
  present("nethergeist", environment(caster))->set_owner("asskicker");
  present("nethergeist", environment(caster))->kill_ob(caster, 0);
    remove();
    return;
  }
  
  set_work_message("%^GREEN%^You work to combine the corpses.");
  time = (630);
  	if(archp(caster)) {
	time = 1;
	}
  start_work(caster, at, time, power);
  return;
}

void finish_work(object caster, object at, int power) {
  object ob;
   
  present("dracolich", environment(caster))->remove();
  present("abomination", environment(caster))->remove();
  present("nethergeist", environment(caster))->remove();
  
  message("info", "The corpses combine into an everlasting body.", caster);
  message("info", (string)caster->query_cap_name() + " utters some " + "necromantic incantations, and the undead creations combine to form an everlasting body ", environment(caster), ({ caster }) );
  
  seteuid(getuid());
  ob = new("/std/diewarzau/obj/misc/everlasting_body");
  ob->move(environment(caster));
  remove();
  return;
}
  