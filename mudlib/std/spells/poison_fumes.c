inherit "/std/spells/spell";

int sp_pow;
object cas, stuff;

void create() {
    ::create();
    set_property("name","poison fumes");
    set_property("skill","alchemy");
    set_property("casting time",12);
    set_property("base mp cost",64);
    set_property("dev cost", 75);
    set_property("fast dev cost", 223);
    set_property("spell level", 14);
    set_property("moon","luna");
    set_property("caster message","You mix the $T up, activating it.");
    set_property("target message","");
    set_property("observer message","$C does some alchemistic things on $T and coughs a bit.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("duration", 30);
    return;
}

void info() {
    message("help",
      "This spell allows you activate a poison perfume potion.  "
      "The perfume may be smashed in a room.  "
      "Poison clouds will form, choking and poisoning everyone "
      "in the room for a period of time.  "
      "You will be unaffected by the poison.  ",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{

    object ob;


    if(!at || !at->is_poison_fumes_potion()) {
	message("info", "This must be cast at a poison fumes potion.",
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

