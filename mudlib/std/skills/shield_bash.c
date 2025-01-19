// Recode in progress -TW
// 3. Enable spike-shield
// 4. Enable flaming-shield
// 5. Enable royal-insignia
#include <colors.h>

inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(10);
    set_fast_dev_cost(30);
    set_property("target type", "living");
    set_property("must be present",1);
}

void info() {
    message("help",
      "Using this skill you take your shield and bash your oponent.  "+
      "This will be most deadly on opponents of a much lighter weight "+
      "then you.  If successfull, you will knock your oponents down "+
      "causing them to fight less effectively, break their concentration, "+
      "and possibly damaging them.  Beware howerver, if your oponent dodges "+
      "your shield bash, you may become unbalanced and fall down instead.  "+
      "  You may only use this skill once every five combat rounds."+
      "\nSyntax: use shield bash at <player> with <shield worn>"+
      "\nExample: use shield bash at tailwind with large shield",
      this_player());
}

void skill_func(object from, object at, string arg) {
    int flag, i, diff, woffset;
    string *limbs;
    string shieldstr;
    object shieldob;
    int acid, spiked, oiled, brand, acidnew;

    if((time() - (int)from->query_last_use("shield bash")) < 6)
    {
	message("info", "You are too tired to use this skill yet."
	  , from);
	return;
    }
    if(environment(from) &&
      environment(from)->query_property("no attack")) {
	message("info", "Mystic forces prevent your action.", from);
	remove();
	return ;
    }
    if(at->shadow_form() || at->query_ghost()) {
	message("info", "You may not shield-bash a target which is immaterial.",
	  from);
	remove();
	return;
    }

    if(!arg){
	message("info", "You must specify the shield you'd like to use.", from);
	remove();
	return;
    }

    sscanf(arg, "%s", shieldstr);
    shieldob=present(shieldstr, from);

    if(!shieldob){
	message("info", "You don't have that shield.", from);
	remove();
	return;
    }

    if(!shieldob->query_worn()){
	message("info", "You're not wearing that shield.", from);
	remove();
	return;
    }

    from->set_last_use("shield bash");
    from->kill_ob(at, 0);

    woffset = from->query_weight() - at->query_weight();

    diff = props["skill level"] - at->query_skill("dodge");
    diff += random(woffset);
    if ((diff + random(100)) < 35) {
	message("my_combat", CMAGENTA + "You attempt to bash but "+
	  (string)at->query_cap_name()+ " dodges nimbly out of the way."+
	  CYELLOW + "You are unbalanced by the miss.",
	  from);
	message("other_combat", (string)from->query_cap_name() +
	  " attempts to bash you with "+possessive(from)+
	  " shield but you nimbly dodge out of the way.", at);
	message("other_combat", (string)from->query_cap_name() +
	  " attempts to bash "+
	  (string)at->query_cap_name()+ " with "+
	  possessive(from)+ " shield but " +
	  (string)at->query_cap_name()+" dodges.",
	  all_inventory(environment(from)),
	  ({ from, at }) );
	remove();
	return;
    }
    props["skill level"] -= (random(100) + 
      at->query_current_protection("torso","crushing")/4 ) - random(woffset / 25);
    if((int)props["skill level"] < -10) {
	message("my_combat", CMAGENTA +  "You attempt to bash "+
	  (string)at->query_cap_name()+ " but miss miserably.",
	  from);
	message("other_combat", (string)from->query_cap_name() +
	  " attempts to bash you with "+possessive(from)+ 
	  " shield but misses.", at);
	message("other_combat", (string)from->query_cap_name() +
	  " attempts to bash "+
	  (string)at->query_cap_name()+ " with "+
	  possessive(from)+ " shield but misses.",
	  all_inventory(environment(from)),
	  ({ from, at }) );
	remove();
	return;
    }
    message("my_combat", CMAGENTA + "You bash "+
      (string)at->query_cap_name()+ " fiercely with your shield.",
      from);
    message("other_combat", (string)from->query_cap_name() +
      " unbalances you with a fierce bash from " +possessive(from)+
      " shield.", at);
    message("other_combat", (string)from->query_cap_name() +
      " delivers a nasty bash to "+
      (string)at->query_cap_name()+ " with "+
      possessive(from)+ " shield.",
      all_inventory(environment(from)),
      ({ from, at }) );

    if(props["skill level"] > 20){
	message("other_combat", CYELLOW + "You are knocked on your back!",
	  at);
	message("my_combat", CYELLOW + 
	  at->query_cap_name() + " is knocked down!",
	  from);
	at->knock_down();
	at->set_paralyzed(random(5)+1);
    }

    acid=shieldob->query("acidcoated");
    spiked=shieldob->query_property("spiked");
    oiled=shieldob->query("flameoil");
    brand=shieldob->query_property("branded");

    switch(props["skill level"]) {
    case -10..5:
	at->do_damage((string)at->return_target_limb(), random(8)+1);
	break;
    case 6..20:
	at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
	if((acid*10 > at->query_skill("dodge")) && acid){
	    do_critical(from, at, "acid A");
	    shieldob->set_property("acidcoated", acid-1);
	}
	if((oiled*10 > at->query_skill("dodge")) && oiled){
	    do_critical(from, at, "fire A");
	}
	do_critical(from, at, "crushing A");
	break;
    case 21..33:
	at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
	if((acid*10 > at->query_skill("dodge")) && acid){
	    do_critical(from, at, "acid B");
	    shieldob->set_property("acidcoated", acid-2);
	}
	if((spiked*10 > at->query_skill("dodge")) && spiked){
	    do_critical(from, at, "impaling A");
	}
	if((oiled*10 > at->query_skill("dodge")) && oiled){
	    do_critical(from, at, "fire B");
	}
	if((brand*10 > at->query_skill("dodge")) && brand){
	    do_critical(from, at, "reflection A");
	}
	do_critical(from, at, "crushing B");
	break;
    case 34..45:
	at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
	if((acid*10 > at->query_skill("dodge")) && acid){
	    do_critical(from, at, "acid C");
	    shieldob->set_property("acidcoated", acid-3);
	}
	if((spiked*10 > at->query_skill("dodge")) && spiked){
	    do_critical(from, at, "impaling B");
	}
	if((oiled*10 > at->query_skill("dodge")) && oiled){
	    do_critical(from, at, "fire C");
	}
	if((brand*10 > at->query_skill("dodge")) && brand){
	    do_critical(from, at, "reflection B");
	}
	do_critical(from, at, "crushing C");
	break;
    case 46..62:
	at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
	if((acid*10 > at->query_skill("dodge")) && acid){
	    do_critical(from, at, "acid D");
	    shieldob->set_property("acidcoated", acid-4);
	}
	if((spiked*10 > at->query_skill("dodge")) && spiked){
	    do_critical(from, at, "impaling C");
	}
	if((oiled*10 > at->query_skill("dodge")) && oiled){
	    do_critical(from, at, "fire D");
	}
	if((brand*10 > at->query_skill("dodge")) && brand){
	    do_critical(from, at, "reflection C");
	}
	do_critical(from, at, "crushing D");
	break;
    case 63..10000:
	at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
	if((acid*10 > at->query_skill("dodge")) && acid){
	    do_critical(from, at, "acid E");
	    shieldob->set_property("acidcoated", acid-5);
	}
	if((spiked*10 > at->query_skill("dodge")) && spiked){
	    do_critical(from, at, "impaling D");
	}
	if((oiled*10 > at->query_skill("dodge")) && oiled){
	    do_critical(from, at, "fire E");
	}
	if((brand*10 > at->query_skill("dodge")) && brand){
	    do_critical(from, at, "reflection D");
	}
	do_critical(from, at, "crushing E");
	break;
    }

    acidnew=shieldob->query("acidcoated");
    if(acid && acidnew == acid) shieldob->set("acidcoated", acid-1);
    if(acid < 1){
	write("%^GREEN%^%^BOLD%^The acid wears off on your shield.%^RESET%^%^RESET%^");
	shieldob->set("acidcoated", 0);
    }
    if(acid == 1) write("%^GREEN%^%^BOLD%^The acid wears off on your shield.%^RESET%^%^RESET%^");

    // There's a random chance that your royal insignia will wear off after a bash
    // Disabled till I figure out how to remove a line from the extra long
    /*
	if(royal)
	  if(!random(royal)){
	    message("my_combat", CMAGENTA + "The royal insignia wears off your shield!", from);
	    shieldob->set_property("royalins", 0);
	  }
    */
    remove();
    return;
}

