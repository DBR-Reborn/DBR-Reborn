inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "elite orb sacrifice");
    set_property("skill", "orb manipulation");
    set_property("duration", "until quit");
    set_property("casting time", 135);
    set_property("base mp cost", 522);
    set_property("dev cost", 456);
    set_property("fast dev cost", 1393);
    set_property("spell level", 48);
    set_property("caster message", "You conjure up a powerful energy link in an attempt to siphon power away from a soul!");
    set_property("target message", "");
    set_property("observer message", "$C conjures up a powerful energy link in an attempt to siphon power away from a soul.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This spell permits true masters of the Nethermancer Guild to perform the most powerful of soul orb sacrifices by siphoning power from a nether category four soul encapsulated inside one, granting him/her excessively powerful skill and spell bonuses on par with the most powerful in Daybreak Ridge. After a sacrifice is finished on an orb, the power that is gained will last until the caster logs out. A soul orb must be finalized with the spell 'elite orb finalization' before this spell can succeed, and every sacrifice for each login must be of a different type of soul. Upon completion of the spell, the orb will be shattered from the soul expansion and it can never be fully restored. Listed below is a chart of all sacrifices that are possible from using this spell alongside the mandatory levels the caster is required to have to perform them as well as the skills and spells that each bestows."+
      "\n\nShadowflame Templar (Level 48)     +400% attack, +400% two handed staff,\n                                   Multiple Elemental Critbacks\nDeath Dragon (Level 52)            +7 Perfect Armour Bonus, +500 AC Boost\n                                   Invulnerable Shell,\n                                   +350% path of inevitability\nNether Lord (Level 55)             Ethereal Storm, Absorption,\n                                   +380% warcasting, +380% owedquar's will\n\nSyntax: 'cast *6 elite orb sacrifice at orb with death dragon'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object ob;
    object ob2;
    int bonus = 1;

    if(power > 9) bonus = 2;
    if(power > 15) bonus = 3;

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(at->query_property("soul orb finalize") < 1) {
	message("info", "This soul orb is not finalized and cannot yet be sacrificed into magical power.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "%^BOLD%^%^RED%^You inadvertently misdirect the energy and remove the soul orb's finalization!", caster);
	at->set_property("soul orb finalize", 0);
	at->set_short("A soul orb");
	remove();
	return;
    }
    if(args != "shadowflame templar" && args != "death dragon" && args != "nether lord") {
	message("info", "That argument cannot be used with this spell. See 'help spell elite orb sacrifice' for a listing of soul types that are valid.", caster);
	remove();
	return;
    }
    if(at->query_property(""+args+" souls") < 1) {
	message("info", "This orb is not finalized with a "+args+" soul.", caster);
	remove();
	return;
    }
    if(caster->query(""+args+" sacrifice") > 0) {
	message("info", "You have already sacrificed an orb containing a "+args+" soul during this login.", caster);
	remove();
	return;
    }
    ob = new("/std/spells/shadows/skill_shadow.c");
    if(args == "shadowflame templar") {
	if(caster->query_level() < 48) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_new_skill_bonus("attack", 400);
	ob->add_new_skill_bonus("two handed staff", 400);
	ob2 = new("/std/spells/shadows/ele_pres_shad");
	ob2->set_power(3);
	ob2->set_damage(({ "fire", "acid", "aether", "unholy" }));
	ob2->start_shadow(this_object(), 2000000000, "");
    }
    if(args == "death dragon") {
	if(caster->query_level() < 52) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob2 = new("/std/spells/shadows/ac_shadow");
	ob2->set_shad_ac(800*bonus);
	ob->add_spell("invulnerable shell", power);
	ob->add_skill("path of inevitability", 350);
	caster->set("enhance criticals", (caster->query("enhance criticals") - 7));
    }
    if(args == "nether lord") {
	if(caster->query_level() < 55) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_spell("ethereal storm", power);
	ob->add_spell("absorption", power);
	ob->add_new_skill_bonus("warcasting", 380);
	ob->add_new_skill_bonus("owedquar's will", 380);
    }
    ob->set_shadow_name(""+args+" sacrifice");
    ob->start_shadow(caster, 10000000);
    caster->set(""+args+" sacrifice", 1);
    message("info", "%^BOLD%^%^CYAN%^The orb explodes outward as you draw the power of its soul into your body, granting you a temporary boost in power!%^RESET%^", caster);
    message("info", "%^BOLD%^%^CYAN%^"+(string)caster->query_cap_name()+"'s orb explodes outward as he channels all the power of its soul into his body!%^RESET%^", environment(caster), ({ caster }));
    at->remove();
    remove();
    return;
}
