inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","create elemental fighter");
    set_property("skill","elementalism");
    set_property("casting time",101);
    set_property("base mp cost",300);
    set_property("dev cost", 300);
    set_property("fast dev cost", 677);
    set_property("spell level", 40);
    set_property("moon","luna");
    set_property("caster message","You summon a elemental fighter to do your bidding.");
    set_property("target message","");
    set_property("observer message","$C utters some magical incantations and a elemental fighter appears.");
    set_property("spell type",({ }));
    set_property("duration", 600);
    set_property("no target", 1);
    set_property("elemental spell", 1);
    set_property("prereq", "summon elemental dragon");
    return;
}


void info() {
    message("help", "This spell allows an Elementalist to create a Elemental Fighter, a temporary pet designed for hand-to-hand combat to assist the caster against designated targets. Please note that this spell takes a considerable amount of time to cast, and the summoned fighter will only remain for a limited duration. Once summoned, the fighter will embody the element used in the spell, gaining slight protection against offensives of that elemental nature. Additionally, Elemental Fighters cannot be toggled aggressive.\n\nSyntax: 'cast *6 create elemental fighter'", 
    this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;
    int zlevel;

  seteuid(getuid());
   ob = new("/std/spells/summon/ele/elemental_fighter");
//ADD
    zlevel = caster->query_level()-random(11);
    if(zlevel <= 40) {zlevel=40;}
    ob->set_level(zlevel);
    ob->set_short("["+zlevel+"] "+capitalize(props["element"])+" Elemental Fighter");
//END
  ob->set_up(power, props["element types"], props["element"]);
  ob->move(environment(caster));
  if(!flag)
    ob->set_owner((string)caster->query_name());
  ob->set_dur(props["duration"]);
caster->add_exp2(400+caster->query_level()*power);
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

