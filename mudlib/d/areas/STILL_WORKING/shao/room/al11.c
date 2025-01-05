#include <std.h>
#include <shao.h>

inherit ROOM;
object mon;
void init(){
    ::init();
    add_action("kick_wall", "kick");
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 0);
    set("short", "alley");
set("long","%^RESET%^Garbage and old crates clutter "
      "the narrow alley, and make passage between the two solid "
      "stone walls to the north and south dificult.\n"
      "The alley continues east into darkness and west back to the "
      "street\n");
set_search("default",(:call_other,this_object(),"search_default":));
    add_exit("al12", "south");
add_exit("al10", "west");

set_smell("default","Something smells REALLY BAD here...\nAlmost like rotting flesh.");
}
void search_default(){
write("You dig around a bit, turning over crates, and "+
"sifting garbage, when you flip over a fairly new"+
" looking wooden box....\n"+
"\n"
"Inside you find .... a CORPSE!\n");
mon = new(MON_PATH+"thug");
mon->set_hp(20);
mon->add_poisoning(100);
mon->move(this_object());
mon->force_me("say I don't feel so good, please 'help me'");
}
