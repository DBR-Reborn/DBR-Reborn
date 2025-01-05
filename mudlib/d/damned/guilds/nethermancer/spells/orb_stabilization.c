inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name", "orb stabilization");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 220);
    set_property("dev cost", 141);
    set_property("fast dev cost", 433);
    set_property("spell level", 24);
    set_property("moon", "luna");
    set_property("caster message", "You begin to attempt stabilizing a soul orb.");
    set_property("target message","");
    set_property("observer message", "$C begins to attempt stabilizing a soul orb.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This particularly useful spell enables a Nethermancer to restabilize soul orbs that have been destabilized by the fumbling of certain long-term magics. When an orb is restabilized, it will be returned to a non-finalized state containing all of its souls and new souls may once again be added to create various different soul combinations as if the aforementioned spell fumble never took place. This is a long-term spell (see help long-term), and can take very much real time to complete. The overall time of this long term is determined by power of the spell as well as the amount and type of souls in the destabilized orb. Unlike numerous other Nethermancer long terms, the completion time is NOT affected by any nether arts skills. This spell may only be cast at a destabilized soul orb, and no argument need be supplied.\n\nSyntax: 'cast *6 orb stabilization at orb'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int finaltime;

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(at->query_property("fumbled") != 1) {
	message("info", "This soul orb is already stable.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "In your attempts to stabilize the soul orb, you instead misdirect the energy upon your own body! Charred beyond all recognition, it drops dead with little suffering", caster);
	caster->die();
	remove();
	return;
    }
    finaltime = finaltime + (at->query_property("bone man souls")*300);
    finaltime = finaltime + (at->query_property("rotted zombie souls")*600);
    finaltime = finaltime + (at->query_property("skeletal zombie souls")*900);
    finaltime = finaltime + (at->query_property("revenant souls")*1200);
    finaltime = finaltime + (at->query_property("blood hound souls")*1500);
    finaltime = finaltime + (at->query_property("bone hound souls")*1800);
    finaltime = finaltime + (at->query_property("undead beast souls")*2100);
    finaltime = finaltime + (at->query_property("ghost souls")*2400);
    finaltime = finaltime + (at->query_property("ghast dog souls")*2700);
    finaltime = finaltime + (at->query_property("zombie spirit souls")*3000);
    finaltime = finaltime + (at->query_property("skeletal essence souls")*3300);
    finaltime = finaltime + (at->query_property("blood fiend souls")*3600);
    finaltime = finaltime + (at->query_property("vampiric hound souls")*4200);
    finaltime = finaltime + (at->query_property("fanged spirit souls")*4800);
    finaltime = finaltime + (at->query_property("black essence souls")*5400);
    finaltime = finaltime + (at->query_property("red ghoul souls")*6000);
    finaltime = finaltime + (at->query_property("dark knight souls")*6600);
    finaltime = finaltime + (at->query_property("blood knight souls")*7200);
    finaltime = finaltime + (at->query_property("essence warrior souls")*7800);
    finaltime = finaltime + (at->query_property("chaos shadow souls")*8400);
    finaltime = finaltime + (at->query_property("soul knight souls")*9000);
    finaltime = finaltime + (at->query_property("shadow beast souls")*9600);
    finaltime = finaltime + (at->query_property("deathmage souls")*10200);
    finaltime = finaltime + (at->query_property("gravewyrm souls")*10800);
    finaltime = finaltime + (at->query_property("shadowflame templar souls")*12000);
    finaltime = finaltime + (at->query_property("death dragon souls")*13200);
    finaltime = finaltime + (at->query_property("nether lord souls")*14400);
    finaltime = finaltime + (at->query_property("eternal darkness souls")*21600);

    set_property("long term exp", finaltime*10);
    finaltime = finaltime/power;

    if(finaltime < 5) finaltime = 5;
    if(wizardp(caster)) finaltime = 1;
    message("info", "%^BOLD%^%^RED%^You successfully bond your magic onto the soul orb and begin to restabilize it!%^RESET%^", caster);
    set_work_message("%^BOLD%^%^BLUE%^You stabilize the orb.%^RESET%^");
    start_work(at, caster, finaltime, power);
    return;
}

void finish_work(object caster, object at, int power) {

    if(power <= 0) {
	message("info", "BUG", environment(caster));
	remove();
	return;
    }
    message("info", "You have successfully stabilized the soul orb!", caster);
    message("info", ""+(string)caster->query_cap_name()+" finishes stabilizing a soul orb.", environment(caster), ({ caster }));
    at->remove_property("fumbled");
    at->set_short("A soul orb");
    remove();
    return;
}
