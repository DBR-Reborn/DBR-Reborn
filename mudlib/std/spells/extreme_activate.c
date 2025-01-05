inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","extremed weapon");
    set_property("skill","enchantment");
    set_property("casting time",2);
    set_property("base mp cost",0);
    set_property("dev cost",65);
    set_property("fast dev cost",155);
    set_property("spell level", 120);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You make $T extreme and claim it as your own.");
    set_property("target message","");
    set_property("observer message","$C casts extremed weapon at $T.");
    set_property("spell type",({  }));
    set_property("duration", 400);
    set_property("must be present", 1);
    set_property("target type", "any");
    return;
}

void info() {
message("help",
"This is not a spell\n",
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
  if((string)at->query_property("extreme by") !=
    (string)caster->query_name()) {
    message("info", "You cannot activate this enchantment unless the "
      "weapon is made extreme by you.", caster);
    remove();
    return;
  }
  message("info", "You have imbued yourself with the power to use "
    "your extreme weapon.",
          caster);
  ob = new("/std/spells/shadows/skill_shadow");
  ob->add_skill((string)at->query_type(),
    250 + 10*power);
  ob->start_shadow(caster, 420,
    "%^COLOR13%^The extreme weapon aura disappears, "+
      "leaving you unable to use your extreme weapon.");
  remove();
  return;
}

