#include <std.h>
#include <security.h>
inherit OBJECT;

void init() {
	::init();
	add_action("shatter_crystal", "shatter");
	add_action("shatter_crystal", "smash");
	add_action("shatter_crystal", "break");
	add_action("shatter_crystal", "crush");
}

void create() {
	set_name("egg");
	set_id( ({"egg", "warm egg", "warm" }) );
	set_short("A egg with something inside it");
	set("long",
		"This is a egg from a dragon! what would happen if you %^YELLOW%^smash%^RESET%^ it?"
	);
	set_weight(30);
	set_value(1);
}

int shatter_crystal(string str) {
	object ob;
	if(!str) { return 0; }
  // if(this_player()->is_player() && (int)this_player()->query_level() > 5) {
    //write("only level 5 or lower people may use this item");
    //return 0;
  //}
	if(str == "egg") {
		message("info", "With a sacred ritualy you crack open the egg"
			"what"
			"emerges is a baby dragon which immediately walks up to its "
			"new master.", this_player());
		message("info", (string)this_player()->query_cap_name()+
			" shatters the egg!  A dragon emerges from "
			"the debris.", environment(this_player()),
			({ this_player() }) );
		seteuid(getuid());
        ob = new("/d/1tlny/loot/summon/whelp_dragon");
        //ob = new("/d/1tlny/loot/summon/bear");
        //ob = new("/d/damned/guilds/nethermancer/pets/dark_knight");
		//ob = new("/d/damned/guilds/nethermancer/pets/eternal_darkness");
		//ob = new("/d/damned/guilds/nethermancer/pets/death_dragon");
		//ob = new("/d/damned/guilds/nethermancer/pets/nether_lord");
		//ob = new("/d/damned/guilds/nethermancer/pets/undead_beast");
        //lesser vacid elemental
		//ob = new("/daemon/db/crit/mon/a11");
		ob->set_up();
		ob->set_owner((string)this_player()->query_name());
		ob->move(environment(this_player()));
		this_object()->remove();
		return 1;
	}
	return 0;
}
