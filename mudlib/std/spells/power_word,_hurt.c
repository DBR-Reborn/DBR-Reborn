inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","power word, hurt");
    set_property("skill","magery");
    set_property("casting time",2);
    set_property("base mp cost",115);
    set_property("dev cost", 85);
    set_property("fast dev cost", 220);
    set_property("spell level", 18);
    set_property("moon","warzau");
    set_property("caster message","You say a power word at $T.");
    set_property("target message","$C says a power word at you!");
    set_property("observer message","$C says a power word at $T.");
    set_property("must be present", 1);
    set_property("can resist", 1);
    set_property("save mod", "constitution");
    set_property("damage multiplier", 6);
    set_property("combat spell", 1);
    set_property("duration", "instantaneous");
    set_property("target type", "living");
    set_property("prereq", "power word, blind");
    return;
}

void info() {
message("help",
"This spell attempts to hurt the target.  You have a higher chance of hurting "
"targets of lower levels, and of course, the chance is increased at high power.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int diff;
  
  if(flag) {
    message("info", "%^RED%^%^BOLD%^OOPS, You hurt yourself!!!", caster);
    caster->add_hp(((int)caster->query_hp()/2) + -1*(int)caster->query_hp());
  }
  diff = (int)caster->query_level() - (int)at->query_level();
  if(diff >= 0 && random(100/power) <= diff) {
    message("info", "You hurt "+(string)at->query_cap_name()+"!", caster);
    message("info", "%^RED%^%^BOLD%^YOU ARE HURT!!!", at);
    at->add_hp(((int)at->query_hp()/3) + -1*(int)at->query_hp());
  } else {
    message("info", "Your spell has no effect.", caster);
    message("info", (string)caster->query_cap_name() +
      " tried to cast Power word, hurt at you, but failed.", at);
  }
  remove();
  return;
}

