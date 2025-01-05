inherit "/std/weapon";

void create() {
::create();
set_ac(0);
set_name("holy bane");
set("id", ({ "holy bane", "owedquar's weapon", "chosen weapon", "owedquar's chosen weapon", "bane" }));
set_short("%^BOLD%^%^RED%^The Holy Bane, Owedquar's Chosen Weapon%^RESET%^");
set_long("This enormous two handed monstrosity is a truly legendary weapon, carrying a laen handle and an extremely odd shaped blade, almost as if the weapon cannot be classified as a definite sword or dagger. The mineral of the blade is unlike any found in this realm, and it pulsates with nearly every imaginable element coarsing through it indefinitely. Countless inscriptions cover the entire weapon, which hint of its origin in the distant realm of Owedquar and its intention to rest only in the hands of his greatest followers."); 
set_type("owedquar's weapon");
set_quality(6);
set_weight(500);
set_property("no add quality", 1);
set_property("no decay", 1);
set_property("no save", 1);
set_property("brittle", 100);
set_material("eog");
set_value(10000);
set_verb("disunite");
}

void init() {
::init();
set_wield((: call_other, this_object(), "weapon_wield" :));
set_unwield((: call_other, this_object(), "weapon_unwield" :));
}

int weapon_wield() {
if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only Dark-Paladins of level 16 or higher may use this item.");
    return 0;
}

   if((string)this_player()->query_class() != "dark-paladin") {
      write("%^BOLD%^Only Dark-Paladins may use this item.");
    return 0;
  }


message("info", "You place the Holy Bane in your hands and it awakens, flashing violently with inhuman power and shaking your entire body! You suddenly feel invincible as if you can slay the divine gods themselves!", this_player());
return 1;
}

int weapon_unwield() {
message("info", "You let go of the legendary power of Owedquar's Chosen Weapon and you almost immediately feel very inferior, once again a normal mortal.", this_player());
return 1;
}
