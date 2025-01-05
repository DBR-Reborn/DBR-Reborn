inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "orb sacrifice");
    set_property("skill", "orb manipulation");
    set_property("duration", "until quit");
    set_property("casting time", 65);
    set_property("base mp cost", 192);
    set_property("dev cost", 97);
    set_property("fast dev cost", 308);
    set_property("spell level", 20);
    set_property("caster message", "You conjure up a powerful energy link in an attempt to siphon power away from a soul!");
    set_property("target message", "");
    set_property("observer message", "$C conjures up a powerful energy link in an attempt to siphon power away from a soul.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This magic gives a Nethermancer the means of sacrificing a soul orb by drawing power out of a nether category two soul trapped inside of its design and utilizing it as significantly strong knowledge for either skills or spells. After a sacrifice is complete on a given orb, the power gained will last until the caster logs out from the mud. This magic will only succeed if the orb it is cast upon is finalized with the spell 'orb finalization', and each sacrifice per login must be for a different type of soul for stacking is prohibited. The soul orb will shatter once this spell succeeds from the soul being outwardly drawn and the orb itself is gone forever. Below is a listing of all sacrifices that are valid with this spell alongside their level requirements and the skills/spells that are attained."+
      "\n\nBlood Fiend (Level 20)             Consume Soul, +140% spiritmancy\nVampiric Hound (Level 21)          Greater Curse, +150% curse lore\nFanged Spirit (Level 23)           +150% parry, +150% dodge\nBlack Essence (Level 25)           +650 AC Boost\nRed Ghoul (Level 27)               +175% attack, +175% two handed staff\nDark Knight (Level 30)             +3 Perfect Armour Bonus\nBlood Knight (Level 32)            Devour Soul, Darken Soul,\n                                   +190% spiritmancy\nEssence Warrior (Level 33)         +200% perception, +200% reverse stroke,\n                                   +100% combat awareness\n\nSyntax: 'cast *6 orb sacrifice at orb with blood knight'", this_player());
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
    if(args != "blood fiend" && args != "vampiric hound" && args != "fanged spirit" && args != "black essence" && args != "red ghoul" && args != "dark knight" && args != "blood knight" && args != "essence warrior") {
	message("info", "That argument cannot be used with this spell. See 'help spell orb sacrifice' for a listing of soul types that are valid.", caster);
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
    if(args == "blood fiend") {
	if(caster->query_level() < 20) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_spell("consume soul", power);
	if(caster->query_base_skill("spiritmancy") > 0) ob->add_new_skill_bonus("spiritmancy", 140*bonus);
	if(caster->query_base_skill("spiritmancy") < 1) ob->add_skill("spiritmancy", 140*bonus);
    }
    if(args == "vampiric hound") {
	if(caster->query_level() < 21) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_spell("greater curse", power);
	if(caster->query_base_skill("curse lore") > 0) ob->add_new_skill_bonus("curse lore", 150*bonus);
	if(caster->query_base_skill("curse lore") < 1) ob->add_skill("curse lore", 140*bonus);
    }
    if(args == "fanged spirit") {
	if(caster->query_level() < 23) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	if(caster->query_base_skill("parry") > 0) ob->add_new_skill_bonus("parry", 150*bonus);
	if(caster->query_base_skill("parry") < 1) ob->add_skill("parry", 150*bonus);
	if(caster->query_base_skill("dodge") > 0) ob->add_new_skill_bonus("dodge", 150*bonus);
	if(caster->query_base_skill("dodge") < 1) ob->add_skill("dodge", 150*bonus);
    }
    if(args == "black essence") {
	if(caster->query_level() < 25) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob = new("/std/spells/shadows/ac_shadow");
	ob->set_shad_ac(650*bonus);
    }
    if(args == "red ghoul") {
	if(caster->query_level() < 27) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	if(caster->query_base_skill("attack") > 0) ob->add_new_skill_bonus("attack", 175*bonus);
	if(caster->query_base_skill("attack") < 1) ob->add_skill("attack", 175*bonus);
	if(caster->query_base_skill("two handed staff") > 0) ob->add_new_skill_bonus("two handed staff", 175*bonus);
	if(caster->query_base_skill("two handed staff") < 1) ob->add_skill("two handed staff", 175*bonus);
    }
    if(args == "dark knight") {
	if(caster->query_level() < 30) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	caster->set("enhance criticals", (caster->query("enhance criticals") + 3));
    }
    if(args == "blood knight") {
	if(caster->query_level() < 32) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_spell("devour soul", power);
	ob->add_spell("darken soul", power);
	if(caster->query_base_skill("spiritmancy") > 0) ob->add_new_skill_bonus("spiritmancy", 190*bonus);
	if(caster->query_base_skill("spiritmancy") < 1) ob->add_skill("spiritmancy", 190*bonus);
    }
    if(args == "essence warrior") {
	if(caster->query_level() < 33) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	if(caster->query_base_skill("perception") > 0) ob->add_new_skill_bonus("perception", 200*bonus);
	if(caster->query_base_skill("perception") < 1) ob->add_skill("perception", 200*bonus);
	if(caster->query_base_skill("reverse stroke") > 0) ob->add_new_skill_bonus("reverse stroke", 200*bonus);
	if(caster->query_base_skill("reverse stroke") < 1) ob->add_skill("reverse stroke", 200*bonus);
	if(caster->query_base_skill("combat awareness") > 0) ob->add_new_skill_bonus("combat awareness", 100*bonus);
	if(caster->query_base_skill("combat awareness") < 1) ob->add_skill("combat awareness", 100*bonus);
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
