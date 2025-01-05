inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";
inherit "/std/check_brittle";

void create() {
    ::create();
    set_property("name","demon prince sword");
    set_property("skill","chaos magic");
    set_property("casting time",14);
    set_property("base mp cost",70);
    set_property("dev cost",180);
    set_property("fast dev cost",481);
    set_property("spell level", 38);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You bind the demon to the weapon.");
    set_property("target message","");
    set_property("observer message","$C bind’s a demon to a weapon.");
    set_property("spell type",({}));
    //set_property("duration", "permanent");
    set_property("duration", 2020);
    set_property("stack key", "demon prince sword");
    set_property("stack num", 1);
    set_property("must be present", 1);
    set_property("target type", "living");
    set_property("prereq", "summon demon prince");
    return;
}

void info() {
message("help",
"This spell binds a demon prince to your weapon, increasing damage.  "
"This spell must be cast at a demon prince which has been summoned and controlled "
"by you. You may only bind on prince per weapon\n"
"Syntax: cast *<pow> demon prince sword at <demon> with <weapon>\n",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object weap, ob;
  int ench, i, idx, lvl;
  mixed tmp;

  
  if(!at->id("demon prince")) {
    message("info", "You must cast this spell at a demon prince.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(!at->query_owner() || (string)at->query_owner() != (string)caster->query_name()) {
    message("info", "The demon must have been summoned and contolled by you.",
        caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "Instead of binding the demon to your weapon, you release it "
      "from your control and it attacks!", caster);
    message("info", (string)at->query_cap_name() + " angrily attacks "+
          (string)caster->query_cap_name() + "!", environment(caster),
          ({ caster, at }));
    at->set_owner("asskicker");
    at->kill_ob(caster, 0);
    remove();
    return;
  }

  if(!args || !(weap = present(lower_case(args), caster))) {
    if(!args)
      message("info", "You must supply a weapon to which to bind the demon.",
          caster);
    else
      message("info", "You have no '"+args+"'.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
//add
  at->remove();
  message("info", "You bind the demon to "+(string)weap->query_short()+".", caster);
lvl = (caster->query_level()/2); 
  ob = new("/std/spells/shadows/weapon_shadow");
  if(!check_stack(weap, ob)) {
    message("info", "You may not stack any further demons on that weapon.",
      caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  ob->set_extra_wc(([ "impact" : 15*power+lvl, "disruption" : 12*power+lvl, "fire" : 8*power+lvl, ]));
  ob->set_auto_crits(([ "disruption D" : 2*power+lvl ]));
  ob->start_shadow(weap, props["duration"], "%^CYAN%^A demon prince sword spell wears off.");
  remove();
  at->remove();
  return;
}

//end 

/* 
  if((int)weap->query_property("demon prince sword") >= 1 ) {
    message("info", "This weapon can receive no more demon prince binds.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}
  
  ench = (int)weap->query_property("demon prince sword");
  
	if(!check_brittle(weap, caster, power)) {
    remove();
    return;
  }
  
  if(!ench){
   ench = 0;
  }

  ench += power;
    weap->set_property("demon prince sword", 1);
    //ench = (int)weap->query_wc("unholy");
    //if(!ench) ench = power*60;
    //else ench += power*60;
	//weap->set_wc(ench, "unholy");
	//ench = (int)weap->query_wc("infernal");
    //if(!ench) ench = power*60;
    //else ench += power*60;
    //weap->set_wc(ench, "infernal");

    ench = (int)weap->query_wc("fire");
    if(!ench) ench = power*60;
    else ench += power*60;
    weap->set_wc(ench, "fire");	
    ench = (int)weap->query_wc("impact");
    if(!ench) ench = power*60;
    else ench += power*60;
    weap->set_wc(ench, "impact");
    ench = (int)weap->query_wc("disruption");
    if(!ench) ench = power*60;
    else ench += power*60;
  	weap->set_wc(ench, "disruption");
  	ench = (int)weap->query_ac("disruption A");
    if(!ench) ench = power*40;
    else ench += power*40;
  	weap->set_ac(ench, "disruption A");
  	at->remove();
    caster->add_exp2(400*power);

  tmp = (mixed)weap->query_property("extra long");
  if(!tmp) tmp = ({});
  else if(stringp(tmp)) tmp = ({ tmp });
  idx = -1;
  i = sizeof(tmp);
  while(i--) {
    if(pointerp(tmp[i]) && sizeof(tmp[i]) == 2 &&
       eliminate_colour(tmp[i][0]) == "This weapon has demon prince sword.") idx = 1;
  }
  if(idx < 0)
    tmp += ({ ({ "This weapon has %^ORANGE%^Demon Prince%^RESET%^ %^BOLD%^%^WHITE%^Sword." ,
		   "detect magic" }) });
  weap->set_property("extra long", tmp);
  remove();
  return;
}
*/
