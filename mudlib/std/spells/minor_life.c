inherit "/std/spells/long_term_spell";

int time, mod;
int skill = 1;

void create() {
    ::create();
    set_property("name","minor life");
    set_property("skill","alchemy");
    set_property("duration", "permanent");
    set_property("casting time",1);
    set_property("base mp cost",38);
    set_property("dev cost", 7);
    set_property("fast dev cost", 21);
    set_property("spell level", 3);
    set_property("moon","luna");
    set_property("caster message",
      "You begin to breathe life into a body.");
    set_property("target message","");
    set_property("observer message",
      "$C begins to breathe life into a body.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help",
"Minor Life allows an Alchemist to magically enchant a golem body to make
it come to life and serve the caster. Minor life is the least powerful of
the 'life' spells, and does not give the golem any special powers, such as
spells. Also see 'help spell major life' and 'help spell true life'.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
  if(!at->id("body")) {
    message("info", "You must cast this spell at a body.",
            caster);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the life energies and destroy "+
            "the body!", caster);
    message("info", (string)caster->query_cap_name() +
            " inadvertently crumbles a body to dust.",
            environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  set_work_message("You breathe life into the body.");
  skill = caster->query_skill(props["skill"]);

  time = (600 + 30*power - skill*2);
  if(time<200){time=200;}

  if(wizardp(caster))time = 1;

  start_work(at, caster, time, power);
  return;
}

void finish_work(object caster, object at, int power) {
  object ob;

  if(power <= 0) {
    message("info", "BUG in golem spell....unable to complete.",
            environment(caster));
    remove();
    return;
  }
  message("info", "The body transforms into a golem.", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
          "alchemistic incantations, and a body "+
          "transforms into a golem.",
          environment(caster), ({ caster }) );

//  seteuid(getuid());


if((string)at->query_golem_name()== "metal_golem"){
  ob = new("/std/tailwind/pets/" + (string)at->query_golem_name()); 

if(at->query_material()=="metal/boernerine"){
  ob->set_property("melee damage", ([ "impact" : 15 ]) );
}
if(at->query_material()=="metal/mcgrail"){
  ob->set_property("melee damage", ([ "cutting" : 15 ]) );
}
if(at->query_material()=="metal/davistone"){
  ob->set_property("melee damage", ([ "weapon-break" : 15 ]) );
}
if(at->query_material()=="metal/javednite"){
  ob->set_property("melee damage", ([ "javednite" : 15 ]) );
}
if(at->query_material()=="metal/catoetine"){
  ob->set_property("melee damage", ([ "speed" : 15 ]) );
  ob->set_overall_ac(15);
}
if(at->query_material()=="metal/raysorite"){
  ob->set_property("melee damage", ([ "stress" : 30 ]) );
}
if(at->query_material()=="metal/inniculmoid"){
  ob->set_property("melee damage", ([ "impact" : 30 ]) );
  ob->set_overall_ac(30);
}
if(at->query_material()=="metal/elrodnite"){
  ob->set_property("melee damage", ([ "cold" : 30 ]) );
}
if(at->query_material()=="metal/mithril"){
  ob->set_property("melee damage", ([ "fire" : 30 ]) );
  ob->set_overall_ac(30);
}
if(at->query_material()=="metal/platnite"){
  ob->set_property("melee damage", ([ "electricity" : 15 ]) );
}
if(at->query_material()=="metal/mabril"){
  ob->set_property("melee damage", ([ "stun" : 15 ]) );
  ob->set_overall_ac(30);
}
if(at->query_material()=="metal/neurolite"){
  ob->set_property("melee damage", ([ "limb" : 15 ]) );
}
if(at->query_material()=="metal/laen"){
  ob->set_overall_ac(45);
}
if(at->query_material()=="metal/iysaughton"){
  ob->set_property("melee damage", ([ "disruption" : 30 ]) );
}
if(at->query_material()=="metal/eonmite"){
  ob->set_property("melee damage", ([ "time" : 30 ]) );
}
if(at->query_material()=="metal/eog"){
  ob->set_property("melee damage", ([ "aether" : 45 ]) );
  ob->set_overall_ac(45);
}

  ob->set_material(replace_string((string)at->query_material(), "/",
"",1));
  ob->set_owner((string)caster->query_name());
  ob->move(environment(caster));
  ob->set_power(power);
  ob->set_create_skill(at->query_create_skill());
  ob->setup_golem();
  at->remove();
  remove();
  return;
}

// set_property("magic resistance",30);


  ob = new("/std/tailwind/pets/" + (string)at->query_golem_name() );
  ob->move(environment(caster));
  ob->set_power(power);
  ob->set_create_skill(at->query_create_skill());
  ob->set_owner((string)caster->query_name());
  ob->setup_golem();
  at->remove();
  remove();
  return;
}


