inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","holy light");
    set_property("skill","prayer");
    set_property("casting time",7);
    set_property("base mp cost",12);
    set_property("dev cost", 4);
    set_property("fast dev cost", 11);
    set_property("spell level", 1);
    set_property("moon","luna");
    set_property("caster message","You summon a globe of holy light.");
    set_property("target message","");
    set_property("observer message","$C summons a globe of holy light.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", 360);
    return;
}

void info() {
message("help",
"This spell summons a torch-like light to guide your way.    You may specify how bright you "
"want it...default is as bright as a torch.\n"
"Usage: cast *<pow> light at <level>\n"
"ex: cast *2 light at bright\n\n"
"Light levels: low, torch (default), bright",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;
  ob = new("/std/spells/shadows/light_shad");
  switch(args) {
  case "low":
    ob->set_light(flag?-power:power);
    break;
  case "bright":
    ob->set_light(flag?-power*3:power*3);
    break;
  default:
  case "torch":
    ob->set_light(flag?-power*2:power*2);
    break;
  }
  ob->start_shadow(caster, props["duration"],
	           "A holy light spell expires.");
caster->add_exp2(1 * caster->query_skill("prayer") + (this_player()->query_level()*100));
  return;
}
