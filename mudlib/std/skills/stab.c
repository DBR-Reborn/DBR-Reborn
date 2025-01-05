inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(14);
    set_fast_dev_cost(46);
    set_property("target type", "living");
    set_property("must be present", 1);
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: None\n\nThis skill enables an Assassin to assault his or her target with a considerable stabbing attack, inflicting damage based on the level of the skill, overall WC of the weapon, and the overall AC of the target. This attack is similar to that of a low strength assassination with the exception that this skill cannot be used to collect bounties.\n\nSyntax: 'use stab at morten'", this_player());
}

void skill_func(object from, object at, string arg) {
    object *inv;
    int offense;
    int defense;
    int skill;
    int damage;
    int hit;
    int randomizer;
    int difference;
    int stdifference;
    int value;

    inv = (object *)from->query_wielded();

    if(at->query_property("no kill")) {
	message("info", "This target cannot be attacked.", from);
	remove();
	return;
    }
    if(at->query_ghost()) {
	message("info", "You cannot use this skill on a ghost.", from);
	remove();
	return;
    }
    if(environment(from) && environment(from)->query_property("no attack")) {
	message("info", "Greater powers prevent your malice.", from);
	remove();
	return;
    }
    if(from->query_current_attacker()) {
	message("info", "You cannot use this skill while engaged in combat.", from);
	remove();
	return;
    }
    if(!inv || !sizeof(inv)) {
	message("info", "You must be wielding a weapon to use this skill.", from);
	remove();
	return;
    }
    if(sizeof(inv) > 1) {
	message("info", "You must be single wielding to use this skill.", from);
	remove();
	return;
    }
    if((time() - (int)from->query_last_use("stab")) < 10) {
	message("info", "You may only use this skill once every few rounds.", from);
	remove();
	return;
    }
    offense = (int)inv[0]->query_wc();
    defense = (int)((at->query_ac("right hand") + at->query_ac("left hand") + at->query_ac("left foot") + at->query_ac("right foot") + at->query_ac("right leg") + at->query_ac("left leg") + at->query_ac("right arm") + at->query_ac("left arm") + at->query_ac("torso") + at->query_ac("head")) / 10);
    skill = (int)from->query_skill("stab");
    damage = (offense + skill)*3 - defense;
    randomizer = random(100);
    difference = to_int(to_float((int)from->query_skill("stab")) / to_float(2));
    stdifference = to_int(to_float((int)at->query_skill("dodge")) - to_float(difference));
    value = to_int((to_float(stdifference) / to_float(difference)) * to_float(100));

    if((int)at->query_skill("dodge") <= difference) {
	hit = 1;
    }
    if(((int)at->query_skill("dodge") > difference) && ((int)at->query_skill("dodge") < (int)from->query_skill("stab"))) {
	if(randomizer <= value) {
	    hit = 2;
	}
	if(randomizer > value) {
	    hit = 1;
	}
    }
    if((int)at->query_skill("dodge") >= (int)from->query_skill("stab")) {
	hit = 2;
    }
    from->set_last_use("stab");

    if(hit == 1) {
from->add_exp2(15 * props["skill level"]+(this_player()->query_level()*100));
	message("info", "%^BLUE%^You stab "+at->query_cap_name()+" square in the stomach with your weapon.%^RESET%^", from);
	message("info", "%^BLUE%^"+from->query_cap_name()+" violently stabs you square in the lower body.%^RESET%^", at);
	message("info", from->query_cap_name()+" nastily stabs "+at->query_cap_name()+" in the midsection.", environment(from), ({ from, at }));
	at->add_hp(-(damage));
	at->kill_ob(from, 0);
	remove();
	return;
    }
    if(hit == 2) {
	message("info", "%^BLUE%^You try to stab "+at->query_cap_name()+" but are thwarted by superior dodging skills.%^RESET%^", from);
	message("info", "%^BLUE%^"+from->query_cap_name()+" attempted to stab you but you dodge quickly out of the way.%^RESET%^", at);
	message("info", from->query_cap_name()+" attempts to viciously stab "+at->query_cap_name()+" but painfully misses.", environment(from), ({ from, at }));
	at->kill_ob(from, 0);
	remove();
	return;
    }
}
