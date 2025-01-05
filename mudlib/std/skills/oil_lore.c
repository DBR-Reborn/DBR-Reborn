inherit "/std/skills/long_term";
 
void create() {
    ::create();
    set_stat("constitution");
    set_dev_cost(21);
    set_fast_dev_cost(50);
    set_property("target type", "any");
    set_property("must be present", 1);
}
 
void info() {
message("help",
"This skill lets the user make a pouch of protective oil from an organ from a dissected corpse. The protective power of the oil depends upon the level of the creature that the organ was taken from. You may only have one type of oil on at a time.",
this_player());
}
 
void skill_func(object from, object at, string arg)
{

  int time;
  int skill;

  if(!at->id("organ")) {
    message("info", "You must use this skill at an organ.",
            from);
    remove();
    return;
  }

skill = props["skill level"];
time = 1600 - (skill * 8);
if(time < 500) time = 500;
  message("info", "You begin to create the oil.", from);
  set_work_message("You grind the organ into oil for a bit.");
  start_work(at, from, time);
  return;
}
 
void finish_work(object from, object at) {
  object ob;
  int power;
 

  message("info", "The organ becomes a pouch of oil ", from);
  message("info", (string)from->query_cap_name() + " does some "+
          "alchemistic rituals, and an organ becomes "+
          "a self-contained pouch of oil.",
          environment(from), ({ from }) );
  seteuid(getuid());
  ob = new("/std/tailwind/obj/oil");
  ob->set_power(at->query_organ_level());
  ob->move(from);
  at->remove();
  remove();
  return;
}
