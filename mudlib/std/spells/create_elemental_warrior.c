inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "create elemental warrior");
    set_property("skill", "elementalism");
    set_property("casting time", 125);
    set_property("base mp cost", 400);
    set_property("dev cost", 400);
    set_property("fast dev cost", 855);
    set_property("spell level", 50);
    set_property("moon", "luna");
    set_property("caster message","You summon a elemental warrior to do your bidding.");
    set_property("target message","");
    set_property("observer message","$C utters some magical incantations and a elemental warrior appears.");
    set_property("spell type", ({ }));
    set_property("duration", 800);
    set_property("no target", 1);
    set_property("elemental spell", 1);
    set_property("prereq", "create elemental fighter");
    return;
}

void info() {
    message("help", "This spell allows an Elementalist to call forth an Elemental Warrior, a more advanced hand to hand warrior than the likes of the lower level Elemental Fighter. A temporary pet designed for hand-to-hand combat to assist the caster against designated targets. Please note that this spell takes a considerable amount of time to cast, and the summoned warrior will only remain for a limited duration. Upon its creation, the warrior will assume the power of the element present NOTE: Elemental Warriors cannot be toggled aggressive.\n\nSyntax: 'cast *6 create elemental warrior'", this_player()); 
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;
    int zlevel;

  seteuid(getuid());
   ob = new("/std/spells/summon/ele/elemental_warrior");
//ADD
    zlevel = caster->query_level()-random(11);
    if(zlevel <= 50) {zlevel=50;}
    ob->set_level(zlevel);
    ob->set_short("["+zlevel+"] "+capitalize(props["element"])+" Elemental Warrior");
//END
  ob->set_up(power, props["element types"], props["element"]);
  ob->move(environment(caster));
  if(!flag)
    ob->set_owner((string)caster->query_name());
  ob->set_dur(props["duration"]);
caster->add_exp2(500+caster->query_level()*power);
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

