// poison glyph by glen

#include <colors.h>
inherit "/std/glen/glyphs/glyph";

void create() {
    ::create();
    set_id(({ "gravity glyph", "heavy glyph", "glyph" }));
    set_short(CBOLD + CWHITE + "A gravity glyph" + CRESET);
    set_long("This nasty glyph is etched out in some magical language.");
    set_property("no clean",1);
    set("function", (: call_other, this_object(), "do_gate" :));
    return;
}

int do_command(){
    if(this_player()->query_paralyzed()){
	write("You cant seem to do that in this gravity field!");
	return 1;
    }
    return 0;
}

void do_gate(object who) {
    int pois, i;
    object ob;
    object *inv;
    int str = who->query_stats("strength");

    if(!present(who, environment(this_object())))
	return;

    if(who->query_ghost())
	return;

    add_action("do_command","wield");
    add_action("do_command","wear");
    add_action("do_command","equip");

    message("info", CBOLD + "You are caught in a gravity field!",   who);

    inv = all_inventory(who);

    for(i = 0;i < sizeof(inv); i++){
	if(inv[i]->is_weapon())
	    inv[i]->unequip();
	if(inv[i]->is_armour() &&
	  inv[i]->query_weight()*query_level() > str*3)
	    inv[i]->unequip();
    }
    who->knock_down();
    who->set_paralyzed(query_level()+random(query_level()));

    call_out("do_gate", 7, who);

    return;
}

