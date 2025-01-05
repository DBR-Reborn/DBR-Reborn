inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","dl bind");
    set_property("skill","chaos magic");
    set_property("casting time",11);
    set_property("base mp cost", 68);
    set_property("dev cost",145);
    set_property("fast dev cost",430);
    set_property("spell level", 28);
    set_property("moon","warzau");
    set_property("caster message","You cast bind demon at $T.");
    set_property("target message","");
    set_property("observer message","$C casts bind demon at $T.");
    set_property("spell type",({ "protection" }));
    //HONSPRON2020 - protection was at 13...really low... and added holy
    set_property("protection types", ([ "impaling" : 20, "crushing" : 20,
          "cutting" : 20, "disruption" : 20, "strike" : 20,
          "fire" : 20, "cold" : 20, "electricity" : 20,
          "impact" : 20, "stress" : 20, "holy" : 20 ]));
    set_property("stack key", "demonl armour");
    set_property("stack num", 3);
    set_property("duration", 50);
    set_property("prereq", "bind greater demon");
    set_property("must be present", 1);
    set_property("target type", "living");
    return;
}

void info() {
message("help",
"This spell binds a demon lord to your skin as armour.  The spell must "
"be cast at the demon itself, and the demon must be one which you have "
"summoned and successfully controlled.  The spell must be cast at a level "
"equal to or higher than the power level of the demon.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;
  if(!at->id("demon lord")) {
    message("info", "You must cast this spell at a demon lord.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(!at->query_owner() || (string)at->query_owner() != (string)caster->query_name()) {
    message("info", "The demon must have been summoned and contolled by you.",
        caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "Instead of binding the demon to you, you release it "
      "from your control and it attacks!", caster);
    message("info", (string)at->query_cap_name() + " angrily attacks "+
          (string)caster->query_cap_name() + "!", environment(caster),
          ({ caster, at }));
    at->set_owner("asskicker");
    at->kill_ob(caster, 0);
    remove();
    return;
  }
  if((int)at->query_power() < power) {
    message("info", "The demon must be equal or greater power than the spell.",
        caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
   if((int)caster->query_stack("ldemon armour") + (int)caster->query_stack("demon armour") + (int)caster->query_stack("gdemon armour") + (int)caster->query_stack("demonl armour")== 3) {
    message("info", (string)caster->query_cap_name() +
	    " cannot receive any more demon binds.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
   at->remove();
  args = 0;
  ::spell_func(caster, caster, power, args, 0);
  return;
}



