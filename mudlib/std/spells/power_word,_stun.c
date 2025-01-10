inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","power word, stun");
    set_property("skill","magery");
    set_property("casting time",2);
    set_property("base mp cost",30);
    set_property("dev cost", 24);
    set_property("fast dev cost", 70);
    set_property("spell level", 5);
    set_property("moon","warzau");
    set_property("caster message","You say a power word at $T.");
    set_property("target message","$C says a power word at you!");
    set_property("observer message","$C says a power word at $T.");
    set_property("must be present", 1);
    set_property("can resist", 1);
    set_property("save mod", "constitution");
    set_property("damage multiplier", 6);
    set_property("combat spell", 1);
    set_property("duration", 8);
    set_property("target type", "living");
    return;
}

void info() {
message("help",
"This spell attempts to stun the target.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  if(flag) {
    message("info", "%^RED%^%^BOLD%^OOPS, You stun yourself!!!", caster);
    at = caster;
  }
  if (random(20) < (caster->query_level() - at->query_level() + 10 + power))
    {
      at->set_paralyzed(props["duration"], "You are stunned and cannot move!");
      if(!flag)
	message("info", "%^RED%^%^BOLD%^You are stunned!", at);
      remove();
    }
  else
    {
      message("info", "You resist the spell!", at);
      message("info", at->query_true_name()+" resists the spell!", caster);
      remove();
    }
  return;
}







