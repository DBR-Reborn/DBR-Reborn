inherit "/std/skills/long_term.c";

int skill;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(9);
    set_fast_dev_cost(19);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"Shamen, being the nature-lovers they are, spend lots of time in the wilderness. Since they can't always find water in the wilderness, they make waterskins to hold water whenever they do find it. The quality of the leather affects how much the skin can hold, while the skill enables the user to make them faster.\n"
"Syntax: use make waterskin at <leather-sheet>",
	this_player());
}

void skill_func(object from, object at, string arg) {
  string *tmp, fname;
  int time;

  if(!at->id("sheet of leather")) {
    message("info", "This skill must be used on a sheet of leather.", from);
    remove();
    return;
  }

  skill = props["skill level"];
  time = 800 - (skill * 6);
  if(time < 250) time = 250;
  message("info", "%^CYAN%^%^BOLD%^You begin to make a waterskin.", from);
  set_work_message("%^CYAN%^You fool with the leather, and make some stitches.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
object ob;  
  message("info", "You sew a last stitch on to the leather, and find yourself with a waterskin!",
    from);
  ob=new("/std/tailwind/obj/shaman_waterskin");
  ob->set_capacity(at->query_level()/2);
  ob->move(from);
  at->remove();
  remove();
  return;
}

