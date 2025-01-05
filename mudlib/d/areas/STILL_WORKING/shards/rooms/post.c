#include "../shards.h"
#include <std.h>
#include <objects.h>
#include <post.h>

inherit ROOM;

void init() {
    object ob;
    ::init();
    add_action("mail", "mail");
}

void create() {
    ::create();
    set("short", "Abandoned Post Office");
    set("long",
        "This room is completely empty, save a solitay wooden box in the center of the room.");
    set_property("no castle", 1);
    set_property("light", 2);
    set_property("indoors", 1);
    set_items( ([ "box" : "It's a Magic Mail Box (tm). You have a sneaking suspicion to doesn't work now."]) );
    add_exit(ROOMS+"square", "up");
}

int mail(string str) {
    object ob;

    write("This post office doesn't work anymore. Better head to Daybreak Ridge.\n", environment(this_player()));
    return 1;
}
