inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "forbidden orb finalization");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 733);
    set_property("dev cost", 9999);
    set_property("fast dev cost", 31100);
    set_property("spell level", 59);
    set_property("caster message", "You attempt to finalize a soul of the netherworld.");
    set_property("target message", "");
    set_property("observer message", "$C attempts to finalize a soul of the netherworld.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This extremely powerful magic gives the most powerful of all Nethermancers the ability to finalize a soul orb for creation of the legendary Eternal Darkness of the Netherworld. After the end of the finalization period, the orb will not be able to recieve any added souls and in addition all of the souls present in the orb except one soul for the Eternal Darkness will be destroyed. This is a long-term spell (see help long-term), and a very high amount of time is necessary to complete it. That time however can be noticably lowered by the latent 'forbidden nether arts' skill. Since this spell is only effective to finalize an orb for a single type of soul, no argument need be supplied in the syntax.\n\nSyntax: 'cast *6 forbidden orb finalization at orb'\n\nNOTE: Due to the extreme power of the Eternal Darkness, this spell gives no long-term experience.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("forbidden nether arts") * 8;
    int exp = caster->query_base_skill("forbidden nether erudition") / 2;
    int finaltime;

    petname = args;

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(at->query_property("soul orb finalize") > 0) {
	message("info", "This soul orb has already been finalized.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "%^BOLD%^%^RED%^You misdirect the finalization energies and blast your own body with them, instantly dropping your horribly damaged body to the floor!%^RESET%^", caster);
	caster->set_hp(-1);
	remove();
	return;
    }
    if(caster->query_level() < 60) {
	message("info", "You are not yet high enough level to finalize this orb for the Eternal Darkness.", caster);
	remove();
	return;
    }
    if(at->query_property("eternal darkness souls") < 1) {
	message("info", "This orb does not contain an Eternal Darkness soul to be finalized for.", caster);
	remove();
	return;
    }
    finaltime = (180000/power) - bonus;
    set_property("long term exp", 0);
    if(finaltime < 5) finaltime = 5;
    if(archp(caster)) finaltime = 1;
    message("info", "%^BOLD%^%^CYAN%^You encapsulate the soul orb in a sphere of magical power and begin the endeavour of finalization!%^RESET%^", caster);
    set_work_message("%^BOLD%^%^BLUE%^You finalize the orb.%^RESET%^");
    start_work(at, caster, finaltime, power);
    return;
}

void finish_work(object caster, object at, int power) {

    if(power <= 0) {
	message("info", "BUG", environment(caster));
	remove();
	return;
    }
    at->remove_all_properties();
    at->set_property(""+petname+" souls", 1);
    at->set_property("soul orb finalize", 1);
    message("info", "%^BOLD%^%^BLUE%^You have successfully finalized the soul orb! It may now either be sacrificed for temporary abilities or transformed into an undead pet with appropriate magics.%^RESET%^", caster);
    message("info", "%^BOLD%^%^BLUE%^"+(string)caster->query_cap_name()+" successfully finalizes a soul orb!", environment(caster), ({ caster }));
    at->set_property("total souls", 2);
}
