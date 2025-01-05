inherit "/std/skills/skill";

int ready = 0;
void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(36);
    set_fast_dev_cost(108);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 300%\n\nThis is an extremely potent assassination skill which enables an Assassin to attempt a fatal strike against an unsuspecting target that will cause instant death regardless of all physical defense and hit points. This strike is an all or nothing gamble, meaning if it misses NO damage will be caused to the target unlike with other assassinations that arent powerful enough to instantly kill through armour. This skill carries a considerable usage delay, and also can only be used once every 10 minutes real time. No weapon is required wielded but one can be if the Assassin permits since there are many ways to kill someone even with bare hands. The success rate of this attack once executed is entirely dependent on the skill level.\n\nSyntax: 'use mortal attack at synge'", this_player());
}

void skill_func(object from, object at, string args) {
    int randomizer;
    int skill;

    skill = (int)from->query_skill("mortal attack");
    randomizer = random(1000);
    if(from->query_current_attacker()) {
	message("info", "You cannot concentrate a mortal strike while already in combat.", from);
	remove();
	return;
    }
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
    if((time() - (float)from->query_last_use("mortal attack")) < 900) {
	message("info", "You have not yet regained the concentration required to prepare another mortal strike.", from);
	remove();
	return;
    }
    if(ready > 0) {
	if(!present(at, environment(from))) {
	    message("info", "You attempt your mortal blow but "+(string)at->query_cap_name()+" is no longer present in the room.", from);
	    remove();
	    return;
	}
	if(randomizer < skill) {
	    message("info", "%^BOLD%^%^RED%^You deliver a %^RESET%^LETHALLY %^BOLD%^%^RED%^potent strike to "+(string)at->query_cap_name()+"'s body, killing "+(string)at->query_possessive()+" instantly!%^RESET%^", from);
	    message("info", "%^BOLD%^%^RED%^"+(string)from->query_cap_name()+" delivers a %^RESET%^LETHALLY %^BOLD%^%^RED%^potent strike to your body, instantly killing you!%^RESET%^", at);
	    message("info", "%^BOLD%^%^RED%^"+(string)from->query_cap_name()+" delivers a devastating mortal wound to "+(string)at->query_cap_name()+"'s body!%^RESET%^", environment(from), ({ from, at }));
	    at->die();
	    at->kill_ob(from, 0);
	    remove();
	    return;
	}
	if(randomizer >= skill) {
	    message("info", "%^BOLD%^%^RED%^You attempt to mortally wound "+(string)at->query_cap_name()+" but miserably fail.%^RESET%^", from);
	    message("info", "%^BOLD%^%^RED%^"+(string)from->query_cap_name()+" attempted to mortally wound and kill you, but luckily failed.%^RESET%^", at);
	    message("info", (string)from->query_cap_name()+" attempted to mortally wound "+(string)at->query_cap_name()+" but miserably failed.", environment(from), ({ from, at }));
	    at->kill_ob(from, 0);
	    remove();
	    return;
	}
    }
    message("info", "You begin to concentrate adeptly on "+(string)at->query_cap_name()+"'s body, preparing to deal "+(string)at->query_possessive()+" a mortal blow.", from);
    ready = 1;
    call_out("skill_func", 30, from, at, args);
}
