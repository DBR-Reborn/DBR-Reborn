inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "minor orb sacrifice");
    set_property("skill", "orb manipulation");
    set_property("duration", "until quit");
    set_property("casting time", 40);
    set_property("base mp cost", 44);
    set_property("dev cost", 19);
    set_property("fast dev cost", 59);
    set_property("spell level", 1);
    set_property("caster message", "You conjure up a powerful energy link in an attempt to siphon power away from a soul!");
    set_property("target message", "");
    set_property("observer message", "$C conjures up a powerful energy link in an attempt to siphon power away from a soul.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This is a spell that gives a Nethermancer the power to sacrifice a soul orb with the intention of channelling power away from a nether category one soul contained within it and transforming that power into temporary skill or spell knowledge. When a sacrifice is completed on an orb, the power attained from it will remain on the caster until he or she decides to log out and will not vanish for any other reason. This spell will only be effective if it is cast upon a soul orb finalized with the spell 'minor orb finalization', and each individual sacrifice must be of an orb with a different soul because no stacking of abilities from the same exact type of orb is permitted. The orb this spell is cast on will be shattered instantly through the power of the soul being drawn out of it and it cannot be restored. A listing is below of all the valid sacrifices that can be carried out with this magic as well as the level prerequisites for each sacrifice and the abilities gained from them."+
      "\n\nBone Man (Level 1)                 +30% attack, +30% two handed staff\nRotted Zombie (Level 3)            +100 AC Boost\nSkeletal Zombie (Level 4)          Cold Blast, 60% necromancy\nRevenant (Level 5)                 +50% attack, +50% two handed staff\nBlood Hound (Level 7)              Instill Poison, 80% body alteration\nBone Hound (Level 9)               +250 AC Boost\nUndead Beast (Level 10)            +80% attack, +80% two handed staff\nGhost (Level 12)                   Decay, Dark Assault, 110% necromancy,\n                                   110% owedquar's will\nGhast Dog (Level 14)               +400 AC Boost\nZombie Spirit (Level 15)           +100% parry, +100% dodge\nSkeletal Essence (Level 18)        +125% attack, +125% two handed staff\n\nSyntax: 'cast *6 minor orb sacrifice at orb with undead beast'", this_player());
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
    if(args != "bone man" && args != "rotted zombie" && args != "skeletal zombie" && args != "revenant" && args != "blood hound" && args != "bone hound" && args != "undead beast" && args != "ghost" && args != "ghast dog" && args != "zombie spirit" && args != "skeletal essence") {
	message("info", "That argument cannot be used with this spell. See 'help spell minor orb sacrifice' for a listing of soul types that are valid.", caster);
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
    if(args == "bone man") {
	if(caster->query_level() < 1) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_new_skill_bonus("attack", 30*bonus);
	ob->add_new_skill_bonus("two handed staff", 30*bonus);
    }
    if(args == "rotted zombie") {
	if(caster->query_level() < 3) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob = new("/std/spells/shadows/ac_shadow");
	ob->set_shad_ac(100*bonus);
    }
    if(args == "skeletal zombie") {
	if(caster->query_level() < 4) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_spell("cold blast", power);
	ob->add_new_skill_bonus("necromancy", 60*bonus);
    }
    if(args == "revenant") {
	if(caster->query_level() < 5) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_new_skill_bonus("attack", 50*bonus);
	ob->add_new_skill_bonus("two handed staff", 50*bonus);
    }
    if(args == "blood hound") {
	if(caster->query_level() < 7) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_spell("instill poison", power);
	ob->add_new_skill_bonus("body alteration", 80*bonus);
    }
    if(args == "bone hound") {
	if(caster->query_level() < 9) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob = new("/std/spells/shadows/ac_shadow");
	ob->set_shad_ac(250*bonus);
    }
    if(args == "undead beast") {
	if(caster->query_level() < 10) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_new_skill_bonus("attack", 80*bonus);
	ob->add_new_skill_bonus("two handed staff", 80*bonus);
    }
    if(args == "ghost") {
	if(caster->query_level() < 12) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_spell("decay", power);
	ob->add_spell("dark assault", power);
	ob->add_new_skill_bonus("necromancy", 110*bonus);
	ob->add_new_skill_bonus("owedquar's will", 110*bonus);
    }
    if(args == "ghast dog") {
	if(caster->query_level() < 14) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob = new("/std/spells/shadows/ac_shadow");
	ob->set_shad_ac(400*bonus);
    }
    if(args == "zombie spirit") {
	if(caster->query_level() < 15) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_new_skill_bonus("parry", 100*bonus);
	ob->add_new_skill_bonus("dodge", 100*bonus);
    }
    if(args == "skeletal essence") {
	if(caster->query_level() < 18) {
	    message("info", "You are not yet high enough level to successfully sacrifice this soul orb.", caster);
	    remove();
	    return;
	}
	ob->add_new_skill_bonus("attack", 125*bonus);
	ob->add_new_skill_bonus("two handed staff", 125*bonus);
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
