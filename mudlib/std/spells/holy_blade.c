inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";
void create() {
    ::create();
    set_property("name","holy blade");
    set_property("skill","prayer");
    set_property("casting time",8);
    set_property("base mp cost",45);
    set_property("dev cost",65);
    set_property("fast dev cost",155);
    set_property("spell level", 17);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast holy blade at $T.");
    set_property("target message","");
    set_property("observer message","$C casts holy blade at $T.");
    set_property("spell type",({}));
    set_property("duration", 280);
    set_property("must be present", 1);
    set_property("stack key", "holy blade");
    set_property("stack num", 3);
    set_property("target type", "any");
    set_property("prereq", "sanctify blade");
    return;
}

void info() {
message("help",
"This spell imbues your weapon with holy force, unleashing righteous "
"power on your enemies!\n",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

    if(!at->is_weapon()) {
        message("info", "You must cast this spell at a weapon.", caster);
        caster->add_mp(props["mp cost"]);
        remove();
        return;
    }
  if(flag) {
    message("info", "The spell fizzles, costing double mp.", caster);
    caster->add_mp(-1* props["mp cost"]);
    remove();
    return;
  }

    ob = new("/std/spells/shadows/weapon_shadow");

    if(check_stack(at, ob)){
        message("info", "Your weapon glows with %^BOLD%^holy%^RESET%^ power.", caster);
        ob->set_extra_wc(([ "holy" : 6*power+(caster->query_level()/2) ]));
        ob->set_auto_crits((["holy B" : 5*power+(caster->query_level()/2) ] )); 
        ob->start_shadow(at,props["duration"], "%^CYAN%^A holy blade spell wears off.");
    }
    else{
        message("info", "The stack limit on this weapon has been reached.", caster);
        ob->external_destruct(ob);
    }
    remove();
    return;
}
