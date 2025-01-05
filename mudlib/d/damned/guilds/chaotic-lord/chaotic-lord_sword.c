#include <std.h>

inherit "/std/weapon";
inherit AUTOLOAD;

create() {
    ::create();
    set_ac(25);
    set_name("sword");
    set("id", ({ "sword", "guildmaster sword", "soultaker", "blade" }));
    set("short", "The Soultaker");
    set("long", 
"The Soultaker is jagged and jet black lined with ruins.  The blade looks "
"looks centuries old and forged by some unknown entienty.");
    set_type("blade");
    set_quality(5);
    set_property("no add quality",1);
    set_material("metal/iysaughton");
    set_property("no decay", 1);
    set_wc(30,"cutting");
    set_wc(10, "impaling");
    set_wc(20, "disruption");
    set_verb("slice");
    set_wield( (: call_other, this_object(), "gm_item" :) );
    set_parry_bonus(5);
    set_property("hit bonus", 25);
    set_property("enchantment",20);
    set_weight(300);
    set_value(30);
    return;
}

int query_always_keep() { return 1; }

int gm_item() {



   if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only Chaotic-lords of level 16 or higher may use this item.");
    return 0;
}

   if((string)this_player()->query_class() != "chaotic-lord") {
      write("%^BOLD%^Only Chaotic-lords may use this item.");
    return 0;
  }
return 1;
}
