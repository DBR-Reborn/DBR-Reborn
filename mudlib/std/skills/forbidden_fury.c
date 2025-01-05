inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(33);
    set_fast_dev_cost(103);
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 300%\n\nThis highly effective attack skill empowers an Assassin with the ability to launch several instantaneous and consecutive rounds of combat before the opposition is permitted to swing back at all immediately upon its invocation. The number of free rounds granted is directly influenced by the skill level of this ability, and regardless of that skill level can never exceed eight. This ability also regardless of that value may only be used once every 10 minutes real time, and it cannot be combined with the 'lightning strike' skill due to balancing reasons concerned with the number of attacks granted. This ability however can be combined with normal hasting skills and spells without penalty.\n\nSyntax: 'use forbidden fury'", this_player());
}

void skill_func(object from, object at, string arg) {
    object ob;
    int power;

    power = to_int(to_float((int)from->query_skill("lightning strike")) / to_float(60));
    if(power > 8) power = 8;

    if((time() - (int)from->query_last_use("lightning strike")) < 900) {
	message("info", "You are still too exhausted from your most recent combat rage and must rejuvenate your strength before attempting it again.", from);
	remove();
	return;
    }
    if(!from->query_current_attacker()) {
	message("info", "This skill may only be used while fighting in combat.", from);
	remove();
	return;
    }
    if(from->query_my_skill("multi attack")) {
	message("info", "You are already using a quick multiple attack modifier at this time.", from);
	remove();
	return;
    }
    from->set_last_use("forbidden fury");
    seteuid(geteuid(this_object()));
    ob = new("/std/spells/shadows/haste_shadow");
    ob->set_power(0);
    ob->set_my_skill("multi attack");
    ob->set_shadow_name("forbidden fury");
    ob->start_shadow(from, 0, "");
from->add_exp2(10 * props["skill level"]+(this_player()->query_level()*100));
    message("info", "%^B_BLUE%^%^WHITE%^You flat out burst into insanity and launch forth a rapid succession of powerful attacks!%^RESET%^", from);
    message("info", (string)from->query_cap_name()+" flat out bursts into insanity and launches forth a rapid succession of powerful attacks!", environment(from), ({ from }));
    while(power > 0) {
	message("info", "%^BOLD%^%^YELLOW%^You continue attacking your enemy!%^RESET%^", from);
	message("info", "%^BOLD%^%^YELLOW%^"+(string)from->query_cap_name()+" continues attacking "+(string)from->query_possessive()+" enemy!%^RESET%^", environment(from), ({ from }));
	power--;
	from->continue_attack();
    }
}
