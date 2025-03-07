inherit "/std/skills/long_term.c";

int skill;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(23);
    set_fast_dev_cost(56);
    set_property("target type", "any");
   //set_property("prereq", "engrave");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill is used to inscribe a plasa rune (physical protection rune) on an armour.  "
"This adds physical plasma protection to the armour.  The potency of the rune "
"depends on skill level.  This is a long-term skill ('help long-term') and takes "
"much real time to use.  If interrupted, you may pick up the skill again later "
"by 'use'-ing the skill again.\n"
"Syntax: use inscribe plasa at <armour>",
	this_player());
}

void skill_func(object from, object at, string arg) {
  string *tmp, fname;
  int time;

  if(!at->is_armour()) {
    message("info", "This skill must be used on a piece of armour.", from);
    remove();
    return;
  }
  fname = file_name(at);
  if(strlen(fname) < 18 || fname[0..17] != "/d/damned/virtual/") {
    message("info", "Runes may only be inscribed on 'generic' armours, "+
      "i.e., those forged by tinkers or purchased at a shop.", from);
    remove();
    return;
  }
  while(shadow(at, 0)) shadow(at, 0)->external_destruct(shadow(at, 0));
  tmp = (string *)at->query_property("runes");
  if(!tmp) tmp = ({});
  if(sizeof(tmp) >= 10) {
    message("info", "No armour may receive more than 10 runes.",
      from);
    remove();
    return;
  }
  if(member_array("plasa", tmp) >= 0) {
    message("info", "That armour already has a plasa rune on it.",
      from);
    remove();
    return;
  }
  skill = props["skill level"];
  time = 1600 - (skill * 8);
  if(time < 500) time = 500;
  message("info", "%^CYAN%^%^BOLD%^You begin inscribing.", from);
  set_work_message("%^CYAN%^You inscribe upon the armour.");
if(archp(this_player())){
time = 1;
}
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  mapping wc;
  int i;
  string *wc_keys, *runes;
  mixed tmp;
  
  message("info", "%^CYAN%^%^BOLD%^You finish inscribing the rune.",
    from);
  wc = (mapping)at->all_base_ac();
  if(!wc) wc = ([]);
  if(!wc["plasma"]) wc["plasma"] = 0;
  wc["plasma"] += skill/2+skill/2+skill/3+skill/4+skill/5+skill/6+(this_player()->query_level()/2);
  wc_keys = keys(wc);
  i = sizeof(wc_keys);
  while(i--)
    at->set_ac(wc[wc_keys[i]], wc_keys[i]);
from->add_exp2(15 * props["skill level"]+(this_player()->query_level()*100));
  message("info", "A %^B_RED%^%^ORANGE%^plasa%^RESET%^ rune appears on the armour.", from);
  if(!(runes=(string *)at->query_property("runes")))
    runes = ({});
  runes += ({ "plasa" });
  at->set_property("runes", runes);
  tmp = at->query_property("extra long");
  if(pointerp(tmp)) tmp += ({ "A %^B_RED%^%^ORANGE%^Plasa%^RESET%^ rune is inscribed on the armour." });
  else if(stringp(tmp)) tmp = ({ tmp, "A %^B_RED%^%^ORANGE%^Plasa%^RESET%^ rune is inscribed on the armour." });
  else tmp = ({ "A %^B_RED%^%^ORANGE%^Plasa%^RESET%^ rune is inscribed on the armour." });
  at->set_property("extra long", tmp);
  remove();
  return;
}

