#include <move.h>
#include <std.h>

inherit "/std/armour";
inherit AUTOLOAD;

static private object worn_by;

int query_always_keep() { return 1; }
int query_worn();

int query_worn() {
    if(worn_by && worn_by == environment()) return 1;
    return 0;
}
int take_me_off() {
    worn_by = 0;
    return 1;
}

create() {
    ::create();
    set("id", ({ "robe", "gmitem", "void", "robe of the void" }));
    set_name("robe");
    set("short", "Robe of the Void");
    set("long", "Years ago, Oberon came into power by defeating all those that stood against him. He created had created a robe to protect him against all intruders. During the battle for the void, the robe was sent into the aether and never to be found. A new robe was created and passed down to the leader of the Voidwalker guild as a symbol of their leadership.");
    set_limbs(({"torso", "left arm", "right arm", "left leg", "right leg","head"}));
    set_ac(50);
    set_weight(25);
    set_type("robe");
    set_wear((: call_other,this_object(), "make_me_gm" :));
set_remove((: call_other, this_object(), "take_me_off" :));
    set_enh_critical(-2);
    set_value(0);
    set_property("no save", 1);
    return;
}

int make_me_gm() {
    object ob;

    seteuid(getuid());
    ob= new("d/damned/guilds/voidwalker/voidwalker_obj");
    ob->make_me_master(this_player());
worn_by = environment();
    return 1;
}

