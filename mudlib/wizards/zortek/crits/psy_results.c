//	Some fun special results for crits.
#define A_NAME ((string)from->query_cap_name())
#define T_NAME ((string)to->query_cap_name())

void shatter_me(object me, object you) {
    call_out("do_shatter", 2, ({ (string)you->query_name(),
	environment(you), you }));
    return;
}

void blindness(object from, object to) {
  object ob;

  seteuid(getuid());
  ob = new("/std/spells/shadows/blind_shadow");
  ob->start_shadow(to);
  return;
}

void melt_weapon(object from, object to) {
  object *weap;
  int i;

  weap = (object *)to->query_wielded();
  if(sizeof(weap)) {
    i = random(sizeof(weap));
    if(objectp(weap[i]))
      weap[i]->remove();
  }
  return;
}

void force_shield1(object from, object to) {
  object ob;

  seteuid(getuid());
  ob = new("/std/spells/shadows/ac_shadow");
  ob->set_shad_ac(10 + random(10));
  ob->set_expire_message("%^BOLD%^BLUE%^Your force shield goes away.");
  ob->start_shadow(from, 40);
  return;
}

void force_shield2(object from, object to) {
  object ob;

  seteuid(getuid());
  ob = new("/std/spells/shadows/ac_shadow");
  ob->set_shad_ac(20 + random(10));
  ob->set_expire_message("%^BOLD%YELLOW%^Your force shield goes away.");
  ob->start_shadow(from, 40);
  return;
}

void electricity_critical(object from, object to) {
  string crit;

  crit = sprintf("electricity %s", ({ "B", "C", "D" })[random(3)]);
  do_critical(from, to, ({ crit }) );
  return;
}

void fire_critical(object from, object to) {
  string crit;

  crit = sprintf("electricity %s", ({ "B", "C", "D" })[random(3)]);
  do_critical(from, to, ({ crit }) );
  return;
}

void plasma_crit(object from, object to) {
  string crit;

  crit = sprintf("plasma %s", ({ "B", "C", "D" })[random(3)]);
  do_critical(from, to, ({ crit }) );
  return;
}

void constriction_critical(object from, object to) {
  string crit;

  crit = sprintf("constriction %s", ({ "B", "C", "D" })[random(3)]);
  do_critical(from, to, ({ crit }) );
  return;
}

void disruption_critical(object from, object to) {
  string crit;

  crit = sprintf("disruption %s", ({ "B", "C", "D" })[random(3)]);
  do_critical(from, to, ({ crit }) );
  return;
}

void dest_pet(object what) {
  if(objectp(what)) {
    message("info", (string)what->query_short() +
      " gates back to its home plane.", environment(what));
    what->remove();
  }
  return;
}

void animate_knife_11(object from, object to) {
  object ob;

  seteuid(getuid());
  ob = new("/wizards/zortek/pet/knife");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(3)+1);
  ob->set_dur(100 + random(200));
  ob->kill_ob(to, 0);
  return;
}

void animate_short_1(object from, object to) {
  object ob;

  seteuid(getuid());
  ob = new("/wizards/zortek/pet/short");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(3)+4);
  ob->set_dur(200 + random(200));
  ob->kill_ob(to, 0);
  return;
}

void animate_long_1(object from, object to) {
  object ob;

  seteuid(getuid());
  ob = new("/wizards/zortek/pet/long");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(6);
  call_out("dest_pet", 50+random(50), ob);
  ob->kill_ob(to, 0);
  return;
}

void animate_bastard_1(object from, object to) {
  object ob;
  int x;

  seteuid(getuid());
  ob = new("/wizards/zortek/pet/bastard");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  x = random(4);
  ob->set_up(x+1);
  call_out("dest_pet", 150-(25*x), ob);
  ob->kill_ob(to, 0);
  return;
}

void animate_claymore_1(object from, object to) {
  object ob;
  int x;

  seteuid(getuid());
  ob = new("/wizards/zortek/pet/claymore");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  x = random(3);
  ob->set_up(x+4);
  call_out("dest_pet", 150-(25*x), ob);
  ob->kill_ob(to, 0);
  return;
}

void extra_a_hbeat(object from, object to) {
  from->heart_beat(1);
  return;
}

void extra_attack(object me, object you) {
  me->continue_attack();
  return;
}

void haste_me(object me, object you) {
  object ob;

  ob = new("/std/spells/shadows/haste_shadow");
  ob->start_shadow(me, 20, "%^CYAN%^You stop attacking speedily.");
  return;
}


void dest_corpse(object from, object to) {
  call_out("remove_corpse", 2, to);
  return;
}

void remove_corpse(object who) {
  object corpse;

  corpse = (object)who->query("corpse ob");
  if(corpse) corpse->remove();
  return;
}

void do_shatter(mixed *arg) {
  object env;
  string name;
  object corpse;
  int i, count;

  if(sizeof(arg) != 3) return;
  name = arg[0];
  env = arg[1];
  if(arg[2])
    corpse = (object)arg[2]->query("corpse ob");
  else corpse = 0;
  if(objectp(corpse))
    corpse->remove();
  seteuid(getuid(this_object()));
  count = random(7)+3;
  for(i = 0; i <= count; i++) {
    corpse = new("/wizards/diewarzau/crits/shards");
    corpse->set_person(name);
    corpse->move(env);
  }
  return;
}

void corrode_weapon(object from, object to) {
  object *weap;

  weap = (object *)to->query_wielded();
  if(!weap || !sizeof(weap)) return;
  weap[0]->decay_me(20+random(50));
  message("info", A_NAME+" attacks your weapon, inflicting "+
    "some damage upon it.", to);
  message("info", "You inflict some damage upon "+T_NAME+"'s "+
    " weapon.", from);
  message("info", A_NAME+" strikes "+T_NAME+"'s weapon, "+
    "damaging it.", environment(to), ({ from, to }));
  return;
}

void shatter_weapon(object from, object to) {
  object *weap;

  weap = (object *)to->query_wielded();
  if(!weap || !sizeof(weap)) return;
  message("info", A_NAME+" attacks your weapon, shattering "+
    "it completely!", to);
  message("info", "You attack "+T_NAME+"'s "+
    "weapon, shattering it completely!", from);
  message("info", A_NAME+" strikes "+T_NAME+"'s weapon, "+
    "shattering it completely!", environment(to), ({ from, to }));
  weap[0]->remove();
  return;
}

int not_shield(object item) {
  if(!item->is_armour()) return 0;
  if(!item->query_worn()) return 0;
  if((string)item->query_type() == "shield") return 0;
  return 1;
}

int shield_filter(object item) {
  if(!item->is_armour()) return 0;
  if(!item->query_worn()) return 0;
  if((string)item->query_type() == "shield") return 1;
  return 0;
}

void break_armour1(object from, object to) {
  if(random(100) <= 1) this_object()->shatter_armour(from, to);
  return;
}

void break_armour2(object from, object to) {
  if(random(100) <= 5) this_object()->shatter_armour(from, to);
  return;
}

void shatter_armour(object from, object to) {
  object *weap;
  int idx;

  weap = filter_array(all_inventory(to), "not_shield", this_object());
  if(!weap || !sizeof(weap)) return;
  message("info", A_NAME+" attacks a piece of your armour, destroying "+
    "it completely!", to);
  message("info", "You attack a piece of "+T_NAME+"'s "+
    "armour, destroying it completely!", from);
  message("info", A_NAME+" strikes a piece of "+T_NAME+"'s armour, "+
    "destroying it completely!", environment(to), ({ from, to }));
  idx = sizeof(weap);
  if(idx > 1) idx = random(idx);
  else idx = 0;
  message("info", (string)weap[idx]->query_short()+" is destroyed!",
     to);
  weap[idx]->remove();
  return;
}

void break_shield1(object from, object to) {
  if(random(100) <= 1) this_object()->shatter_shield(from, to);
  return;
}

void break_shield2(object from, object to) {
  if(random(100) <= 5) this_object()->shatter_shield(from, to);
  return;
}

void shatter_shield(object from, object to) {
  object *weap;
  int idx;

  weap = filter_array(all_inventory(to), "shield_filter", this_object());
  if(!weap || !sizeof(weap)) return;
  message("info", A_NAME+" attacks your shield, destroying "+
    "it completely!", to);
  message("info", "You attack "+T_NAME+"'s "+
    "shield, destroying it completely!", from);
  message("info", A_NAME+" strikes "+T_NAME+"'s shield, "+
    "destroying it completely!", environment(to), ({ from, to }));
  idx = sizeof(weap);
  if(idx > 1) idx = random(idx);
  else idx = 0;
  message("info", (string)weap[idx]->query_short()+" is destroyed!",
     to);
  weap[idx]->remove();
  return;
}

int armour_limb_filter(object armour, string limb) {
  string *ac_limbs;
  
  if(!armour->is_armour()) return 0;
  if(!armour->query_worn()) return 0;
  if(!(ac_limbs=(string *)armour->query_actual_limbs())) return 0;
  if(member_array(limb, ac_limbs) < 0) return 0;
  return 1;
}

void torso_no_armour(object me, object you) {
  object *inv;
  int i;

  inv = filter_array(all_inventory(you), "armour_limb_filter",
    this_object(), "torso");
  if(!inv || !(i=sizeof(inv))) return;
  while(i--) {
    message("info", (string)inv[i]->query_short()+
      " is vaporized!", environment(you));
    inv[i]->remove();
  }
  return;
}

int leg_filter(string limb) {
  string *words;

  words = explode(limb, " ");
  if(member_array("leg", words) >= 0 ||
    member_array("root", words) >= 0) return 1;
  return 0;
}

void leg_no_armour(object me, object you) {
  object *inv;
  string *limbs;
  int i;

  if(!living(you)) return;
  limbs = filter_array((string *)you->query_limbs(), "leg_filter", this_object());
  if(!limbs || !(i=sizeof(limbs))) return;
  if(i == 1) i = 0;
  else i = random(i);
  inv = filter_array(all_inventory(you), "armour_limb_filter",
    this_object(), limbs[i]);
  if(!inv || !(i=sizeof(inv))) return;
  while(i--) {
    message("info", (string)inv[i]->query_short()+
      " is vaporized!", environment(you));
    inv[i]->remove();
  }
  return;
}

void drop_all(object me, object you) {
  object *inv;
  int i;
  
  message("info", "You drop all of your possessions!", you);
  inv = all_inventory(you);
  while(i--) {
    if(inv[i]->drop()) continue;
    if(inv[i]->query_worn()) continue;
    message("info", (string)you->query_cap_name()+
      " drops "+(string)inv[i]->query_short()+".",
      environment(you), ({ you }));
    inv[i]->move(environment(you));
  }
  return;
}

void goo_janitor(object me, object you) {
    call_out("do_janitor", 2, ({ (string)you->query_name(),
	environment(you), you }));
    return;
}

void do_janitor(mixed *arg) {
  object env;
  string name;
  object corpse, jan;

  if(sizeof(arg) != 3) return;
  name = arg[0];
  env = arg[1];
  if(arg[2])
    corpse = (object)arg[2]->query("corpse ob");
  else corpse = 0;
  if(objectp(corpse))
    corpse->remove();
  seteuid(getuid(this_object()));
  if(!env) return;
  corpse = new("/wizards/diewarzau/obj/misc/puddle");
  corpse->move(env);
  corpse->set_person(name);
  jan = new("/wizards/diewarzau/obj/mon/janitor");
  jan->move(env);
  jan->set_puddle(corpse);
  message("info", "Janitor arrives.", env);
  return;
}

void frenzy(object from, object to){
int extra_attacks;
  
  extra_attack = random(4) + 3;
  while(extra_attacks--)
  {   
    message("info", from->query_cap_name() + " attacks you in a "
                    "psychotic frenzy.", to);
    message("info", "You attack " + to->query_cap_name() + " in a "
                    "psychotic frenzy.", from );
    message("info", from->query_cap_name() + " attacks " + 
                    to->query_cap_name() + " in a psychotic frenzy.",
            environment(from), ({from, to}));
    from->continue_attack();
  }
  return;
}

void leech_hp(object from, object to)
{
  int amt;
  
  amt = random(50) + 50;
  if(amt >= to->query_hp()) amt = to->query_hp()-1;
  from->add_hp(amt);
  to->add_hp(-amt);
  message("info", 
  return;
}

void leech_mp(object from, object to)
{
int amt;
  
  amt = random(50) + 50;
  if(amt >= to->query_mp()) amt = to->query_hp()-1;
  from->add_mp(amt);
  to->add_mp(-amt);
  return;
}
