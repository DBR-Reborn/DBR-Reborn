inherit "/std/skills/long_term";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(4);
    set_fast_dev_cost(10);
    set_property("target type", "any");
    set_property("must be present",1);
}

void info() {
message("help",
"This skill allows the tinker to carve his mark into an item.  "
"IE name the item to whatever he/she wishes.  Higher skill levels  "
"will shorten the time on this skill. "
"The format for this skill is as follows: "
"use engrave at <item> with <desc> "
"Example: use engrave at sword with Excalibur"
"This is a long-term skill (see help long-term), and may take much real "
"time to cast.  If you are interrupted while working, "
"you may pick up again at a later time.",
this_player());
}

void skill_func(object from, object at, string arg) {
  int time,mod;
  string *ids, id;
  if(at->is_living()) {
    message("info", "You cannot engrave on a living thing!",from);
    remove();
    return;
  }
  ids=at->query_id();
  id=ids[0];
  at->set_property("new desc", arg+" {"+id+"}");
  set_work_message("You engrave on the weapon.");
  time = (3600/from->query_skill("engrave"))+1;
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  int ench, i, idx;
  mixed tmp;
from->add_exp2(5 * props["skill level"]+(this_player()->query_level()*100));
  message("info", "You are finished engraving!", from);
  at->set_short((string)at->query_property("new desc"));
  remove();
  return;
}


