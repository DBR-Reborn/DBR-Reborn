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
	set_name("crystal");
	set_id( ({"crystal", "magical crystal" }) );
	set_short("A crystal with a pet in stasis inside it");
	set("long",
		"About the size of an egg, this small delicate crystal"
		"contains a living creature held in some form of magical "
		"stasis.  You can see a tiny creature inside this crystal."
        "What would happen if you %^YELLOW%^smash%^RESET%^ it?"
	);
	set_weight(30);
	set_value(1);
}

int shatter_crystal(string str) {
	object ob;
	if(!str) { return 0; }
   if(this_player()->is_player() && (int)this_player()->query_level() > 5) {
    write("only level 5 or lower people may use this item");
    return 0;
  }
	if(str == "crystal") {
		message("info", "With a loud POP!!!, the crystal shatters into "
			"millions of tiny fragments!  From the glittering cloud "
			"emerges a creature which immediately walks up to its "
			"new master.", this_player());
		message("info", (string)this_player()->query_cap_name()+
			" shatters a small crystal!  A pet emerges from "
			"the debris.", environment(this_player()),
			({ this_player() }) );
		seteuid(getuid());
        //ob = new("/d/1tlny/loot/summon/rabbit");
        ob = new("/d/1tlny/loot/summon/bear");
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
