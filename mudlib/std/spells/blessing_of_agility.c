#define SKILLS_AFFECTED ([ "attack" : 4, "blade" : 3, "two handed blade" : 3, \
    "blunt" : 3, "two handed blunt" : 3, "axe" : 3, "two handed polearm" : 3, \
    "flail" : 3, "two handed flail" : 3, "body block" : 3, "parry" : 2, \
    "block" : 3, "dodge" : 2, "whirlwind attack" : 2, "dual attack" : 2, \
    "offhand training" : 3, "dance of daggers" : 2, "knife" : 3, \
    "thrown" : 3, "repair weapon" : 4, "resist stun" : 2, \
    "two handed staff" : 3,])
    
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","blessing of agility");
    set_property("skill","prayer");
    set_property("casting time",7);
    set_property("base mp cost",30);
    set_property("dev cost", 25);
    set_property("fast dev cost", 95);
    set_property("spell level", 8);
    set_property("moon","ankh");
    set_property("caster message","You pray for a blessing of agility for $T.");
    set_property("target message","$C prays for a blessing of agility for you.");
    set_property("observer message","$C appears to pray for $T.");
    set_property("spell type",({ "stat mod", "skill mod" }));
    set_property("stat dice", "4D6");
    set_property("skill dice", "2D5");

    set_property("stats", ({ "dexterity" }) );
    set_property("skills", ({ "attack", "melee", "blade", "two handed blade", "blunt", "two handed blunt", "axe", "two handed polearm", "flail", "two handed flail", "body block", "parry", "block", "dodge", "whirlwind attack", "knife", "resist stun", "two handed staff", "dual attack", "offhand training", "repair weapon", "thrown", "dance of daggers"  }));

    set_property("target type", "living");
    set_property("must be present",1);
    set_property("duration", 480);

if(this_player()->query_name() == "healer") {
    set_property("casting time",1);
    set_property("duration", 1000);
}
    return;
}

int res_spell() { return 1; }

void info() {
message("help",@TEXT
This spell gives a general short-term bonus in skills and stats which
may be useful in a variety of situations. Most general physical skills will receive bonuses from this spell. Skills used to accomplish unholy pursuits (back stab, steal, etc.) will not be affected.
TEXT
,this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
//  object ob;
  mapping sk_aff = SKILLS_AFFECTED;



  seteuid(getuid());
  if ((int)at->query("a bless num") + (int)at->query("f bless num") + (int)at->query("c bless num") >= 1 ) {
    message("info", (string)at->query_cap_name() +
	    " can receive no additional blessings of agility.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
    at->set("a bless num", (int)at->query("a bless num") + 1);
    delayed_call("remove_stack", props["duration"], at);
    ::spell_func(caster, at, power, args, flag);
caster->add_exp2(8 * caster->query_skill("prayer") + (this_player()->query_level()*100));
  return;

}
/*
  if(flag) message("info", "The spell's effects are reversed!", caster);
  map_mapping(sk_aff, (: call_other($3, $4, $1, $2 * $5) :),
    at, "add_skill_bonus", ((flag)?-1:1) * power);
  at->set("a bless num", (int)at->query("a bless num") + 1);
  delayed_call("remove_spell", props["duration"], power, at, flag);
  ::spell_func(caster, at, power, args, flag);
  return;
}
*/

void remove_stack(object at) {
  if(!objectp(at)) return;
    at->set("a bless num", (int)at->query("a bless num") - 1);
  message("info", "%^CYAN%^A blessing of agility expires.", at);
  remove();
  return;
}

/*
void remove_spell(int power, object at, int flag) {
  mapping sk_aff = SKILLS_AFFECTED;
  
  if(!at) {
    remove();
    return;
  }
  message("info", "%^CYAN%^A blessing of agility expires.", at);
  map_mapping(sk_aff, (: call_other($3, $4, $1, $2 * $5) :),
    at, "add_skill_bonus", ((flag)?1:-1) * power);
  at->set("a bless num", (int)at->query("a bless num") - 1);
  remove();
  return;
}
*/
