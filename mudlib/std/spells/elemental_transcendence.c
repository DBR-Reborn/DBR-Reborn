#include "/adm/include/spell.h"

inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","elemental transcendence");
    set_property("skill","elementalism");
    set_property("elemental spell", 1);
    set_property("casting time",15);
    set_property("base mp cost",300);
    set_property("dev cost", 300);
    set_property("fast dev cost", 615);
    set_property("spell level", 50);
    set_property("moon","ankh");
    set_property("caster message","You cast elemental transendence.");
    set_property("target message","");
    set_property("observer message","$C casts elemental transendence.");
    set_property("spell type",({ "stat mod", "skill mod", "protection" }));
    set_property("stat dice", "8D8");
    set_property("skill dice", "4D12");
    set_property("ele protection", 175);
    set_property("stats", ({ "strength", "intelligence", "dexterity" }) );
    set_property("skills", ({ "attack", "melee" }));
    set_property("no target", 1);
    set_property("must be present",1);
    set_property("duration", 800);
    set_property("prereq", "elemental transformation");
    return;
}

int res_spell() { return 1; }

void info() {
message("help",
"This spell transforms the caster's body into the form of the element "
"chosen.  The caster will receive a substantial bonus in melee skill as "
"well as bare-handed damage of the element chosen.  The caster will also "
"receive mild protection from the element as well as a skill bonus to "
"the lore skill of that element.\n"
"NOTE: This is a more powerful version of 'body of elements.'",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;

  seteuid(getuid());
  if(flag) {
    message("info", "You misdirect the spell, calling the element upon "+
      "yourself!", caster);
    message("info", CQN+" misdirects "+possessive(caster)+" spell, "+
      "calling the wrath of "+props["element"]+" on "+objective(caster)+
      "self!", EC, ({ caster }));
    do_critical(caster, caster, map_array(props["element types"], (: $1 + $2 :),
      " C"));
    remove();
    return;
  }
  if((int)caster->query_etrans()) {
    message("info", (string)caster->query_cap_name() +
	    " has already been transformed by a body transformation spell.",
	    caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  ob = new("/std/spells/shadows/etrans_shadow");
  //ob->set_melee(14 + power *4);
  //ob->set_melee_skill(20+power*3);
    ob->set_melee((power*8)+caster->query_level());
    ob->set_melee_skill((power*8)+caster->query_level());
  //ob->set_shadow_name("elemental transcendence");
    //ob->set_auto_critical(implode(props["element types"], " C"));
   //no work //ob->set_auto_critical(caster, caster, map_array(props["element types"], (: $1 + $2 :), " C"));
  ob->set_elements(props["element types"]);
  ob->start_shadow(caster, props["duration"],
		   "%^CYAN%^Body of elements wears off.");
  message("info", "You transform your body into the form of "+props["element"]+
	  ".", caster);
  message("info", CQN+" transforms into a being of pure "+props["element"]+"!",
	  EC, ({ caster }));
  set_property("skills", ({ "elementalism", sprintf("%s lore", 
						    props["element"]) }));
  ::spell_func(caster, caster, power, args, 0);
  return;
}

