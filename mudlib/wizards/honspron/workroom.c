inherit "/std/save_room.c";

void create()
{
    ::create();
    set_property("light", 6);
    set_property("no scry", 1);
    set_property("indoors",1);
    set_property("indoors", 0);
     set("short", "The workroom of a new immortal");
    set("long", "This inherits from /std/vault_locker_room.c");
    set("night long", "It is night outside.\nA new immortal works here.\n");
    set("day long", "It is day outside.\nA new immortal works here.\n");
    set_exits( ({ "/std/obj/workroom.c"}), ({"main"}) );
    add_exit("/wizards/honspron/workroom_2.c", "south");
    add_exit("/wizards/honspron/workroom_3.c", "east");

    if (!present("trash can")) {
	new("d/damned/guilds/join_rooms/tcan")->move(this_object());
	 }
}
