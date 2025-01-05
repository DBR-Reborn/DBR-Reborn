#include <colors.h>

inherit "/std/glen/glyphs/glyph";

static int hb_on;
static int heal_status;

int living_filter(object who) { return living(who); }

void create() {
    ::create();
    set_property("non-combat", 1);
    heal_status = 6;
    set_id(({ "glyph", "heal glyph", "regenerative glyph", "regenerative" }));
    set_short(CBOLD + CBLUE + "a regenerative glyph" + CRESET);
    set_long("This glyph is inscribed on the floor in an ancient magical language.");
    set_property("no clean",1);
    set("function", (: call_other, this_object(), "do_heal" :));
    hb_on = 1;
    set_heart_beat(1);
    return;
}

void do_heal(object who, int flag) {
    hb_on = 1;
    set_heart_beat(1);
    return;
}

void heart_beat() {
    object *inv;
    int i;

    heal_status--;
    if(heal_status > 0)
	return;
    heal_status = 20 - query_level()*2;
    inv = filter_array(all_inventory(environment()), "living_filter",
      this_object());
    if(!inv || !sizeof(inv)) {
	hb_on = 0;
	set_heart_beat(1);
	return;
    }
    i = sizeof(inv);
    while(i--) {
	if(inv[i]->query_hp() < inv[i]->query_max_hp() ||
	  inv[i]->query_mp() < inv[i]->query_max_mp()){
	    message("info", CBOLD + CBLUE + "The glyph heals you.", inv[i]);
	    inv[i]->do_healing((int)inv[i]->calculate_healing());
	}
    }
    return;
}

