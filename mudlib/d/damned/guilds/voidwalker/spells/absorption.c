inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "absorption");
    set_property("skill", "void lore");
    set_property("casting time", 5);
    set_property("base mp cost", 200);
    set_property("dev cost", 140);
    set_property("fast dev cost", 420);
    set_property("spell level", 27);
    set_property("moon","warzau");
    set_property("caster message", "You absorb $T's life force.");
    set_property("target message", "$C absorbs your life force!");
    set_property("observer message", "$C absorbs $T's life force!");
    set_property("spell type",({ }));
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("prereq", "dark pact");
    set_property("target type", "living");
    return;
}

void info() {
message("help", "This is an extremely powerful spell that allows a follower of Oberon to drain very large amounts of life from a designated target, transferring it completely over to him/her. The caster maximum hit points can be exceeded by this spell and it has the advantage of ignoring all defense put forth in attempts to hinder its power. Due to this fact however, its power is limited to *6 and will not improve with attained power bonuses.", this_player());
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
if(power > 6) {
mult = 6;
}
  at->add_hp(-1 * mult * roll);
  caster->add_hp(mult * roll/2);
  remove();
  return;
}
