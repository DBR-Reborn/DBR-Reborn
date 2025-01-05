inherit "/std/spells/long_term_spell";

object rune;

void create() {
    ::create();
    set_property("name","destroy rune");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",1);
    set_property("base mp cost", 82);
    set_property("dev cost", 82);
    set_property("fast dev cost", 205);
    set_property("spell level", 13);
    set_property("moon","luna");
    set_property("caster message","You begin to destroy the rune.");
    set_property("target message","");
    set_property("observer message","$C begins to magically destroy a rune.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("can be in room", 1);
    return;
}

void info() {
message("help",
"This allows one to try to dispel a rune.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  if(!at->is_rune()) {
    message("info", "You must cast this spell at a rune.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "You fumble while trying to dispel the rune!", caster);
    message("info", (string)caster->query_cap_name() +
	    " dispels a rune.",
	    environment(caster), ({ caster }) );
    caster->add_mp(-1*props["mp cost"]);
    return;
  }
  
  set_work_message("%^CYAN%^You are destroying the rune.");
  at->start_preserve();
  rune = at;
  start_work(at, caster, 1, power);
  return;
}

void move_me(object who) {
  if(rune) rune->set_dur(30);
  ::move_me(who);
  return;
}

void finish_work(object caster, object at, int power) {
//  object ob;

  if(power <= 0) {
    message("info", "BUG in Rune spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
     message("info", "You destroy the rune!", caster);
    message("info", (string)caster->query_cap_name() +
            " destroys a rune.",
            environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
 }

