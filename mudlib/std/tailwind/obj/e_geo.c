 //    Poison Rune
#define CRITS ([ "1" : ({ "plasma A" }), "2" : ({ "plasma A","impact A" }), \
  "3" : ({ "plasma B" }), "4" : ({ "plasma B", "impact B" }), "5" : ({ "plasma C"}), \
  "6" : ({ "plasma C", "impact C" }) ])
 
inherit "/std/diewarzau/obj/misc/rune";
 
void create() {
  ::create();
  set_id(({ "explosive geometry", "geometry", "rune" }));
  set_short("An explosive geometry");
  set_long("This rune is drawn on the floor in a complex mathematical language.");
  set("function", (: call_other, this_object(), "do_explosion" :));
  return;
}
 
void do_explosion(object who) {
  int dmg, i;
  string targ_limb;
 
 
  dmg = 0;
  for(i=1; i<=10; i++) dmg += 1+random(10);
  dmg *= query_level();
   targ_limb = (string)who->return_target_limb();
  dmg -= who->query_current_protection(targ_limb, "plasma");
  dmg -= who->query_current_protection(targ_limb, "impact");
  message("info", "You are hit by an explosive geometry!", who);
if(dmg > 0) who->do_damage(targ_limb, dmg);
  do_critical(this_object(), who, CRITS[sprintf("%d", query_level())], 0);
  return;
}
