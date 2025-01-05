inherit "/std/spells/spell";

object stuff;

void create() {
    ::create();
    set_property("name","aura flare");
    set_property("skill","alchemy");
    set_property("casting time",37);
    set_property("base mp cost",22);
    set_property("dev cost", 41);
    set_property("fast dev cost", 98);
    set_property("spell level", 13);
    set_property("moon","ankh");
    set_property("caster message",
      "You finish your alchemistic ritual on $T. $T is now active and can be drank.");
    set_property("target message",
      "$C grabs a potion and gives it to you. You drink it, and suddenly, a powerful aura flare surrounds you.");
    set_property("observer message",
      "$C finishes an alchemistic spell on $T. $T seems to glow with radiant energy.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("duration", 120);
    return;
}

void info() {
    message("help",
      "This spell activates an aura flare potion.  "
      "Aura flare potions can be drank, and are quite usefull.  "
      "Besides protecting the target from plasma, radiation, and fire damage, "
      "it may also do one of those crits to an attacker who hits the target of "
      "this spell. You must cast this spell at an aura flare potion.",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    object ob;
    int roll, i;

    if(!at || !at->is_aura_flare_potion()) {
	message("info", "This must be cast at an aura flare potion.",
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
	//    message("info", (string)caster->query_cap_name()
	//        +" accidentally flares "+
	//          "you!", at);
	//    do_critical(caster, at, ({ "fire D", "radiation D", "plasma D" }) );
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

