inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "icefire breath");
set_property("skill", "conjuration");
set_property("casting time", 5);
set_property("base mp cost", 850);
set_property("dev cost", 65535);
set_property("fast dev cost", 65535);
set_property("spell level", 100);
set_property("moon", "warzau");
set_property("caster message", "You breathe massive fire and ice upon all present!");
set_property("target message", "$C breathes massive %^RED%^fire%^RESET%^ and %^BLUE%^ice %^RESET%^from both heads upon all present!");
set_property("observer message", "$C breathes massive %^RED%^fire%^RESET%^ and %^BLUE%^ice %^RESET%^from both heads upon all present!");
set_property("spell type", ({ "area damage" }));
set_property("damage types", ([ "cold" : 250, "cold #2" : 250, "fire" : 250, "fire #2" : 250 ]));
set_property("damage multiplier", 30);
set_property("must be present", 1);
set_property("combat spell", 1);
set_property("can resist", 1);
set_property("no target", 1);
return;
}
