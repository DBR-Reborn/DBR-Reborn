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
    set("id", ({ "amulet", "gmitem", "rag'goc", "rag'goc amulet" }));
    set_name("amulet");
    set("short", "The amulet Rag'Goc");
    set("long","Forged from the heat and power of battle, Rag'Goc is a symbol of the power of the blade and those that wield it into battle.  Won by the General Edge during a battle against the minions of Chaos, the amulet is now in the possession of the guild of fighters and is used as a symbol denoting the leader of the Royal-Infantry");
    set_limbs(({"head"}));
    set_ac(50);
    set_ac(50, "cutting");
    set_ac(50, "impaling");
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
    ob= new("d/damned/guilds/royal-infantry/ri_obj");
    ob->make_me_master(this_player());
    worn_by = environment();
    return 1;
}
