inherit "/std/spells/long_term_spell";

int time, mod;

void create() {
    ::create();
    set_property("name","true life");
    set_property("skill","alchemy");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",78);
    set_property("dev cost", 123);
    set_property("fast dev cost", 313);
    set_property("spell level", 20);
    set_property("moon","luna");
    set_property("caster message",
      "You begin to breathe life into a body.");
    set_property("target message","");
    set_property("observer message",
      "$C begins to breathe life into a body.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("prereq", "major life");
    return;
}

void info() {
    message("help",
"True Life allows an Alchemist to magically enchant a golem body to make it
come to life and serve the caster. True Life is the most powerful of the
'life' spells and gives the golem powerful spell abilities. Also see 'help
spell major life' and 'help spell true life'.",
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
  mod = 30+2*props["spell level"];
  time = (3600 + 90*power)-mod;
  if(time<1800){time=1800;}
  if(wizardp(caster))time = 1;
  start_work(at, caster, time, power);
  return;
}

void finish_work(object caster, object at, int power) {
   int pow=power;
   object ob;
   int skill = at->query_create_skill();

  if(power <= 0) {
    message("info", "BUG in golem spell....unable to complete.",
            environment(caster));
    remove();
    return;
  }
  message("info", "The body transforms into a "+
          "golem.", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
          "alchemistic incantations, and a body "+
          "transforms into a golem.",
          environment(caster), ({ caster }) );
//  seteuid(getuid());



if((string)at->query_golem_name()== "metal_golem"){
  ob = new("/std/tailwind/pets/" + (string)at->query_golem_name() );
  ob->set_material(replace_string((string)at->query_material(), "/","",1));
}
else
  ob = new("/std/tailwind/pets/" + (string)at->query_golem_name() );

  ob->set_combat_chance(90);
  ob->set_owner((string)caster->query_name());
  ob->set_skill("body alteration", 50+15*pow);
  ob->set_skill("prayer", 55+15*pow);
  ob->set_skill("conjuration", 55+15*pow);
  ob->set_skill("magery", 55+15*pow);

  ob->set_spell_level("divine transformation", 3+pow/2);
  ob->set_spell_level("cure critical wounds", 3+pow/2);
  ob->set_spell_level("holy armour", 3+pow/2);
  ob->set_spell_level("vacuum bolt", pow);
  ob->set_spell_level("power word, stun", 3+pow/2);
  ob->set_spell_level("mad rage", 3+pow/2);
  ob->set_spell_level("fire shield", 3+pow/2);
  ob->set_spell_level("blizzard", 3+pow/2);

  ob->add_spell("divine transformation", "$(ME)");
  ob->add_spell("cure critical wounds", "$(ME)");
  ob->add_spell("holy armour", "$(ME)");
  ob->add_spell("vacuum bolt", "$A");
  ob->add_spell("power word, stun", "$A");
  ob->add_spell("mad rage", "$(ME)");
  ob->add_spell("fire shield", "$(ME)");
  ob->add_spell("blizzard", "$A");


  ob->move(environment(caster));
  ob->set_power(power+6);
  ob->set_create_skill(at->query_create_skill());
  ob->setup_golem();
  at->remove();
  remove();
  return;

}

