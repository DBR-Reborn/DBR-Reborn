#include <std.h>

inherit "/std/weapon";
inherit AUTOLOAD;

create() {
    ::create();
    set_ac(20);
    set_name("mace");
    set("id", ({ "mace", "guildmaster mace", "basher" }));
    set("short", "The Holy Mace Basher");
    set("long", 
"The Holy Basher is a well worn mace used by many past clerical leaders "
"to punish opponents deemed to be enemies of the church.");
   set_type("blunt");
    set_quality(6);
    set_property("no add quality",1);
    set_property("no decay", 1);
   set_wc(30,"crushing");
    set_wc(10, "impact");
    set_wc(15, "holy");
    set_verb("bash");
    set_parry_bonus(5);
    set_wield( (: call_other, this_object(), "gm_item" :) );
    set_property("hit bonus", 15);
    set_property("enchantment",15);
    set_enh_critical(1);
   set_weight(250);
    set_value(15);
    return;
}


int query_always_keep() { return 1; }

int gm_item() {
object ob;


   if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only Clerics of level 16 or higher may use this item.");
    return 0;
}

   if((string)this_player()->query_class() != "cleric") {
      write("%^BOLD%^Only Clerics may use this item.");
    return 0;
  }
return 1;
}
