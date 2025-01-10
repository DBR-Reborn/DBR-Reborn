inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name","ultimate plasma blade");
    set_property("skill","magery");
    set_property("casting time",27);
    set_property("base mp cost",83);
    set_property("dev cost",100);
    set_property("fast dev cost",225);
    set_property("spell level", 24);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message",
      "You cast ultimate plasma blade at $T.");
    set_property("target message","");
    set_property("observer message",
      "$C casts ultimate plasma blade at $T.");
    set_property("spell type",({}));
    set_property("duration", 720);
    set_property("must be present", 1);
    set_property("stack key", "greater plasma blade");
    set_property("stack num", 3);
    set_property("target type", "any");
    set_property("prereq", "greater plasma blade");
    return;
}

void info() {
    message("help",
      "This spell imbues your weapon with plasma force, unleashing the most "
      "powerful plasma criticals on your enemies!\n"
      "\n\n"
      "  'You will find no steel that will protect you from me.'\n"
      "                                 -Lord Renard\n"
      "\n",

      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob, weap;
    int skill = caster->query_skill(query_property("skill"));
    if(skill < 100)
	skill = 100;
    if(!at->is_weapon()) {
	message("info", "You must cast this spell at a weapon.", caster);
	caster->add_mp(props["mp cost"]);
	return;
    }


    ob = new("/std/spells/shadows/weapon_shadow");
    if(!check_stack(at, ob)) {
	message("info", "You may not stack any further plasma on that weapon.",
	  caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    message("info", "Your weapon glows with plasma power.",
      caster);
	ob->set_extra_wc(([ "plasma" : 12*power+(caster->query_level()/2) ]));
	ob->set_auto_crits((["plasma A" : 6*power+(caster->query_level()/2), "plasma B" : 5*power*skill/100, "plasma C" : 3*power*skill/100 ] )); 
ob->start_shadow(at,props["duration"], "%^CYAN%^An ultimate plasma blade spell wears off.");

remove();
return;
}


