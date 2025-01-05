// poison glyph by glen

#include <colors.h>
inherit "/std/glen/glyphs/glyph";

void create() {
    ::create();
    set_id(({ "vortex glyph", "ethereal glyph", "glyph" }));
    set_short(CBOLD + CBLACK + "A vortex glyph" + CRESET);
    set_long("This nasty glyph is etched out in some magical language.");
    set_property("no clean",1);
    set("function", (: call_other, this_object(), "do_gate" :));
    return;
}

int do_command(){
    write("You are stuck in a vortex and cannot seem to do that.");
    return 1;
}

void do_maul(object who){
    int i, weight;
    object *inv;
    string short_desc, limb;
    inv = all_inventory(who);

    message("info", CBOLD + CYELLOW + "You are caught in a vortex!",   who);

    for(i = 0;i < sizeof(inv); i++)
	if(random(4) == 2){
	    weight = inv[i]->query_weight();
	    short_desc = inv[i]->query_short();
	    limb = who->return_target_limb();
	    who->do_damage(limb, weight);
	    message("info", short_desc + CBOLD + CRED + 
	      " just mauled you!", who);
	}
    if(random(query_level()) > 1)
	call_out("do_maul", 4, who);
    else
	who->move("/std/glen/rooms/vortex_room", 0);
}

void do_gate(object who) {
    int i;
    object ob;

    if(!present(who, environment(this_object())))
	return;

    if(who->query_ghost())
	return;

    add_action("do_command","");

    message("info", CBOLD + CYELLOW + "You are caught in a vortex!",   who);

    call_out("do_maul", 2, who);

    return;
}

