//	Some fun special results for crits.
#define AETHER_ELEMENTS ({"vacuum","electricity","fire","cold","holy","unholy"})
#define A_NAME ((string)from->query_cap_name())
#define T_NAME ((string)to->query_cap_name())
#define MONEY_TYPES ({"gold","silver","mithril","electrum","copper",\
	"platinum"})

//TLNY 2020 Remade and merged all crit code

object environment;
int times;

void pass_storm(object to, object from);
void do_element(object to,object from);

void create() {
  seteuid(getuid());
}

void shatter_me(object me, object you) {
    call_out("do_shatter", 2, ({ (string)you->query_name(),
	environment(you), you }));
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
    corpse = new("/daemon/db/crit/pet_d/shards");
    corpse->set_person(name);
    corpse->move(env);
  }
  return;
}


void blind_me(object from, object to) {
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

void increase_ac(object from, object to) {

  object ob;
  message("info","%^YELLOW%^You are given Protection temporarily%^RESET%^", (from));
  seteuid(getuid());
  ob = new("/std/spells/shadows/ac_shadow");
  ob->set_shad_ac(10 + random(10));
  ob->set_expire_message("%^YELLOW%^The protection aura about you dissipates.%^RESET%^");
  ob->start_shadow(from, 40);
  return;

}


void raise_weapon1(object from, object to) {
  object shad, weap;
  int sz;

  if(!from->query_wielded() || !(sz = sizeof((object *)from->query_wielded())))
    return;
  weap = ((object *)from->query_wielded())[random(sz)];
  shad = new("/std/spells/shadows/weapon_shadow");
  shad->set_enchantment(1+random(4));
  shad->start_shadow(weap, 50+random(25), "%^CYAN%^An aura about your weapon wears off.");
  return;
}


void raise_weapon2(object from, object to) {
  object shad, weap;
  int sz;

  if(!from->query_wielded() || !(sz = sizeof((object *)from->query_wielded())))
    return;
  weap = ((object *)from->query_wielded())[random(sz)];
  shad = new("/std/spells/shadows/weapon_shadow");
  shad->set_enchantment(4+random(4));
  shad->start_shadow(weap, 50+random(25), "%^CYAN%^An aura about your weapon wears off.");
  return;
}

void fire_crit(object from, object to) {
  string crit;

  crit = sprintf("fire %s", ({ "B", "C", "D" })[random(3)]);
  do_critical(from, to, ({ crit }) );
  return;
}


void impact_crit(object from, object to) {
  string crit;

  crit = sprintf("impact %s", ({ "B", "C", "D" })[random(3)]);
  do_critical(from, to, ({ crit }) );
  return;
}

void electricity_crit(object from, object to) {
  string crit;

  crit = sprintf("electricity %s", ({ "B", "C", "D" })[random(3)]);
  do_critical(from, to, ({ crit }) );
  return;
}

void vacuum_crit(object from, object to) {
  string crit;

  crit = sprintf("vacuum %s", ({ "B", "C", "D" })[random(3)]);
  do_critical(from, to, ({ crit }) );
  return;
}

void fire_A_crit(object from, object to) {
  do_critical(from, to, ({ "fire A" }) );
  return;
}

void impact_A_crit(object from, object to) {
  do_critical(from, to, ({ "impact A" }) );
  return;
}

void strike_A_crit(object from, object to) {
  do_critical(from, to, ({ "strike A" }) );
  return;
}

void electricity_A_crit(object from, object to) {
  do_critical(from, to, ({ "electricity A" }) );
  return;
}


void fire_E_crit(object from, object to) {
  do_critical(from, to, ({ "fire E" }) );
  return;
}

void cold_E_crit(object from, object to) {
  do_critical(from, to, ({ "cold E" }) );
  return;
}


void dest_pet(object what) {

  if(objectp(what)) {
    message("info", (string)what->query_short() +
      " winks out of existence.", environment(what));
    what->remove();
  }
  return;
}


void summon_ethereal_entity1(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/pet_d/ethereal_entity");
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Ethereal Entity");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(3)+1);
  ob->set_dur(55 + random(50));
  ob->kill_ob(to, 0);
  return;
}

void summon_unholy_ethereal_entity1(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/pet_d/unholy_ethereal_entity");
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Unholy Ethereal Entity");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(3)+1);
  ob->set_dur(55 + random(50));
  ob->kill_ob(to, 0);
  return;
}


void summon_ethereal_entity2(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/pet_d/ethereal_entity");
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Ethereal Entity");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(3)+4);
  ob->set_dur(55 + random(50));
  ob->kill_ob(to, 0);
  return;
}

void summon_unholy_ethereal_entity2(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/pet_d/_unholy_ethereal_entity");
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Unholy Ethereal Entity");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(3)+4);
  ob->set_dur(55 + random(50));
  ob->kill_ob(to, 0);
  return;
}

void summon_elder_seraph(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/pet_d/elder_seraph");
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Elder Seraph");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(50), ob);
  ob->kill_ob(to, 0);
  return;
}

void summon_lich(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/pet_d/lich");
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Lich");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(50), ob);
  ob->kill_ob(to, 0);
  return;
}

void summon_arch_angel(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/pet_d/arch_angel");
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Arch Angel");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+1);
  call_out("dest_pet", 55+random(50), ob);
  ob->kill_ob(to, 0);
  return;
}

void summon_dracolich(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/pet_d/dracolich");
              ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Dracolich");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+1);
  call_out("dest_pet", 55+random(50), ob);
  ob->kill_ob(to, 0);
  return;
}

void multitude_of_the_heavenly_host(object from, object to) {
  object ob;
  int i;
  seteuid(getuid());

  for(i=1;i<=5;i++) {
    ob = new("/daemon/db/crit/pet_d/elder_seraph");
                ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Elder Seraph");
    ob->move(environment(to));
    if(from->is_pet() && from->query_owner())
      ob->set_owner((string)from->query_owner());
    else
      ob->set_owner((string)from->query_name());
    ob->set_up(random(5)+2);
    call_out("dest_pet", random(50) + 100, ob);
    ob->kill_ob(to, 0);
    if(i >= 4) {
      ob = new("/daemon/db/crit/pet_d/arch_angel");
            ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Arch Angel");
      ob->move(environment(to));
      if(from->is_pet() && from->query_owner())
        ob->set_owner((string)from->query_owner());
      else
        ob->set_owner((string)from->query_name());
      ob->set_up(random(4)+1);
      call_out("dest_pet", random(50) + 100, ob);
      ob->kill_ob(to, 0);
    }
  }
  return;
}

void multitude_of_the_undead_host(object from, object to) {
  object ob;
  int i;
  seteuid(getuid());

  for(i=1;i<=5;i++) {
    ob = new("/daemon/db/crit/pet_d/lich");
          ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Lich");
    ob->move(environment(to));
    if(from->is_pet() && from->query_owner())
      ob->set_owner((string)from->query_owner());
    else
      ob->set_owner((string)from->query_name());
    ob->set_up(random(5)+2);
    call_out("dest_pet", random(50) + 100, ob);
    ob->kill_ob(to, 0);
    if(i >= 4) {
      ob = new("/daemon/db/crit/pet_d/dracolich");
            ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Dracolich");
      ob->move(environment(to));
      if(from->is_pet() && from->query_owner())
        ob->set_owner((string)from->query_owner());
      else
        ob->set_owner((string)from->query_name());
      ob->set_up(random(4)+1);
      call_out("dest_pet", random(50) + 100, ob);
      ob->kill_ob(to, 0);
    }
  }
  return;
}


void extra_a_hbeat(object from, object to) {
  from->heart_beat(1);
  return;
}


void extra_attack(object me, object you) {
  message("info","%^YELLOW%^Crit you attack again%^RESET%^", (me));
  me->continue_attack();
  return;
}


void haste_me(object me, object you) {
  object ob;

  ob = new("/std/spells/shadows/haste_shadow");
  ob->start_shadow(me, 20, "%^CYAN%^You stop attacking speedily.");
  return;
}


void haste_me2(object me, object you) {
  object ob;

  ob = new("/std/spells/shadows/haste_shadow");
  ob->start_shadow(me, 30, "%^CYAN%^You stop attacking speedily.");
  ob = new("/std/spells/shadows/haste_shadow");
  ob->start_shadow(me, 30, "%^CYAN%^You stop attacking speedily.");
  return;
}


void dest_corpse(object from, object to) {

  call_out("remove_corpse", 2, to);
  return;
}


void remove_corpse(object from,object to) {
	object *inv;
	if(!(int)to->is_player()) from->add_exp2((int)to->query_exp());
	to->add_hp(-((int)to->query_hp() + 10));
	if(to->is_player()) {
		times = 0;
		call_out("corpse_check",3,to,from);
	}
}

// removed old code and added new
/*
void remove_corpse(object who) {
  object corpse;

  corpse = (object)who->query("corpse ob");
  if(corpse) corpse->remove();
  return;
}
*/
// removed weapon and armour break code for now
/*
void decay_weapon(object from, object to) {
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



void break_weapon1(object from, object to) {
  if(random(100) <= 1) this_object()->shatter_weapon(from, to);
  return;
}



void break_weapon2(object from, object to) {
  if(random(100) <= 5) this_object()->shatter_weapon(from, to);
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

*/

void drop_all(object me, object you) {
  object *inv;
  int i;

  message("info", "%^YELLOW%^You drop all of your possessions!%^RESET%^", you);
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

// removed code for janitor missing code
/*
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

*/
//TLNY2020 TEST Create BEGIN
void increase_ac_holy(object from, object to) {

  object ob;
  message("info","%^YELLOW%^You are blessed with Holy protection temporarily%^RESET%^", (from));
  seteuid(getuid());
  ob = new("/std/spells/shadows/ac_shadow");
  ob->set_shad_ac(10 + random(10));
  ob->set_expire_message("%^YELLOW%^The holy aura about you dissipates.%^RESET%^");
  ob->start_shadow(from, 40);
  return;
}

void increase_ac_unholy(object from, object to) {

  object ob;
  message("info","%^B_BLUE%^You are corrupted with Unholy protection temporarily%^RESET%^", (from));
  seteuid(getuid());
  ob = new("/std/spells/shadows/ac_shadow");
  ob->set_shad_ac(10 + random(10));
  ob->set_expire_message("%^B_BLUE%^The unholy aura about you dissipates.%^RESET%^");
  ob->start_shadow(from, 40);
  return;
}

void increase_ac_infernal(object from, object to) {

  object ob;
  message("info","%^BOLD%^%^RED%^You are set a flame with infernal protection temporarily%^RESET%^", (from));
  seteuid(getuid());
  ob = new("/std/spells/shadows/ac_shadow");
  ob->set_shad_ac(10 + random(10));
  ob->set_expire_message("%^BOLD%^%^RED%^The infernal flames of protection die down.%^RESET%^");
  ob->start_shadow(from, 40);
  return;
}



void increase_str_infernal(object from, object to) {

  object ob;
  message("info","%^BOLD%^%^RED%^You are given Infernal Strength temporarily%^RESET%^", (from));
  seteuid(getuid());
  ob = new("/std/spells/shadows/stat_shadow_new");
  ob->set_stat("strength");
  ob->set_mod(10 + random(10));
  ob->set_expire_message("%^BOLD%^%^RED%^Your Infernal Strength Fades.%^RESET%^");
  ob->start_shadow(from, 40);
  return;
}

void increase_str_holy(object from, object to) {

  object ob;
  message("info","%^YELLOW%^You are blessed with Holy Strength temporarily%^RESET%^", (from));
  seteuid(getuid());
  ob = new("/std/spells/shadows/stat_shadow_new");
  ob->set_stat("strength");
  ob->set_mod(10 + random(10));
  ob->set_expire_message("%^YELLOW%^Your Holy Strength Fades.%^RESET%^");
  ob->start_shadow(from, 40);
  return;
}

void increase_str_unholy(object from, object to) {

  object ob;
  message("info","%^B_BLUE%^You are corrupted with Unholy Strength temporarily%^RESET%^", (from));
  seteuid(getuid());
  ob = new("/std/spells/shadows/stat_shadow_new");
  ob->set_stat("strength");
  ob->set_mod(10 + random(10));
  ob->set_expire_message("%^B_BLUE%^Your Unholy Strength Fades.%^RESET%^");
  ob->start_shadow(from, 40);
  return;
}

void increase_str(object from, object to) {

  object ob;
  message("info","%^YELLOW%^You are blessed with Holy Strength temporarily%^RESET%^", (from));
  seteuid(getuid());
  ob = new("/std/spells/shadows/stat_shadow_new");
  ob->set_stat("strength");
  ob->set_mod(1 + random(10));
  ob->set_expire_message("%^YELLOW%^Your Holy Strength Fades.%^RESET%^");
  ob->start_shadow(from, 40);
  return;
}

//END

//TLNY ADD in Inferal pets
void summon_impish_creature1(object from, object to) {
  object ob;

  seteuid(getuid());
  ob = new("/daemon/db/crit/pet_z/imp");
        ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Imp");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(3)+1);
  ob->set_dur(50 + random(50));
  ob->kill_ob(to, 0);
  return;
}

void summon_impish_creature2(object from, object to) {
  object ob;

  seteuid(getuid());
  ob = new("/daemon/db/crit/pet_z/imp_pet");
        ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Imp");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(3)+4);
  ob->set_dur(50 + random(50));
  ob->kill_ob(to, 0);
  return;
}
void summon_erines_devil(object from, object to) {
  object ob;

  seteuid(getuid());
  ob = new("/daemon/db/crit/pet_z/erines_pet");
        ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Erines");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(6);
  call_out("dest_pet", 55+random(50), ob);
  ob->kill_ob(to, 0);
  return;
}

void summon_devilish_noble(object from, object to) {
  object ob;
  int x;

  seteuid(getuid());
  ob = new("/daemon/db/crit/pet_z/devilish_noble");
        ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Devilish Noble");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  x = random(4);
  ob->set_up(x+1);
  call_out("dest_pet", random(50) + 60, ob);
  ob->kill_ob(to, 0);
  return;
}

void summon_devilish_noble2(object from, object to) {
  object ob;
  int x;

  seteuid(getuid());
  ob = new("/daemon/db/crit/pet_z/devilish_noble");
        ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Devilish Noble");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  x = random(3);
  ob->set_up(x+4);
  call_out("dest_pet", random(50) + 60, ob);
  ob->kill_ob(to, 0);
  return;
}

void hoards_of_hell(object from, object to) {
  object ob;
  int i;

  seteuid(getuid());
  for(i=1;i<=8;i++) {
    ob = new("/daemon/db/crit/pet_z/imp_pet");
          ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Imp");
    ob->move(environment(to));
    if(from->is_pet() && from->query_owner())
      ob->set_owner((string)from->query_owner());
    else
      ob->set_owner((string)from->query_name());
    ob->set_up(random(6)+1);
    call_out("dest_pet", random(50) + 55, ob);
    ob->kill_ob(to, 0);

    if(i >= 4) {
      ob = new("/daemon/db/crit/pet_z/erines_pet");
            ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Erines");
      ob->move(environment(to));
      if(from->is_pet() && from->query_owner())
        ob->set_owner((string)from->query_owner());
      else
        ob->set_owner((string)from->query_name());
      ob->set_up(random(5)+2);
      call_out("dest_pet", random(50) + 55, ob);
      ob->kill_ob(to, 0);
    }

    if(i >= 6) {
      ob = new("/daemon/db/crit/pet_z/devilish_noble");
            ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Devilish Noble");
      ob->move(environment(to));
      if(from->is_pet() && from->query_owner())
        ob->set_owner((string)from->query_owner());
      else
        ob->set_owner((string)from->query_name());
      ob->set_up(random(2)+5);
      call_out("dest_pet", random(50) + 55, ob);
      ob->kill_ob(to, 0);
    }
  }
  ob = new("/daemon/db/crit/pet_z/prince_pet");
      ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Devil Prince");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
     ob->set_owner((string)from->query_name());
  ob->set_up(6);
  call_out("dest_pet", random(50) + 55, ob);
  ob->kill_ob(to, 0);
  return;
}

void mad_attack(object from,object to) {
	int rounds;
	object shadow;
	rounds = 2+random(5);
	while(rounds--) {
		message("info","%^ORANGE%^%^BOLD%^"+((string)from->query_cap_name())+" attacks "+((string)to->query_cap_name())+" in a crazed, "+
			"magic induced rage!",
			environment(from),({to,from}));
		message("info","%^ORANGE%^%^BOLD%^You attack "+((string)to->query_cap_name())+" in a crazed, "+
			"magic induced rage!",from);
		message("info","%^ORANGE%^%^BOLD%^"+((string)from->query_cap_name())+" attacks you in a crazed, "+
			"magic induced rage!",to);
		from->continue_attack();
	}
}

void energy_barrier(object from,object to) {
  object ob;
  seteuid(getuid());
  ob = new("/std/spells/shadows/ac_shadow");
  ob->set_shad_ac(15 + random(25));
  ob->set_expire_message("The energy barrier around you fades away.");
  ob->start_shadow(from, 60);
  return;
}

void lower_max_hp(object from,object to) {
	object shadow;
	seteuid(getuid());
	shadow = new("/std/spells/shadows/max_hp_shadow");
	shadow->start_shadow(to,-(random(400)+100),60);
}

void rob_money(object from,object to) {
	int i;
	i = sizeof(MONEY_TYPES);
	while(i--) {
		if(to->query_money(MONEY_TYPES[i])) {
			from->add_money(MONEY_TYPES[i],
				(int)to->query_money(MONEY_TYPES[i]));
			to->add_money(MONEY_TYPES[i],
				-(int)to->query_money(MONEY_TYPES[i]));
		}
	}
	message("info","%^RED%^You have lost all the money on your person!!!",to);
}

void transfer_hp(object from,object to) {
	int amount;
	amount = random(300) + 20;
	from->add_hp(amount);
	if(((int)to->query_hp() - amount) <= 0) {
                if(!(int)to->is_player()) from->add_exp2((int)to->query_exp()/5);
		to->add_hp(-((int)to->query_hp() + 10));
		return;
	}
	to->add_hp(-amount);
}

void heavy_drop(object from,object to) {
	object *inv;
	int i;
	inv = all_inventory(to);
	i = sizeof(inv);
	while(i--) {
		if((int)inv[i]->query_weight() > 120) {
			message("info","%^B_BLUE%^"+
				capitalize((string)inv[i]->query_short())+" falls to the ground!",to);
			message("info","%^B_BLUE%^"+((string)to->query_cap_name())+" can no longer hold onto "+
				capitalize((string)inv[i]->query_short())+", so it "+
				"falls to the ground!",environment(to),({to}));
			inv[i]->move(environment(to));
		}
	}
}

void no_balance(object from,object to) {
	object ob;
	message("info","%^MAGENTA%^You begin to have serious trouble focusing on "+
				"things.",to);
	seteuid(getuid());
	ob = new("/std/spells/shadows/blur_shadow");
	ob->set_penalty(random(5)+10);
	ob->start_shadow(to,(100+random(80)),
		"%^CYAN%^You regain control of your vision.");
	call_out("do_balance",1,from,to);
}
void do_balance(object from,object to) {
	object *stuff;
	int i;
	if(!random(30)) return;
	switch(random(4)) {
		case(0):
			stuff = filter_array(map_array((string *)to->query_limbs(),
        		(: call_other, to, "query_weapon" :)),
        		(: ($1 != $2) :), 0);
        	message("info","%^MAGENTA%^In your unbalanced state you are unable to wield "+
        		"your weapons!",to);
        	i = sizeof(stuff);
        	while(i--) {
        		if(stuff[i]->query_wielded())
        			stuff[i]->__ActuallyUnwield();
        	}
        	break;
        case(1):
        	message("my_action","%^MAGENTA%^Shoot! You trip and fall down on one of "+
        		"your weapons!",to);
        	message("other_action","%^MAGENTA%^In "+(string)to->query_possessive()+
        		" unbalanced state "+(string)to->query_cap_name()+" trips and "+
        		"falls on one of his weapons.",environment(to),({to}));
        	i = random(30) + 1;
        	if(to->query_hp() - i <= 0) {
        		from->add_exp2(to->query_exp());
        		to->add_hp(-i);
        		return;
        	}
        	to->add_hp(-i);
        	break;	
        case(2):
        	message("my_action","%^MAGENTA%^You walk into something.",to);
        	message("other_action","%^MAGENTA%^"+(string)to->query_cap_name()+
        	" walks into something.",environment(to),({to}));
        	i = random(20) + 1;
        	if(to->query_hp() - i <= 0) {
        		from->add_exp2(to->query_exp());
        		to->add_hp(-i);
        		return;
        	}
        	to->add_hp(-i);
        	break;
        case(3):
        	message("my_action","%^MAGENTA%^You collapse on the ground.",to);
        	message("other_action","%^MAGENTA%^"+(string)to->query_cap_name()+
        	" collapses on the ground.",environment(to),({to}));
        	i = random(15) + 1;
        	if(to->query_hp() - i <= 0) {
        		from->add_exp2(to->query_exp());
        		to->add_hp(-i);
        		return;
        	}
        	to->add_hp(-i);
        	break;	
        }
       call_out("do_balance",2,from,to);
}

void poison_blood(object from,object to) {
	to->add_poisoning(300);
}

void lesser_unworldly(object from,object to) {
	object mon;
	seteuid(getuid());
	mon = new("/daemon/db/crit/pet_e/lesser_unworldly");
     mon->set_level((int)this_player()->query_level());
mon->set_short("["+((int)this_player()->query_name())+"s]Lesser Unworldly");
	mon->move(environment(to));
	mon->set_owner((string)from->query_name());
	mon->kill_ob(to,0);
    call_out("remove_pet",55 +random(50),mon);
}

void greater_unworldly(object from,object to) {
	object mon;
	seteuid(getuid());
	mon = new("/daemon/db/crit/pet_e/greater_unworldly");
    mon->set_level((int)this_player()->query_level());
mon->set_short("["+((int)this_player()->query_name())+"s]Greater Unworldly");
	mon->move(environment(to));
	mon->set_owner((string)from->query_name());
	mon->kill_ob(to,0);
    call_out("remove_pet",55 +random(50),mon);
	//call_out("remove_pet",3000,mon);
}

void remove_pet(object ob) {
	message("info",(string)ob->query_short()+" suddenly dissapears.",
		 environment(ob));
	ob->remove();
}

void elemental_control(object from,object to) {
	do_element(to,from);
}

void do_element(object to,object from) {
	string crit;
	int i;
	object tmp;
	i = random(30);
	if(to->query_ghost() || !i || !find_living((string)to->query_name())) {
		if(!i) message("info","%^PINK%^You feel your elemental control "+
			"fade away...",from);
		return;
	}
	i = random(2);
	tmp = present(to,environment(from));
	if(!tmp && !i) {
		message("info","%^GREEN%^%^BOLD%^"+(string)from->query_cap_name()+" uses a powerful wind to drag "+
			"you back into battle!",to);
		message("info","%^GREEN%^%^BOLD%^A powerful wind suddenly "+
			"drags "+(string)to->query_cap_name()+" away.",environment(to),
			({to}));
		message("info","%^GREEN%^%^BOLD%^"+(string)from->query_cap_name()+" uses a powerful wind to "+
			"drag "+(string)to->query_cap_name()+" back into the "+
			"room.",environment(from),({from}));
		message("info","%^GREEN%^%^BOLD%^HA! You're not about to let "+
		(string)to->query_cap_name()+""+((string)to->query_cap_name())+" get "+
			"away that easily! "+
			"You drag "+(string)to->query_objective()+" back into the room!",from);
		to->move(environment(from));
	} else {
		if(!tmp) {
			return;
		}
	}
	i = random(sizeof(AETHER_ELEMENTS));
	crit = AETHER_ELEMENTS[i];
	message("info",((string)from->query_cap_name())+" uses %^RED%^"+crit+"%^RESET%^.",
		environment(from),({from}));
	message("info","You use %^RED%^"+crit+"%^RESET%^.",
		from);
	crit = crit+" "+({"B","C","D","E"})[random(4)];
	do_critical(from, to, ({ crit }) );
	call_out("do_element",2,to,from);
}

void leave_dimension(object from,object to) {
	object where,ob;
	int n;
	n = 5;
	message("info","%^CYAN%^Several %^RED%^portals "+
		"%^RESET%^%^CAYN%^appear as reality weakens.");
	while(n--) {
		seteuid(getuid());
		ob = new("/wizards/excelsior/misc/portal");
		ob->move(environment(from));
		ob->setup_color();
	}
	to->add_hp(-((int)to->query_hp() + 30));
	message("info","%^RED%^"+(string)to->query_cap_name()+" suddenly "+
		"fades into nothingness.",environment(to),({to}));
	if(!to->is_player()) return;
	message("info","%^RED%^You find yourself transported to a very strange place.",
		to);
	where = new("/wizards/excelsior/crits/dimensional_room");
	to->move(where);
	times = 0;
	call_out("corpse_check",3,to,from);
}

void corpse_check(object who,object from) {
	object ob;
	if(!who->query_ghost()) {
		if(times > 30) return;
		call_out("corpse_check",3,who,from);
		times++;
		return;
	}
	ob = (object)who->query("corpse ob");
	if(!present(ob,environment(from))) ob->move(environment(from));
	ob->remove();
}

void summon_a1(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a1");
    ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Air Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}

void summon_a2(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a2");
      ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Water Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}

void summon_a3(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a3");
ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Earth Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}

void summon_a4(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a4");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Fire Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}

void summon_a5(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a5");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Cold Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_a6(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a6");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Wind Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_a7(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a7");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Ice Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_a8(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a8");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Electricity Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_a9(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a9");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Inertia Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_a10(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a10");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Plasma Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_a11(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/a11");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Vacid Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b1(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b1");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Air Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b2(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b2");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Water Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b3(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b3");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Earth Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b4(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b4");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Fire Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b5(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b5");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Cold Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b6(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b6");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Wind Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b7(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b7");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Ice Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b8(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b8");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Electricity Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b9(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b9");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Inertia Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b10(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b10");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Plasma Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_b11(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/b11");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Vacid Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c1(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c1");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Air Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c2(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c2");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Water Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c3(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c3");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Earth Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c4(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c4");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Fire Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c5(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c5");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Cold Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c6(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c6");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Wind Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c7(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c7");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Ice Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c8(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c8");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Electricity Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c9(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c9");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Inertia Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c10(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c10");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Plasma Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_c11(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/c11");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Vacid Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d1(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d1");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Air Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d2(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d2");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Water Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d3(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d3");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Earth Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d4(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d4");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Fire Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d5(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d5");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Cold Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d6(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d6");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Wind Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d7(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d7");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Ice Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d8(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d8");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Electricity Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d9(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d9");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Inertia Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d10(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d10");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Plasma Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_d11(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/d11");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Vacid Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e1(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e1");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Air Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e2(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e2");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Water Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e3(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e3");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Earth Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e4(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e4");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Fire Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e5(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e5");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Cold Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e6(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e6");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Wind Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e7(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e7");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Ice Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e8(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e8");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Electricity Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e9(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e9");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Inertia Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e10(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e10");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Plasma Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}
void summon_e11(object from, object to) {
  object ob;
  seteuid(getuid());

  ob = new("/daemon/db/crit/mon/e11");
  ob->set_level((int)this_player()->query_level());
ob->set_short("["+((int)this_player()->query_name())+"s]Vacid Elemental");
  ob->move(environment(to));
  if(from->is_pet() && from->query_owner())
    ob->set_owner((string)from->query_owner());
  else
    ob->set_owner((string)from->query_name());
  ob->set_up(random(4)+2);
  call_out("dest_pet", 55+random(25), ob);
  ob->kill_ob(to, 0);
  return;
}

