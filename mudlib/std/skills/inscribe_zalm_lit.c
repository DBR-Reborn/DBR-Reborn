inherit "/std/skills/long_term.c";
inherit "/std/check_brittle.c";

int skill;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(16);
    set_fast_dev_cost(41);
    set_property("prereq", "engrave");
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill is used to inscribe a Zalm Lit rune (wieldliness rune) on a weapon.  "
"This rune adds parry chance to the weapon permanently.  The amount of parry chance "
"depends on skill level.  This is a long-term skill ('help ling-term') and takes "
"much real time to use.  If interrupted, you may pick up the skill again later "
"by 'use'-ing the skill again.\n"
"Syntax: use inscribe zalm lit at <weapon>",
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
    message("info", "No weapon may receive more than 10 runes.",
      from);
    remove();
    return;
  }
  if(member_array("zalm lit", tmp) >= 0) {
    message("info", "That weapon already has a zalm lit rune on it.",
      from);
    remove();
    return;
  }
  skill = props["skill level"];
  time = 1600 - (skill * 8);
  if(time < 400) time = 400;
  message("info", "%^CYAN%^%^BOLD%^You begin inscribing.", from);
  set_work_message("%^CYAN%^You inscribe upon the weapon.");
if(archp(this_player())){
time = 1;
}
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  int i, hit_bonus;
  mixed tmp;
  string *runes;
  
  message("info", "%^CYAN%^%^BOLD%^You finish inscribing the rune.",
    from);
  if(!check_brittle(at, from, 8)) {
    remove();
    return;
  }
from->add_exp2(15 * props["skill level"]+(this_player()->query_level()*100));
  message("info", "A %^GREEN%^%^BOLD%^Zalm Lit%^RESET%^ rune appears on the weapon.", from);
  hit_bonus = (int)at->query_parry_bonus();
  hit_bonus += skill/3 + (this_player()->query_level()/2);
  at->set_parry_bonus(hit_bonus);
  if(!(runes=(string *)at->query_property("runes")))
    runes = ({});
  runes += ({ "zalm lit" });
  at->set_property("runes", runes);
  tmp = at->query_property("extra long");
  if(pointerp(tmp)) tmp += ({ "A %^MAGENTA%^%^BOLD%^Zalm Lit%^RESET%^ rune is inscribed on the weapon." });
  else if(stringp(tmp)) tmp = ({ tmp, "A %^MAGENTA%^%^BOLD%^Zalm Lit%^RESET%^ rune is inscribed on the weapon." });
  else tmp = ({ "A %^MAGENTA%^%^BOLD%^Zalm Lit%^RESET%^ rune is inscribed on the weapon." });
  at->set_property("extra long", tmp);
  remove();
  return;
}

