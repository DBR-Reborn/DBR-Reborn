inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","animate everlasting");
    set_property("skill","necromancy");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",330);
    set_property("dev cost", 199);
    set_property("fast dev cost", 510);
    set_property("spell level", 40);
    set_property("moon","luna");
    set_property("caster message","You begin to mold the body.");
    set_property("target message","");
    set_property("observer message","$C begins to mold a body.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("prereq", "create everlasting body");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell animates an everlasting body into a being of Everlasting Death, a powerful undead who will serve you as an undead thrall.  "
"She will serve you by fighting beside you in combat. When killed, some take the form of a ‘Lord of Death’...\n"
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  The spell must be cast at an everlasting body, which must "
"be made with the ‘create everlasting body’ spell.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
	int time;
  if(!at->id("everlasting body")) {
    message("info", "You must cast this spell at an everlasting body.",
	    caster);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the summoning energies and destroy "+
	    "the body!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently destroys an everlasting body.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  set_work_message("%^GREEN%^You mold the body.");
  time = (19500+((960-(int)caster->query_skill("necromancy"))*power));
  if(archp(caster)) {
time = 1;
}
  start_work(at, caster, time, power);
  return;
}



void finish_work(object caster, object at, int power) {
  object ob;

  if(power <= 0) {
    message("info", "BUG in undead spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "The body transforms into a "+
	  "Everlasting.", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "necromantic incantations, and an everlasting body "+
	  "transforms into an Everlasting.",
	  environment(caster), ({ caster }) );
	      	if(archp(caster)) {
	    }else{  
	   message("info", "%^GREEN%^%^BOLD%^A crack of thunder is heard throughout the land as an everlasting emerges from the undead realm.",
	   users()); }
  at->remove();
  seteuid(getuid());
  ob = new("/std/spells/summon/everlasting");
  ob->set_up(power);
  ob->set_owner((string)caster->query_name());
  ob->move(environment(caster));
  remove();
  return;
}

