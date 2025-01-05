inherit "/std/skills/skill";
    
void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(15);
    set_fast_dev_cost(36);
    set_property("target type", "living");
    set_property("must be present",1);
}

void info() {
message("help",
"This skill may be used against enemies in combat.  You will attempt to head butt your oponent and stun them."+
"  You may only use this skill once every 5 combat rounds. However, that time goes away if your skill is high enough.",
this_player());
}
void skill_func(object from, object at, string arg) {
 // int flag, i; 
 // string *limbs,race;
  
  if ((int)props["skill level"] >= 200) {
   if((time() - (int)from->query_last_use("head butt")) < 2)
    {
    message("info", "You are too tired to use this skill yet."
        , from);
    return;
   } 
  } else {
  if((time() - (int)from->query_last_use("head butt")) < 10)
    {
    message("info", "You are too tired to use this skill yet."
        , from);
    return;
  }
}
  
  from->set_last_use("head butt");
  at->kill_ob(from, 0);
  props["skill level"] -= random(100);
  if((int)props["skill level"] < -10) {
    message("my_combat", "You attempt to head butt "+
            (string)at->query_cap_name()+ " but miss miserably and look like an idiot.",
            from);
    message("other_combat", (string)from->query_cap_name() +
            " attempts to head butt you.", at);
    message("other_combat", (string)from->query_cap_name() +
            " attempts to head butt "+
            (string)at->query_cap_name()+ ".", 
            all_inventory(environment(from)),
            ({ from, at }) );
    remove();  
    return;
  }
  message("my_combat", "You head butt "+
          (string)at->query_cap_name(),
          from);
  message("other_combat", (string)from->query_cap_name() +
          " head butt’s you.", at); 
  message("other_combat", (string)from->query_cap_name() +
          " hits "+
          (string)at->query_cap_name()+ " with "+
          " a head butt.",
          all_inventory(environment(from)),
          ({ from, at }) );
from->add_exp2(15 * props["skill level"]+(this_player()->query_level()*100));
  switch(props["skill level"]
) {
  case -10..55:
    at->set_paralyzed(10, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
message("my_combat", "You focus hard and use your head smash your head into "+(at->query_short()+" and he is dazed at the impact")+ "!", from);  
break; 
  case 56..99: 
    at->set_paralyzed(20, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^"); 
message("my_combat", "Using your head you smash it into "+(at->query_short()+" and he is Staggered")+ "!", from);     
break;
  case 100..174:
    at->set_paralyzed(30, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
message("my_combat", "Using your head like a battling ram you smash it into "+(at->query_short()+" and he is Stunned")+ "!", from);     
break;
 case 175..224:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)*2));
    do_critical(from, at, "impact A"); 
    at->set_paralyzed(40, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
 case 225..300:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)*2));
    do_critical(from, at, "impact A"); 
    at->set_paralyzed(60, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
 case 301..400:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)*2));
    do_critical(from, at, "impact B"); 
    at->set_paralyzed(60, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
 case 401..500:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)*2));
    do_critical(from, at, "impact C"); 
    at->set_paralyzed(60, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
 case 501..600:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)*2));
    do_critical(from, at, "impact D"); 
    at->set_paralyzed(60, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
 case 601..650:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)*2));
    do_critical(from, at, "impact E"); 
    at->set_paralyzed(60, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
 case 651..1000000:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)*2));
    do_critical(from, at, "impact B"); 
    at->set_paralyzed(60, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
  }
  remove();   
  return;
}
