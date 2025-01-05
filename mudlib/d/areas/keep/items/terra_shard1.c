#include <std.h>
#include "../keep.h"

/* This is one of the three shards obtained from the arcane orbs required to forge the legend key in the black keep. This shard is retrieved by activating the green arcane orb with the green gem found from the dwarves far away on mount nelfton. The shard once obtained is taken to the paladin temple room of the black keep and offered to Sacrel by a paladin. However, unlike the offerings for the shards of Power and Life, when the shard is first offered a powerful monster called the Icefire Hydra appears as a mini boss. Only when this creature is defeated can the shard be offered again and then blessed. After being blessed the playe recieved terra_shard2.c, and the shard is taken to the Shadowforge in the center of the keep and forged by a merchant into the legend key. */

inherit OBJECT;

object ob;
int a;

void init() {
::init();
add_action("offer", "offer");
}

int offer(string str) {
if(id(str)) {
if(present("pillar", environment(this_player())) && this_player()->query_class() == "paladin" && a<1) {
message("my_action", "You hold up the crystal shard and offer it to Sacrel. The four pillars in the room glow white, as does the cracked cross on the south wall. A voice is then heard clearly within the room.", this_player());
message("my_action", this_player()->query_cap_name() +" offers the crystal shard to Sacrel.", environment(this_player()));
tell_room(environment(this_player()), "A mysterious voice says in Common: %^CYAN%^I am Sacrel, the Holy God of Light. I shall now offer the shard my power, but before i do so i will utterly destroy you. HA HA HA! You fools are more worthless than i thought. Your pitiful God is nothing to me, and neither are you. To prove it, it gives me great pleasure to introduce you to my loyal pet. Regret being born with such fragile bodies!");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "You hear faint sounds resembling thumping footsteps coming from down the hall.");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "The pounding noise gets progressively louder as the seconds seem to slowly elapse.");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "A defeaning roar is heard from outside the room as the footsteps get even louder.");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "Four glowing white eyes are seen in the doorway, and another roar is released almost completely breaking your hearing. The creature then enters the room and reveals itself as an enormous blue and red headed hydra!");
ob = new(MON+"icefire_hydra.c");
ob->move(environment(this_player()));
a++;
return 1;
}
if(present("icefire hydra", environment(this_player())) && this_player()->query_class() == "paladin") {
message("my_action", "The hulking Icefire Hydra easily breaks the purity of the room, preventing you from offering the shard.", this_player());
return 1;
}
if(present("pillar", environment(this_player())) && this_player()->query_class() == "paladin" && a==1) {
message("my_action", "You hold up the crystal shard and offer it to Sacrel. The four pillars in the room glow white, as does the cracked cross on the south wall. A voice is then heard clearly within the room.", this_player());
message("my_action", this_player()->query_cap_name() +" offers the crystal shard to Sacrel.", environment(this_player()));
tell_room(environment(this_player()), "A surreal voice says in Common: %^GREEN%^Well done. You have defeated the incredible beast sent to hinder your quest with flying colors. Upon witnessing this event, i am completely convinced you are among the chosen ones, the ones that shall destroy Owedquar. It was he that was speaking to you mocking my name when you first attempted to offer to me the crystal shard. He exists in this realm by means of a shadow, an embodiment of a portion of the dark god's power. He controls the shadow from a distant realm. I know with all my heart that you can defeat Owedquar's Shadow, so i shall bless the crystal shard with my power. Go my children, and succeed without fail!");
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "%^BOLD%^%^WHITE%^Four bursts of white energy are emitted from the four stone pillars in the room, touching the Crystal Shard of Terra! A mindblowing blast is then released from the cracked cross filling it with incredible power.");
ob = new(ITEM+"terra_shard2.c");
ob->move(this_player());
remove();
return;
}
if(!present("pillar", environment(this_player()))) {
message("my_action", "What?", this_player());
return 1;
}
message("my_action", "You hold the crystal shard above your head attempting to give it as an offering but nothing happens.", this_player());
return 1;
}
}

void create() {
::create();
set_name("terra shard");
set("id", ({ "shard", "crystal", "crystal shard", "shard of terra", "crystal shard of terra", "terra shard" }));
set_short("%^BOLD%^%^WHITE%^Crystal Shard of Terra%^RESET%^");
set_long("This shard is a relatively small piece of pure one hundred percent delicate crystal. It is completely clear, and an extremely faint green glow emanates from the inside.");
set_property("no save", 1);
set_weight(50);
set_value(500000);
}
