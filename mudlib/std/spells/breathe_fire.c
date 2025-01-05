inherit "/std/spells/spell";

int sp_pow;
object cas;

void create() {
    ::create();
    set_property("name","breathe fire");
    set_property("skill","black magic");
    set_property("casting time",8);
    set_property("base mp cost",69);
    set_property("dev cost", 400);
    set_property("fast dev cost", 400);
    set_property("spell level", 80);
    set_property("moon","luna");
    set_property("caster message","You breathe fire at $T.");
    set_property("target message","$C breathes fire at you!");
    set_property("observer message","$C breathes fire at $T.");
    set_property("spell type",({ }));
    set_property("target type", "living");
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("duration", 30);
    set_property("can resist", 0);
    set_property("stack key", "breathe fire");
    set_property("stack num", 2);
    return;
}

void info() {
message("help",
"This spell is for necromancer dragons only!",
this_player());
}

void spell_func(object caster, object at, int power) {
  sp_pow = power;
  
    at->set("breathe fire #", (int)at->query("breathe fire #") + 1);
  call_out("damage_dude", 5, at, props["duration"]/5);
  cas = caster;
}

void damage_dude(object at, int times) {

  if(!at) {
    remove();
    return;
  }
  times--;
  message("info", "%^RED%^The dragon breathes fire at you.", at);
  at->add_hp(-8 * (sp_pow*random(5)));
  if(times <= 0) {
    at->set("breathe fire #", (int)at->query("breathe fire #") - 1);
    remove();
    return;
  }
  call_out("damage_dude", 5, at, times);
  return;
}

