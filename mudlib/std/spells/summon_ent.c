// Used for spell name, mob name, and messages
#define NAME "ent"
// The type of creature (sky, water, earth, fire, magic)
#define TYPE "earth"
// The base MP cost
#define MPCOST 140
// The normal train dev cost
#define NORMALDEVCOST 160
// The fast train dev cost
#define FASTDEVCOST 390
// The spell's casting level
#define LEVEL 35
// The IDs of the creature
#define ID ({"ent", "tree", "tree-man"})
// The creature's short desc
#define SHORT "sturdy ent"
// The creature's long desc
#define LONG "Ents are big and old trees that can move and are sentient. They've got sharp looking branches."
// The creature's race
#define RACE "plant"
// The creature's body type
#define BODYTYPE "ent"
// The type of crit damage the creature does in battle
#define MELEEDAMAGE "crushing"
// The creature's level. Multiplies melee damage power (hence the name).
#define POWERMULTIPLIER 35
// The charge multiplier. SPELLPOWER*CHARGEMULTI=how many points of charge the animal gives to a jewel
#define CHARGEMULTIPLIER 35

inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","summon "+NAME);
    set_property("skill","environmental control");
    set_property("duration", "permanent");
    set_property("casting time",1);
    set_property("base mp cost", MPCOST);
    set_property("dev cost", NORMALDEVCOST);
    set_property("fast dev cost", FASTDEVCOST);
    set_property("spell level", LEVEL);
    set_property("moon","luna");
    set_property("caster message","You begin to chant and dance wildly.");
    set_property("target message","");
    set_property("observer message","$C begins to chant and dance wildly.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell summons a "+NAME+" to serve the caster.  "
"It will serve you by fighting beside you in combat.  "
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  The spell must be cast on a elemental symbol of "+TYPE+", which must "
"be acquired somehow.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int
flag) {
  int time;
  if(!(at->is_elemental_symbol())) {
    message("info", "You must cast this spell at an environmental symbol.",
            caster);

    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(!((string)at->query_property("type")==TYPE)) {
    message("info", "You must cast this spell on a symbol of "+TYPE+".", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "You trip and accidentally destroy "+
            "the symbol!", caster);
    message("info", (string)caster->query_cap_name() +
            " falls on his face like a moron.",
            environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  set_work_message("You dance around in a circle, shouting natural things.");
  time = 120*(LEVEL*power/6);
  if(wizardp(caster)) time = 1;
  start_work(at, caster, time, power);
  return;
}

void finish_work(object caster, object at, int power) {
  object ob;

  if(power <= 0) {
    message("info", "BUG in Shaman spell....unable to complete.", environment(caster));
    remove();
    return;
  }
  message("info", "You finish dancing, and a "+NAME+" appears.", caster);
  message("info", (string)caster->query_cap_name() + " stops dancing like a fool, and a "+NAME+" appears.",
          environment(caster), ({ caster }) );
  seteuid(getuid());
  ob = new("/std/tailwind/pets/shaman_pet");
  ob->set_name(NAME);
  ob->set_id(ID);
  ob->set_short(SHORT);
  ob->set_long(LONG);
  ob->set_body_type(BODYTYPE);
  ob->set("race", RACE);
  ob->set_up((power*POWERMULTIPLIER)/6);
  ob->set_property("melee damage", ([ MELEEDAMAGE : 40 + 5*((power*POWERMULTIPLIER)/6), "impact" : 40 + 5*((power*POWERMULTIPLIER)/6) ]));
  ob->set_owner((string)caster->query_name());
  ob->add_charge(power*CHARGEMULTIPLIER);
  ob->set_type(TYPE);
  ob->move(environment(caster));
  remove();
  return;
}
