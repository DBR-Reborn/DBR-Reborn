//inherit "/std/spells/long_term_spell";
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","summon demon prince");
    set_property("skill","chaos magic");
    set_property("duration", "permanent");
    set_property("casting time",101);
    set_property("base mp cost",311);
    set_property("dev cost", 175);
    set_property("fast dev cost", 481);
    set_property("spell level", 35);
    set_property("moon","luna");
    set_property("caster message","You open a conduit to the demon world.");
    set_property("target message","");
    set_property("observer message","$C Opens a conduit to the demon world.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", 440);
    //set_property("target type", "any");
    set_property("prereq", "summon demon lord");
    //set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell is used to summon a DEMON PRINCE!  You must make a successful "
"control roll at -50 ('help skill control demon'), or he may simply disappear, "
"or ATTACK!  Once summoned, he may be bound to your skin as armour or "
"your sword to increase damage.  Other spells are necessary to do these, "
"however.  The demon, if controlled, may be used additionally to fight at "
"your side.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;
  int roll;

  seteuid(getuid());
  ob = new("/std/spells/summon/demon_prince");
  ob->set_dur(props["duration"]);
  ob->set_owner("asskicker");
  ob->set_up(power);
  ob->move(environment(caster));
  if(flag) {
    message("info", "%^RED%^%^BOLD%^The demon angrily attacks you!", caster);
    message("info", "%^RED%^%^BOLD%^The demon angrily attacks "+
      (string)caster->query_cap_name()+"!", environment(caster), ({ caster }));
    ob->kill_ob(caster, 0);
    ob->set_following(caster);
    caster->add_follower(ob);
    remove();
    return;
  }
  roll = random(100);
  if(roll < (int)caster->query_skill("control demon")-50) {
    message("info", "The demon is successfully contolled.", caster);
    ob->set_owner((string)caster->query_name());
    remove();
    return;
  } else if(roll - ((int)caster->query_skill("control demon")-50) < 15) {
    message("info", "The demon is not controlled, and he goes in search of bigger and better things.",
        caster);
    ob->set_moving(1);
    ob->set_speed(60);
    ob->move_around();
    ob->set_aggr_status(1);
    ob->set_owner("asskicker");
    remove();
    return;
  } else if(roll - ((int)caster->query_skill("control demon")-50) < 30) {
    message("info", "The demon is not controlled.  Annoyed, he returns to his plane.",
        caster);
    ob->remove();
    remove();
    return;
  } else {
    message("info", "The demon is not controlled.  He angrily attacks you!",
         caster);
    ob->kill_ob(caster, 0);
    ob->set_following(caster);
    caster->add_follower(ob);
    remove();
    return;
  }
  remove();
  return;
}



/*
void spell_func(object caster, object at, int power, string args, int flag) {
  int time;
  if(!at->id("desecrated corpse")) {
    message("info", "You must cast this spell at an embalmed corpse.",
	    caster);
    remove();
    return;
  }
  if((int)at->query_level() < query_property("spell level")) {
    message("info", "You must cast this spell on a desecrated corpse of at least "+
      sprintf("level %d.", query_property("spell level")), caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the summoning energies and destroy "+
	    "the corpse!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently crumbles a desecrated corpse to dust.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
time=(12500+((760-(int)caster->query_skill("chaos magic"))*power));
if(archp(caster)) {
time = 1;
}
  set_work_message("%^ORANGE%^You channel chaos power.");
  start_work(at, caster, time, power);
  return;
}

void finish_work(object caster, object at, int power) {
  object ob;

  if(power <= 0) {
    message("info", "BUG in summon spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "You summon a Prince from the demonic world.", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "demonic incantations, and summons "+
	  "a demon prince.",
	  environment(caster), ({ caster }) );
	  if(archp(caster)) {
	    }else{  
	message("info", "%^ORANGE%^%^BOLD%^A loud rumble is heard across the realm as a demon prince is summoned from the demonic world!",
	  users());}
  at->remove();
  seteuid(getuid());
  ob = new("/std/spells/summon/demon_prince");
  ob->set_up(power);
  ob->set_owner((string)caster->query_name());
  ob->move(environment(caster));
  remove();
  return;
}
*/
