inherit "/std/spells/spell";

int sp_pow;
object cas;

void create() {
    ::create();
    set_property("name","decay");
    set_property("skill","black magic");
    set_property("casting time",8);
    set_property("base mp cost",69);
    set_property("dev cost", 40);
    set_property("fast dev cost", 120);
    set_property("spell level", 7);
    set_property("moon","luna");
    set_property("caster message","You cast decay at $T.");
    set_property("target message","$C casts decay at you!");
    set_property("observer message","$C casts decay at $T.");
    set_property("spell type",({ }));
    set_property("target type", "living");
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("duration", 20);
    set_property("can resist", 2);
    set_property("stack key", "decay");
    set_property("stack num", 3);
    return;
}

void info() {
message("help",
"This spell, when cast upon the target, causes him/her/it to decay "
"slowly.  This decay will never result in death, but may come close.  "
"For the length of the duration, the target takes damage every so often.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  sp_pow = power;
  if(flag) {
    message("info", "%^GREEN%^You accidentally rot away a good deal of your hit points!",
      caster);
    caster->add_hp(-1 * (int)caster->query_hp()/4);
    remove();
    return;
  }
    at->set("decay #", (int)at->query("decay #") + 1);
  call_out("damage_dude", 5, at, props["duration"]/5);
  cas = caster;
}

void damage_dude(object at, int times) {
//  int i;

  if(!at) {
    remove();
    return;
  }
  times--;
  message("info", "%^GREEN%^You take damage from decay.", at);
  at->add_hp(-1 * sp_pow * (int)at->query_hp() / 50);
//TLNY2021 broken line of code
  //at->kill_ob(cas, 1);
  if(times <= 0) {
    at->set("decay #", (int)at->query("decay #") - 1);
    message("info", "%^CYAN%^%^BOLD%^A decay spell wears off.",
        at);
    remove();
    return;
  }
  call_out("damage_dude", 5, at, times);
  return;
}

