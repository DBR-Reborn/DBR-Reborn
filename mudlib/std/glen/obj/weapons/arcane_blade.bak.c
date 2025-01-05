
#include <move.h>

inherit "/std/weapon";

object shad;

int is_arcane_blade(){
    return 1;
}

void create() {
    ::create();
    set("id", ({ "sword", "blade", "arcane blade" }));
    set_name("sword");
    set("short", "" + "Arcane Blade" + "");
    set("long",

      "This magnificent blade shines as if it has just been polished. ");
    set_weight(70);
    set_type("blade");
    set_wc(25, "cutting");
    set_wc(25, "impaling");
    set_wc(25, "plasma");
    set_ac(10);
    set_parry_bonus(10);
    set_property("no save", 1);
    set_quality(4);
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_decay_rate(1500);
    set_unwield((: call_other, this_object(), "unwield_me" :));
    set_auto_critical(([ "plasma B" : 10 ]));
    set_property("enchantment", 3);
    set_value(0);
    set_property("no save",1);
    return;
}

int unwield_me() {
    remove_delayed_call("dest_me");
    delayed_call("dest_me", 1);
    return 1;
}

int drop() {
    remove_delayed_call("dest_me");
    delayed_call("dest_me", 3);
    return 0;
}

// no longer has a duration
void set_dur(int dur) {
    //    delayed_call("dest_me", dur);
    return;
}

void dest_me() {
    if(environment())
	message("info", "" + "The Arcane Blade Dissapears.",
	  environment());
    if(shad) shad->external_destruct(shad);
    remove();
    return;
}

void set_shadow(object ob) {
    shad = ob;
}


