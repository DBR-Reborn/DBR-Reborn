
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","demon haste");
    set_property("skill","chaos magic");
    set_property("casting time",10);
    set_property("base mp cost",41);
    set_property("dev cost", 57);
    set_property("fast dev cost", 150);
    set_property("spell level", 11);
    set_property("moon","warzau");
    set_property("caster message","You bind the energy of $T.");
    set_property("target message","");
    set_property("observer message","$C binds the energy of $T.");
    set_property("spell type",({ }));
    set_property("target type", "living");
    set_property("must be present", 1);
    set_property("duration", 200);
    set_property("stack key", "demonhaste");
    set_property("stack num", 1);
    return;
}    


void info() {
message("help",
"This spell gives you extra rounds in combat.  It needs to be cast at a demon, greater demon or demon lord. The stronger the demon, the greater the effect. It may only be cast once on a target.",
this_player());
}



void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;
  if(at->id("lesser demon")) {
    message("info", "You must cast this spell at a demon, greater demon or demon lord.", caster);
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
    
seteuid(getuid());
  if(caster->query_haste()) {
    message("info", "A target may only receive one haste spell.",
      caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}
 message("info", "%^MAGENTA%^%^BOLD%^You bind the demon.", caster);
  caster->set("demonhaste #", (int)caster->query("demonhaste #") + 1);
  call_out("remove_stack", props["duration"], caster);

 if (!at->id("greater demon") || (!at->id("demon lord"))){
  ob = new("/std/spells/shadows/demon_haste_shadow");
    ob->start_shadow(caster, props["duration"], "%^CYAN%^A haste spell expires."); 
  at->remove();
  return;
  }
  
  if (at->id("greater demon")) {
  ob = new("/std/spells/shadows/gdemon_haste_shadow");
    ob->start_shadow(caster, props["duration"], "%^CYAN%^A haste spell expires."); 
  at->remove();
  return;
  }
  if (at->id("demon lord")){
  ob = new("/std/spells/shadows/demonl_haste_shadow");
    ob->start_shadow(caster, props["duration"], "%^CYAN%^A haste spell expires."); 
  at->remove();
  return;
  }

  return;

}
void remove_stack(object caster) {
  if(!objectp(caster)) return;
  caster->set("demonhaste #", (int)caster->query("demonhaste #") - 1);
  remove();
  return;
}
