inherit "/std/spells/long_term_spell";
inherit "/std/check_brittle";

void create() {
    ::create();
    set_property("name","electric blade");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",50);
    set_property("dev cost", 40);
    set_property("fast dev cost", 120);
    set_property("spell level", 7);
    set_property("moon","luna");
    set_property("caster message","You begin to imbue the weapon with electricity damage.");
    set_property("target message","");
    set_property("observer message","$C begins to enchant a weapon.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell adds electricity damage to ANY weapon (not just blades).  "
"Only 4 of these spells may be stacked on any weapon.  "
"Different blade spells with the same element are not allowed on a weapon. "
"This is a long-term spell (see help long-term), and may take much real "
"time to cast.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int time,mod;
  int ctime;
  if(!at->is_weapon()) {
    message("info", "You must cast this spell at a weapon.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the enchanting energies and shatter "+
	    "the weapon!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently shatters the weapon.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  if((int)at->query_property("lightning blade") >= 1 ) {
    message("info", "Different blade spells with the same element are not allowed on a weapon.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if((int)at->query_property("electric blade") >= 4 ) {
    message("info", "This weapon can receive no more electric blade spells.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  set_work_message("%^CYAN%^You enchant the weapon.");
  time = 480 + 90*power;
  mod = 30+2*props["spell level"];
ctime = (time*mod)/caster->query_skill("enchantment");
if(archp(caster)) {
ctime = 1;
}
start_work(at, caster, ctime, power);
return;
}

void finish_work(object caster, object at, int power) {
  int ench, i, idx;
  mixed tmp;

  if(power <= 0) {
    message("info", "BUG in Enchanter spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "You are finished enchanting!", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "magical incantations.",
	  environment(caster), ({ caster }) );
  ench = (int)at->query_property("electric blade");
  
  /*
   * Brittle code follows...
   */
  if(!check_brittle(at, caster, power)) {
    remove();
    return;
  }
  /*
   * End of brittle code
   */

  if(!ench) ench = 0;
  if(ench + 1 >= 4) {
    message("info", "This weapon is now enchanted as much as is possible with "+
	    "this spell.", caster);
    at->set_property("electric blade", 4);
    ench = 4;
  } else {
    at->set_property("electric blade", ench +1);
    ench = (int)at->query_wc("electricity");
    if(!ench) ench = power;
    else ench += power;
    at->set_wc(((7*power)+ench)+(caster->query_level()/2), "electricity");
    caster->add_exp2(700*power);
/*
    at->set_property("electric blade", ench + 1);
    ench = (int)at->query_wc("electricity");
    if(!ench) ench = power+2;
    else ench += power+2;
    at->set_wc(ench, "electricity");
    caster->add_exp2(350*power);
*/
  }
  tmp = (mixed)at->query_property("extra long");
  if(!tmp) tmp = ({});
  else if(stringp(tmp)) tmp = ({ tmp });
  idx = -1;
  i = sizeof(tmp);
  while(i--) {
    if(pointerp(tmp[i]) && sizeof(tmp[i]) == 2 &&
       eliminate_colour(tmp[i][0]) == "This weapon has Electric Blade.") idx = 1;
  }
  if(idx < 0)
    tmp += ({ ({ "This weapon has %^YELLOW%^Electric%^RESET%^ Blade." ,
		   "detect magic" }) });
  at->set_property("extra long", tmp);
  remove();
  return;
}










