#include <colors.h>
#include <daemons.h>

inherit "/std/skills/long_term.c";

int skill;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(21);
    set_fast_dev_cost(58);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
    message("help",
"The Royal-Infantry specializes in highly-effective combat tactics. Using their intimate familiarity with the power of rulership, a member of the Royal-Infantry can draw the royal insignia of Daybreak Ridge onto their shield, empowering it to do extra damage on a shield bash. The user will need dyes to paint the insignia on. This skill takes a lot of real time to use.\nSyntax: use royal insignia at <shield> with <color dye>\nExample: use royal insignia at shield with dyes", this_player());
}

void skill_func(object from, object at, string arg) {
    string *tmp, fname;
    int time;
	object ob;

    if(!at->id("shield")) {
	message("info", "This skill must be used on a shield.", from);
	remove();
	return;
    }
    fname = file_name(at);
    if(strlen(fname) < 18 || fname[0..17] != "/d/damned/virtual/") {
	message("info", "Sigils may only be inscribed on 'generic' armours, "+
	  "i.e., those forged by merchants or purchased at a shop.", from);
	remove();
	return;
    }

  if(at->query_property("royalins")){
    message("info", "That shield already has a royal insignia on it.", from);
    remove();
    return;
  }
    if(LAW_D->is_fugitive(this_player()->query_name())){
      message("info", "You can't paint a royal insignia as a criminal.",
from);
      return;
    }
  if(!arg){
    message("info", "You need to specify some dyes.", from);
    remove();
    return;
  }

  ob=present(arg, this_player());

  if(!ob) {
    message("info", "You don't have those dyes.", from);
    remove();
    return;
  }

  if(ob->query_name() != "dyes"){
    message("info", "That isn't a color dye. Ask your local alchemist for
some.", from);
    remove();
    return;
  }
    skill = props["skill level"];
    time = 1600 - (skill * 8);
    if(time < 500) time = 500;
    if(wizardp(from)) time=1;
    message("info", CBOLD+CCYAN+"You begin inscribing.", from);
    set_work_message(CBOLD+"You inscribe upon the armour.");
    start_work(at, from, time);
    return;
}

void finish_work(object from, object at) {
    mapping wc;
    int i;
    string *runes, *wc_keys;
    mixed tmp;
    string str = CGREEN+"A royal insignia is inscribed on the shield.";

    message("info", CBOLD+CCYAN+"You finish inscribing the sigil.",    from);

    message("info", "You finish inscribing the royal insignia.", from);
    tmp = at->query_property("extra long");
    if(pointerp(tmp)) tmp += ({ str });
    else if(stringp(tmp)) tmp = ({ tmp, str });
    else tmp = ({ str });
    at->set_property("extra long", tmp);
at->set_property("royalins", (int)skill/2 + (int)random(skill/5));
    remove();
    return;
}






