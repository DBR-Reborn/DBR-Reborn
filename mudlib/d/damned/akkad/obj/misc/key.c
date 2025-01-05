#include <std.h>
#include <security.h>
inherit OBJECT;

void init() {
	::init();
	add_action("shatter_key", "break");
}

void create() {
	set_name("key");
	set_id( ({"key", }) );
	set_short("A key");
	set("long",
		"This is a key to unluck stuff"
	);
	set_weight(30);
	set_value(1);
}

int shatter_key(string str) {
	object ob;
	
	if(str == "key") {
		message("info", "You snap the key in half and throw the pieces aside", this_player());
		message("info", (string)this_player()->query_cap_name()+
			" Snaps the key in half and tosses the pieces aside", environment(this_player()),
			({ this_player() }) );
		seteuid(getuid());
		this_object()->remove();
		return 1;
	}
	return 0;
}
