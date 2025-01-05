#define ARMOUR ({\
"leather-vest",\
"leather-jacket",\
"leather-pants",\
"leather-glove",\
"studded-leather-vest",\
"studded-leather-jacket",\
"studded-leather-pants",\
"studded-leather-glove",\
"leather-boots",\
"leather-belt",\
"cloak",\
"hooded-cloak",\
"robe",\
"tabard",\
"leather-helmet",\
"quilted-vest", \
"leather-wing-guards", \
"cloth-wing-guards", \
"padded-glove" })

inherit "/std/skills/long_term.c";

string name, type;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(9);
    set_fast_dev_cost(26);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill is used to forge leather armour.  You must have a leather sheet to do this.  "
"This is "
"a long-term skill (see 'help long-term') and may take much real time to "
"finish.  If you are interrupted, you may pick up at a later time.  "
"\nType 'help "
"armour' for armour types.\n"
"Usage: use leather craft at <sheet> with <armour-name>\n"
"Example: use leather craft at sheet 2 with leather-pants\n"
"NOTE: If you are picking up the skill after leaving off, you still need to "
"supply the armour type...this is to avoid accidentally starting over.",
	this_player());
}

int filter_armour(object item, string type) {
  if(!item->id("sheet of leather")) return 0;
  if(!item->query_property("progress "+name)) return 0;
  if((string)item->query_property("progress "+name) != type) return 0;
  return 1;
}

void skill_func(object from, object at, string arg) {
  object *inv, tmp;
  int time, qual;

  seteuid(getuid());
  arg = lower_case(arg);
  if(member_array(arg, ARMOUR) >= 0) {
    name = (string)from->query_name();
    inv = filter_array(all_inventory(from), "filter_armour",
      this_object(), arg);
    if(sizeof(inv)) at = inv[0];
    if(!at->id("sheet of leather")) {
      message("info", "You must use this skill on a sheet of leather.", from);
      remove();
      return;
    }
    name = arg;
    type = "armour";
    tmp = new("/d/damned/virtual/"+arg+".armour");
    time = (700 + 3*(int)tmp->query_value()) / (props["skill level"]/33 + 1);
    tmp->remove();
    at->set_property("progress "+name, arg);
    if(time < 500) time = 500;
    set_work_message("%^CYAN%^You fashion the leather.");
    if(archp(this_player())){
    time = 1;
    }
    start_work(at, from, time);
    return;
  }
  message("info", "See 'help armour' for the armour you can forge.",
      from);
  remove();
  return;
}

void finish_work(object from, object at) {
  object ob;

  int base_ac, bonus_ac, skill, lvl, vl;

  seteuid(getuid());

  message("info", "%^CYAN%^You are finished crafting!", from);
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
  //ob->set_material("/misc/leather");

  skill = (int)from->query_skill("leather craft");
  lvl = (int)from->query_level();
vl=at->query_value();   

  bonus_ac = skill/5 + (random(skill) + lvl*2)/5 + to_int(lvl/5)+(random(vl)+vl);

  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/10), "aether");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/10), "infernal");  
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/10), "unholy");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/10), "holy");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/9), "plasma");  
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/9), "disruption");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/9), "electricity");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/9), "vacuum");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/5), "cold");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/5), "fire");  
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/7), "stress");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/6), "impact");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/8), "strike");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/6), "impaling");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/4), "cutting");
  ob->set_ac(vl + base_ac + bonus_ac + (random(skill)/7), "crushing"); 

if(at->query_material() == "/leather/Ghost" ) {
ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1) );

  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "aether");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "infernal");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "unholy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "holy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "plasma");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "disruption");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "electricity");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "vacuum");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "cold");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "fire");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "stress");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "impact");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "strike");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "impaling");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "cutting");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/1), "crushing"); 
}

if(at->query_material() == "/leather/Zoanthrope" ) {
ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4) );

  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "aether");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "infernal");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "unholy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "holy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "plasma");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "disruption");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "electricity");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "vacuum");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "cold");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "fire");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "stress");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "impact");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "strike");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "impaling");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "cutting");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/4), "crushing"); 
}


if(at->query_material() == "/leather/Carnifex" ) {
ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3) );

  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "aether");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "infernal");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "unholy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "holy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "plasma");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "disruption");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "electricity");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "vacuum");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "cold");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "fire");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "stress");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "impact");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "strike");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "impaling");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "cutting");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "crushing"); 
}

if(at->query_material() == "/leather/Hive Tyrant" ) {
ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2) );

  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "aether");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "infernal");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "unholy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "holy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "plasma");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "disruption");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "electricity");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "vacuum");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "cold");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "fire");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "stress");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "impact");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "strike");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "impaling");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "cutting");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "crushing"); 
}



if(at->query_material() == "/leather/Beholder" ) {
ob->set_ac(base_ac + bonus_ac + (random(vl)+random(skill)/3) );

  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "aether");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "infernal");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "unholy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "holy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "plasma");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "disruption");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "electricity");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "vacuum");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "cold");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "fire");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "stress");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "impact");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "strike");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "impaling");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "cutting");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/3), "crushing"); 
}

if(at->query_material() == "/leather/Elder Brain" ) {
ob->set_ac(base_ac + bonus_ac + (random(vl)+random(skill)/2) );

  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "aether");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "infernal");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "unholy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "holy");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "plasma");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "disruption");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "electricity");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "vacuum");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "cold");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "fire");  
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "stress");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "impact");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "strike");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "impaling");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "cutting");
  ob->set_ac(vl+base_ac + bonus_ac + (random(vl)+random(skill)/2), "crushing"); 
}

/* to add
/leather/Statue
/leather/Grom
/leather/Unworldly
/leather/Angel
/leather/Dracolich
/leather/lich
*/
//END


if((int)ob->query_ac() < 1) ob->set_ac(1);
    if(intp(ob->prop("hardness"))){
  ob->set_decay_rate((int)ob->prop("hardness"));
    }
  at->remove();
  remove();
  return;
}

