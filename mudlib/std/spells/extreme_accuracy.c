inherit "/std/spells/long_term_spell";
inherit "/std/check_brittle";

void create() {
    ::create();
    set_property("name","extreme accuracy");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",160);
    set_property("dev cost", 220);
    set_property("fast dev cost", 660);
    set_property("spell level", 43);
    set_property("moon","luna");
    set_property("caster message","You begin to imbue the weapon with magical power.");
    set_property("target message","");
    set_property("observer message","$C begins to enchant a weapon.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("prereq", "master accuracy");
    return;
}

void info() {
message("help",
"This spell makes it extremely easy to hit with a weapon.  The enchantment "
"limit for this spell is higher than that of master accuracy.  "
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  If you are interrupted while casting, "
"you may pick up again at a later time.\n"
"***This is a very powerful spell and only the most dedicated enchanters may use it. A skill of 190% is needed to cast this spell.\n"
"==>This spell can only be used by members of the ENCHANTER guild<==",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int time, mod;
  int ctime;
  if(!at->is_weapon()) {
    message("info", "You must cast this spell at a weapon.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if((int)caster->query_skill("enchantment") < 190 ) {
    message("info", "You need more enchantment to imbue extreme accuracy.", caster);
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
  if(flag) {
    message("info", "You misdirect the summoning energies and shatter "+
	    "the weapon!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently shatters the weapon.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  if((int)at->prop("hit bonus") >= 100) {
    message("info", "This weapon may receive no further extreme "+
      " accuracy enchantments.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  set_work_message("%^CYAN%^You enchant the weapon.");
  time = 3200 + 500*power;
  mod = 40+2*props["spell level"];
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
//ADD
if(power >= 6) {
    at->set_property("hit bonus", 100);
	}  
//END
  message("info", "You are finished enchanting!", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "magical incantations.",
	  environment(caster), ({ caster }) );
  if(!check_brittle(at, caster, power)) {
    remove();
    return;
  }
  ench = (int)at->prop("hit bonus");
  if(!ench) ench = 0;
  if(ench + power*4 >= 100) {
    message("info", "This weapon is now enchanted as much as is possible with "+
	    "this spell.", caster);
    at->set_property("hit bonus", 100);
    ench = 100-(power*4);
  } 
  else
    {
      at->set_property("hit bonus", ench + power*4);
    }
  caster->add_exp2(8000*power);
  tmp = (mixed)at->query_property("extra long");
  if(!tmp) tmp = ({});
  else if(stringp(tmp)) tmp = ({ tmp });
  idx = -1;
  i = sizeof(tmp);
  while(i--) {
    if(pointerp(tmp[i]) && sizeof(tmp[i]) == 2 &&
       arrange_string(tmp[i][0], 9) == "Accuracy:") idx = i;
  }
  if(idx >= 0) tmp = exclude_array(tmp, idx);
  tmp += ({ ({ sprintf("Accuracy: %%^CYAN%%^%+d%%", power*4+ench),
		 "detect magic" }) });
  at->set_property("extra long", tmp);
  remove();
  return;
}

