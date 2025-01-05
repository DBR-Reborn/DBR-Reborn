inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","consume soul");
    set_property("skill","spiritmancy");
    set_property("casting time",5);
    set_property("base mp cost",50);
    set_property("dev cost", 105);
    set_property("fast dev cost", 315);
    set_property("spell level", 20);
    set_property("moon","warzau");
    set_property("caster message","You cast consume soul at $T.");
    set_property("target message","$C casts consume soul at you!");
    set_property("observer message","$C casts consume soul at $T.");
    set_property("spell type",({ }));
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("can resist", 2);
    set_property("no target", 1);
    set_property("prereq", "orb sacrifice");
    set_property("target type", "living");
    return;
}

void info() {
message("help",
"This spell is a powerful way to drain the target's life.  "
"The caster's max hit points may be exceeded by this spell.",
this_player());
}

int can_exceed_max_hp() { return 1; }

void spell_func(object caster, object at, int power, string args, int flag) {
  int mult, roll;

  mult = power;
  if(flag) {
    message("info", "You accidentally consume your own lifeforce, giving it to "
       "the target!!!", caster);
    mult *= -1;
  }
  roll = random(20) + random(20) + random(20) + 10;
  at->add_hp(-1 * mult * roll);
  caster->add_hp(mult * roll/2);
  remove();
  return;
}
