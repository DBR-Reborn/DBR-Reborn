#include <std.h>
#include <daemons.h>

inherit MONSTER;

string EXIT_DIR = "north";
string guild = "tinker";

int pass(){
    if((string)this_player()->query_class() != guild) {
	write("The Guard says in Common: Only "+
	  guild+"s may pass.");
	return 0;
    }
    return 1;
}

object load_join_room(){
    return find_object_or_load("/d/damned/guilds/join_rooms/"+guild+"_join");
}

void improve_weapon(){
    object *weap;
    string type;
    int i;

    weap = query_wielded();
    if(sizeof(weap) < 1)
	return;

    for(i = 0; i < sizeof(weap); i++){
	type = weap[i]->query_type();
	set_skill(type, query_skill(type) * 2);
    }
}

create() {
    ::create();
    set_name("guard");
    set_id( ({ "guard" }) );
    set_short("A big, burly guard");
    set("race", "high-man");
    set_long(
      "The guard stands in front of the north exit.");
    set_body_type("human");
    set_level(38);
    ITEM_BANK_D->multi_restore(this_object(), "guilds", guild);
    force_me("equip");
    improve_weapon();
}

void init() {
    ::init();
    add_action("block_exit", EXIT_DIR);
    return;
}

int block_exit() {
    int gld;
    string p_name;
    object join_room, *inv;

    if(wizardp(this_player())) return 0;
    if(!pass())return 1;
    inv = filter_array(all_inventory(this_player()), "locker_filter",
      this_object());
    if(sizeof(inv)) {
	write("The Guard says in Common: We do not allow storage devices in here.");
	return 1;
    }
    join_room = load_join_room();
    p_name = (string)this_player()->query_name();
    if(member_array("treasury restrict", (string *)join_room->
	query_member_privs(p_name)) >= 0) {
	write("The Guard says in Common: You have been barred from the treasury by the Guildmaster.");
	return 1;
    }
    return 0;
}

int locker_filter(object item) { 
    return (int)item->query_is_locker(); 
}

