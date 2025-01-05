#include <std.h>
#include <def.h>
#include <shao.h>

inherit ROOM;

int test_player(object ob);

void init() {
   ::init();
   add_action("filter_cmds","");
add_action("read_sign","read");
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
set("day long","%^RESET%^%^ORANGE%^The "
"hot sun warms the cracked and dry "
"cobble stone street.  "
"A thin fog rolls onto the street from the north and "
"evaporates.  To the east you see one "
"of the city gates that monitors the commings and goings of "
"citizens and visitors to Shao-tan.  "
"\n"
"\n"
"Southern Row can be traveled west from here, or Shadow Lane "
"can be taken on a northern heading...\n");
set("night long","%^RESET%^The street is well "
"lit here with "
"a unique looking street lantern, that seems to glow with "
"an almost magical brilliance.  "
"Much light is also provided by the "
"lanterns that hang around the city gate to the west.\n"
"\n"
"The street seems to continue west as well as another street "
"that heads north.\n");
add_exit("e_entrance", "east");
add_exit("sr8","west");
add_exit("shad1","north");
set_items(([
({"sign","street sign","writings","words","symbols",
"scribbles","blood"}):
"The sign says:\n"
"        Shadow Lane\n"
"            ^^\n"
"            ||\n"
"            ||\n"
"<--== Southern Row ==-->\n"
"\n"
"...some words have been written over top the original"
" street directions, perhaps you should read them.\n"
]));
// add_post_exit_function("south","go_south");

}
int read_sign(string str){
if(!str){
notify_fail("wtf is your illiterate ass trying to read?");
return 0;
}
if(str == "sign" || str == "words" ||
str == "writing"){
write("The words appear to have been written in BLOOD!\n"+
"they say: %^RED%^FEAR THE SHADOWS...\n"
"%^RESET%^the rest is unreadable as it is smeared down"
" off the edge of the sign, almost as if "
"the writer had fallen while trying to finish it.\n");
return 1;
}
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
