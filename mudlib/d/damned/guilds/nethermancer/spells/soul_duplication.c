inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "soul duplication");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 263);
    set_property("dev cost", 222);
    set_property("fast dev cost", 688);
    set_property("spell level", 32);
    set_property("moon", "luna");
    set_property("caster message", "You attempt to connect with a soul and duplicate its essence.");
    set_property("target message","");
    set_property("observer message", "$C attempts to connect with a soul and duplicate its essence.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This spell gives a Nethermancer the extremely potent ability to make a complete duplication of a soul contained inside of a soul orb. The newly created soul will possess all of the properties of a soul created with all of the necessary lesser soul components, meaning it can be used to create greater souls and a soul orb can be finalized for it. This is a long-term type of spell, with the time required to complete influenced both by the power of the spell and the degree of the soul that is being duplicated, and unlike with many other long-term spells no nether arts skills will affect the time. When using this magic, only a soul orb is permitted to be targetted and the soul that is to be duplicated must be specified in the syntax as shown below.\n\nSyntax: 'cast *6 soul duplication at orb with death dragon'", this_player()); 
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int finaltime;

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(at->query_property("fumbled") > 0) {
	message("info", "This soul orb is destabilized and cannot have any of its souls duplicated.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "You accidentaly misdirect the connection and dissolve the soul you were attempting to duplicate!", caster);
	at->set_property(""+args+" souls", (at->query_property(""+args+" souls") - 1));
	remove();
	return;
    }
    if(!at->query_property(""+args+" souls")) {
	message("info", "This soul orb does not currently contain a "+args+" soul to be duplicated.", caster);
	remove();
	return;
    }
    if(at->query_property("soul orb finalize") > 0) {
	message("info", "This soul orb is finalized and cannot have its soul duplicated with this spell.", caster);
	remove();
	return;
    }
    if(args == "bone man") finaltime = 1800/power;
    if(args == "rotted zombie") finaltime = 2520/power;
    if(args == "skeletal zombie") finaltime = 3600/power;
    if(args == "revenant") finaltime = 4320/power;
    if(args == "blood hound") finaltime = 5400/power;
    if(args == "bone hound") finaltime = 6480/power;
    if(args == "undead beast") finaltime = 7920/power;
    if(args == "ghost") finaltime = 9000/power;
    if(args == "ghast dog") finaltime = 9720/power;
    if(args == "zombie spirit") finaltime = 10800/power;
    if(args == "skeletal essence") finaltime = 12600/power;
    if(args == "blood fiend") finaltime = 14400/power;
    if(args == "vampiric hound") finaltime = 15120/power;
    if(args == "fanged spirit") finaltime = 16200/power;
    if(args == "black essence") finaltime = 18000/power;
    if(args == "red ghoul") finaltime = 19800/power;
    if(args == "dark knight") finaltime = 21600/power;
    if(args == "blood knight") finaltime = 23400/power;
    if(args == "essence warrior") finaltime = 27000/power;
    if(args == "chaos shadow") finaltime = 28800/power;
    if(args == "soul knight") finaltime = 32400/power;
    if(args == "shadow beast") finaltime = 36000/power;
    if(args == "deathmage") finaltime = 39600/power;
    if(args == "gravewyrm") finaltime = 43200/power;
    if(args == "shadowflame templar") finaltime = 216000/power;
    if(args == "death dragon") finaltime = 324000/power;
    if(args == "nether lord") finaltime = 432000/power;
    if(args == "eternal darkness") finaltime = 4320000/power;
    set_property("long term exp", finaltime*20);
    if(wizardp(caster)) finaltime = 1;
    message("info", "%^BOLD%^%^RED%^You connect your magical powers to the soul and begin to create a complete copy of it!%^RESET%^", caster);
    set_work_message("%^BOLD%^%^BLUE%^You duplicate the soul.%^RESET%^");
    start_work(at, caster, finaltime, power);
    petname = args;
    return;
}

void finish_work(object caster, object at, int power) {

    if(power <= 0) {
	message("info", "BUG", environment(caster));
	remove();
	return;
    }
    at->set_property(""+petname+" souls", (at->query_property(""+petname+" souls") + 1));
    message("info", "%^BOLD%^%^RED%^You have successfully duplicated the soul!%^RESET%^", caster);
    message("info", ""+(string)caster->query_cap_name()+" finishes duplicating a soul within his soul orb.", environment(caster), ({ caster }));
    remove();
    return;
}
