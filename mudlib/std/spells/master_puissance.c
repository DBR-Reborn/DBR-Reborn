inherit "/std/spells/long_term_spell";
inherit "/std/check_brittle";

void create() {
    ::create();
    set_property("name","master puissance");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost", 97);
    set_property("dev cost", 140);
    set_property("fast dev cost", 420);
    set_property("spell level", 27);
    set_property("moon","luna");
    set_property("caster message","You begin to imbue the weapon with magical power.");
    set_property("target message","");
    set_property("observer message","$C begins to enchant a weapon.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("prereq", "major puissance");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell adds a great deal of extra damage to a weapon.  The enchantment "
"limit for this spell is higher than that of major puissance.  "
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  If you are interrupted while casting, "
"you may pick up again at a later time.",
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
  if((int)at->query_property("enchantment") >= 70) {
    message("info", "This weapon may receive no further master "+
      "enchantments.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  set_work_message("%^CYAN%^You enchant the weapon.");
  time = 2200 + 500*power;
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
    at->set_property("enchantment", 70);
	}  
//END
  message("info", "You are finished enchanting!", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "magical incantations.",
	  environment(caster), ({ caster }) );
  if(!check_brittle(at, caster, power*2)) {
    remove();
    return;
  }
  ench = (int)at->query_property("enchantment");
  if(!ench) ench = 0;
  if(ench + power*2 >= 70) {
    message("info", "This weapon is now enchanted as much as is possible with "+
	    "this spell.", caster);
    at->set_property("enchantment", 70);
    ench = 70-(power*2);
  } 
  else
    {
      at->set_property("enchantment", ench + power*2);
    }
  caster->add_exp2(3500*power);
  tmp = (mixed)at->query_property("extra long");
  if(!tmp) tmp = ({});
  else if(stringp(tmp)) tmp = ({ tmp });
  idx = -1;
  i = sizeof(tmp);
  while(i--) {
    if(pointerp(tmp[i]) && sizeof(tmp[i]) == 2 &&
       arrange_string(tmp[i][0], 10) == "Puissance:") idx = i;
  }
  if(idx >= 0) tmp = exclude_array(tmp, idx);
  tmp += ({ ({ sprintf("Puissance: %%^CYAN%%^+%+d%%", power*2+ench),
		 "detect magic" }) });
  at->set_property("extra long", tmp);
  remove();
  return;
}

