inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name","greater seeking blade");
    set_property("skill","magery");
    set_property("casting time",13);
    set_property("base mp cost",65);
    set_property("dev cost",73);
    set_property("fast dev cost",155);
    set_property("spell level", 26);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message",
      "You cast greater seeking blade at $T.");
    set_property("target message","");
    set_property("observer message",
      "$C casts greater seeking blade at $T.");
    set_property("spell type",({}));
    set_property("duration", 420);
    set_property("must be present", 1);
    set_property("stack key", "seeking blade");
    set_property("stack num", 4);
    set_property("target type", "any");
    return;
}

void info() {
    message("help",
      "This spell imbues your weapon with the ability to better seek your "
      "opponent.  It will hit your oponent more often and will be deflected less."
      "\n\n"
      "This spell may only be cast on an arcane blade."
      "\n\n"
      "  'It becomes too easy.  I often believe I could just close my eyes and \n"    
      "   swing, and my sword would still find its mark.'\n"
      "                                 -Lord Renard\n"
      "\n",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob, weap;
    if(!at->is_weapon()) {
	message("info", "You must cast this spell at a weapon.", caster);
	caster->add_mp(props["mp cost"]);
	return;
    }
    if(!(at->is_arcane_blade())) {
	message("info", 
	  "This spell must be cast on an arcane blade only", 
	  caster);
	caster->add_mp(props["mp cost"]);
	return;
    }

    seteuid(getuid());

    ob = new("/std/spells/shadows/weapon_shadow");
    if(!check_stack(at, ob)) {
	message("info", 
	  "You may not cast another seeking spell on that weapon.",
	  caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }

    message("info", "Your weapon seems lighter and easier to wield.",
      caster);

    ob->set_hit_bonus(power*4);
	ob->set_shadow_name("greater seeking blade");
    ob->start_shadow(at,props["duration"], "%^CYAN%^Seeking blade wears off.");

    remove();
    return;
}


