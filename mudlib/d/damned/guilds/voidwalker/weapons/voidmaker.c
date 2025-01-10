#include <move.h>
#include <colors.h>

inherit "/std/weapon";

object shad;

void create() {
    ::create();
    set_ac(20);
    set_name("voidmaker");
    set("id", ({ "voidmaker", "oberon's weapon", "chosen weapon", "oberon's chosen weapon", "maker" }));
    set_short("%^BOLD%^%^RED%^The Voidmaker, Oberon's Chosen Weapon%^RESET%^");
    set_long("This enormous two handed monstrosity is a truly legendary weapon, carrying a laen handle and an extremely odd shaped blade, almost as if the weapon cannot be classified as a definite sword or dagger. The mineral of the blade is unlike any found in this realm, and it pulsates with nearly every imaginable element coarsing through it indefinitely. Countless inscriptions cover the entire weapon, which hint of its origin in the distant realm of Oberon and its intention to rest only in the hands of his greatest followers."); 
    set_type("attack");
    set_quality(6);
    set_weight(400);
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_property("no save", 1);
    set_property("brittle", 100);
    set_material("boernerine");
    set_value(10);
    set_verb("disunite");
    return;
}

void init() {
    ::init();
    set_wield((: call_other, this_object(), "weapon_wield" :));
    set_unwield((: call_other, this_object(), "weapon_unwield" :));
}

int weapon_wield() {
    if((string)this_player()->query_class() != "voidwalker") {
	message("info", "You attempt to wield the powerful weapon of Oberon, but as you do so it violently flashes with unspeakable energy and blasts you ferociously, instantly dropping your corpse to the floor!", this_player());
	message("info", "You attempt to wield the powerful weapon of Oberon, but as you do so it violently flashes with unspeakable energy and forces you to drop it like a hot potato.", this_player());
	this_object()->move(environment(this_player()));
	return 0;
    }
    message("info", "You place the Voidmaker in your hands and it awakens, flashing violently with inhuman power and shaking your entire body! You suddenly feel invincible as if you can slay the divine gods themselves!", this_player());
    return 1;
}

int weapon_unwield() {
    message("info", "You let go of the legendary power of Oberon's Chosen Weapon and you almost immediately feel very inferior, once again a normal mortal.", this_player());
    return 1;
}
int drop() {
    remove_delayed_call("dest_me");
    delayed_call("dest_me", 1);
    return 0;
}

void dest_me() {
    if(environment())
	message("info", "" + "The Voidmaker of Oberon disappears.",
	  environment());
    if(shad) shad->external_destruct(shad);
    remove();
    return;
}

void set_shadow(object ob) {
    shad = ob;
}
