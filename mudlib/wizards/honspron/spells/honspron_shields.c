inherit "/std/spells/spell";



void create() {

    ::create();

    set_property("name","honspron shield");

    set_property("skill","energy manipulation");

    set_property("casting time",16);

    set_property("base mp cost", 80);

    set_property("dev cost", 98);

    set_property("fast dev cost", 194);

    set_property("spell level", 75);

    set_property("moon", "ankh");

    set_property("caster message",

		 "An arch grants protection to $T.");

    set_property("target message","An arch grants you protection. You feel very protected... and lucky");

    set_property("observer message",

		 "The earth forms a barrier around $T. An arch as granted protection.");

    set_property("spell type",({ "protection" }));

    set_property("target type", "living");

    set_property("protection types", ([ "impaling" : 300, "crushing" : 300,
	"strike" : 300, "impact" : 300, "cutting" : 300, "aether" : 300, "infernal" : 300,
	"unholy" : 300, "holy" : 300, "plasma" : 300, "disruption" : 300, "electricity" : 300,
	"vacuum" : 300, "cold" : 300, "fire" : 300, "stress" : 300 ]) );

    set_property("duration", 600);

    set_property("stack key", "hons");

    set_property("stack num", 2);

    set_property("must be present", 1);

    return;

}



void info() {

message("help",

"This spell is the be all, end all of physical protection spells. \n"

"It is used to help kids. - Honspron",

  this_player());

}



void spell_func(object caster, object at, int power, string args, int flag) {



  ::spell_func(caster, at, power, args, flag);

  return;

}

