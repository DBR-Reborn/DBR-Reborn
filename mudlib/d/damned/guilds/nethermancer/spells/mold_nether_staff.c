inherit "/std/spells/long_term_spell";

string soulname;

void create() {
    ::create();
    set_property("name", "mold nether staff");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 99);
    set_property("dev cost", 57);
    set_property("fast dev cost", 174);
    set_property("spell level", 10);
    set_property("moon","luna");
    set_property("caster message", "You begin to mold several soul orbs together to create a nether staff.");
    set_property("target message", "");
    set_property("observer message", "$C begins to mold several soul orbs together to create a nether staff.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This spell lets a Nethermancer mold together the essences of several finalized soul orbs to create a very powerful weapon called a Nether Staff. Once created, the staff is permanent and will never degrade regardless of how much it is used in combat. To create the staff, three finalized soul orbs of the same soul are required to be in the casters inventory and the spell itself must be cast upon one of them. The spell will then transform the three orbs into a soul crystal which will then be molded into the staff. This is a long-term spell, and a great deal of time is required to complete it varying on the type of staff being made. A listing of the souls that can be utilized to make these weapons is displayed directly below.\n\n"+
      "Rotted Zombie:                     fire, cold (low)\nBlood Hound:                       disruption (medium)\nUndead Beast:                      electricity, sonic (medium)\nZombie Spirit:                     unholy, cold, acid (medium)\nBlood Fiend:                       plasma (high)\nVampiric Hound:                    time (high)\nRed Ghoul:                         crushing, strike, impact (high)\nEssence Warrior:                   acid, radiation (high)\nChaos Shadow:                      disruption, infernal (high)\nSoul Knight:                       time, reflection, stress (high)\nGravewyrm:                         all elements (low)\nShadowflame Templar:               unholy, fire, plasma (very high)\nNether Lord:                       aether (extremely high)\n\nSyntax: 'cast *6 mold nether staff at orb with nether lord'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    int orbs;
    int finaltime;
    string soultype;
    mixed desc;
    object ob, *ob_p;

    if(!at->id("soul orb") && !at->id("soul crystal")) {
	message("info", "This spell may only be cast upon a soul orb or a soul crystal.", caster);
	remove();
	return;
    }
    if(args != "rotted zombie" && args != "blood hound" && args != "undead beast" && args != "zombie spirit" && args != "blood fiend" && args != "vampiric hound" && args != "red ghoul" && args != "essence warrior" && args != "chaos shadow" && args != "soul knight" && args != "gravewyrm" && args != "shadowflame templar" && args != "nether lord") {
	message("info", "This argument is not a valid one to cast this spell with. See 'help spell mold nether staff' for a list of the arguments that are valid.", caster);
	remove();
	return;
    }
    if(at->id("soul orb") && at->query_property(""+args+" souls") < 1) {
	message("info", "This orb does not contain that soul within it.", caster);
	remove();
	return;
    }
    if(at->id("soul orb") && at->query_property("soul orb finalize") < 1) {
	message("info", "This orb is not finalized and cannot be used to create a nether staff.", caster);
	remove();
	return;
    }
    if(at->id("soul orb")) {
	ob_p = ({});
	orbs = 0;
	ob = first_inventory(caster);
	ob_p = ({});
	while(ob) {
	    if(ob->id("soul orb") && ob->query_property(""+args+" souls") > 0 && ob->query_property("soul orb finalize") > 0) {
		ob_p += ({ ob });
		orbs++;
	    }
	    ob = next_inventory(ob);
	}
	if(orbs < 3) {
	    message("info", "You must possess at least three finalized soul orbs of the same soul to proceed with this spell.", caster);
	    remove();
	    return;
	}
	at = new("/d/damned/guilds/nethermancer/misc/soul_crystal");
	orbs = 3;
	desc = at->query_property("extra long");
	if(!desc) desc = ({});
	desc += ({ "\n%^BOLD%^%^CYAN%^This crystal contains %^RED%^3%^CYAN%^ "+args+" souls." });
	at->set_property("extra long", desc);
	while(orbs--) ob_p[orbs]->remove();
	at->move(caster);
	message("info", "%^BOLD%^%^MAGENTA%^You magically mold three "+args+" finalized soul orbs into a soul crystal! With the crystal in hand, you begin to mold it further into a nether staff.%^RESET%^", caster);
	message("info", "%^BOLD%^%^MAGENTA%^"+(string)caster->query_cap_name()+" magically molds three "+args+" finalized soul orbs into a soul crystal! With the crystal in hand, he begins to mold it further into a nether staff.%^RESET%^", environment(caster), ({ caster }));
    }
    if(flag) {
	message("info", "You misdirectly the molding magics and instead mold your own body into a disfigured corpse!%^RESET%^", caster);
	caster->set_hp(-10);
	remove();
	return;
    }
    if(args == "rotted zombie") {
	finaltime = (5400/power);
	set_property("long term exp", 2*(250));
    }
    if(args == "blood hound") {
	finaltime = (10800/power);
	set_property("long term exp", 6*(250));
    }
    if(args == "undead beast") {
	finaltime = (16200/power);
	set_property("long term exp", 17*(250));
    }
    if(args == "zombie spirit") {
	finaltime = (21600/power);
	set_property("long term exp", 81*(250));
    }
    if(args == "blood fiend") {
	finaltime = (32400/power);
	set_property("long term exp", 136*(500));
    }
    if(args == "vampiric hound") {
	finaltime = (37800/power);
	set_property("long term exp", 168*(500));
    }
    if(args == "red ghoul") {
	finaltime = (54000/power);
	set_property("long term exp", 499*(500));
    }
    if(args == "essence warrior") {
	finaltime = (64800/power);
	set_property("long term exp", 1141*(500));
    }
    if(args == "chaos shadow") {
	finaltime = (75600/power);
	set_property("long term exp", 1460*(500));
    }
    if(args == "soul knight") {
	finaltime = (86400/power);
	set_property("long term exp", 2060*(500));
    }
    if(args == "gravewyrm") {
	finaltime = (108000/power);
	set_property("long term exp", 4167*(500));
    }
    if(args == "shadowflame templar") {
	finaltime = (172800/power);
	set_property("long term exp", 4723*(750));
    }
    if(args == "nether lord") {
	finaltime = (216000/power);
	set_property("long term exp", 4723*(750));
    }
    if(wizardp(caster)) finaltime = 1;
    set_work_message("%^BOLD%^%^MAGENTA%^You mold the nether staff.%^RESET%^");
    start_work(at, caster, finaltime, power);
    soulname = args;
    return;
}

void finish_work(object caster, object at, int power) {
    object ob;

    if(power <= 0) {
	message("info", "BUG", environment(caster));
	remove();
	return;
    }
    message("info", "%^BOLD%^%^GREEN%^The crystal is successfully molded into a powerful nether staff!%^RESET%^", caster);
    message("info", "%^BOLD%^%^GREEN%^"+(string)caster->query_cap_name()+" successfully molds a soul crystal into a powerful nether staff!%^RESET%^", environment(caster), ({ caster }));
    seteuid(getuid());
    ob = new("/d/damned/guilds/nethermancer/misc/nether_staff");
    if(soulname == "rotted zombie") {
	ob->add_wc(50, "fire");
	ob->add_wc(50, "cold");
	ob->set_enh_critical(1);
    }
    if(soulname == "blood hound") {
	ob->add_wc(100, "disruption");
	ob->set_enh_critical(2);
    }
    if(soulname == "undead beast") {
	ob->add_wc(100, "electricity");
	ob->add_wc(100, "sonic");
	ob->set_enh_critical(2);
    }
    if(soulname == "zombie spirit") {
	ob->add_wc(100, "unholy");
	ob->add_wc(100, "cold");
	ob->add_wc(100, "acid");
	ob->set_enh_critical(2);
    }
    if(soulname == "blood fiend") {
	ob->add_wc(200, "plasma");
	ob->set_enh_critical(4);
    }
    if(soulname == "vampiric hound") {
	ob->add_wc(200, "time");
	ob->set_enh_critical(4);
    }
    if(soulname == "red ghoul") {
	ob->add_wc(200, "crushing");
	ob->add_wc(200, "strike");
	ob->add_wc(200, "impact");
	ob->set_enh_critical(4);
    }
    if(soulname == "essence warrior") {
	ob->add_wc(200, "acid");
	ob->add_wc(200, "radiation");
	ob->set_enh_critical(4);
    }
    if(soulname == "chaos shadow") {
	ob->add_wc(250, "disruption");
	ob->add_wc(250, "infernal");
	ob->set_enh_critical(5);
    }
    if(soulname == "soul knight") {
	ob->add_wc(250, "time");
	ob->add_wc(250, "reflection");
	ob->add_wc(250, "stress");
	ob->set_enh_critical(5);
    }
    if(soulname == "gravewyrm") {
	ob->add_wc(50, "acid");
	ob->add_wc(50, "aether");
	ob->add_wc(50, "cold");
	ob->add_wc(50, "crushing");
	ob->add_wc(50, "cutting");
	ob->add_wc(50, "unholy");
	ob->add_wc(50, "disruption");
	ob->add_wc(50, "electricity");
	ob->add_wc(50, "fire");
	ob->add_wc(50, "holy");
	ob->add_wc(50, "impact");
	ob->add_wc(50, "impaling");
	ob->add_wc(50, "internal");
	ob->add_wc(50, "light");
	ob->add_wc(50, "plasma");
	ob->add_wc(50, "radiation");
	ob->add_wc(50, "reflection");
	ob->add_wc(50, "royal");
	ob->add_wc(50, "sonic");
	ob->add_wc(50, "stress");
	ob->add_wc(50, "strike");
	ob->add_wc(50, "time");
	ob->add_wc(50, "vacuum");
	ob->set_enh_critical(5);
    }
    if(soulname == "shadowflame templar") {
	ob->add_wc(350, "unholy");
	ob->add_wc(350, "fire");
	ob->add_wc(350, "plasma");
	ob->set_enh_critical(6);
    }
    if(soulname == "nether lord") {
	ob->add_wc(500, "aether");
	ob->set_enh_critical(6);
    }
    at->remove();
    ob->move(caster);
    remove();
    return;
}
