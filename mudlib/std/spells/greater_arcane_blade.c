inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","greater arcane blade");
    set_property("skill","magery");
    set_property("casting time",12);
    set_property("base mp cost",75);
    set_property("dev cost", 65);
    set_property("fast dev cost", 108);
    set_property("spell level", 15);
    set_property("moon","luna");
    set_property("caster message",
      "You bring the arcane blade to your hands.");
    set_property("target message","");
    set_property("observer message",
      "A blade forms in the hands of $C.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", 600);
    set_property("prereq", "");
    return;
}

void info() {
    message("help",
      "This spell summons the arcane blade for you to use.  "
      "It is bound to your will, and will function as a sword.  "
      "Its abilities should surpass mundane iron weapons.  "
      "\n\n"
      "  'Sometimes you have only iron, but it is not enough.'\n"    
      "                                 -Lord Renard\n"
      "\n"
      "NOTE: If you unwield the weapon, it will disappear.",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    object ob, ob2, *weps;
    string *limbs;

    if(flag) {
	message("info", "The fumble causes you to be drained of "
	  "half of your remaining mp!", caster);
	caster->add_mp(-1 * (int)caster->query_mp() / 2);
	remove();
	return;
    }
    limbs = (string *)caster->query_wielding_limbs();
    if(sizeof(limbs) < 1) {
	message("info", "You must have 1 wielding limb to cast this "
	  "spell.", caster);
	caster->add_mp(props["mp cost"]);
	ob->remove();
	remove();
	return;
    }
    ob = new("/std/glen/obj/weapons/arcane_blade.c");
    ob->move(caster);
    if(!caster->query_property("ambidextry") &&
      caster->query_property("handedness") &&
      (member_array((string)caster->query_property("handedness"),
	  limbs) > -1)) {
	caster->force_me("wield sword in "+
	  (string)caster->query_property("handedness"));
    }
    caster->force_me("wield sword in "+   limbs[0]);
    caster->force_me("wield sword in "+   limbs[1]);
    if(!ob->query_wielded())
	ob->dest_me();
    ob->set_dur(props["duration"]);
    ob->set_property("hit bonus", power*5); 
    ob->set_property("enchantment", 6*power);
    ob->set_wc(30, "fire");
    ob->set_material("metal/mithril");

    remove();
    return;
}


