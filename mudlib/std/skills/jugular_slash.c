inherit "/std/skills/skill";

int stab_filter(object weapon) {
    string *wcs, type;

    if(!weapon || !objectp(weapon) || !weapon->is_weapon()) return 0;
    if(!mapp(weapon->query_all_wc())) return 0;
    type = (string)weapon->query_type();
    if(!type || type != "knife") 
	return 0;
    wcs = keys((mapping)weapon->query_all_wc());
    if(member_array("cutting", wcs) >= 0) return 1;
    if(member_array("impaling", wcs) >= 0) return 1;
    else return 0;
}

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(20);
    set_fast_dev_cost(40);
    set_property("target type", "living");
    set_property("must be present",1);
}

void info() {
    message("help",
      "This skill allows the thief to slash at the jugular vein of"
      " thier opponents.  A knife weapon that does cutting "
      " damage must be wielded in order to use this skill.  "
      "Slashing the jugular vein with a poisoned weapon will "
      "have very devastating effects.  "
      "  You may only use this skill once every five combat rounds.",
      this_player());
}

void skill_func(object from, object at, string arg) {
    object *tmp;
    int poison;
    int max_dam;
    int thief_poison;
    int avoid = 0;
    int stunned = at->query_paralyzed();
    int js_skill = props["skill level"];
    int prot = 0;
    int damage, i;
    string d_message;
    int head_dam;
    object ob;


    if(at->query_property("no kill")) {
      from->kill_ob(at, 0);
      remove();
      return;
    }
    if((time() - (int)from->query_last_use("jugular slash")) < 10)
    {
	message("info", "You are too tired to use this skill yet.", from);
	return;
    }
    if(environment(from) && environment(from)->query_property("no attack"))
    {
	message("info", "Mystic forces prevent your action.", from);
	remove();
	return ;
    }
    if(at->shadow_form() || at->query_ghost()) {
	message("info", 
	  "You may not slash a target which is immaterial.", from);
	remove();
	return;
    }
    tmp = (object *)from->query_wielded();
    if(!tmp || !sizeof(tmp)) {
	message("info", "You must have a weapon wielded to slash.", from);
	remove();
	return;
    }
    tmp = filter_array(tmp, "stab_filter", this_object());
    if(!sizeof(tmp)) {
	message("info", "You must wield a one-handed cutting knife weapon.", from);
	remove();
	return;
    }
    from->set_last_use("jugular slash");


    poison = (int)tmp[0]->query_poisoning();
    thief_poison = (int)tmp[0]->query_poison_strength();

    if(poison > thief_poison && thief_poison > 0)
	poison = thief_poison;
    if(poison > thief_poison)
	poison = poison / 2;

    from->kill_ob(at, 0);


    // dodge complete avoid
    if (js_skill + random(js_skill) < at->query_skill("dodge"))
	avoid = 1;

    // perception complete avoid
    if (js_skill + random(js_skill) < at->query_skill("perception"))
	avoid = 1;

    if(at->query_skill("reverse stroke") 
      + random(at->query_skill("reverse stroke")) / 4
      >
      from->query_skill("jugular slash") +
      random(from->query_skill("jugular slash")) / 4){
	ob = at;
	at = from;
	from = ob;
    }

    prot = at->query_current_protection("head", "cutting");

    if(stunned)
	damage = js_skill * 5 - prot / 4;
    else
	damage = js_skill* 3 - prot / 4;

    damage += tmp[0]->query_wc("cutting") * 3;

    // rejected by armour
    // harder to reject by armour if stunned
    if (damage < 1){
	message("my_combat", "You attempt to slash at "	 +(string)at->query_cap_name()+"'s jugular but "	 +(string)at->query_cap_name()+"'s armour deflects your blow. ",	 from);	message("other_combat", (string)from->query_cap_name() 
	  +" attempts to slash at your jugular vein but your armour protects you.",
	  at);
	message("other_combat", (string)from->query_cap_name() + " attempts
        to slash at "+ (string)at->query_cap_name()+ "'s jugular vein but
        "+(string)at->query_cap_name()+" seems unharmed.",
        all_inventory(environment(from)), ({ from, at }) );
      remove();
      return;
  }


 // dodge/perception avoid
 if(avoid && !stunned){
      message("my_combat", "You attempt to slash at "
          +(string)at->query_cap_name()+"'s jugular but"
          +(string)at->query_cap_name()+" manages to scramble out of the way",
        from);
      message("other_combat", (string)from->query_cap_name() 
      +" attempts to slash at your jugular vein but you manage to scramble out of the way.",
        at);
      message("other_combat", (string)from->query_cap_name() + " attempts
        to slash at "+ (string)at->query_cap_name()+ "'s jugular vein but "
        +(string)at->query_cap_name()+" manages to scramble out of the way.",
        all_inventory(environment(from)), ({ from, at }) );
      remove();
      return;
    }

    switch(damage){
        case 0..25:
            d_message = "barely";
            break;
        case 26..50:
            d_message = "roughly";
            break;
        case 51..80:
            d_message = "brutaly";
            break;
        case 81..140:
            d_message = "forcefuly";
            break;
        case 141..200:
            d_message = "vigoroussly";
            break;
        case 201..100000:
            d_message = "violently";
            break;
    }

message("my_combat", "You "+d_message+" slash at "+at->query_cap_name()+"'s jugular vein!", from);
 message("other_combat", (string)from->query_cap_name() + " " + d_message +" slashes your jugular vein!", at);
 message("other_combat", (string)from->query_cap_name() + " " + d_message +" slashes "+at->query_cap_name()+"'s jugular vein", all_inventory(environment(from)), ({ from, at }) );

    // add poisoning if there is any
    if(poison)
        at->add_poisoning(poison);
    tmp[0]->add_poisoning(-tmp[0]->query_poisoning() / 5);


//    max_dam = at->query_max_dam("head");

    head_dam = damage;

    at->do_damage("head", head_dam);
    at->set_paralyzed(1+ damage / 25);

    i = at->query_property("bleeding");
    at->set_property("bleeding", damage / 2);

    if(wizardp(this_player())){
        write("damage : " + damage);
        write("head damage : " + head_dam);
        write("bleeding : " + (head_dam / 2));
        write("paralyzed : " + (1+ damage / 25));
    }

  remove();
  return;
}
