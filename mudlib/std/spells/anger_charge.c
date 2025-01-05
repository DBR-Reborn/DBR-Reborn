inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "anger charge");
set_property("skill", "empowerment");
set_property("casting time", 10);
set_property("base mp cost", 25);
set_property("dev cost", 40);
set_property("fast dev cost", 120);
set_property("spell level", 7);
set_property("moon", "ankh");
set_property("caster message", "You magically charge $T's inner anger!");
set_property("target message", "$C magically charges your inner anger!");
set_property("observer message", "$C magically charges $T's inner anger!");
set_property("spell type", ({ "skill mod" }));
set_property("skill dice", "4D1");
set_property("skills", ({ "attack", "two handed blunt", "two handed blade", "two handed flail", "two handed polearm" }));
set_property("target type", "living");
set_property("must be present", 1);
set_property("duration", 200);
set_property("stack key", "anger charge");
set_property("stack num", 2);
return;
}

void info() {
message("help", "This spell allows a Dark Paladin to magically reach into someones soul and bring out some of their dormant anger, raising their attack and weapon skills. This magic may be cast on any target a total of two times.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

if ((int)caster->query("anger charge #") + (int)caster->query("owedquar fury #") >= 2) {
    message("info", "You can not get more angry.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

if ((int)caster->query("anger charge #") >= 2) {
    message("info", (string)caster->query_cap_name() +
	    " can not get more angry.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
if ((int)caster->query("owedquar fury #") >= 2) {
    message("info", (string)caster->query_cap_name() +
	    " can not get more angry.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
if ((int)caster->query("owedquar wrath #") >= 1) {
    message("info", (string)caster->query_cap_name() +
	    " can not get more angry.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  caster->set("anger charge #", (int)caster->query("anger charge #") + 1);
  call_out("remove_stack", props["duration"], caster);
  ::spell_func(caster, caster, power, args, flag);
  
}

void remove_stack(object caster) {
  if(!objectp(caster)) return;
  caster->set("anger charge #", (int)caster->query("anger charge") - 1);
  message("info", "Your are no longer angry.", caster);
  remove();
  return;
}