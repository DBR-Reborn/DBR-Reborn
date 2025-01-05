//  edited by stoNey: 240701
#include <std.h>
//#include <colors.h>

inherit "/std/spells/long_term_spell";
inherit "/std/check_brittle";

void create() {
    ::create();
    set_property("name","condition weapon");
    set_property("skill","alchemy");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",74);
    set_property("dev cost", 97);
    set_property("fast dev cost", 278);
    set_property("spell level", 26);
    set_property("moon","luna");
    set_property("caster message",
      "You begin to condition the weapon.");
    set_property("target message","");
    set_property("observer message",
      "$C begins to condition a weapon.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help",
      "This spell is very powerfull.  It conditions a weapon to last longer "+
      "and degrade less slowly.  This means the weapon may go longer between "+
      "repairs.  This spell requires an ingot or piece of material the weapon "+
      "is made out of.  Such as a mithril sword would require a mithril ingot "+
      "or a pine staff would require some pine wood.\n\n"+
      "Ex: cast *4 condition weapon at sword with mithril ingot\n"+
      "The higher the power level, the more effective the conditioning.\n",
      this_player());
}

object with;

void spell_func(object caster, object at, int power, string args, int flag)
{
    int mult, time, mod;

    if(!at->is_weapon()) {
	message("info", "You must cast this spell at a weapon.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(args)
	with = present(args, caster);
    if(!with || (!with->id("ingot") && !with->id("wood"))
      || with->query_material() != 
      at->query_material() ) {

	message("info", "You must cast this spell with a material "+
	  "to augment the weapon.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }

    if(flag) {
      message("info","You misdirect the summoning energies and shatter "+
        "the weapon!", caster);
      message("info", (string)caster->query_cap_name() +
        " inadvertently shatters the weapon.",
        environment(caster), ({ caster }) );
      at->remove();
      remove();
      return;
    }
    set_work_message("You condition the weapon.");
    time = 3600 + 480*power;
    if(wizardp(caster))
	time = 1;
    start_work(at, caster, time, power);
    return;
}

void finish_work(object caster, object at, int power) {
    mixed ench;
    string *types;
    int i;
    mapping tmp;
    mixed val;

    if(power <= 0) {
	message("info", "BUG in spell....unable to complete.",
	  environment(caster));
	remove();
	return;
    }
    if(!objectp(with)) {
	message("info", "Where did the component go?",
	  environment(caster));
	remove();
	return;
    }
    caster->add_exp2(35000*power);

    message("info", "You are finished conditioning.", caster);
    message("info", (string)caster->query_cap_name() + 
      " completes conditioning a weapon.",
      environment(caster), ({ caster }) );
    if(!check_brittle(at, caster, power*2)) {
	remove();
	return;
    }
    i = at->query_property("decay conditioning");
    i++;
    at->set_property("decay conditioning", i);
    with->remove();

    i = at->query_decay_rate();
    i += i*power;
    at->set_decay_rate(i);
    val = (mixed)at->query_property("extra long");
    if(!val) val = ({});
    else if(stringp(val)) val = ({ val });
    val += ({ ({ CCYAN + "This weapon has been conditioned." +CRESET ,
	"detect magic" }) });
    at->set_property("extra long", val);
    remove();
    return;
}

