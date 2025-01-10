#include <clock.h>

inherit "/std/armour";


object shad;

void create() {
    ::create();
    set_name("ring");
    set("id", ({ "ring", "magic ring" }) );
    set("short", "a magical ring of night vision");
    set("long",
      "This small ring glows with an inner magic of the night."
    );
    set_weight(35);
    set_value(1);
    set_type("ring");
    set_limbs( ({"left hand", "right hand"}) );
    set_ac(5);
    set_material("iron");
    set_property("brittle",100);
    set_wear((: call_other,this_object(), "wear_equipment" :));
    set_remove((: call_other,this_object(), "remove_equipment" :));

}

int remove_equipment(){
    if(shad)
	shad->expire_vision(shad);
    return 1;
}

int wear_equipment() {
    object ob;

    if(this_player()->query_level() > 300){
	message("info",
	  "You should not need this ring with your ability level.",
	  this_player());
	return 0;
    }

    message("info",
      "You can now see in the dark.",
      this_player());

    ob = new("/std/spells/shadows/dvision_shadow");
    ob->set_max(5);

    ob->start_shadow(this_player(), 0, "You can no longer see in the dark.");
    shad = ob;
    return 1;
}

