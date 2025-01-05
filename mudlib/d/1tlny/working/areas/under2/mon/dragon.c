#include <std.h>
inherit MONSTER;
void create() {
::create();
set("id", ({"opalescent dragon", "dragon"}));
set("short", "An Opalescent Dragon");
set("long", "Schroom's dragon");
set("race", "dragon");
set_level(20);
set_gender("neuter");
set_body_type("dragon");
set_combat_chance(120);
}
