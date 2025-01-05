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
"This skill may be used against enemies in combat.  If you have an empty "+
"hand, you can punch your target."+
"  You may only use this skill once every 5 combat rounds. However, that time goes away if your skill is high enough.",
this_player());
}
void skill_func(object from, object at, string arg) {
  int flag, i; 
  string *limbs,race;
  
  if ((int)props["skill level"] >= 200) {
   if((time() - (int)from->query_last_use("reverse punch")) < 2)
    {
    message("info", "You are too tired to use this skill yet."
        , from);
    return;
   } 
  } else {
  if((time() - (int)from->query_last_use("reverse punch")) < 10)
    {
    message("info", "You are too tired to use this skill yet."
        , from);
    return;
  }
}
  race = from->query_race();
  flag = 0;
  limbs = from->query_limbs();
  i = sizeof(limbs);
  while(i--) {
    if( (object)from->query_weapon(limbs[i]) ||
      (member_array("shield", (string *)from->query_armour(limbs[i])) > -1))
      flag++;
  }
  if((race != "ent" && flag > 1) || flag > 3) {
    message("my_action", "You do not have a free hand to strike with!",
             from);
    remove();  
    return;
  }
  from->set_last_use("reverse punch");
  at->kill_ob(from, 0);
  props["skill level"] -= random(100);
  if((int)props["skill level"] < -10) {
    message("my_combat", "You attempt to punch "+
            (string)at->query_cap_name()+ " but miss miserably.",
            from);
    message("other_combat", (string)from->query_cap_name() +
            " attempts to punch you.", at);
    message("other_combat", (string)from->query_cap_name() +
            " attempts to punch "+
            (string)at->query_cap_name()+ ".", 
            all_inventory(environment(from)),
            ({ from, at }) );
    remove();  
    return;
  }
  message("my_combat", "You hit "+
          (string)at->query_cap_name()+ " with your reverse punch. ",
          from);
  message("other_combat", (string)from->query_cap_name() +
          " hits you with a reverse punch", at); 
  message("other_combat", (string)from->query_cap_name() +
          " hits "+
          (string)at->query_cap_name()+ " with "+
          " a reverse punch.",
          all_inventory(environment(from)),
          ({ from, at }) );
from->add_exp2(15 * props["skill level"]+(this_player()->query_level()*100));
  switch(props["skill level"]
) {
  case -10..10:
    at->do_damage((string)at->return_target_limb(), random(10)+5);
    break; 
  case 11..30:
    at->do_damage((string)at->return_target_limb(), 2 * (random(10)+5));
    do_critical(from, at, "strike A");  
    break;
  case 31..55:
    at->do_damage((string)at->return_target_limb(), 2 * (random(10)+5));
    do_critical(from, at, "strike B");
   // at->set_paralyzed(10, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
  case 56..75:
    at->do_damage((string)at->return_target_limb(), 2 * (random(10)+5));
    do_critical(from, at, "strike C");  
   // at->set_paralyzed(20, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^"); 
    break;
  case 76..174:
    at->do_damage((string)at->return_target_limb(), 2 * (random(10)+5));
    do_critical(from, at, "strike D");
   // at->set_paralyzed(30, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
 case 175..224:
    at->do_damage((string)at->return_target_limb(), 2 * (random(10)*2));
    do_critical(from, at, "strike D");
    at->set_paralyzed(10, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
 case 225..10000:
    at->do_damage((string)at->return_target_limb(), 3 * (random(15)*2));
    do_critical(from, at, "strike E");
    at->set_paralyzed(10, "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
    break;
  }
  remove();   
  return;
}
