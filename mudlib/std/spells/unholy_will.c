#include <spell.h>

inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","unholy will");
    set_property("skill","chaos magic");
    set_property("casting time",5);
    set_property("base mp cost",41);
    set_property("dev cost", 57);
    set_property("fast dev cost", 150);
    set_property("spell level", 11);
    set_property("moon","ankh");
    set_property("caster message","You cast unholy will at $T.");
    set_property("target message","$C casts unholy will upon you!");
    set_property("observer message","$C casts unholy will at $T.");
    set_property("spell type",({ }));
    set_property("duration",40);
    set_property("must be present", 1);
    set_property("target type", "living");
    set_property("stack key", "unholy will");
    set_property("stack num", 1);
    return;
}

void info() {
message("help",
"This spell makes the target immune to stunning for a short time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  if(flag) {
    message("info", "You accidentally stun "+TQN+"!", caster);
    message("info", CQN+" accidentally stuns "+
      TQN+"!", EC, ({ caster, at }));
    message("info", CQN+" accidentally stuns you!", at);
    at->set("no stun", 0);
    at->set_paralyzed(4*power);
    remove();
    return;
  }
  if(at->query("no stun")) {
    message("info", TQN+" is already resistant to stunning.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  at->set("unholy will #", (int)at->query("unholy will #") + 1);
  call_out("remove_stack", props["duration"], at);
  ::spell_func(caster, at, power, args, flag);
  at->set("no stun", 1);
  message("info", "You are now resistant to stunning.", at);
  call_out("remove_will", props["duration"], at);
  return;
}

void remove_will(object who) {
  if(!who) {
    remove();
    return;
  }
  message("info", "%^CYAN%^Unholy will wears off.", who);
  who->set("no stun", 0);
  remove();
  return;
}
void remove_stack(object at) {
  if(!objectp(at)) return;
  at->set("unholy will #", (int)at->query("unholy will #") - 1);
  remove();
  return;
}

