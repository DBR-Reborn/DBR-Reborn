#define WOOD ({ "quarter-staff", "bokken", "wooden-axe", "stick", \
 "club", "wooden-spear", "wooden-two-handed-sword", "nunchucks", \
 "three-section-staff", "kanabou", "tonfa" })

#define WARMOUR ({ "wood-helm", "wood-plate", "wooden-armour", "wood-hand-guard",\
"wood-bracer", "wood-leg-guards", "stumps", \
"tower-shield","wall-shield", "large-shield", "small-shield", "buckler-shield", \
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
}

void info() {
message("help",
"This skill is used to forge wooden weapons or wooden armour.  You must have a wood board to do this.  "
"This is "
"a long-term skill (see 'help long-term') and may take much real time to "
"finish.  If you are interrupted, you may pick up at a later time.  "
"\nType 'help weapons' to see what weapons can be forged and 'help "
"armour' for armour.\n"
"Usage: use carpentry at <board> with <weapon-name>\n"
"Example: use carpentry at board 2 with quarter-staff\n"
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
    type = "weapon";
    set_work_message("%^CYAN%^You fashion the wood.");
if(archp(this_player())){
time = 1;
}
    start_work(at, from, time);
    return;
  }
//ADD
 else if(member_array(arg, WARMOUR) >= 0) {
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
       set_work_message("%^CYAN%^You fashion the wood.");
    start_work(at, from, time);
    return;
  }
//END

  message("info", "See 'help weapons' and 'help armour' for the weapons and armour you can forge.",
      from);
  remove();
  return;
}

void finish_work(object from, object at) {
  object ob;
  seteuid(getuid());
  message("info", "%^CYAN%^You are finished carpentering!", from);
  ob = new("/d/damned/virtual/"+name+"."+type);
  ob->move(from);
  if(!present(ob,from)) {
        message("info","%^CYAN%^You cannot carry your creation so it falls to the ground.",
                from);
        ob->move(environment(from));
  }
from->add_exp2(5 * props["skill level"]+(this_player()->query_level()*100));
  //from->add_exp2(5 * props["skill level"]);
  ob->set_property("extra long","Crafted by: "+from->query_cap_name());
  ob->set_material(replace_string((string)at->query_material(), "/", "", 1));
    if(intp(ob->prop("hardness"))){
  ob->set_decay_rate((int)ob->prop("hardness"));
    }
  at->remove();
  remove();
  return;
}
