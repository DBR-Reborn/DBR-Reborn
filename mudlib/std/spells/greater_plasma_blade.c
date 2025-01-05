inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name","greater plasma blade");
    set_property("skill","magery");
    set_property("casting time",8);
    set_property("base mp cost",65);
    set_property("dev cost",82);
    set_property("fast dev cost",195);
    set_property("spell level", 16);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast greater plasma blade at $T.");
    set_property("target message","");
    set_property("observer message","$C casts greater plasma blade at $T.");
    set_property("spell type",({}));
    set_property("duration", 280);
    set_property("must be present", 1);
    set_property("stack key", "greater plasma blade");
    set_property("stack num", 3);
    set_property("target type", "any");
    set_property("prereq", "lesser plasma blade");
    return;
}

void info() {
message("help",
"This spell imbues your weapon with plasma force, unleashing greater plasma criticals "
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
	message("info", "Your weapon glows with %^COLOR220%^plasma%^RESET%^ power.", caster);
		if(power < 4 ){
		ob->set_extra_wc(([ "plasma" : 7*power+(caster->query_level()/2) ]));
		ob->set_auto_crits((["plasma B" : 5*power+(caster->query_level()/2) ] )); 
		}
		else{
		ob->set_extra_wc(([ "plasma" : 8*power+(caster->query_level()/2) ]));
		ob->set_auto_crits((["plasma B" : 6*power+(caster->query_level()/2) ] )); 
		ob->start_shadow(at,props["duration"], "%^CYAN%^A greater plasma blade spell wears off.");
		}
	}
	else{	
	message("info", "You may not stack any further plasma on that weapon.",caster);
	caster->add_mp(props["mp cost"]);
	ob->external_destruct(ob);
	}
    remove();
    return;
}


