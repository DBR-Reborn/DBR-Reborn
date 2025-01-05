#include <colors.h>
inherit "/std/glen/glyphs/glyph";

void create() {
    ::create();
    set_id(({ "glyph", "rifting glyph", "rift glyph" }));
    set_short(CYELLOW + "A rifting glyph");
    set_long("This glyph is inscribed on the floor in an ancient magical language.");
    set_property("no clean",1);
    set("function", (: call_other, this_object(), "do_gate" :));
    return;
}

void do_gate(object who) {
    object ob;
    int i;

    seteuid(getuid());
    if(who->is_pet() || wizardp(this_player())) return;
    for(i = 0; i < query_level() / 3 + 1; i++){
	ob = new("/std/glen/pet/greater_demon");
	ob->set_owner("query_caster()");
	ob->move(environment(who));
	ob->materialize();
	message("info", CBOLD + CGREEN + "A Huge Angry Demon appears!",    
	  environment(who));
	ob->set_up(random(query_level()*30) + query_level() * 35);
	ob->set_dur(query_level() * 30);
	ob->kill_ob(who, 0);
	who->add_follower(ob);
    }
    return;
}


