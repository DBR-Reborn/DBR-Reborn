#include <colors.h>
#include <daemons.h>

inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(7);
    set_fast_dev_cost(19);
    set_property("target type", "any");
    set_property("must be present",1);
}

void info() {
   message("help",
      "Fighters are deadly combatants, trained in the art of battle and the mastery of weapons. "+
      "Using a mystic technique, they can imbue their weapons with the raw energy of lightning, "+
      "delivering electrifying blows to their opponents. Arcblade does not last for long, but its "+
      "shocking power is enough to turn the tide of battle in their favor."+
      "\nSyntax: use arcblade at <weapon>"+
      "\nExample: use arcblade at long sword",
      this_player());
}

void skill_func(object from, object at, string arg) {
    int skill=props["skill level"];
    object ob;

if(!wizardp(from)) {
	if((time() - (int)from->query_last_use("archblade")) < skill*4)
	{
	    message("info", "You are too tired to use this skill yet."
	      , from);
	    return;
	}
    }

    //if(LAW_D->is_fugitive(this_player()->query_name())){
	//message("info", "You try to power up your weapon, but your criminal status prevents you from doing so.", from);
	//return;
    //}

    from->set_last_use("archblade");
    from->kill_ob(at, 0);

    ob = new("/std/spells/shadows/weapon_shadow");
    if(at->query_num("archblade")) {
	message("info", "You may not stack any further Archblades on that weapon.", from);
	remove();
	return;
    }

    message("info", "%^MAGENTA%^Your weapon turns a regal purple.%^RESET%^", from);
message("info", "%^MAGENTA%^"+from->query_cap_name()+"'s weapon turns a regal purple.%^RESET%^", environment(from), from);
    ob->set_extra_wc(([ "electricity" : skill/3 ]));
    ob->set_auto_crits((["electricity B" : skill/5 ] ));
ob->set_shadow_name("archblade");
ob->start_shadow(at, skill*3, "%^MAGENTA%^Your weapon's regal colour fades.%^RESET%^");
from->add_exp2(15 * props["skill level"]+(this_player()->query_level()*100));
remove();
return;
}

