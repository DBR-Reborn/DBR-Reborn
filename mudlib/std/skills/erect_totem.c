inherit "/std/skills/long_term.c";

int skill;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(15);
    set_fast_dev_cost(29);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"Sometimes, Shamen will settle down in a more permenant home. In order not to lose their touch with nature, they erect large totems of nature. Magic energy can be deposited into these totems, and withdrawn. Anyone can do this. The Shaman requires a board of wood to make this totem. This skill is a long-term skill, and takes much real time. The totem is placed wherever you are when the skill finishes - be careful, because you cannot move it!\n"
"Syntax: use make totem at <board>",
	this_player());
}

void skill_func(object from, object at, string arg) {
  string *tmp, fname;
  int time;

if(present("totem", environment(from))) {
   message("info", "You may only build one totem per room.", from);
return 0;
}

  if(!at->id("board")) {
    message("info", "This skill must be used on a wooden board.", from);
    remove();
    return;
  }

  skill = props["skill level"];
  time = 2000 - (skill * 8);
  if(time < 600) time = 600;
  if(wizardp(from)) time=0;
  message("info", "%^CYAN%^%^BOLD%^You begin to carve out a totem from the board.", from);
  set_work_message("%^CYAN%^You make a carving into the intricate design of the totem.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
object ob;  

if(present("totem", environment(from))) {
   message("info", "You may only build one totem per room.", from);
return 0;
}

  message("info", "You make a final carve, and the totem is finished!",
    from);
  ob=new("/std/tailwind/obj/shaman_totem");

switch(at->query_material()) {
case "/wood/wood":
ob->set_capacity(10*this_player()->query_skill("erect totem"));
break;
case "/wood/ridgewood":
ob->set_capacity(10*this_player()->query_skill("erect totem")*(11/10));
break;
case "/wood/ironwood":
ob->set_capacity(10*this_player()->query_skill("erect totem")*(12/10));
break;
case "/wood/bluewood":
ob->set_capacity(10*this_player()->query_skill("erect totem")*(13/10));
break;
case "/wood/icetree":
ob->set_capacity(10*this_player()->query_skill("erect totem")*(14/10));
break;
case "/wood/demontimber":
ob->set_capacity(10*this_player()->query_skill("erect totem")*(15/10));
break;
default:
ob->set_capacity(10*this_player()->query_skill("erect totem"));
break;
}
  ob->move(environment(from));
  at->remove();
  "/adm/daemon/save_items_d"->update_lockers(environment(ob));
  remove();
  return;
}

