//	An example skill training room for the fighter's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95
//
//      Edited by Tailwind
//
//      Blessed ReturnLIB
//      Tailwind 10/28/98

#include <std.h>

inherit "/std/guilds/skill_room";

void create() {
    object ob;
    ::create();
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({"board", "alchemist_board"}) );
    ob->set_board_id("alchemist_board");
    ob->set_max_posts(25);
    ob->set_location("/d/damned/guilds/alchemist/train_room");
    ob->set("short","Alchemist Board");
    ob->set("long","A board for players to post notes.\n");
    set("short", "The Alchemists' Training Room");
    set("long", "This is the room where alchemists come to hone their "+
      "mysterious lores.\nTo the east is the treasury.  A donation of "+
      "5 silver per level is required to enter, but you may store items there.");
    //  "\n" important here, too.
    set_property("light", 2);
    set_property("indoors", 1);
    
    //  The following line is VERY, VERY important.
    set_join_room("/d/damned/guilds/join_rooms/alchemist_join");
    
    set_exits( ([ "south" : "/d/damned/guilds/join_rooms/alchemist_join",
	"west" : "/d/damned/guilds/alchemist/spell_room",
	"east" : "/d/damned/guilds/alchemist/a_treas" ]));
    
    //  All the rest is adding the skills.  The add_skill lines are of the
    //  following form:
    //  	add_skill(string skill, int level, int flag)
    //	skill 		The name of the skill which is being added
    // 	level		The level at which the player may begin
    //			developing the skill.
    //	flag		(optional)  If a non-zero number is supplied,
    //			the skill will be considered "secondary" to
    //			the guild and cost double to develop.
    
    add_skill("blade", 1);
    add_skill("consider", 1);
    add_skill("trade lore", 1, 1);
    add_skill("attack", 1);
    add_skill("melee", 1);
    add_skill("parry", 1);
    add_skill("prospecting", 1, 1);
    add_skill("blunt", 1);
    add_skill("axe", 1);
    add_skill("alchemy", 1);
    add_skill("geometry", 1);
    add_skill("knife", 1);
    add_skill("swimming", 1);
    add_skill("construct mud golem", 3);
    add_skill("thrown", 2);
    add_skill("create acid vial", 2);
    add_skill("potion lore", 3);
    add_skill("perception", 3);
    add_skill("construct wood golem", 5);
    add_skill("poison lore", 5);
    add_skill("dodge", 5);
    add_skill("dissect corpse", 5);
    add_skill("oil lore", 6);
    add_skill("focus casting", 6);
    add_skill("detect magic", 6);
    add_skill("skin corpse", 7);
    add_skill("construct clay golem", 8);
    add_skill("spell sense", 9);
    add_skill("offhand training", 10);
    add_skill("herb lore", 11);
    add_skill("construct flesh golem", 12);
    add_skill("construct metal golem", 15);
    add_skill("create lab", 25);
    return;
}

void reset() {
    object ob;
    ::reset();
    if(!present("guard", this_object()))
	new("/d/damned/guilds/alchemist/t_guard")->move(this_object());
    ob = new("/std/tailwind/obj/lab");
    ob->set_weight(500000);
    ob->move(this_object());
    return;
}
