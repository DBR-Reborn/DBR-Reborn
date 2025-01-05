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
   if(verb == "south")
      call_out("go_south",1);
   return 0;
}

void create() {
    ::create();
    set_author("hood");
    set_property("light",2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "1st Street");
set("day long","%^RESET%^%^ORANGE%^The hot sun "
"warms the cracked and dry "
      "cobble stone street.  To the east and west you see large stone "
      "stairs leading up to the top of the stone wall that surounds "
      "the city, and protects it from intruders.\n"
      "The southern gate is to the south while some large and small "
      "buldings are visible ahead to the north.\n");
    set("night long", "%^BOLD%^The poorly lit street seems deserted.\n"
      "To the east and west large stone stairs lead up into the "
      "darkness.  The dark forbidding city continues to the north.\n");
add_exit("s_entrance", "south");
    add_exit("1st1","north");
add_exit("peon4","west");
add_exit("peon5","east");
// add_post_exit_function("south","go_south");

}
int go_south() {
   object *inv;
   int i;

   inv = all_inventory(find_object_or_load("/wizards/hood/area/room/Sgate2"));
   inv = filter_array(inv, "test_player", this_object());
   for(i=0; i < sizeof(inv); i++)
tell_room(inv[i],"%^CYAN%^Through the bars of the "
"guard post to the west\n%^RESET%^"
"you see:\n"+this_player()->query_cap_name()+
" enter from the "
"north");
inv = all_inventory(find_object_or_load("/wizards/hood/area/room/Sgate1"));
inv = filter_array(inv, "test_player", this_object());
for(i=0; i < sizeof(inv); i++)
tell_room(inv[i],"%^CYAN%^Through the bars of the "
"guard post to the east\n%^RESET%^"
"you see:\n"+this_player()->query_cap_name()+
" enter from the north");
return 1;
   return 1;
}

int test_player(object ob) {
   return ob->is_player();
}
