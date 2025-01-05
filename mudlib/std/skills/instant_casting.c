inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(24);
    set_fast_dev_cost(57);
    set_property("no target", 1);
}

void info() {
    message("help", "This is an extraordinarily potent and expensive skill which enables a highly seasoned magus to cast a single spell instantly, regardless of its casting time. The skill level of this ability directly determines how often this skill may be utilized, and it cannot be stacked with any other spell augmentation skills such as focus casting and fast casting.\n\nSyntax: 'use instant casting'", this_player());
}

void skill_func(object from, object at, string arg) {
    object ob;

    if(props["skill level"] < 0) props["skill level"] = 0;
    if((time() - (int)from->query_last_use("instant casting")) < (125000 / (props["skill level"]/5+1)))
    {
	/*
		message("info", "You may only use this skill once every "+
		  sprintf("%d minutes (real time).", (120 / (props["skill level"]/5+1))), from);
	*/
	message("player","You cannot use instant casting again for another "+((125000/(props["skill level"]/5+1) - (time() - from->query_last_use("instant casting"))))/60+" minutes.", from);
	return;
	remove();
	return;
    }
    from->set_last_use("instant casting");
    if(from->query("instant casting"))
    {
	message("info","You may only use one type of spell augmentation skill per spell.", from);
	remove();
	return;
    }

    if(ob=from->query("focus ob")) {
	if(ob->query_type() == "instant") {
	    message("info", "You may only use one type of spell augmentation skill per spell.",
	      from);
	    remove();
	    return;
	}
    }
    from->set("instant casting", 1);
    message("info", "Your next spell will be instantly cast.", from);
    ob = new("/wizards/diewarzau/obj/misc/focus_ob");
    ob->move(from);
    ob->set_caster(from);
    ob->set_type("instant");
    from->set("focus ob", ob);
    remove();
    return;
}

