#include <std.h>

inherit "/std/spells/long_term_spell";

string gemtype, color;
int maxcharge, spellpower;

void create() {
    ::create();
    set_property("name","create jewel");
    set_property("skill","environmental bonding");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",50);
    set_property("dev cost", 91);
    set_property("fast dev cost", 210);
    set_property("spell level", 5);
    set_property("moon","luna");
    set_property("caster message","You begin to charge the gem with the power of nature.");
    set_property("target message","");
    set_property("observer message","$C begins to charge the gem with the power of nature.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help",
      "This spells creates a Shaman Jewel from a gem. The type of gem affects the maximum power and type of power that the Shaman Jewel has for powering spells. Casting level affects maximum power of the gem. Casting this spell at *5 or *6 halves the amount of time it takes to cast this spell. This is a long-term spell (see help long-term), and it takes very much real time to cast.  If you are interrupted while casting, you may pick up again at a later time.",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    int mult, time, mod;
    
    if(!(at->is_gem()||at->query_name("glassgem"))) {
	message("info", "You must cast this spell at a gem.",
	  caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(flag) {
	message("info", "You misdirect the summoning energies and shatter "+
	  "the gem!", caster);
	message("info", (string)caster->query_cap_name() +
	  " inadvertently shatters the gem.",
	  environment(caster), ({ caster }) );
	at->remove();
	remove();
	return;
    }
    time=1;
    mod=1;
    if(power > 4) mult = 2;
    else mult = 1;
    set_work_message("%^CYAN%^You enchant the jewel.");
    time = (1200 + (60*power)-(caster->query_skill("environmental bonding"))/mult);
    if(wizardp(caster)) {time=1;}
    start_work(at, caster, time, power);
    return;
}

void gem_set(string gemmaterial){
    switch(gemmaterial){
    case "/diamond":
	maxcharge=10*spellpower;
	break;
    case "/ruby":
	maxcharge=10*spellpower;
	break;
    case "/emerald":
	maxcharge=10*spellpower;
	break;
    case "/sapphire":
	maxcharge=10*spellpower;
	break;
    case "/jade":
	maxcharge=10*spellpower;
	break;
    case "/obsidian":
	maxcharge=8*spellpower;
	break;
    case "/amethyst":
	maxcharge=10*spellpower;
	break;
    case "/turquoise":
	maxcharge=10*spellpower;
	break;
    case "/onyx":
	maxcharge=10*spellpower;
	break;
    case "/quartz":
	maxcharge=5*spellpower;
	break;
    case "/glass":
	maxcharge=3*spellpower;
	break;
    }
    return;
}

void finish_work(object caster, object at, int power) {
    mixed ench;
    object ob;
    string *types, gemmat;
    int i;
    mapping tmp;
    mixed val;
    
    if(power <= 0) {
	message("info", "BUG in Shaman spell....unable to complete.",
	  environment(caster));
	remove();
	return;
    }
    caster->add_exp2(2000*power);
    spellpower=power;
    gemmat=(at->query_material());
    gemmat = replace_string(gemmat, "/metal", "");
    gemmat = replace_string(gemmat, "metal", "");
    gem_set(gemmat);
    
    message("info", "You are finished creating the Shaman Jewel!", caster);
    message("info", (string)caster->query_cap_name() + " utters some "+
      "natural incantations.",
      environment(caster), ({ caster }) );
    
    ob=new("/std/tailwind/obj/shaman_jewel.c");
    ob->set_flavor("jewel");
    ob->set_max_charge(maxcharge);
    ob->set_material(gemmat);
    ob->set_up();
    ob->move(caster);
    //    message("info", "Debug: Color: " +color+ "  Type: "+ gemtype +"  Max-Charge: "+maxcharge, caster);
    
    at->remove();
    remove();
    return;
}
