// poison glyph by glen

#include <colors.h>
inherit "/std/glen/glyphs/glyph";

void create() {
    ::create();
    set_id(({ "poison glyph", "poisonous glyph", "glyph" }));
    set_short(CBOLD + CGREEN + "A poisonous glyph" + CRESET);
    set_long("This nasty glyph is etched out in some magical language.");
    set_property("no clean",1);
    set("function", (: call_other, this_object(), "do_poison" :));
    return;
}

void remove_blind(object ob, object at) {
    if(at)
	message("info", "A blinding spell wears off.", at);
    if(ob)
	ob->external_destruct(ob);
    return;
}

void do_poison(object who) {
    int pois, i;
    object ob;

    if(!present(who, environment(this_object())))
	return;

    if(who->query_ghost())
	return;

    pois = 0;
    for(i = 1; i <= 10; i++) pois += random(10)+5;
    pois *= query_level();

    message("info", CGREEN + "You are poisoned by a glyph!",   who);
    who->add_poisoning(pois);

    if(query_level() > 5 && !who->query_is_blind()){
	ob = new("/std/spells/shadows/blind_shadow");
	ob->start_shadow(who);
	call_out("remove_blind", query_level() * 7, ob, who);
    }

    if(random(10) != 4)
	call_out("do_poison", 15, who);
    return;
}

