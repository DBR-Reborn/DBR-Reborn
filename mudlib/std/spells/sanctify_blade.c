inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {

    ::create();
    set_property("name","sanctify blade");
    set_property("skill","prayer");
    set_property("casting time",6);
    set_property("base mp cost",23);
    set_property("dev cost",35);
    set_property("fast dev cost",95);
    set_property("spell level", 8);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast sanctify blade at $T.");
    set_property("target message","");
    set_property("observer message","$C casts sanctify blade at $T.");
    set_property("spell type",({}));
    set_property("duration", 280);
    set_property("must be present", 1);
    set_property("stack key", "sanctify blade");
    set_property("stack num", 3);	
    set_property("target type", "any");
    return;
}

void info() {

message("help",
"This spell temporarily sanctifies your weapon, making it holy and "
"increasing the damage.\n",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;

  if(!at->is_weapon()) {
    message("info", "You must cast this spell at a weapon.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
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
	message("info", "You sanctify your weapon and bless it with %^BOLD%^holy%^RESET%^ power.", caster);
	   ob->set_extra_wc(([ "holy" : 3*power+(caster->query_level()/2) ]));
       ob->set_auto_crits((["holy A" : 3*power+(caster->query_level()) ] )); 
  
	ob->start_shadow(at, props["duration"], "%^CYAN%^A sanctify blade spell wears off.");
	}
	else{
	message("info", "You may not stack any further sanctify blade spells on that weapon.", caster);
    caster->add_mp(props["mp cost"]);
	ob->external_destruct(ob);
	}
  remove();
  return;
}
