inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "oberon's wrath");
set_property("skill", "empowerment");
set_property("casting time", 30);
set_property("base mp cost", 200);
set_property("dev cost", 160);
set_property("fast dev cost", 480);
set_property("spell level", 30);
set_property("moon", "ankh");
set_property("caster message", "Using inhuman prowess, you rip a hole in the space time continum and imbue your soul with %^RED%^unspeakable %^RESET%^power from the very realm of Oberon!");
set_property("target message", "");
set_property("observer message", "$C opens a hole in space time and from it imbues himself with SICK power!");
set_property("no borrow", 1);
set_property("spell type", ({ "skill mod" }));
set_property("skill dice", "20D1");
set_property("skills", ({ "attack", "dodge", "parry", "two handed blunt", "two handed blade", "two handed flail", "two handed polearm" }));
set_property("no target", 1);
set_property("must be present", 1);
set_property("duration", 80);
set_property("stack key", "oberon wrath");
set_property("stack num", 1);
set_property("prereq", "oberon's fury");
return;
}

void info() {
message("help", "This is an insanely powerful spell which allows a Voidwalker to rip a hole in the space time continum and open a small rift directly into Oberon's world. Using that rift, the follower of the void god can imbue himself with absolutely unimaginable power which will place him/her into a rage never before seen by mortals. All attack and dodging skills, are given tremendous boosts during its duration, but it requires an extreme amount of mp to cast and the duration is not long. This magic is self cast and cannot be stacked.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {


if ((int)caster->query("anger charge #") >= 1) {
    message("info", "You can not channel any more of Oberon’s wrath.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
if ((int)caster->query("oberon fury #") >= 1) {
    message("info", "You can not channel any more of Oberon’s wrath.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
if ((int)caster->query("oberon wrath #") >= 1) {
    message("info", "You can not channel any more of Oberon’s wrath.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  caster->set("oberon wrath #", (int)caster->query("oberon wrath #") + 1);
  call_out("remove_stack", props["duration"], caster);
  ::spell_func(caster, caster, power, args, flag);
  
}

void remove_stack(object caster) {
  if(!objectp(caster)) return;
  caster->set("oberon wrath #", (int)caster->query("oberon wrath #") - 1);
  message("info", "%^CYAN%^The hole in the space time continum to Oberon’s world closes.", caster);
  remove();
  return;
}
