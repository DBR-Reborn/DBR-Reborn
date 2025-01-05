#include <std.h>
#include <shao.h>

inherit ROOM;

void init(){
::init();
call_out("n_gate_chats",10);
}
object mon;
void reset(){
::reset();
if(!present("guard")){
mon = new(MON_PATH+"sg_guard");
mon->move(this_object());
}
}

void create() {
    ::create();
    set_author("hood");
    set_property("light",2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "1st Street");
set("day long","%^RESET%^%^ORANGE%^The hot "
"sun warms the cracked and dry "
"cobble stone street. To the east and west you see "
" two bunkers carved into the ends of the thick "
"stone wall. "
"Directly south you notice a large iron gate "
"that is wide open.  Glancing beyond the gates "
"you see a medium sized building with a symbol "
"molded on a large iron beem across the front "
"of the structure.\n");
set("night long","%^RESET%^%^CYAN%^Moonlight "
"casts an almost angelic glow on the "
"large iron gate that blocks your path south. "
"Glancing at your suroundings, you "
"see two bunker type structures that have "
"been carved into the ends of the thick "
"city wall to the east and west. "
"You also notice numerous lanterns hanging, "
"and laying about the area. Enought light "
"floods out past the gate you can see a street "
"to the south beyond the gate.\n");
add_exit("Ngate1","west");
add_exit("Ngate2","east");
add_exit("hr2","south");
add_pre_exit_function("south","go_south");
    add_item("iron gate", "A large sturdy iron gate.");
}
int go_south(){
if(!present("guard")){
return 1;
}
if(present("guard")){
if(this_player()->query_invis()) return 1;
if(this_player()->query_stealth()>=40) return 1;
if(present("Shao-tan signet ring", this_player())){
mon->force_me("nod "+this_player()->query_name());
return 1;
}
if(this_player()->query_class()=="thief"){
write("%^CYAN%^You are about to enter the "
"city when the guard stops you...\n"
"\n"
"The guard sniffs your clothing and "
"inspects the items your carrying.");
mon->force_me("say My instincts tell me you "
"are a thief, leave or I will hurt you.\n");
this_player()->add_hp(-20+random(-10));
tell_room(this_object(),this_player()->query_cap_name()+
" tried to enter the city, but the guard pushed him away",
({this_player()}) );
return 0;
}
if(this_player()->query_class()=="chaotic-lord"){
write("The guard lightly slashes you with one "
"of his razor sharp claws as he growls :\n"
"'Chaos and those that worship it, are not welcome or tolerated here...'\n"
"'Now be off with you, before you anger me.'\n");
this_player()->add_hp(-40+random(-20));
tell_room(this_object(),this_player()->query_cap_name()+
" tried to enter the city, but the guard slashed him.",
({this_player()}) );
call_out("mad_guard",10);
return 0;
}
if(this_player()->query_class()=="necromancer"){
write("The guard knocks you on yer ass, and growls :\n"
"'Scum like you are not allowed in Shao-tan, leave before "
"I hurt you bad...'\n");
this_player()->add_hp(-20+random(-10));
tell_room(this_object(),this_player()->query_cap_name()+
" tried to enter the city, but the guard kicked "+
"the "+
this_player()->query_race()+"'s ass",({this_player()}) );
call_out("mad_guard",10);
return 0;
}
if(this_player()->is_pet()){
say("The guard says : 'Pets are not allowed into Shao-tan.'\n"
"'Now take the beast some place else or I shall rid you of it.'\n"
"'I'm in a good mood today so I will give it 10 seconds to leave "
"my sight.'\n");
call_out("mad_guard1",10);
return 0;
}
else {
return 1;
}
}
}
int mad_guard(){
if(present(environment(this_player()))){
call_out("dead_boy",1);
return 1;
}
if(!present(environment(this_player()))){
mon->force_me("say I knew "+this_player()->query_name()+
" would turn tail and run.");
}
}
void dead_boy(){
write("The guard growls : 'Didn't I tell you that your not "
"welcome here...\n");
}
void n_gate_chats(){
}
