inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(27);
    set_fast_dev_cost(78);
    set_property("no target", 1);
    return;
}

void info() {
    message("info", "Prerequisite Base Skill Requirement: 250%\n\nThis skill enables an Assassin to force his or her body into an excessively fast rage, permitting a numerous amount of attacks in a single round. This ability will only work for the round it was activated prior to, and the number of attacks granted is directly influenced by the Assassin's talent in the skill. Regardless of skill level however this ability can only be used once every 10 minutes real time, and due to balance cannot be combined with the 'forbidden fury' skill, although it can be combined with normal combat hastings.\n\nSyntax: 'use lightning strike'", this_player());
}

void skill_func(object from, object at, string arg) {
    object ob;
    int power;

    power = to_int(to_float((int)from->query_skill("lightning strike")) / to_float(30));

    if((time() - (int)from->query_last_use("lightning strike")) < 900) {
	message("info", "You are still too exhausted from your recent attack rage to force yourself into another one.", from);
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
from->add_exp2(25 * props["skill level"]+(this_player()->query_level()*100));
    from->set_last_use("lightning strike");
    seteuid(geteuid(this_object()));
    ob = new("/std/spells/shadows/haste_shadow");
    ob->set_power(power);
    ob->set_my_skill("multi attack");
    ob->set_shadow_name("lightning strike");
    ob->start_shadow(from, 1, "");
    message("info", "%^B_BLUE%^%^WHITE%^You explode into a lightning fast rage of attacks!%^RESET%^", from);
    message("info", (string)from->query_cap_name()+" explodes into a lightning fast rage of attacks!", environment(from), ({ from }));
    remove();
    return;
}
