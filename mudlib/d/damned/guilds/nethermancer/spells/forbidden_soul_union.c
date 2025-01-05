inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "forbidden soul union");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 700);
    set_property("dev cost", 7777);
    set_property("fast dev cost", 22500);
    set_property("spell level", 58);
    set_property("moon", "luna");
    set_property("caster message", "You begin to magically perform a union of damned souls.");
    set_property("target message","");
    set_property("observer message", "$C begins to magically perform a union of damned souls.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This powerful spell allows a Nethermancer to unite numerous incredibly powerful souls to create the ultimate soul of the damned, the soul of the Eternal Darkness. Once the soul has been created, the soul orb can then be finalized for the undead creation of the single most powerful pet in the realm of Daybreak Ridge. In order to use this spell however, a charged master nexus must be present within the same room as the caster, and the spell itself must be cast upon a soul orb in his or her direct possession. This is a long-term spell (see help long-term), but its overall time can be reduced by the latent skill 'forbidden nether arts'. If you are interrupted while casting, you may resume the casting at a later time provided a nexus and the same soul orb is available. When casting the spell, no argument need be supplied because unlike with other soul union spells only one soul can be created from this spell. Below is the number of pets required for and the minimum level required to perform the union."+
      "\n\nEternal Darkness (Level 60):       Shadowflame Templar(6)\n                                   Death Dragon(6)\n                                   Nether Lord(6)\n\nSyntax: 'cast *6 forbidden soul union at orb'\n\nNOTE: Due to the extreme power of the Eternal Darkness, this spell gives no long-term experience.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("forbidden nether arts") * 8;
    int exp = caster->query_base_skill("forbidden nether erudition") / 2;
    int finaltime;

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(!present("nexus", environment(caster))) {
	message("info", "A nexus must be present in the room in order to cast this spell.", caster);
	remove();
	return;
    }
    if(at->query_property("fumbled") > 0) {
	message("info", "This soul orb is destabilized and cannot recieve any more souls.", caster);
	remove();
	return;
    }
    if(at->query_property("soul orb finalize") > 0) {
	message("info", "This soul orb has been finalized for sacrifice or undead creation and therefore cannot recieve any more souls.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "You accidently destabilize the soul orb, preventing it from recieving any new souls!", caster);
	at->set_property("fumbled", 1);
	remove();
	return;
    }
    if(present("nexus", environment(caster))->query_name() != "master nexus") {
	message("info", "The nexus in the room is not powerful enough to perform this magic.", caster);
	remove();
	return;
    }
    if(caster->query_level() < 60) {
	message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	remove();
	return;
    }
    if(at->query_property("shadowflame templar souls") < 6 || at->query_property("death dragon souls") < 6 || at->query_property("nether lord souls") < 6) {
	message("info", "There are not enough shadowflame templar, death dragon, and/or nether lord souls in this orb with which to perform this union.", caster);
	remove();
	return;
    }
    finaltime = (432000/power) - bonus;
    set_property("long term exp", 0);
    if(finaltime < 5) finaltime = 5;
    if(wizardp(caster)) finaltime = 1;
    message("info", "%^ORANGE%^You establish a link with the nexus in the room and begin joining the souls!%^RESET%^", caster);
    set_work_message("%^BOLD%^%^BLUE%^You join the souls.%^RESET%^");
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
    at->set_property("shadowflame templar souls", (at->query_property("shadowflame templar souls") - 8));
    at->set_property("death dragon souls", (at->query_property("death dragon souls") - 8));
    at->set_property("nether lord souls", (at->query_property("nether lord souls") - 8));
    at->set_property("eternal darkness souls", (at->query_property("eternal darkness souls") + 1));
    message("info", ""+(string)caster->query_cap_name()+" finishes performing a soul union.", environment(caster), ({ caster }));
    at->set_property("total souls", 2);
    remove();
    return;
}
