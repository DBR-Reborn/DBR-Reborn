inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","plasma shield");
    set_property("skill","illusionism");
    set_property("casting time",11);
    set_property("base mp cost",22);
    set_property("dev cost", 41);
    set_property("fast dev cost", 98);
    set_property("spell level", 14);
    set_property("moon","ankh");
    set_property("caster message","You cast plasma shield at $T.");
    set_property("target message","$C casts plasma shield at you.");
    set_property("observer message","$C casts plasma shield at $T.");
    set_property("spell type",({ "protection" }));
    set_property("protection types", ([ "plasma" : 15 ]));
    set_property("duration", 420);
    set_property("target type", "living");
    set_property("stack key", "plasma shield");
    set_property("stack num", 3);
    set_property("target type", "living");
    return;
}

void info() {
    message("help",
      "This spell summons a plasma shield about the target.  "
      "This provides excellent protection from plasma.  "
      "In addition to "
      "protecting the target from plasma damage, it has a chance of doing a "
      "plasma critical to the attacker each time he/she is hit.  "
      "But the chance is relatively low.  "
      "\n\n"
      "  'There is an old saying.  When playing with fire, wear gloves.\n"
      "                                 -Lord Renard\n",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

    seteuid(getuid());
    if(flag) {
	message("info", "%^RED%^%^BOLD%^OOPS!  You misdirect the energies of your spell, "
	  "shooting flames at the target!", caster);
	message("info", (string)caster->query_cap_name()+" accidentally shoots plasma at "+
	  (string)at->query_cap_name()+"!", environment(caster),
	  ({ caster, at }));
	message("info", (string)caster->query_cap_name()+" accidentally shoots plasma at "+
	  "you!", at);
	do_critical(caster, at, ({ "plasma D" }) );
	remove();
	return;
    }
    /*  if(at->query_plasma_shield()) {
	message("info", "There may only be one plasma shield on a target.",
	      caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
      }
    */
    ob = new("/std/spells/shadows/plasma_shadow");
    ob->set_power(power);
	ob->set_shadow_name("plasma shield");
    ob->start_shadow(at, props["duration"], 0);
    ::spell_func(caster, at, power, args, flag);
    remove();
    return;
}

