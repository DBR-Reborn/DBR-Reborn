inherit "/std/spells/spell";

void create() {
    ::create();
set_property("name", "absorption");
    set_property("skill","necromancy");
set_property("casting time", 5);
set_property("base mp cost", 300);
    set_property("dev cost", 53);
    set_property("fast dev cost", 115);
    set_property("spell level", 10);
    set_property("moon","warzau");
set_property("caster message", "You absorb $T's life force.");
set_property("target message", "$C absorbs your life force!");
set_property("observer message", "$C absorbs $T's life force!");
    set_property("spell type",({ }));
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("prereq", "drain life");
    set_property("target type", "living");
    return;
}

void info() {
message("help",
"This spell is a more powerful version of drain life.  "
"The caster's max hit points may be exceeded by this spell.",
this_player());
}

int can_exceed_max_hp() { return 1; }

void spell_func(object caster, object at, int power, string args, int flag) {
  int mult, roll;

  mult = power;
  if(flag) {
    message("info", "You accidentally steal your own lifeforce, giving it to "
       "the target!!!", caster);
    mult *= -1;
  }
roll = random(100) + random(100) + random(100) + 5;
  at->add_hp(-1 * mult * roll);
  caster->add_hp(mult * roll/2);
  remove();
  return;
}
