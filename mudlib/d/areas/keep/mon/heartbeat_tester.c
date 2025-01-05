#include <std.h>
#include "../keep.h"

/* This mob is not a monster for the keep, and it is also not intended to be looked at or fought. It is intended to serve as a provider for a heart_beat() function so that in certain rooms of the keep extra things will be able to happen. */ 

inherit MONSTER;

object ob;
int b;

void create() {
::create();
b = 0;
set_name("heartbeat tester");
set_level(1);
set_short("N/A");
set_long("N/A");
set("race", "immaterial");
set_gender("neuter");
set_body_type("humanoid");
set_invis();
}

void heart_beat() {
int a;
::heart_beat();
a = random(10);
if(a<2 && b<1) {
tell_room(environment(this_object()), "%^RED%^Several huge blasts of lightning strike the two obelisks on the platform atop the stairs. Seconds later, a dark figure begins to materialize.%^RESET%^");
ob = new(MON+"owedquars_shadow.c");
ob->move(environment(this_object()));
b = 1;
remove();
}
else
return;
}
