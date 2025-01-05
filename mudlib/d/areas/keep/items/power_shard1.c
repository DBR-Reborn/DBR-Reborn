#include <std.h>
#include "../keep.h"

/* This is one of the three crystal shards that are required to create the legend key needed to unlock the crystal door leading to the black keep's master room on the second floor. This shard is retrieved on the second floor by activating the red arcane orb with the red gem, and defeating the Silver Dragon which appears once the previous has been done. However, this shard is not blessed. To get it blessed, it must be 'offered' to Taul by a Mace of the Lord in the room with his statue. Then the player will recieve power_shard2.c which can be used to create the legend key. */

inherit OBJECT;

object ob;

void init() {
::init();
add_action("offer", "offer");
}

int offer(string str) {
if(id(str)) {
if(present("taul statue", environment(this_player())) && this_player()->query_class() == "mace") {
message("my_action", "You hold up the crystal shard and offer it to Taul. The statue in the room shortly begins to glow viciously, and a booming voice is heard throughout the room.", this_player());
message("my_action", this_player()->query_cap_name() +" offers the crystal shard to Taul.", environment(this_player()));
tell_room(environment(this_player()), "A booming voice echoes in Common: %^RED%^I am Taul, God of War. I have watched your efforts from afar to conquer the many challenges put forth within this keep. From the effort I have seen you give, I can conclude you are indeed without a doubt among the chosen ones selected by nature to defeat the evil of Owedquar. Hold the crystal shard high and I shall offer it my power.%^RESET%^");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "%^BOLD%^%^WHITE%^A massive rush of energy emanates from the mace on the statue, energizing the Crystal Shard of Power!%^RESET%^");
ob = new(ITEM+"power_shard2.c");
ob->move(this_player());
remove();
return 1;
}
if(!present("taul statue", environment(this_player()))) {
message("my_action", "What?", this_player());
return 1;
}
message("my_action", "You hold the crystal shard above your head attempting to give it as an offering but nothing happens.", this_player());
return 1;
}
}

void create() {
::create();
set_name("power shard");
set("id", ({ "shard", "crystal", "crystal shard", "shard of power", "crystal shard of power", "power shard", "power shard 1" }));
set_short("%^BOLD%^%^WHITE%^Crystal Shard of Power%^RESET%^");
set_long("This shard is a relatively small piece of pure one hundred percent delicate crystal. It is completely clear, and an extremely faint red glow emanates from the inside.");
set_property("no save", 1);
set_weight(50);
set_value(500000);
}
