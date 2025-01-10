// Coder: nEv!N
// Darkemud
// Tssn'ri Pool, handles creating Tssn'ri's for the Tssn'ri Eggs generated
//      by Chemoch, gm weapon of the Chaotic-Lords

#include <std.h>

inherit ROOM;

void init() {
        ::init();
        add_action("make_spawn", "create");
}

void create() {
        ::create();
        set_property("light", 0);
        set_property("indoors", 1);
        set("short", "Tssn'ri Pool");
        set("long",
                "Blah blah.  Will fix this later. 'create spawn' to make a "
                "tssn'ri."
        );
        set_exits( ([
                "workroom": "/wizards/nevin/workrooms/workroom"
        ]) );
}

int make_spawn(string str) {
        if(!str) { return 0; }
        if(str == "spawn") {
                message("A tssn'ri steps from the darke pool...", ENV(TP));
                new("/d/damned/guilds/chaotic-lord/tssnri")->move(TO);
                return 1;
        }
}

void create_spawn(object who) {
        call_out("breed_tssnri1", 60, who);
}

void breed_tssnri1(object who) {
        message("info", "You begin to feel very quesy.\n", who);
        message("info", who->query_cap_name()+" begins to look slightly pale.",
                ENV(who), ({who}) );
        call_out("breed_tssnri2", 60, who);
}

void breed_tssnri2(object who) {
        message("info", "You feel as if your heart is about to burst!", who);
        message("info", who->query_cap_name()+" clutches at "+who->
                query_possessive()+" heart!", ENV(who), ({who}) );
        call_out("breed_tssnri3", 60, who);
}

void breed_tssnri3(object who) {
        message("info", "You hear a sibilant voice in your head...'sSooNN "
                "yOOuu WiiLLll DiiiEeE'...the voice fades away to an "
                "insane cackle.", who);
        message("info", who->query_cap_name()+" cluthes "+who->
                query_possessive()+" head in agony...", ENV(who), ({who}) );
        call_out("breed_tssnri4", 120, who);
}

void breed_tssnri4(object who) {
        object ob;
        message("info", "OH THE PAIN!  You collapse to the ground clutching "
                "your chest...you can feel something ripping its way out of "
                "you!  Your head begins to swim from the agony!  Suddenly "
                "a creature too large to have actually fit inside you "
                "bursts from your chest cavity and stands before you.  "
                "Thin snake-like tendrils extend from your chest to the "
                "creature.  A booming voice in your head tells you to "
                "'DIE.  DIE.  DIE.  DIE.  DIE.'  The creature steps "
                "toward you...", who);
        message("info", who->query_cap_name()+" collapses to the ground!  "
                "Suddently a large creature bursts from "+who->
                query_possessive()+"'s chest!", ENV(who), ({who}) );
        ob = new("/d/damned/guilds/chaotic-lord/tssnri");
        ob->move(ENV(who));
        who->add_hp( -(who->query_hp() * 2/3) );
        ob->force_me("kill "+who->query_cap_name());
}
