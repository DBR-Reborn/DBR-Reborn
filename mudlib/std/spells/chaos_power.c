#define SKILLS_AFFECTED ([ "attack" : 4, "blade" : 4, "two handed blade" : 3, \
    "blunt" : 3, "two handed blunt" : 3, "axe" : 3, "two handed polearm" : 3, \
    "flail" : 3, "two handed flail" : 3, "body block" : 3, "parry" : 2, \
    "block" : 3, "dodge" : 2, "whirlwind attack" : 2, "dual attack" : 4, \
    "offhand training" : 4, "dance of daggers" : 2, "knife" : 3, \
    "thrown" : 3, "repair weapon" : 4, "resist stun" : 3, "reverse stroke" : 3, \
     "chaos magic" : 3, "control demon" : 2 ])
    
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","chaos power");
    set_property("skill","chaos magic");
    set_property("casting time",7);
    set_property("base mp cost",30);
    set_property("dev cost", 25);
    set_property("fast dev cost", 95);
    set_property("spell level", 21);
    set_property("moon","ankh");
    set_property("caster message","You bind chaos power to $T.");
    set_property("target message","$C binds chaos power to you.");
    set_property("observer message","$C appears to bind chaos power to $T.");
    set_property("spell type",({ "stat mod" }));
    set_property("stat dice", "1D15");
    set_property("stats", ({ "dexterity" }) );
    set_property("target type", "living");
    set_property("must be present",1);
    set_property("duration", 160);
    return;
}

int res_spell() { return 1; }

void info() {
message("help",@TEXT
This spell gives a general short-term bonus in skills and stats which
may be useful in a variety of situations.  This spell is stackable 2 times.
Most general physical skills will receive bonuses from this spell.
TEXT
,this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
//  object ob;
  mapping sk_aff = SKILLS_AFFECTED;

  seteuid(getuid());
  if ((int)at->query("a bless num") + (int)at->query("f bless num") + (int)at->query("c bless num") >= 2 ) {
    message("info", (string)at->query_cap_name() +
	    " can receive no additional increases of agility.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) message("info", "The spell's effects are reversed!", caster);
  map_mapping(sk_aff, (: call_other($3, $4, $1, $2 * $5) :),
    at, "add_skill_bonus", ((flag)?-1:1) * power);
  at->set("c bless num", (int)at->query("c bless num") + 1);
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
  message("info", "%^CYAN%^A chaos power bind expires.", at);
  map_mapping(sk_aff, (: call_other($3, $4, $1, $2 * $5) :),
    at, "add_skill_bonus", ((flag)?1:-1) * power);
  at->set("c bless num", (int)at->query("c bless num") - 1);
  remove();
  return;
}
