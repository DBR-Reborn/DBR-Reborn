inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "time ward");
set_property("skill", "empowerment");
set_property("casting time", 10);
set_property("base mp cost", 35);
set_property("dev cost", 25);
set_property("fast dev cost", 75);
set_property("spell level", 4);
set_property("moon", "ankh");
set_property("caster message", "You empower $T with protection against time.");
set_property("target message", "$C empowers you with protection against time.");
set_property("observer message", "$C empowers $T with protection against time.");
set_property("spell type", ({ "protection" }));
set_property("target type", "living");
set_property("protection types", ([ "time" : 20 ]));
set_property("duration", 180);
set_property("stack key", "time ward");
set_property("stack num", 3);
set_property("must be present", 1);
return;
}

void info() {
message("help", "This spell provides the target with a relatively good amount of protection against various types of time damage. It can be stacked a total of three times.", this_player());
}
