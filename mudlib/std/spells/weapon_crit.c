inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name","weapon crit");
    set_property("skill","worship of k'thach");
    set_property("casting time",8);
    set_property("base mp cost",55);
    set_property("dev cost",65);
    set_property("fast dev cost",155);
    set_property("spell level", 12);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast weapon crit at $T.");
    set_property("target message","");
    set_property("observer message","$C casts weapon crit at $T.");
    set_property("spell type",({}));
    set_property("duration", 280);
    set_property("must be present", 1);
    set_property("stack key", "weapon crit");
    set_property("stack num", 3);
    set_property("target type", "any");
    return;
}

void info() {
message("help",
"This spell imbues your weapon with holy force as well as impact "
"damage, unleashing righteous "
"power on your enemies!\n",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;
  if(!at->is_weapon()) {
    message("info", "You must cast this spell at a weapon.", caster);
    caster->add_mp(props["mp cost"]);
    return;
  }
if(flag) {
    message("info", "The spell fizzles, costing double mp.", caster);
    caster->add_mp(-1* props["mp cost"]);
    remove();
    return;
  }
  message("info", "Your weapon glows with %^BOLD%^crit%^RESET%^ power.",
          caster);
  ob = new("/std/spells/shadows/weapon_shadow");

if(!check_stack(at, ob)) {
    message("info", "You may not stack any more weapon crit spells on that weapon.",
      caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  //ob->set_extra_wc(([ "holy" : 7*power+(caster->query_level()/2) ]));
  //ob->set_auto_crits(([ "holy A" : 6*power+(caster->query_level()/2) ] ));
  ob->set_enh_critical(power); 
  ob->start_shadow(at,props["duration"], "%^CYAN%^A weapon crit spell wears off.");
  remove();
  return;
}
