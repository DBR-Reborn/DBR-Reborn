inherit "/std/spells/spell";

object stuff;

void create() {
    ::create();
    set_property("name","speed");
    set_property("skill","alchemy");
    set_property("casting time",31);
    set_property("base mp cost",41);
    set_property("dev cost", 57);
    set_property("fast dev cost", 150);
    set_property("spell level", 11);
    set_property("moon","luna");
    set_property("caster message",
      "You activate $T with speed.");
    set_property("target message",
      "$C hands you a flask. You quaff it, and begin to move faster.");
    set_property("observer message",
      "$C finishes an alchemistic spell at $T, it seems to churn and boil.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("duration", 40);
    return;

}

void info() {
    message("help",
      "This spell activates a speed potion for use.  "
      "Speed potions give the target an extra round in combat.  Power affects "
      "only the duration.  Only one speed potion may affect you at a time.",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    object ob;

    seteuid(getuid());
    if(!at || !at->is_speed_potion()) {
	message("info", "This must be cast at a speed potion.",
	  caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }

    if(at->query_potion_power() >= power) {
	message("info", "That potion is already active.",
	  caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }


    message("info", "You cast your spell at the potion.",
      caster);

    seteuid(getuid());
    if(flag) {
	message("info", "OOPS!  You misdirect the energies of your spell, "
	  "accidently destroying the target!", caster);
	message("info", (string)caster->query_cap_name()+
	  " accidentally destroys a potion!", environment(caster), 
	  ({ caster, at }));
	at->remove();
	remove();
	return;
    }

    at->set_potion_power(power);
    at->set_potion_duration((int)props["duration"]);
    caster->add_mp(props["mp cost"]);
    remove();
    return; 
}

