inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","animate sasa");
    set_property("skill","necromancy");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",330);
    set_property("dev cost", 199);
    set_property("fast dev cost", 510);
    set_property("spell level", 100);
    set_property("moon","luna");
    set_property("caster message","You begin to mold the body.");
    set_property("target message","");
    set_property("observer message","$C begins to mold a body.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    //set_property("prereq", "create everlasting body");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell animates an Sasa",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
	int time;
	
	if(!at->id("sasa body")) {
    message("info", "You must cast this spell at a sasa body.",
	    caster);
    remove();
    return;
  }
	
  set_work_message("%^GREEN%^You mold the body.");

time = 1;

  start_work(at, caster, time, power);
  return;
}



void finish_work(object caster, object at, int power) {
  object ob;

  message("info", "You create "+
	  "Sasa!", caster);
  message("info", (string)caster->query_cap_name() + " mutters "+
	  "under his breath and Sasa is born! ",
	  environment(caster), ({ caster }) );
	
  seteuid(getuid());
  at->remove();
  ob = new("/wizards/honspron/pets/sasa_pet");
  ob->set_up(power);
  ob->set_owner((string)caster->query_name());
  ob->move(environment(caster));
  remove();
  return;
}

