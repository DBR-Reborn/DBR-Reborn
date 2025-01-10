inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name","seeking blade");
    set_property("skill","magery");
    set_property("casting time",9);
    set_property("base mp cost",57);
    set_property("dev cost",67);
    set_property("fast dev cost",89);
    set_property("spell level", 15);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message",
      "You cast seeking blade at $T.");
    set_property("target message","");
    set_property("observer message",
      "$C casts seeking blade at $T.");
    set_property("spell type",({}));
    set_property("duration", 420);
    set_property("must be present", 1);
    set_property("stack key", "seeking blade");
    set_property("stack num", 4);
    set_property("target type", "any");
    return;
}

void info() {
    message("help",
      "This spell imbues your weapon with the ability to better seek your "
      "opponent.  It will hit your oponent more often and will be deflected less."
      "\n\n"
      "  'Many foes pride themselves in extraodinary evasive maneuvers.\n"  

      "   Somehow my blade still finds its mark.'\n"
      "                                 -Lord Renard\n"
      "\n",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    object ob, weap;
    if(!at->is_weapon()) {
        message("info", "You must cast this spell at a weapon.", caster);
        caster->add_mp(props["mp cost"]);
        return;
    }
    seteuid(getuid());

    ob = new("/std/spells/shadows/weapon_shadow");
    if(!check_stack(at, ob)) {
        message("info", 
          "You may not cast another seeking spell on that weapon.",
          caster);
        caster->add_mp(props["mp cost"]);
        remove();
        return;
    }

    message("info", "Your weapon seems lighter and easier to wield.",
      caster);

    ob->set_hit_bonus(power*5/2);
    ob->start_shadow(at,props["duration"], "Seeking blade wears off.");

    remove();
    return;
}



