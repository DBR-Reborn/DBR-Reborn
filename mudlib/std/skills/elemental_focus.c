inherit "/std/skills/skill.c";

int sk_bonus;
int med;
object shad;

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(10);
    set_fast_dev_cost(35);
    set_property("no target", 1);
}

void info() {
    message("help", "This is a potent skill that permits an Elemental Mage to focus his or her power into a single element to increase its potential when imbued into a summoned energy mass. Higher skill affects both the time required to focus and how often this skill may be utilized.\n\nSyntax: 'use elemental focus at ice'", this_player());
}

void skill_func(object from, object at, string arg) {
  object ob;
  int time;
  
  if(props["skill level"] < 0) props["skill level"] = 0;
  if((time() - (int)from->query_last_use("elemental focus")) < (3600 /
    (props["skill level"]/5+1)))
    {
    message("info", "You may only use this skill once every "+
      sprintf("%d minutes (real time).", (60 / (props["skill level"]/5+1))), from);
    remove();
    return;
  }
  if(from->query("elemental power")) {
    message("info", "You are already using elemental power.", from);
    remove();
    return;
  }
  if(from->query("elemental focus")) {
    message("info", "You are already using elemental focus.", from);
    remove();
    return;
  }
  if(from->query("grand elemental gathering")) {
    message("info", "You are already using grand elemental gathering.", from);
    remove();
    return;
  }
  if(!arg) {
    message("info", "See 'help skill elemental focus' for syntax.", from);
    remove();
    return;
  }
// heh, ummm yeah, trade is an elemental lore (TM April 2K)
if(lower_case(arg)=="trade"){
message("info", "%^YELLOW%^That's not an element, what are you dumb?", from);
remove();
return;
}

  arg = lower_case(arg);
  if(!from->query_skill(arg+" lore")) {
    message("info", "You must choose an element for which you have a lore "
      "skill.", from);
    remove();
    return;
  }
  from->set_last_use("elemental focus");
  from->set("elemental focus", 1);
  message("info", "%^CYAN%^You begin to call on the elemental focus....",
    from);
  ob = new("/std/spells/shadows/move_shadow");
  ob->set_move_func((: call_other, this_object(), "stop_med" :));
  ob->set_move_arg(from);
  med = 1;
  time = 100 - props["skill level"]/2;
  if(time < 10) time = 10;
  shad = ob;
  delayed_call("do_focus", time, from, arg);
  return;
}

void stop_med(object from) {
  if(!med) return;
  message("info", "%^CYAN%^You interrupt your focusing efforts.\n",
    from);
  if(shad) shad->external_destruct(shad);
  remove_delayed_call("do_focus");
  remove();
  return;
}

int clean_up() { return 0; }

void do_focus(object from, string arg) {
  if(!from) {
    remove();
    return;
  }
  med = 0;
  if(shad) shad->external_destruct(shad);
  message("info", "%^CYAN%^You call upon the focus of "+arg+".", from);
  sk_bonus = 30 + random(10) + random(10);
  message("info", sprintf("You receive a %d%% bonus to you %s lore skill.",
    sk_bonus, arg), from);
  arg += " lore";
  from->add_skill_bonus(arg, sk_bonus);
  delayed_call("reduce_bonus", 60, from, arg);
  return;
}

void reduce_bonus(object from, string arg) {
  if(!from) {
    remove();
    return;
  }
  if((sk_bonus - 5) <= 0) {
    from->add_skill_bonus(arg, -1 * sk_bonus);
    from->set("elemental focus", 0);
    write("Your elemental focus disappears.\n");
    remove();
    return;
  }
  sk_bonus -= 5;
  from->add_skill_bonus(arg, -5);
  delayed_call("reduce_bonus", 60, from, arg);
  return;
}

