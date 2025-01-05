
#include <std.h>

inherit "/std/weapon";
inherit AUTOLOAD;

create() {
    ::create();
    set_ac(10);
    set("id", ({ "staff", "quarter staff" }));
    set_name("sceptre");
    set("short", "A glowing runed staff");
    set("long", "This is a glowing staff inscribed with many arcane runes"
	" and glows with an inner fire.  You suspect that great powers"
	" can be unleashed with a simple invocation.\n ");
	
    set_type("two handed staff");
    set_quality(6);
    set_property("no decay",1);
    set_property("no add quality",1);
    set_wc(20, "crushing");
    set_verb("bludgeon");
    set_parry_bonus(15);
    set_property("enchantment",15);
    set_material("metal/catoetine");
    set_wield( (: call_other, this_object(), "gm_item" :) );
    add_enchantment("vacid", "greater elemental blade", 6, 2500,
"vacid");
    add_enchantment("zap", "greater essential blade", 6, 2500,
"electricity");
    set_enh_critical(1);
    set_weight(100);
    set_value(200000);
    return;
}



int query_always_keep() { return 1; }


int gm_item() {
object ob;


   if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only elemental-mages of level 16 or higher may use this item. It crumbles to dust.");
	  remove ();
    return 0;
}

   if((string)this_player()->query_class() != "elemental-mage") {
      write("%^BOLD%^Only elemental-mages may use this item. It crumbles to dust.");
	  remove ();
    return 0;
  }
return 1;
}
