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
    set("id", ({ "amulet", "gmitem", "alchemy", "alchemy amulet" }));
    set_name("amulet");
    set("short", "The Amulet of the Alchemy");
    set("long","This amulet is a small vial of liquid which slowly changes color as you watch it.  It was created by the ancients of the alchemist guild and has been passed along to the leader of the guild ever since. ");
    set_limbs(({"head"}));
    set_ac(50);
    set_type("amulet");
    set_ac(50, "fire");
    set_ac(50, "cold");
    set_weight(25);
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
    ob= new("d/damned/guilds/alchemist/alchemist_obj");
    ob->make_me_master(this_player());
    worn_by = environment();
    return 1;
}
