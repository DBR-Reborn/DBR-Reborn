inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","increase metabolism");
    set_property("skill","body alteration");
    set_property("casting time",16);
    set_property("base mp cost",45);
    set_property("dev cost", 60);
    set_property("fast dev cost", 145);
    set_property("spell level", 12);
    set_property("moon","luna");
    set_property("caster message",
                "You cast increase metabolism on $T.");
    set_property("target message","$C casts increase metabolism on you.");
    set_property("observer message",
                "$C casts increase metabolism on $T.");
    set_property("spell type",({ }));
    set_property("target type", "living");
    set_property("must be present", 1);
    set_property("duration", 120);
    set_property("stack key", "metab");
    set_property("stack num", 1);

if(this_player()->query_name() == "healer") {
    set_property("casting time",1);
    set_property("duration", 240);
}
    return;
}

void info() {
message("help",
"This spell increases the metabolism of the recipient, allowing him/her to "
"fight faster.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
  object ob;

  seteuid(getuid());
  if(at->query_haste()) {
    message("info", "A target may only receive one spell of this type.",
      caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  at->set("metab #", (int)at->query("metab #") + 1);
  call_out("remove_stack", props["duration"], at);
  ::spell_func(caster, at, power, args, flag);
  ob = new("/std/spells/shadows/haste_shadow");
  if(flag) {
    message("info", "You accidentally slow the target!",
      caster);
    ob->set_fumble();
  }
  ob->start_shadow(at, props["duration"], "%^CYAN%^A metabolism spell expires.");
remove();
  return;

}

 void remove_stack(object at) {
  if(!objectp(at)) return;
  at->set("metab #", (int)at->query("metab #") - 1);
  remove();
  return;
}

