#include <std.h>
#include <shao.h>

inherit ROOM;
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
      "cobble stone street.  To the east and west you see large stone "
      "stairs leading up to the top of the stone wall that surounds "
      "the city, and protects it from intruders.\n"
      "The southern gate is to the south while some large and small "
      "buldings are visible ahead to the north.\n");
set("night long","%^RESET%^The poorly lit "
"street seems deserted.\n"
      "To the east and west large stone stairs lead up into the "
      "darkness.  The dark forbidding city continues to the north.\n");
add_exit("Wgate1","north");
add_exit("Wgate2","south");
add_exit("sr1","east");
add_pre_exit_function("east","go_east");
    add_item("iron gate", "A large sturdy iron gate.");
}
int go_east(){
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
