#include <std.h>

inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","true armour");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",110);
    set_property("dev cost", 135);
    set_property("fast dev cost", 405);
    set_property("spell level", 26);
    set_property("moon","luna");
    set_property("caster message","You begin to imbue the armour with magical power.");
    set_property("target message","");
    set_property("observer message","$C begins to enchant a piece of armour.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("prereq", "major fortification");
    return;
}

void info() {
message("help",
"This is a truly powerful armour enchantment and any armour may only receive one of these.  "
"It decreases the intensity of any critical hit done to the armour.  Due to the extreme power of this "
"spell, it is effective only up to power level 4, not 6.  Casting the spell at power levels 5 or 6 will "
"have the same effect as 3 and 4, respectively, but will take half the time to cast.  "
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int mult, time, mod;
  int ctime;
  mixed val;
  
  if(!at->is_armour()) {
    message("info", "You must cast this spell at a piece of armour.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
//TLNY2025 removed shatter add lose HP and MP
  if(flag) {
message("info", "A surge of energy crackles around you... but suddenly, something goes horribly wrong! You feel a wave of weakness wash over you as you lose half your HP and MP and fill the item with useless energy!", caster);
    caster->add_mp(-1*(int)caster->query_mp() / 2);
    caster->add_hp(-1*(int)caster->query_hp() / 2);

  val = (mixed)at->query_property("extra long");
  if(!val) val = ({});
  else if(stringp(val)) val = ({ val });
  val += ({ ({ "This armour has %^ORANGE%^Fumbled! %^BLUE%^%^BOLD%^True Armour%^RESET%^." ,
      "detect magic" }) });
    at->set_property("extra long", val);
    at->set_property("true armour", 1);
    remove();
    return;
  }
  if((int)at->query_property("true armour") ||
    (intp(at->query_enh_critical()) &&
    (int)at->query_enh_critical() < -2))  {
    message("info", "This armour already has true armour or a similar spell cast on it.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(power > 4) mult = 2;
  else mult = 1;
  set_work_message("%^CYAN%^You enchant the armour.");
  time = 3600 + 800*((power>4)?(power-2):power)/mult;
  //if (wizardp(caster)) time=0;
  mod = 40+2*props["spell level"];
ctime = (time*mod)/caster->query_skill("enchantment");
if(archp(caster)) {
ctime = 1;
}
start_work(at, caster, ctime, power);
return;
}

void finish_work(object caster, object at, int power) {
  mixed ench;
  string *types;
  int i;
//  mapping tmp;
  mixed val;

  if(power <= 0) {
    message("info", "BUG in Enchanter spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  caster->add_exp2(10000*power);
  message("info", "You are finished enchanting True Armour!", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "magical incantations.",
	  environment(caster), ({ caster }) );
	ench = (mixed)at->query_enh_critical();
	if(power > 4) power -= 2;
	if(!ench) ench = 0;
	if(mapp(ench)) {
          types = DAMAGE_TYPES;
	  i = sizeof(types);
	  while(i--) {
	    if(ench[types[i]])
	      ench[types[i]] -= power;
	    else ench[types[i]] = -1 * power;
	  }
	  at->set_enh_critical(ench);
	}
	else
	  at->set_enh_critical(ench-power);
	val = (mixed)at->query_property("extra long");
  if(!val) val = ({});
  else if(stringp(val)) val = ({ val });
  val += ({ ({ "This armour has %^BLUE%^%^BOLD%^True Armour%^RESET%^." ,
      "detect magic" }) });
  at->set_property("extra long", val);
	at->set_property("true armour", 1);
  remove();
  return;
}

