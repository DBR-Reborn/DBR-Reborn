// Added basic ability to restore weapon quality with a spare ingot
// Tigwyk
// 2020-06-12

inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(11);
    set_fast_dev_cost(27);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This spell may be used to keep weapons in good repair.  "
"Weapons go down in quality after repeated usage, but repairing "
"them periodically can delay, or even prevent this loss.  Note that "
"once the weapon has lost a quality level, this skill WILL NOT increase "
"the quality back to the original level, only delay further decay.",
this_player());
}


void skill_func(object from, object at, string arg) {
  int max, rep;
  object ingot;
  if(!at->is_weapon()) {
    message("info", "That is not a weapon!", from);
    remove();
    return;
  }
  if(from->query("repair weapon")) {
    message("info", "You can only do that once at a time.", from);
    remove();
    return;
  }

  max = (int)at->query_decay_rate();
  max -= props["skill level"] * max /100;

  if(max < 0) max = 0;
  if(((int)at->query_decay_status() <= max) && ((int)at->query_quality() == 6)) {
    message("info", "You have repaired that weapon as much as your skill allows.",
      from);
    remove();
    return;
  }

  if(((int)at->query_decay_status() == 0) && ((int)at->query_quality() < 6)) {
    //message("info", "You might be able to restore this weapon's quality.", from);
    ingot = present("ingot", from);
    if(!ingot) {
      message("info", "You do not have the required raw materials to restore this weapon's quality.", from);
      remove();
      return;
    } 
  }

  max = (int)at->query_decay_rate() - max;
  rep = (props["skill level"]/2 + random(props["skill level"]/2))*max / 100;
  if((int)at->query_decay_status() <= rep) rep = (int)at->query_decay_status();
  message("info", "%^CYAN%^%^BOLD%^You begin repairing the weapon...", from);
  message("info", "%^CYAN%^"+(string)from->query_cap_name() + " begins repairing a weapon.",
      environment(from), ({ from }));
  from->set("repair weapon", 1);
  call_out("repair", 10, rep, at, from);
  return;
}

void repair(int rep, object at, object from) {
  object ingot;
  if(from) from->set("repair weapon", 0);
  if(!present(at, from) && !present(at, environment(from))) {
    message("info", "%^CYAN%^%^BOLD%^You have lost the weapon...the skill fails.",
        from);
    remove();
    return;
  }
  if(at->query_decay_status() == 0 && at->query_quality() < 6 && (ingot = present("ingot", from))) {
    message("info","You use up a spare ingot.", from);
    at->set_quality(at->query_quality()+1);
    ingot->remove();
  }
  message("info", "%^CYAN%^%^BOLD%^You complete the repairs.", from);
  message("info", "%^CYAN%^"+(string)from->query_cap_name() + " finishes repairing a weapon.",
      environment(from), ({ from }));
  at->repair(rep);
  remove();
  return;
}


