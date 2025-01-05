inherit "/std/spells/long_term_spell";

string weaptype,damtype;

void create() {
    ::create();
    set_property("name","natural weapon");
    set_property("skill","environmental bonding");
    set_property("duration", "permanent");
    set_property("casting time",10);
    set_property("base mp cost", 50);
    set_property("dev cost", 100);
    set_property("fast dev cost", 250);
    set_property("spell level", 34);
    set_property("moon","luna");
    set_property("caster message","You begin to shape the powers of nature to your will.");
    set_property("target message","");
    set_property("observer message","$C begins to shape the powers of nature.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell creates a powerful natural weapon from a Shaman Jewel. This is a long-term spell (see help long-term), and it takes very much real time to cast.  The spell must be cast on a Shaman Jewel that is not made of obsidian or quartz.  If you are interrupted while casting, you may pick up again at a later time.\n",
this_player());
}

void spell_func(object caster, object at, int power, string args, int
flag) {
  int time;
  if(!(at->is_battery())) {
    message("info", "You must cast this spell at a jewel.",
            caster);

    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if((string)at->query_property("type")=="none") {
    message("info", "You may not cast this spell on obsidian or quartz jewels.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  if(flag) {
    message("info", "You say a wrong word and accidentally destroy "+
            "the jewel!", caster);
    message("info", (string)caster->query_cap_name() +
            " mutters some vulgar things as his jewel disintegrates.",
            environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  set_work_message("You dance around in a circle, shouting natural things.");
  time = 870 + 110*power;
  if(wizardp(caster)) time = 1;
  start_work(at, caster, time, power);
  return;
}





void staff_set(string gemmaterial){
    switch(gemmaterial){
    case "/diamond":
	damtype="holy";
	break;
    case "/ruby":
	damtype="fire";
	break;
    case "/emerald":
	damtype="crushing";
	break;
    case "/sapphire":
	damtype="vacuum";
	break;
    case "/jade":
	damtype="aether";
	break;
    case "/obsidian":
	damtype="crushing";
	break;
    case "/amethyst":
	damtype="time";
	break;
    case "/turquoise":
	damtype="cold";
	break;
    case "/onyx":
	damtype="infernal";
	break;
    case "/quartz":
	damtype="crushing";
	break;
    case "/glass":
	damtype="crushing";
	break;
    }
    return;
}





void finish_work(object caster, object at, int power) {
  object ob;

  if(power <= 0) {
    message("info", "BUG in Shaman spell....unable to complete.", environment(caster));
    remove();
    return;
  }
  message("info", "You finish the spell, and a natural weapon appears.", caster);
  message("info", (string)caster->query_cap_name() + " stops yelling his beliefs, and a weapon of some sort appears.",
          environment(caster), ({ caster }) );

staff_set(at->query_material());


  seteuid(getuid());
  ob = new("/std/tailwind/obj/shaman_weapon");
  ob->set_material(at->query_material());
  ob->set_wc(3*(at->query_property("charge")), damtype);
  ob->set_auto_crits((["speed B" : 30 ]));
  ob->set_enh_critical(1);
  ob->move(caster);
  at->remove();
  remove();
  return;
}
