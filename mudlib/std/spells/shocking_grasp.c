inherit "/std/spells/spell";



void create() {
    ::create();
    set_property("name","shocking grasp");
    set_property("skill", "conjuration");
    set_property("casting time",5);
    set_property("base mp cost",23);
    set_property("dev cost", 12);
    set_property("fast dev cost", 30);
    set_property("spell level", 2);
    set_property("moon","ankh");
    set_property("caster message","You cast shocking grasp on $T.");
    set_property("target message","$C casts shocking grasp on you.");
    set_property("observer message","$C casts shocking grasp on $T.");
    set_property("spell type",({ "stat mod" }));
    set_property("stat dice", "1D2");
    set_property("stats", ({ "strength" }) );
    set_property("target type", "living");
    set_property("must be present",1);
    set_property("duration", 240);
    return;
}

int res_spell() { return 1; }

void info() {
message("help",
"This spell gives the recipient hands that radiate electricity,shocking"
"his/her opponents in combat.  The amount of power increases with the caster's level.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;

  seteuid(getuid());
  if((int)at->query_s_grasp()) {
    message("info", (string)at->query_cap_name() +
	    " already has shocking grasp.",
	    caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(!flag) {
    ob = new("/std/spells/shadows/s_grasp_shadow");
    ob->set_power(power);
    ob->start_shadow(at, props["duration"],
	  	   "\n%^CYAN%^Shocking grasp wears off.%^RESET%^");
  }
  ::spell_func(caster, at, power, args, flag);
  return;
}

