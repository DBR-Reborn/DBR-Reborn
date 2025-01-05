inherit "/std/skills/skill.c";

object ob;
int loopkeeper = 0;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(19);
    set_fast_dev_cost(65);
    set_property("target type", "living");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 75%\n\nThis skill enables an Assassin to shadow a specified player target, permitting unauthorized following of that target for as long as the skill is active or he/she makes a teleporting action. Be warned however that the target's perception can play a part in detecting whether or not they are being stalked, and also however less likely provide a small chance of shaking the Assassin off of their tail. Higher skill decreases the chances of being shook off or detected.\n\nSyntax: 'use shadow target at revjak'", this_player());
}

void skill_func(object from, object at, string arg, int flag) {

    if(ob = (object)from->query("stalk shad")) {
	from->set("stalk shad", 0);
	if((string)ob->query_my_skill() == "stalk" || (string)ob->query_my_skill() == "shadow") {
	    flag = 1;
	}
	ob->external_destruct(ob);
	ob = (object)from->query("stalking");
	if(objectp(ob) && ob->query_followers() && member_array(from, (object *)ob->query_followers()) >= 0) {
	    ob->remove_follower(from);
	    at->remove_follower(from);
	    message("info", "You cease your shadowing of "+(string)ob->query_cap_name()+".", from);
	}
	from->set("stalking", 0);
	if(flag) {
	    message("my_action", "You cease your motions of shadowing.", from);
	    loopkeeper = 1;
	    at->remove_follower(from);
	    ob->external_destruct(ob);
	    remove();
	    return;
	}
    }
    message("my_action", "You begin to shadow "+(string)at->query_cap_name()+", stalking directly from behind.", from);
    seteuid(getuid());
    ob = new("/std/cythug/shadows/stalking_shadow.c");
    from->set("stalk shad", ob);
    ob->set_my_skill("shadow");
    ob->start_shadow(from);
    at->add_follower(from);
    from->set("stalking", at);
    call_out("detect_func", 10, from, at);
    return;
}

void detect_func(object from, object at) {
    int randomizer;
    int randomizer2;
    int difference;
    int stdifference;
    int value;
    int busted = 0;

    randomizer = random(100);
    randomizer2 = random(5);
    difference = to_int(to_float((int)from->query_skill("shadow target")) / to_float(2));
    stdifference = to_int(to_float((int)at->query_skill("perception")) - to_float(difference));
    value = to_int((to_float(stdifference) / to_float(difference)) * to_float(100));

    if((object)from->query("stalk shad")) {
	if((int)at->query_skill("perception") <= difference) {
	    busted = 0;
	}
	if(((int)at->query_skill("perception") > difference) && ((int)at->query_skill("perception") < (int)from->query_skill("shadow target"))) {
	    if(randomizer <= value) {
		busted = 1;
	    }
	    if(randomizer > value) {
		busted = 0;
	    }
	}
	if((int)at->query_skill("perception") >= (int)from->query_skill("shadow target")) {
	    busted = 1;
	}
	if(busted == 1) {
	    message("info", "%^BLUE%^You detect "+(string)from->query_cap_name()+" shadowing you!%^RESET%^", at);
	    if(randomizer2 == 1) {
		message("info", "%^BLUE%^You successfully shake "+(string)from->query_cap_name()+" off your tail!%^RESET%^", at);
		message("info", "%^BLUE%^"+(string)at->query_cap_name()+" has shaken you off his tail!%^RESET%^", from);
		from->set("stalking", 0);
		from->set("stalk shad", 0);
		at->remove_follower(from);
		ob->external_destruct(ob);
		remove();
		return;
	    }
	    if(randomizer2 != 1) {
		call_out("detect_func", 10, from, at);
	    }
	}
	if(busted == 0) {
	    call_out("detect_func", 10, from, at);
	    return;
	}
    }
    return;
}
