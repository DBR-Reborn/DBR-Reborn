#define WOOD ({ "quarter-staff", "bokken", "wooden-axe", "stick", \
 "club", "wooden-spear", "wooden-two-handed-sword", "nunchucks", \
 "three-section-staff", "kanabou", "tonfa" })

inherit "/std/skills/long_term.c";

string name, type;
string name2;
int wood_req;
int qz;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(9);
    set_fast_dev_cost(21);
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("prereq", "carpentry");
}

void info() {
message("help",
"This skill is used to craft wooden weapons.  You must have a wood board to do this.  "
"This is "
"a long-term skill (see 'help long-term') and may take much real time to "
"finish.  If you are interrupted, you may pick up at a later time.  "
"\nType 'help weapons' to see what weapons can be crafted\n"
"Usage: use woodwork weapon at <board> with <weapon-name>\n"
"Example: use woodwork weapon at board 2 with quarter-staff\n"
"NOTE: If you are picking up the skill after leaving off, you still need to "
"supply the weapon type...this is to avoid accidentally starting over.",
        this_player());
}

int filter_weapon(object item, string type) {
  if(!item->id("wood board")) return 0;
  if(!item->query_property("progress "+name)) return 0;
  if((string)item->query_property("progress "+name) != type) return 0;
  return 1;
}


void skill_func(object from, object at, string arg) {
  object *inv, tmp;
  int time, qual, wood;
  seteuid(getuid());
  arg = lower_case(arg);
  if(member_array(arg, WOOD) >= 0) {
    name = (string)from->query_name();
    inv = filter_array(all_inventory(from), "filter_weapon",
      this_object(), arg);
    if(sizeof(inv)) at = inv[0];
    if(!at->id("wood board")) {
      message("info", "You must use this skill on a wooden board.", from);
      remove();
      return;
    }
    tmp = new("/d/damned/virtual/"+arg+"_2.weapon");
    time = (7000 + 3*(int)tmp->query_value()) / (props["skill level"]/16 + 1);
    wood_req = (int)tmp->query_property("wood needed");
    tmp->remove();
    wood = (int)at->query_wood();
    if(wood < wood_req) {
        message("info","That board is not big enough to make the weapon you "+
                "wish to make", from);
        remove();
        return;
    }    
    at->set_property("progress "+name, arg);
    qual = props["skill level"]/24 + random(2+props["skill level"]/26);
    if(qual < 0) qual = 0;
    if(qual > 6) qual = 6;
    name = sprintf("%s_%d", arg, qual);
    name2 = sprintf("%s", arg);
    qz = ("%d", qual);
    type = "weapon";
    if(time < 500) time = 500;
    set_work_message("%^CYAN%^You fashion the wood.");
if(archp(this_player())){
time = 1;
}
    start_work(at, from, time);
    return;
  }

  message("info", "See 'help weapons' and 'help armour' for the weapons and armour you can forge.",
      from);
  remove();
  return;
}

void finish_work(object from, object at) {
  object ob;
   int base_wc, bonus_wc, skill, lvl, val;
  seteuid(getuid());
  message("info", "%^CYAN%^You are finished Woodwork Weapon!", from);
  ob = new("/d/damned/virtual/"+name+"."+type);
  ob->move(from);
  if(!present(ob,from)) {
        message("info","%^CYAN%^You cannot carry your creation so it falls to the ground.",
                from);
        ob->move(environment(from));
  }
from->add_exp2(25 * props["skill level"]+(this_player()->query_level()*100));
  ob->set_property("extra long","Crafted by: "+from->query_cap_name()+" with "+at->query_short());
  ob->set_material(replace_string((string)at->query_material(), "/", "", 1));
//ADD
    val=at->query_weight();
  skill = (int)from->query_skill("woodwork weapon");
  lvl = (int)from->query_level();
   if(skill > lvl*3) {
    bonus_wc = val+(skill/12) + (random(skill - lvl*2) + lvl*2)/10 + to_int(lvl/5);
  }
  else {
    bonus_wc = val+(skill/12) + random(skill)/12 + to_int(lvl/6);
  }

//TLNY2021 add
if(ob->query_material() == "/wood/abachi" ) {
  ob->set_wc(base_wc + bonus_wc + 6+(qz*2), "aether");
}
if(ob->query_material() == "/wood/aspen" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "infernal");
}
if(ob->query_material() == "/wood/buckeye" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "unholy");
}
if(ob->query_material() == "/wood/birch" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "holy");
}
if(ob->query_material() == "/wood/coachwood" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "plasma");
}
if(ob->query_material() == "/wood/dogwood" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "disruption");
}
if(ob->query_material() == "/wood/willow" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "electricity");
}
if(ob->query_material() == "/wood/elm" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "vacuum");
}
if(ob->query_material() == "/wood/gum" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "reflection");
}
if(ob->query_material() == "/wood/limba" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "time");
}
if(ob->query_material() == "/wood/mahogany" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "acid");
}
if(ob->query_material() == "/wood/walnut" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "impact");
}
if(ob->query_material() == "/wood/oak" ) {
  ob->set_wc(base_wc + bonus_wc + 4+(qz*2), "fire");
}
if(ob->query_material() == "/wood/maple" ) {
  ob->set_wc(base_wc + bonus_wc + 4+(qz*2), "cold");
}
if(ob->query_material() == "/wood/ironwood" ) {
  ob->set_wc(base_wc + bonus_wc + 4+(qz*2), "crushing");
}
//END
    if(name2 == "quarter-staff") {
  ob->set_wc(base_wc + bonus_wc + 8+(qz*6), "crushing");
    }  
    if(name2 == "bokken") {
  ob->set_wc(base_wc + bonus_wc + 6+(qz*2), "impaling");
  ob->set_wc(base_wc + bonus_wc + 10+(qz*2), "cutting");
    }
    if(name2 == "wooden-axe") {
  ob->set_wc(base_wc + bonus_wc + 9+(qz*2), "cutting");
  ob->set_wc(base_wc + bonus_wc + 15+(qz*2), "crushing");
    }
    if(name2 == "stick") {
  ob->set_wc(base_wc + bonus_wc + 15+(qz*2), "impaling");
  ob->set_wc(base_wc + bonus_wc + 1+(qz*2), "cutting");
    }
    if(name2 == "club") {
  ob->set_wc(base_wc + bonus_wc + 10+(qz*2), "crushing");
    }
    if(name2 == "wooden-spear") {
  ob->set_wc(base_wc + bonus_wc + 16+(qz*6), "impaling");
    }
    if(name2 == "wooden-two-handed-sword") {
  ob->set_wc(base_wc + bonus_wc + 9+(qz*6), "impaling");
  ob->set_wc(base_wc + bonus_wc + 18+(qz*6), "cutting");
    }
    if(name2 == "nunchucks") {
  ob->set_wc(base_wc + bonus_wc + 13+(qz*2), "crushing");
    }
    if(name2 == "three-section-staff") {
  ob->set_wc(base_wc + bonus_wc + 20+(qz*8), "crushing");
    }
    if(name2 == "kanabou") {
  ob->set_wc(base_wc + bonus_wc + 30+(qz*6), "crushing");
  ob->set_wc(base_wc + bonus_wc + 30+(qz*6), "impact");
    }
    if(name2 == "tonfa") {
  ob->set_wc(base_wc + bonus_wc + 10+(qz*2), "crushing");
  ob->set_wc(base_wc + bonus_wc + 12+(qz*2), "impaling");
    }
//END
    if(intp(ob->prop("hardness"))){
  ob->set_decay_rate((int)ob->prop("hardness"));
    }
  at->remove();
  remove();
  return;
}
