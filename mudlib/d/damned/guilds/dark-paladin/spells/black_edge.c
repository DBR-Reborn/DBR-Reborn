inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "black edge");
set_property("skill", "empowerment");
set_property("casting time", 16);
set_property("base mp cost", 100);
set_property("dev cost", 95);
set_property("fast dev cost", 285);
set_property("spell level", 18);
set_property("moon", "warzau");
set_property("damage multiplier", 1);
set_property("caster message", "You cast %^BOLD%^%^BLUE%^black edge %^RESET%^at $T!");
set_property("target message", "");
set_property("observer message", "$C casts %^BOLD%^%^BLUE%^black edge %^RESET%^at $T.");
set_property("spell type", ({}));
set_property("duration", 280);
set_property("must be present", 1);
set_property("stack key", "black edge");
set_property("stack num", 3);
set_property("target type", "any");
set_property("prereq", "shadow edge");
return;
}

void info() {
message("help", "This spell is darker version of shadow edge and it imbues a respectable amount of dark power into a weapon, allowing its wielder to strike its foes with increased darkness elemental energy for the spells duration.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
object ob;

   if(!at->is_weapon()) {
     message("info", "You may only cast this magic upon weapons.", caster);
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
        message("info", "You imbue the weapon with dark energy.", caster);
        ob->set_extra_wc(([ "unholy" : 8*power ]));
        ob->set_auto_crits(([ "unholy B" : 6*power ]));
        ob->set_shadow_name("black edge");
        ob->start_shadow(at, props["duration"], "%^BLUE%^A black edge spell wears off..%^RESET%^");
    }
    else{
        message("info", "The stack limit on this weapon has been reached.", caster);
        ob->external_destruct(ob);
    }
    remove();
    return;
}
