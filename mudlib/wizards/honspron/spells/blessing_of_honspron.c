#define SKILLS_AFFECTED ([ "attack" : 15, "blade" : 15, "two handed blade" : 15, \
    "blunt" : 15, "two handed blunt" : 15, "axe" : 15, "two handed polearm" : 15, \
    "flail" : 15, "two handed flail" : 15, "body block" : 15, "parry" : 15, \
    "block" : 15, "dodge" : 15, "whirlwind attack" : 15, "dual attack" : 15, \
    "offhand training" : 15, "dance of daggers" : 15, "knife" : 15, \
    "thrown" : 15, "repair weapon" : 15, "resist stun" : 15, "perception" : 15, "conjuration" : 15, "elementalism" : 15, \
    "illusionism" : 15, "body alteration" : 15, "prayer" : 15, "magery" : 15, \
    "spell sense" : 15, "fast casting" : 15, "focus casting" : 15, "concentrate" : 15, \
    "consider" : 15, "animal empathy" : 15, "sorcery" : 15, "focus of elements" : 15, \
    "trade lore" : 15 ])
    
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","blessing of Honspron");
    set_property("skill","prayer");
    set_property("casting time",7);
    set_property("base mp cost",30);
    set_property("dev cost", 25);
    set_property("fast dev cost", 95);
    set_property("spell level", 15);
    set_property("moon","ankh");
    set_property("caster message","You pray for a blessing for $T.");
    set_property("target message","$C prays for a blessing for you.");
    set_property("observer message","$C appears to pray for $T.");
    set_property("spell type",({ "stat mod" }));
    set_property("stat dice", "1D20");
    set_property("stats", ({ "dexterity","intelligence", "wisdom", "charisma", "strength" }) );
    set_property("target type", "living");
    set_property("must be present",1);
    set_property("duration", 600);
    return;
}

int res_spell() { return 1; }

void info() {
message("help",@TEXT
This spell gives a general short-term bonus in skills and stats which
may be useful in a variety of situations.  Each blessing is stackable 2 times.
Most general physical skills will receive bonuses from this spell.
Skills used to accomplish unholy pursuits (back stab, steal, etc.) will
not be affected.
TEXT
,this_player());
}

void spell_func(object caster, object at, int power, string args,int flag) {
//  object ob;
  mapping sk_aff = SKILLS_AFFECTED;
seteuid(getuid());
  if ((int)at->query("a bless num") + (int)at->query("f bless num") + (int)at->query("c bless num") >= 10 ) {
    message("info", (string)at->query_cap_name() +
	    " can receive no additional blessings.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) message("info", "The spell's effects are reversed!", caster);
  map_mapping(sk_aff, (: call_other($3, $4, $1, $2 * $5) :),
    at, "add_skill_bonus", ((flag)?-1:1) * power);
  at->set("a bless num", (int)at->query("a bless num") + 1);
  delayed_call("remove_spell", props["duration"], power, at, flag);
  ::spell_func(caster, at, power, args, flag);
  return;
}


void remove_spell(int power, object at, int flag) {
  mapping sk_aff = SKILLS_AFFECTED;
  
  if(!at) {
    remove();
    return;
  }
  message("info", "%^CYAN%^A blessing expires.", at);
  map_mapping(sk_aff, (: call_other($3, $4, $1, $2 * $5) :),
    at, "add_skill_bonus", ((flag)?1:-1) * power);
  at->set("a bless num", (int)at->query("a bless num") - 1);
  remove();
  return;
}
