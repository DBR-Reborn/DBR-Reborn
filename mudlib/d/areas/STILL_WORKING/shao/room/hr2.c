#include <std.h>
#include <def.h>
#include <shao.h>

inherit ROOM;

int test_player(object ob);

void init() {
   ::init();
   add_action("filter_cmds","");
}

int filter_cmds(string str) {
   string verb;

   verb = query_verb();
   if(verb == "north")
      call_out("go_north",0);
   return 0;
}

void create() {
    ::create();
    set_author("hood");
    set_property("light",2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Holy Row");
set("day long", "%^RESET%^%^ORANGE%^The pure "
"white marble bricks that make up "
"this road are warm under your feet.  The bright sun "
"glimmers off a brass street post, making you squint.  "
"You notice some bricks in front of the building to the south "
"are stained a pinkish red colour.  To the north lay the northern "
"city gate of Shao-tan.\n"
"\n"
"A solid marble plaque hangs from a brass street post here...\n");
set("night long","%^RESET%^The street is well "
"lit here with "
"bright light that flows from a lantern hanging from a street "
"post here.  Much light also flows from the many lanterns "
"that keep the city gate to the north free of darkness.\n"
"\n"
"The street seems to continue east and west, "
"a building lay to the south.\n");
add_exit(PATH+"n_entrance","north");
add_exit(PATH+"hr1","west");
add_exit(PATH+"hr3","east");
add_exit(PATH+"hospital","south");
// add_post_exit_function("south","go_south");

}
int go_north() {
   object *inv;
   int i;

inv = all_inventory(find_object_or_load(PATH+"Ngate2"));
   inv = filter_array(inv, "test_player", this_object());
   for(i=0; i < sizeof(inv); i++)
tell_room(inv[i],"%^CYAN%^Through the "
"west bars of the guard post...\n%^RESET%^"
"you see:\n"+this_player()->query_cap_name()+
" enter from the "
"south.\n");
inv = all_inventory(find_object_or_load(PATH+"Ngate1"));
inv = filter_array(inv, "test_player", this_object());
for(i=0; i < sizeof(inv); i++)
tell_room(inv[i],"%^CYAN%^Through the "
"east bars of the gaurd post...\n%^RESET%^"
"you see:\n"+this_player()->query_cap_name()+
" enter from the south");

inv = all_inventory(find_object_or_load(PATH+"cat4"));
inv = filter_array(inv, "test_player", this_object());
for(i=0; i < sizeof(inv); i++)
tell_room(inv[i],"%^CYAN%^Peering below the catwalk your "
"standing on...\n%^RESET%^"
"you see:\n"+this_player()->query_cap_name()+
" enter from the south");
return 1;
   return 1;
}

int test_player(object ob) {
   return ob->is_player();
}
