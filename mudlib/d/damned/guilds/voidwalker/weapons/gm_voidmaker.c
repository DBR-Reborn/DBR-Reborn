#include <std.h>

inherit "/std/weapon";
inherit AUTOLOAD;

void create() {
	::create();
	set_ac(20);
	set_name("voidmaker");
	set("id", ({ "voidmaker", "voidwalker's weapon", "chosen weapon", "voidwalker's chosen weapon", "maker" }));
	set_short("%^BOLD%^%^RED%^The Voidmaker, Oberon's Chosen Weapon%^RESET%^");
	set_long("This enormous two handed monstrosity is a truly legendary weapon, carrying a laen handle and an extremely odd shaped blade, almost as if the weapon cannot be classified as a definite sword or dagger. The mineral of the blade is unlike any found in this realm, and it pulsates with nearly every imaginable element coarsing through it indefinitely. Countless inscriptions cover the entire weapon, which hint of its origin in the distant realm of Oberon and its intention to rest only in the hands of his greatest followers."); 
	set_type("two handed blade");
	set_quality(6);
	set_weight(300);
	set_property("no add quality", 1);
	set_property("no decay", 1);
	set_material("boernerine");
	set_value(10);
	set_parry_bonus(10);
	set_verb("disunite");
	set_property("enchantment", 20);
	set_wc(75, "vacuum");
        set_wc(75, "time");
	set_wc(75, "radiation");
	set_wc(75, "infernal");
	set_wc(75, "stress");
        set_enh_critical(2);
	return;
}


