//    Nuclear Prism
#define CRITS ([ "1" : ({ "fire A", "radiation A" }), "2" : ({ "fire A","impact A", "radiation A", "plasma A" }), "3" : ({ "impact B", "plasma B" }), "4" : ({ "fire B", "impact B", "radiation B", "plasma B" }), "5" : ({ "plasma C", "radiation A"}),"6" : ({ "fire C", "impact C", "radiation A", "plasma C" }) ])

inherit "/std/diewarzau/obj/misc/rune";

void create() {
    ::create();
    set_id(({ "nuclear prism", "prism", "rune" }));
    set_short("A nuclear prism");
    set_long("This is a prism filled with nuclear energies, floating slowly
in the air.");
  set("function", (: call_other, this_object(), "do_explosion" :));
  return;
}
 
void do_explosion(object who) {
  int dmg, i;
  string targ_limb;
 
 
  dmg = 0;
  for(i=1; i<=5; i++) dmg += 1+random(50);
  dmg *= query_level();
   targ_limb = (string)who->return_target_limb();
  dmg -= who->query_current_protection(targ_limb, "fire");
  dmg -= who->query_current_protection(targ_limb, "plasma");
  dmg -= who->query_current_protection(targ_limb, "radiation");
  message("info", "You are hit by an exploding nuclear prism!", who);
if(dmg > 0) who->do_damage(targ_limb, dmg);
  do_critical(this_object(), who, CRITS[sprintf("%d", query_level())], 0);
  return;
}

