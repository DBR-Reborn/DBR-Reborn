inherit "/std/guilds/skill_room";

void create() {
    object ob;
    ::create();
    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id(({ "board", "nethermancer_board" }));
    ob->set_board_id("nethermancer_board");
    ob->set_max_posts(25);
    ob->set_location("/wizards/cythug/nethermancer/rooms/skill_room");
    ob->set_short("Nethermancer Board");
    ob->set_long("A board where the mages of the Nethermancer Guild can post various different messages.\n");
    set_short("The Nethermancer Chamber of Skill Training");
    set_long("This relatively large chamber is where the members of the Nethermancer Guild come to train all of the skills they require to become a more powerful and more efficient spellcaster. West of this room is the guild treasury, and directly to the east is the chamber of magic where spells may be trained. South of here is the nexus chamber where Nethermancers may easily practice beginner level magics.\n");
    set_property("light", 2);
    set_property("indoors", 1);
    set_join_room("/d/damned/guilds/join_rooms/nethermancer_join");
    add_exit("/wizards/cythug/nethermancer/rooms/nexus_room", "south");
    add_exit("/wizards/cythug/nethermancer/rooms/treasury_room", "west");
    add_exit("/wizards/cythug/nethermancer/rooms/spell_room", "east");
    add_exit("/d/damned/guilds/join_rooms/nethermancer_join", "north");
    add_skill("swimming", 1);
    add_skill("trade lore", 1);
    add_skill("perception", 1);
    add_skill("prospecting", 1);
    add_skill("orb manipulation", 1);
    add_skill("nether magic", 1);
    add_skill("consider", 1);
    add_skill("undead suggestion", 1);
    add_skill("body block", 2);
    add_skill("concentrate", 5);
    add_skill("focus casting", 5);
    add_skill("detect magic", 5);
    add_skill("minor nether arts", 7);
    add_skill("create lesser nexus", 9);
    add_skill("create greater nexus", 16);
    add_skill("nether arts", 25);
    add_skill("major nether arts", 42);
    add_skill("create master nexus", 41);
    add_skill("elite nether arts", 56);
    add_skill("forbidden nether arts", 65);
    add_skill("spell sense", 12);
    add_skill("minor nether erudition", 5);
    add_skill("nether erudition", 23);
    add_skill("major nether erudition", 39);
    add_skill("instant casting", 50);
    add_skill("elite nether erudition", 53);
    add_pre_exit_function("east", "go_east");
    add_pre_exit_function("west", "go_west");
    add_pre_exit_function("north", "go_north");
    return;
}

int go_west() {
    if(this_player()->query_class() == "nethermancer" || this_object()->query_property("nethermancer pet") || wizardp(this_player())) {
	write("The Wraith gives you permission to enter the guild treasury.");
	return 1;
    }
    if(!present("wraith")) {
	return 1;
    }
    write("The Wraith says in Common: Only he who is of the Guild of Nethermancers is permitted entry here. Leave.");
    return 0;
}
int go_east() {
    return 1;
}
int go_north() {
    return 1;
}
void reset() {
    object ob;
    ::reset();
    if(!present("guard")) {
	ob = new("/d/damned/guilds/dark-paladin/t_guard.c");
	ob->set_short("A frightful and shadowed wraith");
	ob->set_long("This is a small but noticeably frightening wraith. It is shrouded in a dark black mist and covered entirely in a robe of a possibly even darker color. It exists for one and only one purpose, to defend the treasury of the Nethermancer Guild.");
	ob->set_level(50);
	ob->set("id", ({ "guard", "wraith", "shadowed wraith", "frightful wraith", "shadowed and frightful wraith" }));
	ob->set_skill("martial arts", 500);
	ob->set_name("wraith");
	ob->set_body_type("human");
	ob->set("race", "undead");
	ob->move(this_object());
	return;
    }
}
