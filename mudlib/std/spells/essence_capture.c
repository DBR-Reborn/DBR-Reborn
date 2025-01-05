inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name","essence capture");
    set_property("skill","environmental bonding");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",77);
    set_property("dev cost", 91);
    set_property("fast dev cost", 278);
    set_property("spell level", 5);
    set_property("moon","luna");
    set_property("caster message","You begin to power a jewel with the essence of a creature.");
    set_property("target message","");
    set_property("observer message","$C begins to power a jewel with the essence of a creature.");
    set_property("spell type",({ }));
    set_property("must be present", 1);
    set_property("target type", "living");
    return;
}

void info() {
message("help",
"This spell charges a jewel with the essence of a creature that you control. Only certain types of creatures can power certain types of jewels. Jewels can be recharged, but if their power is ever completely depleted, they will shatter. The power of the creature directly affects how much charge you can obtain from it. This is a long-term spell (see help long-term), and it takes very much real time to cast.  If you are interrupted while casting, you may pick up again at a later time. Note: undead creatures can be charged into a jewel without owning them. _Do not abuse this._ Get permission first.\n Syntax: cast *<pow> essence capture at <creature> with <jewel>\n Ex: cast *2 essence capture at phoenix with jewel\n",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob, jewel;
  
  if(!(at->is_elemental() || at->is_ul_pet())) {
    message("info", "This creature is not capable of charging a jewel.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  if((!at->query_owner() || (string)at->query_owner() != (string)caster->query_name()) && at->query_race() != "undead") {
    message("info", "The creature must have be controlled by you.",
        caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "The creature takes exception to your attempt to rip its life force from it.", caster);
    message("info", (string)at->query_cap_name() + " angrily attacks "+
          (string)caster->query_cap_name() + "!", environment(caster),
          ({ caster, at }));
    at->set_owner("asskicker");
    at->kill_ob(caster, 0);
    remove();
    return;
  }
  seteuid(getuid());
  if(!args || !(jewel = present(lower_case(args), caster))) {
    if(!args)
      message("info", "You must supply a jewel to be charged.",
          caster);
    else
      message("info", "You have no '"+args+"'.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
 jewel = present(lower_case(args), caster);

/*
  if(jewel->query_property("charge")>0){
  message("info", "This jewel cannot be charged further, as it has already been charged.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}
*/

  if(jewel->query_property("type")=="none"){
  message("info", "The creature's life force is sucked into "+(string)jewel->query_short()+".", caster);
  jewel->add_charge(at->query_property("charge")/2);
  jewel->set_up();
  at->remove();
  remove();
  return;
}

  if(!(at->query_property("type") == jewel->query_property("type"))) {
    message("info", "The creature type must be the same as the jewel's.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  message("info", "The creature's life force is sucked into "+(string)jewel->query_short()+".", caster);
  jewel->add_charge(at->query_property("charge"));
  jewel->set_up();
  at->remove();
  remove();
  return;
}

