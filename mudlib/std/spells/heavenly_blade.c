inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name", "heavenly blade");
    set_property("skill", "prayer");
    set_property("casting time", 24);
    set_property("base mp cost", 175);
    set_property("dev cost", 145);
    set_property("fast dev cost", 435);
    set_property("spell level", 28);
    set_property("moon", "warzau");
    set_property("damage multiplier", 1);
    set_property("caster message", "You cast %^BOLD%^heavenly blade %^RESET%^at $T!");
    set_property("target message", "");
    set_property("observer message", "$C casts %^BOLD%^heavenly blade %^RESET%^at $T.");
    set_property("spell type", ({ }));
    set_property("duration", 200);
    set_property("must be present", 1);
    set_property("stack key", "heavenly blade");
    set_property("stack num", 1);
    set_property("no borrow", 1);
    set_property("target type", "any");
    set_property("prereq", "holy blade");
return;
}

void info() {
message("help", "This is a godly powerful spell that imbues tremendous pure energy into any weapon, a combination of pure light, aether, and plasma power. To cast this however requires a highly considerable amount of mp and its duration is lower than that of most other spells of this type. It can be stacked on a weapon a total of two times, and due to its extreme power cannot be used in conjunction with the arcane-imbuer spell 'bind enchantment'.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
object ob;
int lvl;
    
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
lvl = (caster->query_level()/2);    
    ob = new("/std/spells/shadows/weapon_shadow");
    if(check_stack(at, ob)) {
    message("info", "%^BOLD%^You bless the weapon with power energy!%^RESET%^", caster);
        if(power < 4 ){
        ob->set_extra_wc(([ "holy" : 14*power+lvl, "aether" : 14*power+lvl, "plasma" : 14*power+lvl   ]));
ob->start_shadow(at, props["duration"], "%^BOLD%^An heavenly blade spell wears off.%^RESET%^");
        }
        else{
ob->set_extra_wc(([ "holy" : 24*power+lvl, "aether" : 24*power+lvl, "plasma" : 24*power+lvl   ]));
        ob->start_shadow(at, props["duration"], "%^BOLD%^An heavenly blade spell wears off.%^RESET%^");
        }
    }
    else{
    message("info", "You may not imbue this weapon with any more power.",caster);
	caster->add_mp(props["mp cost"]);
	ob->external_destruct(ob);
    }      
    remove();
    return;
}



