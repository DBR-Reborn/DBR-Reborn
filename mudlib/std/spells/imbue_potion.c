inherit "/std/spells/long_term_spell";

string spell_name;
int spell_pow;
int spell_lev;
string element;

void create() {
    ::create();
    set_property("name","imbue potion");
    set_property("skill","alchemy");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",36);
    set_property("dev cost", 61);
    set_property("fast dev cost", 188);
    set_property("spell level", 12);
    set_property("moon","luna");
    set_property("caster message",
      "You begin to endow the potion.");
    set_property("target message","");
    set_property("observer message","$C begins endowing a potion.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help",
      "This spell allows you to imbue an ensnared spell "
      "into a prismatic potion.  "
      "The spell may be unleashed from the potion at a later time.  "
      "The ensnared spell will cost full mp but will only take 2 rounds to cast, "
      "and may be cast while casting other spells.  "
      "This is a long-term spell (see help long-term), and it takes very much "
      "real time to cast.  If you are interrupted while casting, "
      "you may pick up again at a later time.  If you are continuing the spell, "
      "no arguements need to "
      "be supplied.  If the potion has that spell ensnared in it, it will "
      "be replaced by the new "
      "casting, even if it is lower.\n\n"
      "Imbued potions will ALWAYS target the drinker.  "
      "Weapon spells and things of this nature will not be able to be "
      "imbued into a potion and used.  Attack spells will target "
      "the drinker of the potion if imbued in a potion.\n\n"
      "Syntax: cast *3 imbue potion at <item> with <spell>\n"
      "Ex: cast *3 imbue potion at potion 1 with fireball\n"
"NOTE: The spell will be imbued at a power equal to either the power of
the potion or the power of the "
"spell itself, whichever is lower.\n",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
  int idx, time, mod;
  string file;
  
  if(!at->id("prismatic potion")) {
    message("info", "You must cast this spell on a prismatic potion.",
            caster);
          caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", 
        "You misdirect the summoning energies and disintegrate "+
            "the potion!", caster);
    message("info", (string)caster->query_cap_name() +
            " inadvertently disintigrates the potion.",
            environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  if(query_in_progress(at, caster)) {
    spell_name = (string)at->query_property("scribe spell:"+
          (string)caster->query_name());
    spell_pow = (int)at->query_property("scribe pow:"+
          (string)caster->query_name());
    element = (string)at->query_property("scribe ele:"+
          (string)caster->query_name());
    message("info", "Using the spell: "+spell_name+".", caster);
  } else {
    if(!args) {
      message("info", "See 'help spell imbue potion' for syntax.",
         caster);
      caster->add_mp(props["mp cost"]);
      remove();
      return;
    }
    while(strlen(args) > 1 && args[0] == ' ')
      args = replace_string(args, " ", "", 1);
    while((idx=strlen(args)-1) > 1 && args[idx] == ' ')
      args = args[0..idx-1];
    spell_pow = 0;
    spell_name = lower_case(args);
    spell_pow = (int)caster->query_spell_level(spell_name);
    if((string)caster->query("borrowed spell") == spell_name &&
      (int)caster->query("b spell lev") > spell_pow) {
      spell_pow = (int)caster->query("b spell lev");
      element = (string)caster->query("b spell element");
      caster->set("borrowed spell", 0);
      caster->set("b spell lev", 0);
      caster->set("b spell element", 0);
      message("info", "You use your prepared spell.",
        caster);
    }
    if(!spell_pow) {
      message("info", "You must have the spell: "+spell_name+" or "+
          "borrow it using 'prepare spell'.", caster);
      caster->add_mp(props["mp cost"]);
      remove();
      return;
    }
    at->set_property("scribe spell:"+
          (string)caster->query_name(), spell_name);
    at->set_property("scribe pow:"+
          (string)caster->query_name(), spell_pow);
  }
  seteuid(getuid());
  file = "/std/spells/"+replace_string(spell_name, " ", "_");
  if(!file_exists(file+".c")) {
    message("info", "Cannot find the spell file...this is a BUG.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  idx = (int)file->query_property("spell level");
  if(!element && file->query_property("elemental spell")) {
    element = caster->query_element();
    if(!element) {
      message("info", "This is an elemental spell, and you must use "+
        "an elemental lore skill to scribe it.", caster);
      caster->add_mp(props["mp cost"]);
      remove();
      return;
    }
  }
  if(function_exists("query_in_progress", find_object_or_load(file))) {
    message("info", "You may not scribe a long-term spell.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  at->set_property("scribe ele:"+
          (string)caster->query_name(), element);
  set_work_message("You scribe the scroll.");
  spell_lev = idx;

  time = (120+power*200) - caster->query_skill("alchemy")*2;
  if(wizardp(caster))
      time = 1;
  start_work(at, caster, time, power);
  return;
}

void finish_work(object caster, object at, int power) {
  int ench;

  if(power <= 0) {
    message("info", "BUG in Alchemist spell....unable to complete.",
            environment(caster));
    remove();
    return;
  }
  message("info", "You are finished imbuing.", caster);
  message("info", (string)caster->query_cap_name() + " concludes scribing
the scroll.",
          environment(caster), ({ caster }) );
        if(power < spell_pow) spell_pow = power;
        at->set_spell(spell_name, spell_pow);
        if(element) at->set_property("element", element);
  remove();
  return;
}


