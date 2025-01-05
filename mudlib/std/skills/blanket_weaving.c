inherit "/std/skills/long_term.c";

int skill;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(6);
    set_fast_dev_cost(13);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill enables the user to make a warm and comfortable blanket. You need a sheet of leather for it. This skill takes much real time to do.\n",
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
  message("info", "%^CYAN%^%^BOLD%^You begin to make a blanket.", from);
  set_work_message("%^CYAN%^You take some warm down and stuff the leather with it.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
object ob;  
  message("info", "You finally finish making the blanket!",
    from);
  ob=new("/std/tailwind/obj/blanket");
//  ob->set_capacity(at->query_level()/2);
  ob->move(from);
  at->remove();
  remove();
  return;
}

