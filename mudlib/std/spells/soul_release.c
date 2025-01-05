inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "soul release");
    set_property("skill", "orb manipulation");
    set_property("duration", "permanent");
    set_property("casting time", 125);
    set_property("base mp cost", 353);
    set_property("dev cost", 205);
    set_property("fast dev cost", 615);
    set_property("spell level", 40);
    set_property("moon", "luna");
    set_property("caster message", "You attempt to directly release a soul from a soul orb.");
    set_property("target message","");
    set_property("observer message", "$C attempts to directly release a soul from a soul orb.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("info", "This spell allows a Nethermancer to magically release an infused or united soul from its dwelling inside of a soul orb. The soul once successfully released will be in the possession of the caster and can be later transferred to another soul orb through the means of the spell 'soul transference'. The chances of a soul being taken from an orb with this magic is 10% per power level, if the spell fails the orb will remain the same as it did before the casting. Only the most recent soul released will be in the caster's possession, and if it is not transferred at some point before the caster logs out or if another different soul is released beforehand it will be destroyed. When casting the spell, the soul orb must be stable and non-finalized, and type of soul that is to be removed from it must be included at the end of the syntax.\n\nSyntax: 'cast *6 soul release at orb with deathmage'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(at->query_property("fumbled") > 0) {
	message("info", "This soul orb is destabilized and cannot have any souls released.", caster);
	remove();
	return;
    }
    if(at->query_property("soul orb finalize") > 0) {
	message("info", "This orb is finalized and cannot have any of its contents altered.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "You inadvertently misdirect the energies of soul release and inadvertently destroy the soul!", caster);
	if(at->query_property(""+args+" souls") < 2) at->remove_property(""+args+" souls");
	if(at->query_property(""+args+" souls") > 1) at->set_property(""+args+" souls", ((int)at->query_property(""+args+" souls") - 1));
	remove();
	return;
    }
    if(args != "bone man" && args != "rotted zombie" && args != "skeletal zombie" && args != "revenant" && args != "blood hound" && args != "bone hound" && args != "undead beast" && args != "ghost" && args != "ghast dog" && args != "zombie spirit" && args != "skeletal essence" && args != "blood fiend" && args != "vampiric hound" && args != "fanged spirit" && args != "black essence" && args != "red ghoul" && args != "dark knight" && args != "blood knight" && args != "essence warrior" && args != "chaos shadow" && args != "soul knight" && args != "shadow beast" && args != "deathmage" && args != "gravewyrm" && args != "shadowflame templar" && args != "death dragon" && args != "nether lord" && args != "eternal darkness") {
	message("info", "This type of soul does not exist.", caster);
	remove();
	return;
    }
    if(!at->query_property(""+args+" souls")) {
	message("info", "There are currently no "+args+" souls present in this orb to release.", caster);
	remove();
	return;
    }
    if((random(10) + 1) > power) {
	message("info", "You fail to successfully release the soul from the orb.", caster);
	remove();
	return;
    }
    if(at->query_property(""+args+" souls") < 2) at->remove_property(""+args+" souls");
    if(at->query_property(""+args+" souls") > 1) at->set_property(""+args+" souls", ((int)at->query_property(""+args+" souls") - 1));
    caster->set("released soul", args);
    message("info", "%^BOLD%^%^BLACK%^You successfully release the soul from the orb and imbue it into your palm!%^RESET%^", caster);
    message("info", ""+(string)caster->query_cap_name()+" successfully releases a soul from an orb and imbues it into his palm.%^RESET%^", environment(caster), ({ caster }));
    remove();
    return;
}
