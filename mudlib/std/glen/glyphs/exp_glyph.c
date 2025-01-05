//    Explosive glyph by glen
#include <colors.h>
inherit "/std/glen/glyphs/glyph";

mapping CRITS = 
([ "1" : ({ "fire A" }), 
  "2" : ({ "fire A", "impact A" }), 
  "3" : ({ "fire B" }), 
  "4" : ({ "fire B", "impact B" }), 
  "5" : ({ "fire C"}), 
  "6" : ({ "fire C", "impact C" }),
  "7" : ({ "fire D", "impact C" }),
  "8" : ({ "fire D", "impact D" }),
  "9" : ({ "fire E", "impact C" }),
  "10": ({ "fire E", "impact D" }),
]);


void create() {
    ::create();
    set_id(({ "explosive glyph", "explosive glyph", "glyph" }));
    set_short(CBOLD + CRED + "An explosive glyph");
    set_long("This glyph is inscribed on the floor in an ancient magical language.");
    set_property("no clean",1);
    set("function", (: call_other, this_object(), "do_explosion" :));
    return;
}

void do_explosion(object who) {
    int i, dam, prot, j;
    object ob;
    string limb;

    if(!present(who, environment(this_object())))
	return;

    if(who->query_ghost())
	return;

    limb = who->return_target_limb();

    message("info", CBOLD + CRED + "You are hit by an exploding glyph!", who);
    for(j = 0; j < query_level()/3 + 1; j++)
	for(i = 0; i < query_level(); i++)
	    do_base_critical(this_object(), who, CRITS[sprintf("%d",i)], limb);

    dam = random(query_level() * 100);

    prot = who->query_current_protection(limb, "fire");

    dam -= prot;

    if(dam < query_level() * 4)
	dam = query_level() * 4;

    who->do_damage(limb, dam);

    if(random(10) < 8)
	call_out("do_explosion", 11, who);
    return;
}


