inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","armour of oblivion");
    set_property("skill","energy manipulation");
    set_property("casting time", 16);
    set_property("base mp cost", 75);
    set_property("dev cost", 100);
    set_property("fast dev cost", 300);
    set_property("spell level", 19);
    set_property("moon", "ankh");
    set_property("caster message", "The image of $T shimmers behind an energy void.");
    set_property("target message", "An energy void shimmers around you.");
    set_property("observer message", "The image of $T shimmers behind an energy void.");
    set_property("spell type",({ "protection" }));
    set_property("no borrow", 1);
    set_property("target type", "living");
    set_property("protection types", ([ "fire" : 200, "cold" : 200,
	"electricity" : 200, "vacuum" : 200, "holy" : 100, "disruption" : 100, "aether" : 100, 
    "infernal" : 100, "unholy" : 100, "plasma" : 100 ]) );
    set_property("duration", 360);
    set_property("prereq", "energy shield");
    set_property("stack key", "ram");
    set_property("stack num", 1);
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell is the be all, end all of magical protection spells. As such it may not be borrowed.\n"
"The protection is very SICK.\n",
  this_player());
}

/*
void spell_func(object caster, object at, int power, string args, int flag) {

  if((int)caster->query_stack("ram") + (int)caster->query_stack("eshield") + (int)caster->query_stack("fshield") == 3) {
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
