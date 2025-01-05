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
   if(verb == "west")
      call_out("go_west",1);
   return 0;
}

void create() {
    ::create();
    set_author("hood");
    set_property("light",2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Southern Row");
set("day long","%^RESET%^%^ORANGE%^The hot "
"sun warms the cracked and dry "
"cobble stone street.  Directly north you see the open doors "
"of the Shao-tan city guard barracks.  To the west you see one "
"of the city gates that monitors the commings and goings of "
"citizens and visitors to Shao-tan.  "
"\n"
"\n"
"Southern Row can be traveled east from here, or Knunac Ave "
"can be taken on a southern heading...\n");
set("night long","%^RESET%^The street is well lit "
"here with "
"soft candle light that flows from the window in the bulding "
"to the north.  Much light is also provided by the bright "
"lanterns that hang around the city gate to the west.\n"
"\n"
"The street seems to continue east as well as another street "
"that heads south.\n");
add_exit("w_entrance", "west");
add_exit("sr2","east");
add_exit("can1","south");
// add_post_exit_function("south","go_south");

}
int go_west() {
   object *inv;
   int i;

inv = all_inventory(find_object_or_load(PATH+"Wgate2"));
   inv = filter_array(inv, "test_player", this_object());
   for(i=0; i < sizeof(inv); i++)
tell_room(inv[i],"%^CYAN%^Through the "
"north bars of the guard post...\n%^RESET%^"
"you see:\n"+this_player()->query_cap_name()+
" enter from the "
"east.\n");
inv = all_inventory(find_object_or_load(PATH+"Wgate1"));
inv = filter_array(inv, "test_player", this_object());
for(i=0; i < sizeof(inv); i++)
tell_room(inv[i],"%^CYAN%^Through the "
"south bars of the gaurd post...\n%^RESET%^"
"you see:\n"+this_player()->query_cap_name()+
" enter from the east");

inv = all_inventory(find_object_or_load(PATH+"cat6"));
inv = filter_array(inv, "test_player", this_object());
for(i=0; i < sizeof(inv); i++)
tell_room(inv[i],"%^CYAN%^Peering below the catwalk your "
"standing on...\n%^RESET%^"
"you see:\n"+this_player()->query_cap_name()+
" enter from the east");
return 1;
   return 1;
}

int test_player(object ob) {
   return ob->is_player();
}
