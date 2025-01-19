inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","holy armour");
    set_property("skill","prayer");
    set_property("casting time",6);
    set_property("base mp cost", 24);
    set_property("dev cost", 21);
    set_property("fast dev cost", 52);
    set_property("spell level", 4);
    set_property("moon", "ankh");
    set_property("caster message",
		 "You cast holy armour at $T.");
    set_property("target message","$C casts holy armour upon you.");
    set_property("observer message",
		 "$C casts holy armour at $T.");
    set_property("spell type",({ "protection" }));
    set_property("target type", "living");
    set_property("protection types", ([ "fire" : 42, "cold" : 42,
	"electricity" : 42, "vacuum" : 42, "holy" : 42, "disruption" : 42, "aether" : 42, 
    "infernal" : 42, "unholy" : 66, "plasma" : 42 ]) );
    set_property("duration", 360);
    set_property("stack key", "holy armour");
    set_property("stack num", 1);
    set_property("must be present", 1);
    return;
}

void info() {
message("help", @TEXT
This prayer protects the recipient against MAGICAL attacks.
The protection is relatively mild, but the spell can be stacked.

This prayer is functionally similiar to Armour of Faith excepting
that the protection is against the physical not magical.  Holy Armour
and Armour of Faith each count in the spell stacking.
TEXT
, this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

  if((int)at->query("holy armour #") == 1) {
    message("info", (string)at->query_cap_name() +
	    " cannot receive any more holy armour spells.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
/*
  if((int)at->query("faith armour #") + (int)at->query("holy armour #") == 1) {
    message("info", (string)at->query_cap_name() +
	    " cannot receive any more holy armour spells.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
*/
  at->set("holy armour #", (int)at->query("holy armour #") + 1);
  call_out("remove_stack", props["duration"], at);
  ::spell_func(caster, at, power, args, flag);
    caster->add_exp2(5 * caster->query_skill("prayer") + (this_player()->query_level()*100));
  return;
}

void remove_stack(object at) {
  if(!objectp(at)) return;
  at->set("holy armour #", (int)at->query("holy armour #") - 1);
  remove();
  return;
}
