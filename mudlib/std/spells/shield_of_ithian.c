inherit "/std/spells/spell";



void create() {
    ::create();
    set_property("name","shield of ithian");
    set_property("skill","energy manipulation");
    set_property("casting time", 16);
    set_property("base mp cost", 80);
    set_property("dev cost", 105);
    set_property("fast dev cost", 315);
    set_property("spell level", 20);
    set_property("moon", "ankh");
    set_property("caster message", "An impenetrable shell forms around $T.");
    set_property("target message", "An invisible shell forms around you. You feel very protected.");
    set_property("observer message", "The air shimmers for a second and now $T looks somehow untouchable.");
    set_property("no borrow", 1);
    set_property("spell type",({ "protection" }));
    set_property("protection types", ([ "impaling" : 200, "crushing" : 200, "strike" : 200, "impact" : 200, "cutting" : 200, "stress" : 100 ]) );
    set_property("target type", "living");
    set_property("duration", 360);
    set_property("prereq", "force shield");
    set_property("stack key", "rap");
    set_property("stack num", 1);
    set_property("must be present", 1);
    return;
}



void info() {

message("help",
"This spell is the be all, end all of physical protection spells. As such it may not be borrowed.\n"
"The protection(physical damage) is very SICK and can be stacked twice.",
  this_player());
}

/*
void spell_func(object caster, object at, int power, string args, int flag) {

  if((int)caster->query_stack("rap") + (int)caster->query_stack("eshield") + (int)caster->query_stack("fshield") == 3) {
    message("info", (string)caster->query_cap_name() +
	    " cannot receive any more enchanter armour spells.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  ::spell_func(caster, at, power, args, flag);

  return;

}
*/
