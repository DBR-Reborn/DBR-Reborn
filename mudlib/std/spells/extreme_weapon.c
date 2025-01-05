#include "/adm/include/clock.h"

inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","extreme weapon");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time", 10);
    set_property("base mp cost", 200);
    set_property("dev cost", 245);
    set_property("fast dev cost", 735);
    set_property("spell level", 48);
    set_property("moon","luna");
    set_property("caster message","You begin to make the weapon extreme.");
    set_property("target message","");
    set_property("observer message","$C begins to enchant a weapon.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("prereq", "mastered weapon");
    return;
}

void info() {
message("help",
"This an extremely powerful spell and the stronger version of mastered weapon. When cast on a weapon, the weapon is bound to the caster.  "
"If anyone besides the caster attempts to use the weapon, it will hit as if "
"the wielder had NO SKILL with the weapon at all.  If the enchanter who cast the spell "
"wields the weapon, however, he/she will have extreme skill with the weapon "
"REGARDLESS of what weapon skills the enchanter has!  In a nutshell, this spell "
"gives a single dedicated enchanter FREE skill with that weapon.  However, this effect is not "
"always on.  You must activate it like a locked enchantment ('help spell lock enchantment').  "
"\nThe syntax for the activation is:\n"
"'activate extreme on <weapon>'\n"
"Where <weapon> is the target weapon.  If you wish to see how often this "
"enchantment may be activated, type 'help <weapon>'.  The power of the spell "
"affects how often you can invoke the enchantment and how much "
"free skill with the weapon you receive.\n"
"***This is a very powerful spell and only the most dedicated enchanters may use it. A skill of 215% is needed to cast this spell. And a base skill of 190% to train it.***\n"
"==>This spell can only be used by members of the ENCHANTER guild<==",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int time, mod;
  int ctime;
  if(!at->is_weapon()) {
    message("info", "You must cast this spell on a weapon.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if((int)caster->query_skill("enchantment") < 215 ) {
    message("info", "You need more enchantment to imbue a spell.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(caster->query_class() != "enchanter" && !archp(caster)) {
    message("info", "%^BOLD%^Only %^CYAN%^Enchanters%^RESET%^ %^BOLD%^may use this spell.", caster);
    message("info", "Your spell fails.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(!mapp(at->query_enchantments())) {
    message("info", "That item may not receive locked enchantments.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(at->query_property("claimed by")) {
    message("info", "That weapon is already claimed.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(at->query_property("mastered by")) {
    message("info", "That weapon is already mastered.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(at->query_property("extreme by")) {
    message("info", "That weapon is already extreme.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the energies of the spell and shatter "+
	    "the item!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently shatters the item.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  set_work_message("%^CYAN%^You enchant the weapon.");
  time = 1200+80*power;
  mod = 40+2*props["spell level"];
ctime = (time*mod)/caster->query_skill("enchantment");
if(archp(caster)) {
ctime = 1;
}
start_work(at, caster, ctime, power);
return;
}

void finish_work(object caster, object at, int power) {
//  int ench;
  mixed extra;

  if(power <= 0) {
    message("info", "BUG in Enchanter spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "You are finished enchanting.  Type 'help <item>' to list the enchantments.", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "magical incantations.",
	  environment(caster), ({ caster }) );
	at->add_enchantment("extreme", "extreme activate", power,
	  3600 / (power/2+1), 0);
	if(strsrch((string)at->query_type(), "two handed") > -1)
	  at->set_type("two handed "+(string)caster->query_name()+" extreme");
	else
	  at->set_type((string)caster->query_name()+" extreme");
	message("info", "See the help on this spell to see how to "
	  "activate the extreme weapon.", caster);
	at->set_property("extreme by", (string)caster->query_name());
	extra = at->query_property("extra long");
	if(!extra) extra = ({});
	else if(stringp(extra)) extra = ({ extra });
	else if(!pointerp(extra)) extra = ({});
	extra += ({ "%^CYAN%^This weapon is made extreme by %^RESET%^%^BOLD%^"+
	  (string)caster->query_name() });
  remove();
  return;
}

