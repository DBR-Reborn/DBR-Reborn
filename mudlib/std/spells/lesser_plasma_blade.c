inherit "/std/spells/spell";

inherit "/std/spells/weapon_stack_logic";
void create() {
    ::create();
    set_property("name","lesser plasma blade");
    set_property("skill","magery");
    set_property("casting time",4);
    set_property("base mp cost",55);
    set_property("dev cost",42);
    set_property("fast dev cost",115);
    set_property("spell level", 6);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast lesser plasma blade at $T.");
    set_property("target message","");
    set_property("observer message","$C casts lesser plasma blade at $T.");
    set_property("spell type",({}));
    set_property("duration", 280);
    set_property("must be present", 1);
    set_property("stack key", "plasma blade");
    set_property("stack num", 3);
    set_property("target type", "any");
    return;
}

void info() {
message("help",
"This spell imbues your weapon with plasma force, unleashing lesser plasma criticals "
"on your enemies!\n",
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
  ob = new("/std/spells/shadows/weapon_shadow");
	if(check_stack(at, ob)) {
	message("info", "Your weapon glows with %^COLOR220%^plasma%^RESET%^.", caster);
		if(power < 4 ){
		ob->set_extra_wc(([ "plasma" : 6*power+(caster->query_level()/2) ]));
		ob->set_auto_crits((["plasma A" : 6*power+(caster->query_level()) ]));
		ob->start_shadow(at,props["duration"], "%^CYAN%^A lesser plasma blade spell wears off.", caster);
		}
		else{
		ob->set_extra_wc(([ "plasma" : 8*power*power+(caster->query_level()/2) ]));
		ob->set_auto_crits((["plasma A" : 7*power*power+(caster->query_level()) ] )); 
		ob->start_shadow(at,props["duration"], "%^CYAN%^A lesser plasma blade spell wears off.", caster);
		}
	}
	else{
	message("info", "You may not stack any further plasma on that weapon.", caster);
    caster->add_mp(props["mp cost"]);
	ob->external_destruct(ob);	
	}
    remove();
    return;
}
