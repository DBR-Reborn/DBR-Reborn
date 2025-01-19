inherit "/std/skills/long_term.c";
inherit "/std/check_brittle";

int skill;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(19);
    set_fast_dev_cost(39);
   set_property("prereq", "engrave");
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill is used to inscribe a disrupter rune on a weapon."
"This rune adds disruption damage to the weapon permanently.  The amount of damage "
"depends on skill level.  This is a long-term skill ('help long-term') and takes "
"much real time to use.  If interrupted, you may pick up the skill again later "
"by 'use'-ing the skill again.\n"
  "Syntax: use inscribe disrupter at <weapon>",
        this_player());
}

void skill_func(object from, object at, string arg) {
  string *tmp, fname;
  int time;

  if(!at->is_weapon()) {
    message("info", "This skill must be used on a weapon.", from);
    remove();
    return;
  }
  fname = file_name(at);
  if(strlen(fname) < 18 || fname[0..17] != "/d/damned/virtual/") {
    message("info", "Runes may only be inscribed on 'generic' weapons, "+
      "i.e., those forged by tinkers or purchased at a shop.", from);
    remove();
    return;
  }
  while(shadow(at, 0)) shadow(at, 0)->external_destruct(shadow(at, 0));
  tmp = (string *)at->query_property("runes");
  if(!tmp) tmp = ({});
  if(sizeof(tmp) >= 10) {
    message("info", "No weapon may receive more than 10 runes.", from);
    remove();
    return;
  }
  if(member_array("disrupter", tmp) >= 0) {
    message("info", "That weapon already has a disrupter rune on it.", from);
    remove();
    return;
  }
  skill = props["skill level"];
  time = 2000 - (skill * 9);
  if(time < 600) time = 600;
  message("info", "%^CYAN%^%^BOLD%^You begin inscribing.", from);
  set_work_message("%^CYAN%^You inscribe upon the weapon.");
if(archp(this_player())){
time = 1;
}
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  mapping wc;
  int i;
  string *runes, *wc_keys;
  mixed tmp;
string* auto_criticals;
  
  message("info", "%^CYAN%^%^BOLD%^You finish inscribing the rune.",
    from);
//ADD
if (props["skill level"] >= 150) {
		if (!check_brittle(at, from, 16)) {
        remove();
        return;
    }
} else {
    if (!check_brittle(at, from, 8)) {
        remove();
        return;
    }
}
//END
  wc = (mapping)at->all_base_wc();
  if(!wc) wc = ([]);
  if(!wc["disruption"]) wc["disruption"] = 0;
  wc["disruption"] += skill/2+skill/2+skill/3+skill/4+skill/5+skill/6+(this_player()->query_level()/2);
  wc_keys = keys(wc);
  i = sizeof(wc_keys);
  while(i--)
    at->set_wc(wc[wc_keys[i]], wc_keys[i]);
from->add_exp2(15 * props["skill level"]+(this_player()->query_level()*100));
    message("info", "A %^MAGENTA%^Disrupter%^RESET%^ rune appears on the weapon.", from);
  if(!(runes=(string *)at->query_property("runes")))
    runes = ({});
  runes += ({ "disrupter" });
  at->set_property("runes", runes);
  tmp = at->query_property("extra long");
    if(pointerp(tmp)) tmp += ({ "A %^MAGENTA%^Disrupter%^RESET%^ rune is inscribed on the weapon." });
    else if(stringp(tmp)) tmp = ({ tmp, "A %^MAGENTA%^Disrupter%^RESET%^ rune is inscribed on the weapon." });
  else tmp = ({ "A %^MAGENTA%^Disrupter%^RESET%^ rune is inscribed on the weapon." });

//ADD TLNY2025
if (props["skill level"] >= 150) {
auto_criticals = at->query_auto_critical();

auto_criticals += ({"disruption A"});

at->set_auto_critical(auto_criticals);

message("info", "%^BOLD%^%^YELLOW%^It glows with the brilliance of a Masterpiece!%^RESET%^", from);

 tmp = at->query_property("extra long");
    if(pointerp(tmp)) tmp += ({ "A Masterpiece %^MAGENTA%^Disrupter%^RESET%^ rune is inscribed on the weapon." });
    else if(stringp(tmp)) tmp = ({ tmp, "A Masterpiece %^MAGENTA%^Disrupter%^RESET%^ rune is inscribed on the weapon." });
  else tmp = ({ "A Masterpiece %^MAGENTA%^Disrupter%^RESET%^ rune is inscribed on the weapon." });
}
//END

  at->set_property("extra long", tmp);
  remove();
  return;
}
