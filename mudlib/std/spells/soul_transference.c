inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "soul transference");
    set_property("skill", "orb manipulation");
    set_property("duration", "permanent");
    set_property("casting time", 175);
    set_property("base mp cost", 401);
    set_property("dev cost", 215);
    set_property("fast dev cost", 645);
    set_property("spell level", 42);
    set_property("moon", "luna");
    set_property("caster message", "You extend your palm towards a soul orb in an attempt to transfer a soul into its care.");
    set_property("target message","");
    set_property("observer message", "$C extends his palm towards a soul orb in an attempt to transfer a soul into its care.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("info", "This magic permits a Nethermancer to directly transfer a soul taken from a soul orb and imbued within his or her palm from the spell 'soul release' into an entirely different soul orb. Once transferred, the soul can be used along with other souls already present in soul unions or it can be used by itself in the same manner as if the soul was originally conceived within that orb. Only one soul may be transferred at a time with this spell, and only the most recently released and palm imbued soul can be used with this spell (see help spell 'soul release'). This spell has a 10% chance of success for each power level of the spell when it is casted, and if the spell does not succeed everything will remain unaffected. The soul orb this magic is being cast at must be stable and not finalized at the time of the casting, and no argument need be supplied in the syntax.\n\nSyntax: 'cast *6 soul transference at orb'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    string soultype = caster->query("released soul");

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(at->query_property("fumbled") > 0) {
	message("info", "This soul orb is destabilized and cannot have any souls transferred into it.", caster);
	remove();
	return;
    }
    if(at->query_property("soul orb finalize") > 0) {
	message("info", "This orb is finalized and cannot have any souls transferred to it.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "You inadvertently misdirect the energies of soul release and inadvertently destroy the soul!", caster);
	message("info", "You accidently misdirect the soul transference and instead destroy the soul!", caster);
	caster->set("released soul", "none");
	remove();
	return;
    }
    if(!caster->query("released soul") || caster->query("released soul") == "none") {
	message("info", "You do not have a soul in your possession to transfer with this spell.", caster);
	remove();
	return;
    }
    if((random(10) + 1) > power) {
	message("info", "Your attempt to transfer the soul into the orb was not successful.", caster);
	remove();
	return;
    }
    if(!at->query_property("total souls")) at->set_property("total souls", 1);
    at->set_property(""+soultype+" souls", ((int)at->query_property(""+soultype+" souls") + 1));
    caster->set("released soul", "none");
    message("info", "%^BOLD%^%^BLACK%^You successfully transfer the soul from your possession into the soul orb!%^RESET%^", caster);
    message("info", ""+(string)caster->query_cap_name()+" successfully transfers a soul from his possession into a soul orb.", environment(caster), ({ caster }));
    remove();
    return;
}
