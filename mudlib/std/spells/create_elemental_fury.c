inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "create elemental fury");
    set_property("skill", "elementalism");
    set_property("casting time", 151);
    set_property("base mp cost", 500);
    set_property("dev cost", 500);
    set_property("fast dev cost", 955);
    set_property("spell level", 60);
    set_property("moon", "luna");
    set_property("caster message","You summon a elemental fury to do your bidding.");
    set_property("target message","");
    set_property("observer message","$C utters some magical incantations and a elemental fury appears.");
    set_property("spell type", ({ }));
    set_property("duration", 1000);
    set_property("no target", 1);
    set_property("elemental spell", 1);
    set_property("prereq", "create elemental warrior");
    return;
}

void info() {
    message("help", "The imposing and omnipotent Elemental Fury. Once created is absolutely dynamite in physical combat. It also aids its incredible combat with extremely fast cast and powerful spell that can mow down opposition almost as fast as some strong area spells. A temporary pet designed for hand-to-hand combat to assist the caster against designated targets. Please note that this spell takes a considerable amount of time to cast, and the summoned fury will only remain for a limited duration. \n\nSyntax: 'cast *6 create elemental fury'", this_player()); 
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;
    int zlevel;

  seteuid(getuid());
   ob = new("/std/spells/summon/ele/elemental_fury");
//ADD
    zlevel = caster->query_level()-random(11);
    if(zlevel <= 50) {zlevel=50;}
    ob->set_level(zlevel);
    ob->set_short("["+zlevel+"] "+capitalize(props["element"])+" Elemental Fury");
//END
  ob->set_up(power, props["element types"], props["element"]);
  ob->move(environment(caster));
  if(!flag)
    ob->set_owner((string)caster->query_name());
  ob->set_dur(props["duration"]);
caster->add_exp2(600+caster->query_level()*power);
  if(flag) {
    message("info", "Your fumble has caused the elemental to become "+
	    "hostile!", caster);
    message("info", "The elemental is disoriented and becomes hostile!",
	     environment(caster), ({ caster }) );
    ob->kill_ob(caster, 0);
    remove();
    return;
  }
  ob->set_owner((string)caster->query_name());
  remove();
  return;
}

