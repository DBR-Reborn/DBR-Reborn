inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "violent blaze");
set_property("skill", "owedquar's will");
set_property("casting time", 1);
set_property("base mp cost", 1100);
set_property("dev cost", 65535);
set_property("fast dev cost", 65535);
set_property("spell level", 80);
set_property("moon", "warzau");
set_property("caster message", "%^RED%^You release a violent blaze of superheated flame at your opponents!%^RESET%^");
set_property("target message", "%^RED%^$C emits a violent blaze of superheated fire!%^RESET%^");
set_property("observer message", "%^RED%^$C emits a violent blaze of superheated fire!%^RESET%^");
set_property("spell type", ({ "area damage" }));
set_property("damage types", ([ "fire" : 250+this_player()->query_level(), "fire #2" : 250+this_player()->query_level(), "fire #3" : 250+this_player()->query_level(), "fire #4" : 250+this_player()->query_level(), "fire #5" : 250+this_player()->query_level() ]));
set_property("damage multiplier", 30+this_player()->query_level()*2);
set_property("must be present", 1);
set_property("combat spell", 1);
set_property("can resist", 2);
set_property("no target", 1);
return;
}

void info() {
message("help", "This is a spell restricted to the Silver Dragons in the Black Keep area. This spell gathers up an enormous amount of warm air and releases it as superheated mega fire at all opponents, causing EXTREME and usually fatal fire elemental damage.", this_player());
}

