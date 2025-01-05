inherit "/std/room";
void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",3);
    set_property("no scry", 1);
    set_property("no summon", 1);
    set_property("no teleport",1);
    add_exit("/d/damned/guilds/alchemist/spell_room", "south");
    set("short","The Lab Room");
    set("long", "This room is the busy communal laboratory of the Alchemist guild. The lab can be used for free by any Alchemist... but they still must pay for their own chemicals.");
}
void reset() {
    object forge;
    ::reset();
    if(!present("lab")) {
	forge = new("/std/tailwind/obj/lab");
	forge->set_weight(1000000);
	forge->move(this_object());
    }
    if(!present("can")) {
	new("/d/damned/guilds/join_rooms/tcan")->move(this_object());
    }

}
