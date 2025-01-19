inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","lich form");
    set_property("skill","black magic");
    set_property("casting time", 11);
    set_property("base mp cost", 102);
    set_property("dev cost", 85);
    set_property("fast dev cost", 255);
    set_property("spell level", 16);
    set_property("moon","ankh");
    set_property("caster message","You cast lich form on $T.");
    set_property("target message","$C casts lich form on you.");
    set_property("observer message","$C casts a lich form on $T.");
    set_property("spell type",({ "stat mod", "protection" }));
    set_property("stat dice", "4D8");
    set_property("stats", ({ "strength", "intelligence", "dexterity" }) );
    set_property("protection types", ([
       "crushing" : 75, "impaling" : 75, "cutting" : 75, "impact" : 75,
	       "strike": 75, "stress": 75, "cold": 75, "fire": 75,
               "electricity": 75, "vacuum": 75, "disruption": 75 ]) );
    set_property("target type", "living");
//Removed due to Shadow Form is broken     TLNY2020
//set_property("prereq", "shadow form");
    set_property("must be present",1);
    set_property("duration", 400);
    return;
}

int res_spell() { return 1; }

void info() {
message("help",
"This spell transforms one into a Lich and gives them magical properties.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;

  seteuid(getuid());
  if((int)at->query_lichform()) {
    message("info", (string)at->query_cap_name() +
	    " has already been transformed.",
	    caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(!flag) {
    ob = new("/std/spells/shadows/lichform_shadow");
    ob->set_power(power);
    ob->start_shadow(at, props["duration"],
	  	   "%^CYAN%^Lich Form wears off.");
  }
  ::spell_func(caster, at, power, args, flag);
  return;
}
