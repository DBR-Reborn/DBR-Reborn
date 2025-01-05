inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "mental lock");
    set_property("skill", "assassin's magic");
    set_property("casting time", 12);
    set_property("base mp cost", 69);
    set_property("dev cost", 88);
    set_property("fast dev cost", 303);
    set_property("spell level", 12);
    set_property("moon","luna");
    set_property("caster message", "%^BOLD%^%^CYAN%^You magically establish a mental lock on $T.%^RESET%^");
    set_property("target message","");
    set_property("observer message", "$C deeply focuses a considerable amount of mental energy.");
    set_property("no target", 1);
    set_property("duration", 200);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: None\n\nThis is a very useful and vital tool in an Assassin's magical arsenal as it gives one the power to mentally establish a long distance lock on a specific named target. This lock once active will give permission for the Assassin to use various teleportation magics to reach his or her target from even the farthest distances. Power affects both the duration of the lock once activated and the success rate of gaining it when cast on a target.\n\nSyntax: 'cast *6 mental lock at faustro'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    int lev, diff;
    object who;

    if(!args) {
	message("info", "You must supply a target to establish a lock with this spell.", caster);

	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    args = lower_case(args);
    at = find_player(args);
    if(!at) at = find_living(args);

    who = at;
    if(!who) {
	message("info", args+" cannot be found to be locked with this spell.", caster);
	message("info", (string)caster->query_cap_name()+"'s spell fails.",
	  environment(caster), ({ caster }));
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(environment(who) && environment(who)->query_property("no scry")) {
	message("info", "Your attempt to establish a mental lock on "+(string)at->query_cap_name()+" is rendered useless by an outside force.", caster);
	remove();
	return;
    }
    if(environment(caster) && environment(caster)->query_property("no scry")) {
	message("info", "Your attempt to establish a mental lock on "+(string)at->query_cap_name()+" is rendered useless by an outside force.", caster);
	remove();
	return;
    }
    lev = (int)who->query_level();
    diff = 2 + (int)caster->query_level() - lev;
    if (random(16) > (diff + power))
    {
	message("info", "%^CYAN%^Your attempt to establish a mental lock on "+(string)at->query_cap_name()+" is resisted!%^RESET%^", caster);
	message("info", "%^CYAN%^You resist "+(string)caster->query_cap_name()+"'s attempt to establish a mental lock on you!%^RESET%^", at);
	remove();
	return;
    }

    if(who->query("scryguard")) {
	if(random(100) < (int)who->query("scryguard")/power) {
	    message("info", "You fail to break "+(string)who->query_cap_name() +
	      "'s scryguard.", caster);
	    message("info", "Your scryguard blocks "+
	      (string)caster->query_cap_name()+"'s scry attempt.",
	      who);
	    remove();
	    return;
	}
	else {
	    message("info", (string)who->query_cap_name() + " has a scryguard, "+
	      "but you break through it.", caster);
	    message("info", "You scryguard was insufficient to block "+
	      (string)caster->query_cap_name()+"'s scry.", who);
	}
    }
    caster->set("scry", who);
    caster->set("scry time", time() + props["duration"]);
    message("info", "You successfully establish a lock on "+(string)at->query_cap_name()+"'s location. You may now use a teleporation spell until the lock expires.", caster);
    remove();
    return;
}

