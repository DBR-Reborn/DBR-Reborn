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
    set("short", "Northern Row");
set("day long","%^RESET%^%^ORANGE%^The "
"sun shines down upon Northern "
"Row and the rest of Shao-tan, you find it odd "
"that the cobble stones benieth your feet are "
"icy cold, and the breeze wich blows from the gate "
"to the east is also as bone chilling as death itself...\n"
"\n"
"A street sign is posted on the corner, perhaps you should "
"read it..\n");
set("night long","%^RESET%^The street is "
"layered in "
"dense fog, it seems almost un-natural.  "
"You can barely make out vague silouhettes that "
"resemble buildings or walls on the four "
"corners of the road. You know you are close to "
"a city gate, but find it strange you can't see the "
"bright lanterns that are common features of "
"city gates... perhaps your lost?\n");
add_exit("nne_entrance", "east");
add_exit("nr8","west");
add_exit("shad4","south");
add_exit(PATH+"shad5","north");
set_items(([
({"sign","street sign","corner"}):
"An old wooden sign, spiked into a street post....\n"+
"Perhaps it would help to read it."
]));

}
int go_west() {
   object *inv;
   int i;

inv = all_inventory(find_object_or_load(PATH+"NNEgate2"));
   inv = filter_array(inv, "test_player", this_object());
   for(i=0; i < sizeof(inv); i++)
tell_room(inv[i],"%^CYAN%^Through the "
"north bars of the guard post...\n%^RESET%^"
"you see:\n"+this_player()->query_cap_name()+
" enter from the "
"east.\n");
inv = all_inventory(find_object_or_load(PATH+"NNEgate1"));
inv = filter_array(inv, "test_player", this_object());
for(i=0; i < sizeof(inv); i++)
tell_room(inv[i],"%^CYAN%^Through the "
"south bars of the gaurd post...\n%^RESET%^"
"you see:\n"+this_player()->query_cap_name()+
" enter from the east");

inv = all_inventory(find_object_or_load(PATH+"cat3"));
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
