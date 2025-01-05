inherit "/std/skills/skill.c";

object ob;
int loopkeeper = 0;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(27);
    set_fast_dev_cost(83);
    set_property("target type", "living");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 225%\n\nThis skill allows an Assassin to fixate on and stalk a target with incredible talent while it is in use, enabling for a far less chance of detection based on perception than possible with the 'shadow target' skill. This skill while very powerful however is not a 100% guarantee that a target cannot detect or randomly shake you off their tail if detected, despite the fact that it makes the lower stalking skills obsolete. Higher talent in this skill makes detection and shaking off more difficult.\n\nSyntax: 'use parasitic fixation at ruck'", this_player());
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
	    message("info", "You cease your fixated stalking of "+(string)ob->query_cap_name()+".", from);
	}
	from->set("stalking", 0);
	if(flag) {
	    message("my_action", "You cease your fixations and stop stalking.", from);
	    loopkeeper = 1;
	    at->remove_follower(from);
	    ob->external_destruct(ob);
	    remove();
	    return;
	}
    }
    message("my_action", "You obsessively fixate your attention on "+(string)at->query_cap_name()+" and begin stalking with great precision.", from);
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
    difference = to_int(to_float((int)from->query_skill("parasitic fixation")) * to_float(2));
    stdifference = to_int(to_float((int)at->query_skill("perception")) - to_float((int)from->query_skill("parasitic fixation")));
    value = to_int((to_float(stdifference) / to_float(difference)) * to_float(100));

    if((object)from->query("stalk shad")) {
	if((int)at->query_skill("perception") <= (int)from->query_skill("parasitic fixation")) {
	    busted = 0;
	}
	if(((int)at->query_skill("perception") > (int)from->query_skill("parasitic fixation")) && ((int)at->query_skill("perception") < (int)from->query_skill("parasitic fixation")*2)) {
	    if(randomizer <= value) {
		busted = 1;
	    }
	    if(randomizer > value) {
		busted = 0;
	    }
	}
	if((int)at->query_skill("perception") >= (int)from->query_skill("parasitic fixation")*2) {
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
