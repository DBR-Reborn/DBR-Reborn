// Mineral Change spell
// -Tailwind  8/08/2000

#define MATERIALS ({\
"test", \
"eonmite", \
"iysaughton", \
"laen", \
"mithril", \
"elrodnite", \
"platnite", \
"raysorite", \
"javednite", \
"davistone", \
"mabril", \
"iron", \
"inniculmoid", \
"catoetine", \
"mcgrail", \
"boernerine", \
"steel", \
})

#include "/wizards/stoney/data/m_table.h"

inherit "/std/spells/long_term_spell";
inherit "/std/check_brittle.c";

string mineralname;

void create() {
    ::create();
    set_property("name","mineral change");
    set_property("skill","alchemy");
    set_property("duration", "permanent");
    set_property("casting time",8);
    set_property("base mp cost",120);
    set_property("dev cost", 155);
    set_property("fast dev cost", 253);
    set_property("spell level", 30);
    set_property("moon","luna");
    set_property("caster message","You break out some chemicals from the lab and do some magic material morphing.");
    set_property("target message","");
    set_property("observer message","$C does something weird with $T concerning a lot of lab chemicals.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help",
      "This spell allows the alchemist to change the material of  "
      "weapons or armour. Higher power levels  "
      "will shorten the casting time on this spell. "
      "The format for this spell is as follows: "
      "cast <pow> mineral change at <weapon/armour> with <mineral>. "
      "Example: cast *6 mineral change at sword with elrodnite "
      "This is a long-term spell (see help long-term), and may take much real "
      "time to cast.  If you are interrupted while casting, "
      "you may pick up again at a later time. You need to be in a room "
      "with a lab to use this spell.",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    int time,mod;
    int skill = caster->query_skill("alchemy");
    object ob, ob2;
    class m_table tmp;

    if (!at->is_weapon() && !at->is_armour()) {
	message("info", "You cannot change the chemical properties of anything but a weapon or armour!", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }

    if(at->is_weapon() && at->query_property("no decay")) {
	message("info","You cannot change the chemical properties of an indestructible weapon!\n", caster);
	remove();
	return;
    }
    if(!present("lab", environment(caster))) {
	message("info", "You must be in a room with a lab to use this skill!", caster);
	remove();
	return;
    } 

    if (!args) {
	message("info", "You need to specify a mineral to change the object to.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }

    if(member_array(args, MATERIALS) < 0) {
	message("info", args + " is not a valid mineral.\n", caster);
	remove();
	return;
    }

    if(flag) {
	message("info", "You screw up big time and DESTROY YOUR WORK! DOH! ", caster);
	at->remove();
	return;
    }
    //  at->set_property("new desc", args);

    set_work_message("You changes the mineral of the item.");
    ob2 = load_object("/wizards/stoney/data/mineral_mod_db");
    tmp = (class m_table)ob2->get_table(args);
    time = ( (    (tmp->args[0] * 450) * (12.0 / (power + 6.0))    ) - (skill * 8)  );
    if(time < 120) time = 120;
    if(wizardp(caster)) {
    message("info","Mod: " + tmp->args[0] + "\nPower: " + power + "\nSkill: " + skill + "\nTime: " + time + "\n", caster);
    time = 1;
    }
    mineralname=args;
    start_work(at, caster, time,
      power);
    return;
}

void finish_work(object caster, object at, int power) {
    int ench, i, idx;
    mixed tmp;

    if(power <= 0) {
	message("info", "BUG in Alchemy spell....unable to complete.",
	  environment(caster));
	remove();
	return;
    }

    message("info", "You are finished changing the mineral composition of the item!", caster);
    message("info", (string)caster->query_cap_name() + " utters some "+
      "alchemistic incantations.",
      environment(caster), ({ caster }) );

    at->set_material("metal/"+mineralname);
    if(!check_brittle(at, caster, power)) {
	remove();
	return;
    }
}
