// Glen

inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","invulnerable shell");
    set_property("skill","illusionism");
    set_property("casting time",21);
    set_property("base mp cost",91);
    set_property("dev cost", 141);
    set_property("fast dev cost", 225);
    set_property("spell level", 30);
    set_property("moon","ankh");
    set_property("caster message",
      "An invulnerable shell surrounds you.");
    set_property("target message", "");
    set_property("observer message",
      "$C becomes surrounded by an invulnerable shell.");
    set_property("spell type",({  }));
    set_property("duration", 120);
    set_property("no target", 1);
    return;
}

void info() {
    message("help",
      "This spell creates a bubble of complete invulnerability around you."
      "Nothing may hurt you while this bubble is around you.  "
      "With each attempt at damaging you, the bubble looses energy.  "
      "When the energy is depleted you may be harmed.  "
      "You may not recast this spell until the duration has expired.  "
      "\n\n"
      "  'A bold archer or wizard often feels the need to try assassinating\n"
      "   those of importance.  I shall not perish without a worthy fight.'\n"
      "                                 -Lord Renard\n",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;
    int skill;

    skill = caster->query_skill(query_property("skill"));
    if(skill < 100)skill = 100;

    if(caster->query_invulnerable()) {
	message("info", "You may not stack this spell.", caster);
	caster->add_mp(props["mp cost"]);
	return;
    }


    seteuid(getuid());
    ob = new("/std/spells/shadows/invuln_shadow");
    if(flag)
	ob->set_damage_allowed(1);
    else
	ob->set_damage_allowed(skill*power);
	ob->set_shadow_name("invulnerable shell");
    ob->start_shadow(caster, props["duration"],
      "%^BOLD%^" + "%^GREEN%^" +
      "Invulnerability wears off");
    ::spell_func(caster, at, power, args, flag);
    remove();
    return;
}

