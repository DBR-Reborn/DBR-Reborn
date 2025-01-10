#include <clock.h>

inherit "/std/skills/long_term.c";

object ob;
float mineral_bonus_check(string materialname);

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
"The Royal-Infantry specializes in highly-effective combat tactics. Putting spikes on a shield for maximum shield bashing potential is one of those tactics. By doing this, the infantryman can impale his enemy on his shield, doing lots of bloody damage. The kind of weapon blank used helps determine damage, but does not actually impart that kind of damage to the shield when bashing (so no fire crits with a mithril weapon blank). This skill takes much real time to use.\nSyntax: use spiked shield at <shield> with <weapon blank>\nExample: use spiked shield at shield with weapon blank 2", this_player());
}

void skill_func(object from, object at, string arg) {
  int time;
  int skill;

  if(!(at->id("shield"))) {
    message("info", "You must use this skill on a shield.", from);
    remove();
    return;
  }

  if(at->query_property("spiked")){
    message("info", "That shield already has spikes on it. You cannot upgrade the spikes on a shield.", from);
    remove();
    return;
  }

  if(!arg){
    message("info", "You need to specify a weapon blank.", from);
    remove();
    return;
  }

  ob=present(arg, this_player());

  if(!ob) {
    message("info", "You don't have that weapon blank.", from);
    remove();
    return;
  }

  if(!ob->id("weapon blank")){
    message("info", "That isn't a weapon blank.", from);
    remove();
    return;
  }

skill = props["skill level"];

// Set when skill is fixed

  time = 3600 - (skill * 2);
  if(time<300) time=300;
  if(wizardp(from)) time=1;
  message("info", "You begin to put spikes on the shield.", from);
  set_work_message("You hammer yet another spike into the shield.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  string *wc_keys, *runes;
  mixed tmp;
  float bonus;
  int skill = props["skill level"];
  float fbonus;

  message("info", "You finish putting spikes into the shield!", from);
  message("info", from->query_cap_name() + " finishes spiking his shield!",
        environment(from), ({ from }));
  bonus=mineral_bonus_check(ob->query_material());
  tmp = at->query_property("extra long");
    if(pointerp(tmp)) tmp += ({ "%^RED%^This shield has "+ob->query_property("material_name")+" spikes on it.%^RESET%^" });
    else if(stringp(tmp)) tmp = ({ tmp, "%^RED%^This shield has "+ob->query_property("material_name")+" spikes on it.%^RESET%^" });
  else tmp = ({ "%^RED%^This shield has "+ob->query_property("material_name")+" spikes on it.%^RESET%^" });
  at->set_property("extra long", tmp);
  fbonus=bonus*(skill/2);
  at->set_property("spiked", (int)fbonus);
  ob->remove();
  remove();
  return;
}

float mineral_bonus_check(string materialname) {
  float bonus;
  switch(materialname){
    case "/metal/iron":
      bonus=1;
      break;
    case "/metal/steel":
      bonus=1;
      break;
    case "/metal/laen":
      bonus=1;
      break;
    case "/metal/catoetine":
      bonus=1.25;
      break;
    case "/metal/javednite":
      bonus=1.25;
      break;
    case "/metal/davistone":
      bonus=1.25;
      break;
    case "/metal/mcgrail":
      bonus=1.25;
      break;
    case "/metal/boernerine":
      bonus=1.25;
      break;
    case "/metal/mabril":
      bonus=1.25;
      break;
    case "/metal/neorolite":
      bonus=1.25;
      break;
    case "/metal/raysorite":
      bonus=1.5;
      break;
    case "/metal/inniculmoid":
      bonus=1.5;
      break;
    case "/metal/elrodnite":
      bonus=1.5;
      break;
    case "/metal/mithril":
      bonus=1.5;
      break;
    case "/metal/platnite":
      bonus=1.5;
      break;
    case "/metal/iysaughton":
      bonus=1.5;
      break;
    case "/metal/eonmite":
      bonus=1.5;
      break;
// Hehe
    case "/metal/eog":
      bonus=0.5;
      break;
    default:
      bonus=1;
      break;
  }
  return bonus;
}
