inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","holy awareness");
     set_property("skill","body alteration");
    set_property("casting time",12);
    set_property("base mp cost",35);
    set_property("dev cost", 66);
    set_property("fast dev cost", 148);
    set_property("spell level", 12);
    set_property("moon","ankh");
    set_property("caster message","You cast holy awareness on $T.");
    set_property("target message","$C casts holy awareness on you.");
    set_property("observer message","$C casts holy awareness on $T.");
    set_property("spell type",({ "stat mod", "skill mod" }));
    set_property("stat dice", "1D6");
    set_property("skill dice", "4D8");
    set_property("stats", ({ "intelligence" }) );
    set_property("skills", ({ "perception" }));
    set_property("target type", "living");
    set_property("must be present",1);
    set_property("duration", 300);
    set_property("stack key", "haware");
    set_property("stack num", 1);
    return;
}

int res_spell() { return 1; }

void info() {
message("help",
"This spell will temporarily enhance the target's intelligence "
"and heightened his/her perception. It also allows the target to "
"see invisible players/monsters.",


this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;

  seteuid(getuid());
  if((at->query("haware #") >= 1) || (at->query("daware #") >= 1)) {
    message("info", (string)at->query_cap_name() +
            " is already aware.",
            caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  if(at->query("see invis")) {
    message("info", nominative(at) + " can already see invisible...your spell fails.",
       caster);
    message("info", "%^CYAN%^"+(string)caster->query_cap_name() +
          "'s spell fails.", environment(caster), ({ caster }) );
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  if(flag) {
    message("info", "Hmm...the spell seems to have worked...", caster);
    message("info", "Everything seems fine...BUT WAIT...you are BLIND!", at);
    ob = new("/std/spells/shadows/blind_shadow");
    ob->start_shadow(at);
    call_out("expire_blind", props["duration"], at, ob);
    return;
	}

  
  at->set("haware #", (int)at->query("haware #") + 1);
  at->set("see invis", 1);
  call_out("remove_stack", props["duration"], at);
  ::spell_func(caster, at, power, args, flag);
  
}
/*
    at->set("see invis", 1);
    call_out("expire_me", props["duration"], at);
  }
  ::spell_func(caster, at, power, args, flag);
  return;
*/
/*
void expire_me(object at) {
  message("info", "%^CYAN%^You may no longer see invisible.",
    at);
  at->set("see invis", 0);
  remove();
  return;
}
*/
void expire_blind(object me, object shad) {
  if(!me || !shad) {
    remove();
    return;
  }
  shad->external_destruct(shad);
  message("info", "You can see again.", me);
  remove();
  return;
}

void remove_stack(object at) {
  if(!objectp(at)) return;
  message("info", "%^CYAN%^You may no longer see invisible.",
    at);
  at->set("haware #", (int)at->query("haware #") - 1);
  at->set("see invis", 0);
  remove();
  return;
}


