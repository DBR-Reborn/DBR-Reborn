inherit "/std/spells/long_term_spell";

string soulname;

void create() {
    ::create();
    set_property("name", "mold nether robe");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("dev cost", 55);
    set_property("fast dev cost", 165);
    set_property("base mp cost", 94);
    set_property("spell level", 10);
    set_property("moon","luna");
    set_property("caster message", "You begin to mold several soul orbs together to create a nether robe.");
    set_property("target message", "");
    set_property("observer message", "$C begins to mold several soul orbs together to create a nether robe.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This magic gives a Nethermancer the ability to mold together several souls encapsulated within finalized orbs to fashion a Nether Robe, an extremely useful piece of armour that only they may wear. The robe is permanent once created and is one of the rare robes in Daybreak Ridge that covers all available limbs on the body of its wearer. In order to design the robe, three finalized soul orbs must be in the inventory of the caster and the spell must be cast upon any one of them. The orbs will then be melded together into a soul crystal which from there will be further crafted into the actual robe. This is a long-term spell, and a significant amount of time is necessary to complete it depending on the souls in the crystal that are being dedicated to the robe. Listed below is a chart of all souls that are permitted to be used in robe creations.\n\n"+ 
      "Bone Man:                          impaling, cutting, crushing (low)\nSkeletal Zombie:                   fire, cold, electricity (low)\nRevenant:                          vacuum, strike, disruption (low)\nBone Hound:                        impact (medium)\nGhost:                             unholy, cold, holy (medium)\nGhast Dog:                         disruption, aether, infernal (medium)\nSkeletal Essence:                  plasma, disruption, vacuum (medium)\nFanged Spirit:                     infernal, aether, unholy (medium)\nBlack Essence:                     unholy (high)\nDark Knight:                       impaling, stress, crushing (high)\nBlood Knight:                      infernal, aether, unholy (high)\nShadow Beast:                      cold (extremely high)\nDeathmage:                         unholy, infernal, aether (very high)\nDeath Dragon:                      all elements (very high)\n\nSyntax: 'cast *6 mold nether robe at orb with death dragon'", this_player());
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
    if(args != "bone man" && args != "skeletal zombie" && args != "revenant" && args != "bone hound" && args != "ghost" && args != "ghast dog" && args != "skeletal essence" && args != "fanged spirit" && args != "black essence" && args != "dark knight" && args != "blood knight" && args != "shadow beast" && args != "deathmage" && args != "death dragon") {
	message("info", "This argument is not valid for this spell. See 'help spell mold nether robe' for a list of arguments that can be used.", caster);
	remove();
	return;
    }
    if(at->id("soul orb") && at->query_property(""+args+" souls") < 1) {
	message("info", "This orb does not contain that soul within it.", caster);
	remove();
	return;
    }
    if(at->id("soul orb") && at->query_property("soul orb finalize") < 1) {
	message("info", "This orb is not finalized and cannot be utilized to create a nether robe.", caster);
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
	message("info", "%^BOLD%^%^MAGENTA%^You magically mold three "+args+" finalized soul orbs into a soul crystal! With the crystal in hand, you begin to mold it further into a nether robe.%^RESET%^", caster);
	message("info", "%^BOLD%^%^MAGENTA%^"+(string)caster->query_cap_name()+" magically molds three "+args+" finalized soul orbs into a soul crystal! With the crystal in hand, he begins to mold it further into a nether robe.%^RESET%^", environment(caster), ({ caster }));
    }
    if(flag) {
	message("info", "You misdirectly the molding magics and instead mold your own body into a disfigured corpse!%^RESET%^", caster);
	caster->set_hp(-10);
	remove();
	return;
    }
    if(args == "bone man") {
	finaltime = (5400/power);
	set_property("long term exp", 2*(250));
    }
    if(args == "skeletal zombie") {
	finaltime = (10800/power);
	set_property("long term exp", 3*(250));
    }
    if(args == "revenant") {
	finaltime = (16200/power);
	set_property("long term exp", 4*(250));
    }
    if(args == "bone hound") {
	finaltime = (21600/power);
	set_property("long term exp", 12*(250));
    }
    if(args == "ghost") {
	finaltime = (32400/power);
	set_property("long term exp", 33*(250));
    }
    if(args == "ghast dog") {
	finaltime = (37800/power);
	set_property("long term exp", 60*(250));
    }
    if(args == "skeletal essence") {
	finaltime = (54000/power);
	set_property("long term exp", 174*(250));
    }
    if(args == "fanged spirit") {
	finaltime = (64800/power);
	set_property("long term exp", 247*(500));
    }
    if(args == "black essence") {
	finaltime = (75600/power);
	set_property("long term exp", 353*(500));
    }
    if(args == "dark knight") {
	finaltime = (86400/power);
	set_property("long term exp", 763*(500));
    }
    if(args == "blood knight") {
	finaltime = (108000/power);
	set_property("long term exp", 1002*(500));
    }
    if(args == "shadow beast") {
	finaltime = (129600/power);
	set_property("long term exp", 2296*(500));
    }
    if(args == "deathmage") {
	finaltime = (162000/power);
	set_property("long term exp", 3128*(500));
    }
    if(args == "death dragon") {
	finaltime = (216000/power);
	set_property("long term exp", 4723*(750));
    }
    if(wizardp(caster)) finaltime = 1;
    set_work_message("%^BOLD%^%^MAGENTA%^You mold the nether robe.%^RESET%^");
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
    message("info", "%^BOLD%^%^GREEN%^The crystal is successfully molded into a powerful nether robe!%^RESET%^", caster);
    message("info", "%^BOLD%^%^GREEN%^"+(string)caster->query_cap_name()+" successfully molds a soul crystal into a powerful nether robe!%^RESET%^", environment(caster), ({ caster }));
    seteuid(getuid());
    ob = new("/d/damned/guilds/nethermancer/misc/nether_robe");
    if(soulname == "bone man") {
	ob->add_ac(50, "impaling");
	ob->add_ac(50, "cutting");
	ob->add_ac(50, "crushing");
	ob->set_enh_critical(-1);
    }
    if(soulname == "skeletal zombie") {
	ob->add_ac(70, "fire"); 
	ob->add_ac(70, "cold"); 
	ob->add_ac(70, "electricity"); 
	ob->set_enh_critical(-1);
    }
    if(soulname == "revenant") {
	ob->add_ac(75, "strike"); 
	ob->add_ac(75, "vacuum"); 
	ob->add_ac(75, "disruption"); 
	ob->set_enh_critical(-1);
    }
    if(soulname == "bone hound") {
	ob->add_ac(150, "impact");
	ob->set_enh_critical(-1);
    }
    if(soulname == "ghost") {
	ob->add_ac(100, "unholy");
	ob->add_ac(100, "cold");
	ob->add_ac(100, "holy");
	ob->set_enh_critical(-1);
    }
    if(soulname == "ghast dog") {
	ob->add_ac(100, "disruption");
	ob->add_ac(100, "aether");
	ob->add_ac(100, "infernal");
	ob->set_enh_critical(-1);
    }
    if(soulname == "skeletal essence") {
	ob->add_ac(150, "plasma");
	ob->add_ac(150, "disruption");
	ob->add_ac(150, "vacuum");
	ob->set_enh_critical(-1);
    }
    if(soulname == "fanged spirit") {
	ob->add_ac(200, "infernal");
	ob->add_ac(200, "aether");
	ob->add_ac(200, "unholy");
	ob->set_enh_critical(-1);
    }
    if(soulname == "black essence") {
	ob->add_ac(350, "unholy");
	ob->set_enh_critical(-2);
    }
    if(soulname == "dark knight") {
	ob->add_ac(300, "impaling");
	ob->add_ac(300, "stress");
	ob->add_ac(300, "crushing");
	ob->set_enh_critical(-2);
    }
    if(soulname == "blood knight") {
	ob->add_ac(300, "infernal");
	ob->add_ac(300, "aether");
	ob->add_ac(300, "unholy");
	ob->set_enh_critical(-3);
    }
    if(soulname == "shadow beast") {
	ob->add_ac(700, "cold");
	ob->set_enh_critical(-3);
    }
    if(soulname == "deathmage") {
	ob->add_ac(450, "unholy");
	ob->add_ac(450, "infernal");
	ob->add_ac(450, "aether");
	ob->set_enh_critical(-3);
    }
    if(soulname == "death dragon") {
	ob->add_ac(500, "aether");
	ob->add_ac(500, "cold");
	ob->add_ac(500, "crushing");
	ob->add_ac(500, "cutting");
	ob->add_ac(500, "unholy");
	ob->add_ac(500, "disruption");
	ob->add_ac(500, "electricity");
	ob->add_ac(500, "fire");
	ob->add_ac(500, "holy");
	ob->add_ac(500, "impact");
	ob->add_ac(500, "impaling");
	ob->add_ac(500, "infernal");
	ob->add_ac(500, "plasma");
	ob->add_ac(500, "stress");
	ob->add_ac(500, "strike");
	ob->add_ac(500, "vacuum");
	ob->set_enh_critical(-4);
    }
    at->remove();
    ob->move(caster);
    remove();
    return;
}

