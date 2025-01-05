inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";
inherit "/std/check_brittle.c";


void create() {
    ::create();
    set_property("name","banshee blade");
    set_property("skill","magery");
    set_property("casting time",19);
    set_property("base mp cost",75);
    set_property("dev cost",94);
    set_property("fast dev cost",195);
    set_property("spell level", 20);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast banshee blade at $T.");
    set_property("target message","");
    set_property("observer message","$C casts banshee blade at $T.");
    set_property("spell type",({}));
    set_property("duration", 20);
    set_property("must be present", 1);
    set_property("stack key", "banshee blade");
    set_property("stack num", 3);
    set_property("target type", "any");
    set_property("prereq", "greater plasma blade");
    return;
}

void info() {
message("help",
"This spell imbues your weapon with banshee force, unleashing aether and vacuum criticals "
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
	message("info", "Your weapon glows with banshee power.", caster);
		if(power < 4 ){
		ob->set_extra_wc(([ "aether" : 7*power ]));
		ob->set_auto_crits((["aether B" : 5*power ] )); 
		ob->set_extra_wc(([ "vacuum" : 7*power ]));
		ob->set_auto_crits((["vacuum B" : 5*power ] )); 
		}
		else{
		ob->set_extra_wc(([ "aether" : 8*power ]));
		ob->set_auto_crits((["aether B" : 6*power ] )); 
		ob->set_extra_wc(([ "vacuum" : 8*power ]));
		ob->set_auto_crits((["vacuum B" : 6*power ] )); 
		ob->start_shadow(at,props["duration"], "%^CYAN%^A banshee blade spell wears off.");
		}
		if(!check_brittle(at, caster, 10)) {
    	remove();
  }
	}
	else{	
	message("info", "You may not stack any further banshee on that weapon.",caster);
	caster->add_mp(props["mp cost"]);
	ob->external_destruct(ob);
	}
    remove();
    return;
}


