inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
::create();
set_property("name", "shadow edge");
set_property("skill", "empowerment");
set_property("casting time", 8);
set_property("base mp cost", 50);
set_property("dev cost", 50);
set_property("fast dev cost", 150);
set_property("spell level", 9);
set_property("moon", "warzau");
set_property("damage multiplier", 1);
set_property("caster message", "You cast %^COLOR241%^shadow edge %^RESET%^at $T!");
set_property("target message", "");
set_property("observer message", "$C casts %^COLOR241%^shadow edge %^RESET%^at $T.");
set_property("spell type", ({ }));
set_property("duration", 280);
set_property("must be present", 1);
set_property("stack key", "shadow edge");
set_property("stack num", 2);
set_property("target type", "any");
return;
}

void info() {
message("help", "This spell imbues dark shadow powers into a weapon, allowing its wielder to strike its foes with increased darkness elemental energy for the spells duration.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;
    object weap;

if(!at->is_weapon()) {
message("info", "You may only cast this magic upon weapons.", caster);
caster->add_mp(props["mp cost"]);
return;
}

 if(flag) {
    message("info", "The spell fizzles, costing double mp.", caster);
    caster->add_mp(-1* props["mp cost"]);
    remove();
    return;
  }


ob = new("/std/spells/shadows/weapon_shadow");
if(check_stack(at, ob)) {
	message("info", "You imbue the weapon with shadows.", caster);
	ob->set_extra_wc(([ "unholy" : 3*power+(caster->query_level()/2) ]));
	ob->set_auto_crits(([ "unholy A" : 3*power+(caster->query_level()) ]));
ob->start_shadow(at, props["duration"], "%^COLOR241%^A shadow edge spell wears off.%^RESET%^");
  }    
	else{	
	message("info", "You may not stack anymore of this type of blade spells on that weapon.",
      caster);
    caster->add_mp(props["mp cost"]);
	ob->external_destruct(ob);
	}
    remove();
    return;
}

