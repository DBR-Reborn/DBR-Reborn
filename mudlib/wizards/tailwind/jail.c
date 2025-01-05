#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("no attack", 1);
    set_property("no steal", 1);
    set_property("no castle", 1);
    set_property("no spell", 1);
    set_property("no scry", 1);
    set_property("no summon", 1);
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Jail");
    set("night long", "It is night outside.\nThis is Jail, you must really suck if you are here.\n");
    set("day long", "It is day outside.\nThis is Jail, you must really suck if you are here.\n");
    set_smell("default", "It smells like Jail.");
    set_listen("default", "It is quiet.");
}
void init() {
        ::init();
        add_action("override_functions", "use");
//        add_action("stop_quit", "quit");
        add_action("stop_say", "say");
        add_action("stop_emote", "emote");
        add_action("stop_tell", "reply");
/*
        add_action("stop_chat", "chat");
        add_action("stop_chat", "newbie");
        add_action("stop_chat", "arena");
        add_action("stop_chat", "high-mortal");
        add_action("stop_chat", "bid");
        add_action("stop_chat", "darke");
        add_action("stop_chat", "darkechat");
        add_action("stop_chat", "council");
*/
        add_action("override_trans", "transport");
        add_action("override_trans", "summon");

       }

int override_functions(string str) { 
        if (this_player()->query_position() != "superuser") {
            write("What? You can't do that in jail!");
        return 1;
        }
    return 0;              
}

int override_trans(string str) { 
        if (this_player()->query_position() != "superuser") {
            write("Think you are cool cuz you are a GM, eh?");
        return 1;
        }
    return 0;              
}


int stop_quit(string str) {
        if (this_player()->query_position() != "superuser") {
            write("What? You think i'd let you quit??");
        return 1;
        }
    return 0;              
}

int stop_say(string str) {        
        if (this_player()->query_position() != "superuser") {
            write("Quiet! No talking!");
        return 1;
        }
    return 0;              
}

int stop_emote(string str) {        
        if (this_player()->query_position() != "superuser") {
            write("Jail is no place for emotions.");
        return 1;
        }
    return 0;              
}

int stop_tell(string str) {        
        if (this_player()->query_position() != "superuser") {
            write("Trying to get your acomplises to bust ya out, eh?");
        return 1;
        }
    return 0;              
}

int stop_chat(string str) {        
        if (this_player()->query_position() != "superuser") {
            write("No Lines for You!");
        return 1;
        }
    return 0;              
}
