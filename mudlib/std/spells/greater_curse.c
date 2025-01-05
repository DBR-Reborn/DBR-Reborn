inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","greater curse");
    set_property("skill","curse lore");
    set_property("casting time",20);
    set_property("base mp cost",140);
    set_property("dev cost", 110);
    set_property("fast dev cost", 330);
    set_property("spell level", 21);
    set_property("moon","ankh");
    set_property("caster message","You cast a great curse on $T.");
    set_property("target message","$C casts a great curse on you.");
    set_property("observer message","$C casts a great curse on $T.");
    set_property("spell type",({ "stat mod" }));
    set_property("stat dice", "-3D6");
    set_property("stats", ({ "strength", "intelligence", "dexterity", "wisdom", "charisma" }) );
    set_property("target type", "living");
    set_property("must be present",1);
    set_property("combat spell", 1);
    set_property("duration", 75);
    set_property("stack key", "hex");
    set_property("stack num", 1);
    set_property("prereq", "orb sacrifice");
    return;
}

int res_spell() { return 1; }

void info() {
message("help",
"This spell gives a  great short-term penalty in skills and stats to the "
"target. Greater curses can only be stacked once(x1). This spell can only be obtained thru and orb sacrifice.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;

  seteuid(getuid());
  if((int)at->query_curse_num() >= 2) {
    message("info", (string)at->query_cap_name() +
	    " already has the maximum number of great curses on "+
	    objective(at) + ".", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  ob = new("/std/spells/shadows/curse_shadow");
  ob->set_curse(power * -(random(5) + 1));
  ob->start_shadow(at, props["duration"],
		   "%^CYAN%^A great curse wears off.");
  ::spell_func(caster, at, power, args, flag);
  return;
}

