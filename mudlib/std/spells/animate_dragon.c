inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","animate dragon");
    set_property("skill","necromancy");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",330);
    set_property("dev cost", 199);
    set_property("fast dev cost", 510);
    set_property("spell level", 50);
    set_property("moon","luna");
    set_property("caster message","You begin to mold the body.");
    set_property("target message","");
    set_property("observer message","$C begins to mold a body.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("prereq", "combine everlastings");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell animates an undead dragon scale into an undead dragon, a powerful undead who will serve you as an undead thrall.  "
"She will serve you by fighting beside you in combat.\n"
"You must specify an elemental lore that you have trained to 100.\n"
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  The spell must be cast at a dragon scale, which must "
"be made with the ‘combine everlastings’ spell.  If you are interrupted while casting, "
"you may pick up again at a later time.\n"
"Syntax: cast *6 animate dragon at scale with <lore>\n"
"Ex: cast *6 animate dragon at scale with nexus lore\n",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
	int time;
	string lorename, ele;
	
  if(!at->id("undead dragon scale")) {
    message("info", "You must cast this spell at an undead dragon scale.",
	    caster);
    remove();
    return;
  }
  ele = (args);
  lorename = (""+ele+""" lore");
  if(!caster->query_skill(lorename)) {
    message("info", "You must train "+lorename+" to 100 in order to use that element",
	    caster);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the summoning energies and destroy "+
	    "the scales!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently destroys an undead dragon scale.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  
  at->set_property("element", ele);
  set_work_message("%^GREEN%^You mold the scales.");
  time = (19500+((960-(int)caster->query_skill("necromancy"))*power));
  if(archp(caster)) {
time = 1;
}
  start_work(at, caster, time, power);
  return;
}



void finish_work(object caster, object at, int power, int pow) {
  object ob;
  string lorename, ele;
  pow = power;

  if(power <= 0) {
    message("info", "BUG in undead spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "The dragon scale transforms into a "+
	  "dragon.", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "necromantic incantations, and an undead dragon scale "+
	  "transforms into a dragon.",
	  environment(caster), ({ caster }) );
	      	if(archp(caster)) {
	    }else{  
	   message("info", "%^GREEN%^%^BOLD%^The roar of a dragon is heard throughout the land.",
	   users()); }
  ele = (string)at->query_property("element");
  lorename = (""+ele+""" lore");
  at->remove();
  seteuid(getuid());
  
  ob = new("/std/spells/summon/undead_dragon");
  //ob->set_short(""+ele+" Dragon of the undead realm");
  ob->set_property("element", ""+ele+"");
  ob->set_property("melee damage", ([ ""+ele+"" : 200+(50*pow), "cold" : 200+(50*pow), "unholy" : 200+(50*pow), "infernal" : 200+(50*pow), "disruption" : 200+(50*pow) ]) );
  ob->set_skill(""+lorename+"", 110+(15*pow));
  ob->set_up(power);
  ob->set_owner((string)caster->query_name());
  ob->move(environment(caster));
  remove();
  return;
}

