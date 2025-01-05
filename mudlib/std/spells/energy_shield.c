inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","energy shield");
    set_property("skill","energy manipulation");
    set_property("casting time", 7);
    set_property("base mp cost", 25);
    set_property("dev cost", 50);
    set_property("fast dev cost", 150);
    set_property("spell level", 9);
    set_property("moon", "ankh");
    set_property("caster message",
		 "A small shield of energy forms around $T. ");
    set_property("target message","A small energy shield forms around you.");
    set_property("observer message",
		 "A small shield of energy forms around $T.");
    set_property("spell type",({ "protection" }));
    set_property("target type", "living");
    set_property("protection types", ([ "fire" : 50, "cold" : 50,
	"electricity" : 50, "vacuum" : 50, "holy" : 25, "disruption" : 25, "aether" : 25, 
    "infernal" : 25, "unholy" : 25, "plasma" : 25 ]) );
    set_property("duration", 360);
    set_property("stack key", "eshield");
    set_property("stack num", 1);
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell is a kewl magical protection spell.  It protects against all "
"forms of common magical attack.  The protection can be stacked thrice.",
  this_player());
}

/*
void spell_func(object caster, object at, int power, string args, int flag) {

  if((int)caster->query_stack("ram") + (int)caster->query_stack("rap") + (int)caster->query_stack("eshield") + (int)caster->query_stack("fshield") == 3) {
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

