inherit "/std/spells/spell";
//TLNY2024 NOT A SPELL FOR PLAYERS do to give them

void create() {
    ::create();
    set_property("name","battle fury");
    set_property("skill","prayer");
    set_property("casting time",1);
    set_property("base mp cost",35);
    set_property("dev cost", 61);
    set_property("fast dev cost", 180);
    set_property("spell level", 12);
    set_property("moon","luna");

    set_property("caster message","You cast battle fury on $T.");
    set_property("target message","$C casts battle fury on you.");
     set_property("observer message","$C casts a spell on $T.");

    set_property("spell type",({ "stat mod", "skill mod" }));
    set_property("target type", "living");  
    set_property("must be present",1);  
//set_property("no target", 1);
    set_property("stats", ({ "strength" }));
    set_property("skills", ({ "attack", "melee" }));
    set_property("stat dice", "3D6");
    set_property("skill dice", "3D8");
    set_property("duration", 1000);
    set_property("stack key", "bfury");
    set_property("stack num", 1);
    set_property("prereq", "battle aura");
    return;
}

void info() {
message("help",
"This spell grants the caster an additional attack in combat, as "
"well as increased strength and attack skill.  This spell cannot "
"be combined with haste.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;


seteuid(getuid());
  if(at->query_haste()) {
    message("info", "A target may only receive one haste spell of this type.",
      caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  at->set("bfury #", (int)at->query("bfury #") + 1);
  call_out("remove_stack", props["duration"], at);
  ::spell_func(caster, at, power, args, flag);
  
  ob = new("/std/spells/shadows/haste_shadow");
  if(flag) {
    message("info", "You accidentally slow the target!",
      caster);
    ob->set_fumble();
  }
  ob->start_shadow(at, props["duration"], "%^CYAN%^A battle fury spell expires.");
  //::spell_func(caster, caster, power, 0, 0);
  return;
}

void remove_stack(object at) {
  if(!objectp(at)) return;
  at->set("bfury #", (int)at->query("bfury #") - 1);
  remove();
  return;
}
