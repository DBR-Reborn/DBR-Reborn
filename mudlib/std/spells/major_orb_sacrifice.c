inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "major orb sacrifice");
    set_property("skill", "orb manipulation");
    set_property("duration", "until quit");
    set_property("casting time", 90);
    set_property("base mp cost", 341);
    set_property("dev cost", 180);
    set_property("fast dev cost", 540);
    set_property("spell level", 35);
    set_property("caster message", "You conjure up a powerful energy link in an attempt to siphon power away from a soul!");
    set_property("target message", "");
    set_property("observer message", "$C conjures up a powerful energy link in an attempt to siphon power away from a soul.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "With this spell, a relatively powerful Nethermancer will be able to sacrifice a soul orb through the means of channelling power away from a nether category three soul concealed within it, with the aforementioned action giving him or her extremely powerful skill and spell talents. When a sacrifice is successfully performed on an orb, the power attained from it will last until the caster decides to log out. To fully use this spell, each sacrifice per login must be of a different soul type and the orb it is cast on must have been finalized by the spell 'major orb finalization'. The soul orb will be destroyed upon completion of the spell casting when the soul is drawn outwards, and once shattered it cannot be retrieved. Displayed below is a list of all sacrifices that can be done through this magic as well as the mandatory levels the caster must possess to do them and the skills and spells granted from each."+
      "\n\nChaos Shadow (Level 35)            Life Vortex, Mana Vortex,\n                                   +220% spiritmancy, +220% mentalism\nSoul Knight (Level 38)             +250% attack, +250% two handed staff\nShadow Beast (Level 39)            +800 AC Boost\nDeathmage (Level 42)               Fumble Shield, Shatter Soul,\n                                   +260% channelling, +260% spiritmancy\nGravewyrm (Level 45)               Wind of Death, +300% necromancy\n\nSyntax: 'cast *6 major orb sacrifice at orb with chaos shadow'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object ob;
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
    if(args != "chaos shadow" && args != "soul knight" && args != "shadow beast" && args != "deathmage" && args != "gravewyrm") {
	message("info", "That argument cannot be used with this spell. See 'help spell major orb sacrifice' for a listing of soul types that are valid.", caster);
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
    if(args == "chaos shadow") {
	if(caster->query_level() < 35) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_spell("life vortex", power);
	ob->add_spell("mana vortex", power);
	ob->add_skill("mentalism", 220);
	ob->add_new_skill_bonus("spiritmancy", 220);
    }
    if(args == "soul knight") {
	if(caster->query_level() < 38) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_new_skill_bonus("attack", 250);
	ob->add_new_skill_bonus("two handed staff", 250);
    }
    if(args == "shadow beast") {
	if(caster->query_level() < 39) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob = new("/std/spells/shadows/ac_shadow");
	ob->set_shad_ac(800*bonus);
    }
    if(args == "deathmage") {
	if(caster->query_level() < 42) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_spell("fumble shield", power);
	ob->add_spell("shatter soul", power);
	ob->add_new_skill_bonus("channelling", 260);
	ob->add_new_skill_bonus("spiritmancy", 260);
    }
    if(args == "gravewyrm") {
	if(caster->query_level() < 45) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_spell("wind of death", power);
	ob->add_new_skill_bonus("necromancy", 300);
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
