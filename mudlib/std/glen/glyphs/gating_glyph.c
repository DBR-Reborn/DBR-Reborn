#include <colors.h>
inherit "/std/glen/glyphs/glyph";

void create() {
    ::create();
    set_id(({ "gate glyph", "glyph", "gating glyph" }));
    set_short(CBOLD + CBLUE + "A gating glyph");
    set_long("This rune is inscribed on the floor in an ancient magical language.");
    set_property("no clean",1);
    set("function", (: call_other, this_object(), "do_gate" :));
    return;
}

void do_gate(object who) {
    who->move("/std/diewarzau/rooms/warp", 0);
    return;
}

