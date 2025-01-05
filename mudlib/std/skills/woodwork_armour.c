#define WARMOUR ({ "wood-helm", "wood-plate", "wooden-armour", "wood-hand-guard",\
"wood-bracer", "wood-leg-guards", "stumps", \
"tower-shield","wall-shield", "large-shield", "small-shield", "buckler-shield", "wooden-wing-guards" \
})

inherit "/std/skills/long_term.c";

string name, type;
int wood_req;

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
"This skill is used to craft wooden armour.  You must have a wood board to do this.  "
"This is "
"a long-term skill (see 'help long-term') and may take much real time to "
"finish.  If you are interrupted, you may pick up at a later time.  "
"\nType 'help armour' to see what armour can be crafted\n"
"Usage: use woodwork armour at <board> with <armour-name>\n"
"Example: use woodwork armour at board 2 with bokken\n"
"NOTE: If you are picking up the skill after leaving off, you still need to "
"supply the armour type...this is to avoid accidentally starting over.",
        this_player());
}

//ADD
int filter_armour(object item, string type) {
  if(!item->id("wood board")) return 0;
  if(!item->query_property("progress "+name)) return 0;
  if((string)item->query_property("progress "+name) != type) return 0;
  return 1;
}
//END

void skill_func(object from, object at, string arg) {
  object *inv, tmp;
  int time, qual, wood;
  seteuid(getuid());
  arg = lower_case(arg);
  if(member_array(arg, WARMOUR) >= 0) {
    name = (string)from->query_name();
    inv = filter_array(all_inventory(from), "filter_armour",
      this_object(), arg);
    if(sizeof(inv)) at = inv[0];
    if(!at->id("wood board")) {
      message("info", "You must use this skill on a wooden board.", from);
      remove();
      return;
    }
     tmp = new("/d/damned/virtual/"+arg+".armour");
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
      name = arg;
      type = "armour";
    if(time < 500) time = 500;
       set_work_message("%^CYAN%^You fashion the wood.");
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
  //class v_table tmp;
   //float valf;
  int base_ac, bonus_ac, skill, lvl, val;

  seteuid(getuid());
  message("info", "%^CYAN%^You are finished Woodwork Armour!", from);
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
//db = load_object("/d/damned/data/armour_db");
 // tmp = (class v_table)db->get_table(name);
    val=at->query_weight();
  skill = (int)from->query_skill("woodwork armour");
  lvl = (int)from->query_level();
  //for(x=0; x < sizeof(tmp->funcs); x++)
   // if(tmp->funcs[x] == "set_ac" && sizeof(tmp->args[x]) == 1)
      // base_ac = (int)tmp->args[x][0];
    bonus_ac = val+(skill/5) + (random(skill) + lvl*2)/5 + to_int(lvl/5);
    //ob->set_ac(base_ac + bonus_ac);

  ob->set_ac(base_ac + bonus_ac + (random(skill)/5) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "crushing");
  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "fire");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/5), "cutting");

//TLNY2021 ADD
if(ob->query_material() == "/wood/abachi" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2) );
  ob->set_ac(base_ac + bonus_ac + (100+random(skill)/2), "aether");  
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "infernal");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "unholy");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "holy");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "plasma");  
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "disruption");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "electricity");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "cold");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "fire");  
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "stress");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "impact");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "strike");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "impaling");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "cutting");
  ob->set_ac(base_ac + bonus_ac + (65+random(skill)/2), "crushing");      
}
if(ob->query_material() == "/wood/aspen" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "infernal");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing"); 
}
if(ob->query_material() == "/wood/buckeye" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "unholy");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing"); 
}
if(ob->query_material() == "/wood/birch" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "holy");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing"); 
}
if(ob->query_material() == "/wood/coachwood" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "plasma");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing"); 
}
if(ob->query_material() == "/wood/dogwood" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "disruption");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing");
}
if(ob->query_material() == "/wood/willow" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "electricity");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption"); 
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing");
}
if(ob->query_material() == "/wood/elm" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "vacuum");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing");
}
if(ob->query_material() == "/wood/gum" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "cold");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing");
}
if(ob->query_material() == "/wood/limba" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "fire");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold"); 
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing");
}
if(ob->query_material() == "/wood/mahogany" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "stress");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing");
}
if(ob->query_material() == "/wood/walnut" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "impact");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing");
}
if(ob->query_material() == "/wood/oak" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "impaling");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing");
}
if(ob->query_material() == "/wood/maple" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "cutting");

  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "crushing");
}
if(ob->query_material() == "/wood/ironwood" ) {
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3) );  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/2), "crushing");
  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "aether");  
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "infernal");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "unholy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "holy");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "plasma");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "disruption");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "electricity");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "vacuum");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cold");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "fire");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "stress");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impact");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "strike");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "impaling");
  ob->set_ac(base_ac + bonus_ac + (random(skill)/3), "cutting");
}

//END
  if((int)ob->query_ac() < 1) ob->set_ac(1);
    if(intp(ob->prop("hardness"))){
  ob->set_decay_rate((int)ob->prop("hardness"));
    }
  at->remove();
  remove();
  return;
}
