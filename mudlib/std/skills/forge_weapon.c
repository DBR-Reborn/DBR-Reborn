#define METAL ({\
"dagger", \
"knife", \
"spiked-gauntlet", \
"short-sword", \
"long-sword", \
"bastard-sword", \
"two-handed-sword", \
"scimitar", \
"stiletto", \
"footman's-mace",\
"broad-sword", \
"rapier",\
"brass-knuckles" })

#define BOTH ({ \
"battle-axe", \
"footman's-flail", \
"glaive", \
"halberd", \
"hammer", \
"hand-axe", \
"military-pick", \
"morning-star", \
"shod-staff", \
"spear", \
"trident", \
"war-hammer" })


inherit "/std/skills/long_term";
string name2;
string name, type,what;
object board;
int qz;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(12);
    set_fast_dev_cost(35);
    set_property("prereq", "blacksmith");
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill is used to forge metal weapons out of any metal, even magical metals.  In order to forge weapons, "
"you need a weapon blank.  Some weapons have wooden components, and "
"require both carpentry skill and a wooden board to fashion.  This is "
"a long-term skill (see 'help long-term') and may take much real time to "
"finish.  If you are interrupted, you may pick up at a later time.  "
"\nType 'help weapons' to see what weapons can be forged.\n"
"Usage: use forge weapon at <blank> with <weapon-name>\n"
"Example: use forge weapon at blank 2 with long-sword\n"
"NOTE: If you are picking up the skill after leaving off, you still need to "
"supply the weapon type...this is to avoid accidentally starting over.",
	this_player());
}

int filter_board(object ob) {
	if(!ob->id("board")) return 0;
	if(ob->query_wood() <= 0) return 0;
	return 1;
}

object find_greatest_board(object where) {
	object *inv2, big;
	int n,i;
	inv2 = filter_array(all_inventory(where),"filter_board",this_object());
    i = sizeof(inv2);
    n = 0;
    i--;
    while(i > -1) {
    	if((int)inv2[i]->query_wood() > n) {
    		n = (int)inv2[i]->query_wood();
    		big = inv2[i]
;
    	}
    	i--;
    }
    return big;
}

int filter_weapon(object item, string type) {
  if(!item->id("weapon blank")) return 0;
  if(!item->query_property("progress "+name)) return 0;
  if((string)item->query_property("progress "+name) != type) return 0;
  return 1;
}

void skill_func(object from, object at, string arg) {
  object *inv, tmp;
  int time, qual, mod,wood_req;
  seteuid(getuid());
  arg = lower_case(arg);
   
  if(member_array(arg, METAL + BOTH) >= 0) {
    if(member_array(arg, BOTH) >= 0 && (int)from->query_skill("carpentry") <=
        0) {
      message("info", "Since this weapon has wooden componenets, you must also "+
            "have carpentry skill to forge it.", from);
      remove();
      return;
    }
    name = (string)from->query_name();
    inv = filter_array(all_inventory(from), "filter_weapon",
      this_object(), arg);
    if(sizeof(inv)) at = inv[0];
    if(!at->id("weapon blank")) {
      message("info", "You must use this skill on a weapon blank.", from);
      remove();
      return;
    }
    if(!present("greater forge", environment(from))) {
      message("info", "You must be in a room with a greater forge to use this skill!",
          from);
      remove();
      return;
    }

    if(member_array(arg, BOTH) >= 0) {
    	if(find_greatest_board(from)) {
    		board = find_greatest_board(from);
    	} else {
    		message("info","You need a board in your inventory to make this "+
    			"weapon type.",from);
    		remove();
    		return;
    	}
    	mod = (int)from->query_skill("carpentry");
    	mod = ((mod+1)/16)+3;
    } else {
    	mod = props["skill level"]/16 + 1;
    }
    tmp = new("/d/damned/virtual/"+arg+"_2.weapon");
    time = (7250 + 3*(int)tmp->query_value()) / mod;
    if(member_array(arg, BOTH) >= 0) {
    	wood_req = (int)tmp->query_property("wood needed");
    }
    tmp->remove();
    tmp = new("/wizards/diewarzau/obj/misc/ingot");
    tmp->set_material(replace_string((string)at->query_material(), "/", "", 1));
    time *= to_int(pow(to_float((int)tmp->query_value()/10), 0.4));
    tmp->remove();
    if(member_array(arg, BOTH) >= 0) {
    	if(wood_req > (int)board->query_wood()) {
    		message("info","Your largest board is too small for this weapon "+
    			"type.",from);
    		remove();
    		return;
    	}
    }
    at->set_property("progress "+name, arg);
    qual = props["skill level"]/24 + 1 + random(2+props["skill level"]/26);
    if(qual < 0) qual = 0;
    if(qual > 6) qual = 6;
    name = sprintf("%s_%d", arg, qual);
    name2 = sprintf("%s", arg);
    qz = ("%d", qual);
    type = "weapon";
    set_work_message("%^CYAN%^You pound on the weapon blank.");
    time /= 2;
    if(time < 500) time = 500;
if(archp(this_player())){
time = 1;
}
    start_work(at, from, time);
    return;
  }
  message("info", "See 'help weapons' for the weapons you can forge.",
      from);
  remove();
  return;
}

void finish_work(object from, object at) {
  object ob, ob2, ob3;
 // class v_table tmp;
  float valf;
  int val, base_wc, bonus_wc, skill, lvl, ival;
  seteuid(getuid());

//add TLNY2022
   if(!present("greater forge", environment(from))) {
    message("info", "You moved! You must stay in the room with a greater forge to finish forging your weapon!", from);
    remove();
    return;
  }
//end

  if(member_array(what, BOTH) >= 0) {
  	if(!present(board,from)) {
  		if(!find_greatest_board(from)) {
  			message("info","You no longer have a board in your inventory! You "+
  				"fail to build your weapon.",from);
  			remove();
  			return;
  		}
  		board = find_greatest_board(from);
  	}
  }	
  ob = new("/d/damned/virtual/"+name+"."+type);
  if (member_array(what, BOTH) >= 0) {
  	if((int)board->query_wood() < (int)ob->query_property("wood needed")) {
  		message("info","%^CYAN%^You no longer have enough wood in your inventory to "+
  			"complete the weapon. Your skill fails.",from);
  		remove();
  		ob->remove();
  		return;
  	} else {
  		board->add_wood(-(int)ob->query_property("wood needed"));
  	}
  }
  message("info", "%^CYAN%^You are finished forging!", from);
  ob2 = new("/std/Object");
  ob2->set_material("metal/iron");
  ob3 = new("/std/Object");
  ob3->set_material(replace_string((string)at->query_material(), "/", "", 1));
  ob->move(from);
   if(!present(ob,from)) {
  	message("info","%^CYAN%^You cannot carry your creation so it falls to the ground.",
  		from);
  	ob->move(environment(from));
  }
  if(ob->query_value()) {
    val = (int)ob->query_value();
    val = val * (int)ob3->prop("value") / (int)ob2->prop("value");
    val = val/350;
    ob->set_value(val);
from->add_exp2(25 * props["skill level"]+(this_player()->query_level()*100));
    //from->add_exp2(1000 + val);
  } else if(ob->query_float_value() && (float)ob->query_float_value() > 0.0) {
    valf = (float)ob->query_float_value();
    valf *= to_float((int)ob3->prop("value")) / to_float((int)ob2->prop("value"));
    ob->set_float_value(valf);
from->add_exp2(15 * props["skill level"]+(this_player()->query_level()*100));
    //from->add_exp2(975);
  }
  ob2->remove();
  ob3->remove();
  ob->set_property("extra long","This weapon was forged by: "+from->query_cap_name()+" with "+at->query_short());
  ob->set_material(replace_string((string)at->query_material(), "/", "", 1));
  //add
// TLNY2020 add
  //db = load_object("/d/damned/data/weapon_db");
  //tmp = (class v_table)db->get_table(name);
  skill = (int)from->query_skill("forge weapon");
  lvl = (int)from->query_level();
    ival=at->query_weight();
  //for(x=0; x < sizeof(tmp->funcs); x++)
   // if(tmp->funcs[x] == "set_wc" && sizeof(tmp->args[x]) == 1)
      // base_wc = (int)tmp->args[x][0];
  if(skill > lvl*3) {
    bonus_wc = ival+(skill/12) + (random(skill - lvl*2) + lvl*2)/10 + to_int(lvl/5);
  }
  else {
    bonus_wc = ival+(skill/12) + random(skill)/12 + to_int(lvl/6);
  }
//TLNY2021 add
if(ob->query_material() == "/metal/eog" ) {
  ob->set_wc(base_wc + bonus_wc + 6+(qz*2), "aether");
}
if(ob->query_material() == "/metal/eonmite" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "infernal");
}
if(ob->query_material() == "/metal/iysaughton" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "disruption");
}
if(ob->query_material() == "/metal/platnite" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "electricity");
}
if(ob->query_material() == "/metal/mithril" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "fire");
}
if(ob->query_material() == "/metal/elrodnite" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "cold");
}
if(ob->query_material() == "/metal/inniculmoid" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "impact");
}
if(ob->query_material() == "/metal/raysorite" ) {
  ob->set_wc(base_wc + bonus_wc + 5+(qz*2), "stress");
}

//END

    if(name2 == "bastard-sword") {
  ob->set_wc(base_wc + bonus_wc + 6+(qz*2), "impaling");
  ob->set_wc(base_wc + bonus_wc + 14+(qz*2), "cutting");
    }  
    if(name2 == "broad-sword") {
  ob->set_wc(base_wc + bonus_wc + 12+(qz*2), "impaling");
  ob->set_wc(base_wc + bonus_wc + 4+(qz*2), "cutting");
    }
    if(name2 == "dagger") {
  ob->set_wc(base_wc + bonus_wc + 4+(qz*2), "impaling");
    }
    if(name2 == "knife") {
  ob->set_wc(base_wc + bonus_wc + 4+(qz*2), "impaling");;
    }
    if(name2 == "long-sword") {
  ob->set_wc(base_wc + bonus_wc + 10+(qz*2), "cutting");
  ob->set_wc(base_wc + bonus_wc + 6+(qz*2), "impaling");
    }
    if(name2 == "spiked-gauntlet") {
  ob->set_wc(base_wc + bonus_wc + 15+(qz*2), "cutting");
  ob->set_wc(base_wc + bonus_wc + 4+(qz*2), "impaling");
    }
    if(name2 == "brass-knuckles") {
  ob->set_wc(base_wc + bonus_wc + 10+(qz*2), "crushing");
    }
    if(name2 == "rapier") {
  ob->set_wc(base_wc + bonus_wc + 18+(qz*2), "impaling");
    }
    if(name2 == "scimitar") {
  ob->set_wc(base_wc + bonus_wc + 14+(qz*2), "cutting");
  ob->set_wc(base_wc + bonus_wc + 3+(qz*2), "impaling");
    }
    if(name2 == "short-sword") {
  ob->set_wc(base_wc + bonus_wc + 7+(qz*2), "cutting");
  ob->set_wc(base_wc + bonus_wc + 4+(qz*2), "impaling");
    }
    if(name2 == "stiletto") {
  ob->set_wc(base_wc + bonus_wc + 4+(qz*2), "impaling");
    }
    if(name2 == "two-handed-sword") {
  ob->set_wc(base_wc + bonus_wc + 18+(qz*2), "cutting");
  ob->set_wc(base_wc + bonus_wc + 9+(qz*2), "impaling");
    }
    if(name2 == "footman's-mace") {
  ob->set_wc(base_wc + bonus_wc + 10+(qz*2), "crushing");
    }
//Metal & WOOD
    if(name2 == "battle-axe") {
  ob->set_wc(base_wc + bonus_wc + 10+(qz*2), "cutting");
    }
    if(name2 == "footman's-flail") {
  ob->set_wc(base_wc + bonus_wc + 11+(qz*2), "crushing");
    }
    if(name2 == "glaive") {
  ob->set_wc(base_wc + bonus_wc + 15+(qz*2), "cutting");
    }
    if(name2 == "trident") {
  ob->set_wc(base_wc + bonus_wc + 16+(qz*2), "impaling");
    }
    if(name2 == "war-hammer") {
  ob->set_wc(base_wc + bonus_wc + 20+(qz*2), "crushing");
    }
    if(name2 == "halberd") {
  ob->set_wc(base_wc + bonus_wc + 15+(qz*2), "cutting");
  ob->set_wc(base_wc + bonus_wc + 8+(qz*2), "impaling");
    }
    if(name2 == "hammer") {
  ob->set_wc(base_wc + bonus_wc + 12+(qz*2), "crushing");
    }
    if(name2 == "hand-axe") {
  ob->set_wc(base_wc + bonus_wc + 6+(qz*2), "cuitting");
    }
    if(name2 == "military-pick") {
  ob->set_wc(base_wc + bonus_wc + 16+(qz*2), "impaling");
    }
    if(name2 == "morning-star") {
  ob->set_wc(base_wc + bonus_wc + 13+(qz*2), "crushing");
    }
    if(name2 == "shod-staff") {
  ob->set_wc(base_wc + bonus_wc + 15+(qz*2), "crushing");
    }
    if(name2 == "spear") {
  ob->set_wc(base_wc + bonus_wc + 15+(qz*2), "impaling");
    }
  //END
  if(intp(ob->prop("hardness")))
    ob->set_decay_rate((int)ob->prop("hardness"));
  at->remove();
  remove();
  return;
}



