inherit "/std/skills/skill";

int loopkeeper = 0;
int stabkeeper = 0;

void delayer_func() {
    if(loopkeeper == 1) {
	stabkeeper = 1;
	return;
    }
    if(loopkeeper == 0) {
	call_out("delayer_func", 5);
	loopkeeper = 1;
    }
}

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(18);
    set_fast_dev_cost(59);
    set_property("target type", "living");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 100%\n\nThis skill serves as the Assassin's primary tool in collecting bounties placed on the heads of certain players, with the list of those people located in the Daybreak town tavern. When used against any target, be it a player or mob regardless a significant amount of damage is caused based on the WC of the Assassin's weapon, the level of the skill, and also the overall defense of the designated target. Note however that this skill has a preset delay of a few seconds when used, thus rendering 'bounce' attacks with this skill impossible unlike the case with the lower level skill stab.\n\nSyntax: 'use assassination at synge'", this_player());
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

    if((time() - (float)from->query_last_use("assassination")) <= 4.100000) {
	message("info", "You are already attempting an assassination at this time.", from);
	remove();
	return;
    }
    offense = (int)inv[0]->query_wc();
    defense = (int)((at->query_ac("right hand") + at->query_ac("left hand") + at->query_ac("left foot") + at->query_ac("right foot") + at->query_ac("right leg") + at->query_ac("left leg") + at->query_ac("right arm") + at->query_ac("left arm") + at->query_ac("torso") + at->query_ac("head")) / 10);
    skill = (int)from->query_skill("assassination");

    if(defense < 500) damage = (offense + skill)*8 - defense;
    if(defense >= 1000 < 1500) damage = (offense + skill)*7 - defense;
    if(defense >= 1000 < 1500) damage = (offense + skill)*6 - defense;
    if(defense >= 1500) damage = (offense + skill)*4 - defense;

    randomizer = random(100);
    difference = to_int(to_float((int)from->query_skill("assassination")) / to_float(2));
    stdifference = to_int(to_float((int)at->query_skill("reverse stroke")) - to_float(difference));
    value = to_int((to_float(stdifference) / to_float(difference)) * to_float(100));

    if((int)at->query_skill("reverse stroke") <= difference) {
	hit = 1;
    }
    if(((int)at->query_skill("reverse stroke") > difference) && ((int)at->query_skill("reverse stroke") < (int)from->query_skill("assassination"))) {
	if(randomizer <= value) {
	    hit = 2;
	}
	if(randomizer > value) {
	    hit = 1;
	}
    }
    if((int)at->query_skill("reverse stroke") >= (int)from->query_skill("assassination")) {
	hit = 2;
    }
    from->set_last_use("assassination");

    if(stabkeeper == 1) {
	if(!present(at, environment(from))) {
	    message("info", "You strike your weapon but your target is unfortunately no longer present.", from);
	    remove();
	    return;
	}
	if(hit == 1) {
	    message("info", "%^RED%^You viciously strike "+(string)at->query_cap_name()+" in the back using your weapon.%^RESET%^", from);
	    message("info", "%^RED%^You feel a sharp and horribly painful strike completely surprise you from behind!%^RESET%^", at);
	    message("info", (string)from->query_cap_name()+" strikes "+(string)at->query_cap_name()+" viciously from behind in an assassination attempt.", environment(from), ({ at, from }));
	    at->add_hp(-(damage));
	    at->kill_ob(from, 0);
	    remove();
	    return;
	}
	if(hit == 2) {
	    message("info", "%^RED%^You assassination attempt is perfectly read by "+(string)at->query_cap_name()+" and reversed against you!%^RESET%^", from);
	    message("info", "%^RED%^You read "+(string)from->query_cap_name()+" attempting to assassinate you and reverse the attack against him!%^RESET%^", at);
	    message("info", (string)from->query_cap_name()+" attempts to assassinate "+(string)at->query_cap_name()+" but is caught and reverse struck with his own weapon!", environment(from), ({ at, from }));
	    from->add_hp(-(damage/2));
	    at->kill_ob(from, 0);
	    remove();
	    return;
	}
    }
    if(stabkeeper == 0) {
	stabkeeper = 1;
	message("info", "You sneak up behind "+(string)at->query_cap_name()+" preparing to strike.", from);
	call_out("skill_func", 5, from, at, arg);
    }
}
