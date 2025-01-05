// tranposrt glyph by glen
#include <colors.h>
inherit "/std/glen/glyphs/glyph";

void create() {
    ::create();
    set_id(({ "glyph", "transport glyph" }));
    set_property("non-combat", 1);
    set_short(CYELLOW + "A transport glyph");
    set_long("This glyph is inscribed on the floor in an ancient magical language.");
    set_property("no clean",1);
    set("function", (: call_other, this_object(), "do_gate" :));
    return;
}

void init(){
    ::init();
    add_action("step_func","step");
}

int step_func(string str) {
    object ob;
    string room;
    object who = this_player();

    if(!(room=(string)query_property("room"))) return;

    if((!str) || (str != "glyph")) {
	notify_fail("step on what?\n");
	return 0;
    }

    if(room->query_property("no teleport")) {
	message("info", "You cannot use this glyph to transport to that location "+
	  "as your attempt is blocked by a magical forcefield.", who);
	return;
    }
    message("info", CBOLD + CGREEN + "You are magically transported somewhere.",
      who);
    who->move_player(room, 0);
}

void do_gate(object who) {
    string room;

    if(!(room=(string)query_property("room"))) return;
    if(random(100) <= (int)who->query_level() * 3 / query_level()) {
	message("info", CCYAN + "You resist the effects of a transport glyph.",
	  who);
	return;
    }
    if(room->query_property("no teleport")) {
	message("info", "You cannot use this glyph to transport to that location "+
	  "as your attempt is blocked by a magical forcefield.", who);
	return;
    }
    message("info", CBOLD + CGREEN + "You are magically transported somewhere.",
      who);
    who->move_player(room, 0);
    return;
}


