inherit "/std/spells/long_term_spell";
 
object rune, stuff;
 
void create() {
    ::create();
    set_property("name","destroy pattern");
    set_property("skill","geometry");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost", 82);
    set_property("dev cost", 82);
    set_property("fast dev cost", 205);
    set_property("spell level", 13);
    set_property("moon","luna");
    set_property("caster message","You begin to erase the rune.");
    set_property("target message","");
    set_property("observer message","$C begins to erase a rune.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("can be in room", 1);
    return;
}
 
void info() {
message("help",
"This allows one to try to destroy a rune by erasing its geometrical patterns. "
"This spell requires a magical quill to be present, to be used for erasing.",
this_player());
}
 
void spell_func(object caster, object at, int power, string args, int flag)
{
  if(!at->is_rune()) {
    message("info", "You must cast this spell at a rune.",
            caster);
          caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  if(!(stuff = present("magic quill", caster))) {
    message("info", "You need a magic quill to cast this spell.",
            caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

    if(random(20)==0){

    message("info", "You press too hard and break the quill.",
            caster);
   stuff->remove();
}

  if(flag) {
    message("info", "You fumble while trying to erase the rune!", caster);
    message("info", (string)caster->query_cap_name() +
            " erases a rune.",
            environment(caster), ({ caster }) );
    caster->add_mp(-1*props["mp cost"]);
    return;
  }
  if((int)at->query_level() >= ((props["extra power"])?(power-props["extra
power"]):power)) {
    message("info", "You must cast this spell at a power equal to or
greater than the rune's power to destroy it.",
            caster);
          caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  set_work_message("You are erasing the rune.");
  at->start_preserve();
  rune = at;
  start_work(at, caster, 50 + power * 20, power);
  return;
 
}
 
void move_me(object who) {
  if(rune) rune->set_dur(30);
  ::move_me(who);
  return;
}
 
void finish_work(object caster, object at, int power) {
  object ob;
 
  if(power <= 0) {
    message("info", "BUG in Rune spell....unable to complete.",
            environment(caster));
    remove();
    return;
  }
     message("info", "You erase the rune!", caster);
    message("info", (string)caster->query_cap_name() +
            " erases a rune.",
 
            environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
 }
 
