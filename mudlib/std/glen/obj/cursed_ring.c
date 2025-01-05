
#include <clock.h>
#include <colors.h>

inherit "/std/armour";

object shad;

int charges = 30;

void create() {
    ::create();
    set_name("ring");
    set("id", ({ "ring"}) );
    set("short", "a gemmed ring");
    set("long",
      "This ring is encrusted with all sorts of gems, it must be very valuable"
    );
    set_weight(100);
    set_value(0);
    set_type("ring");
    set_limbs( ({"left hand", "right hand"}) );
    set_ac(5);
    set_material("iron");
    set_property("brittle",100);
    set_wear((: call_other,this_object(), "wear_equipment" :));
    set_remove((: call_other,this_object(), "remove_equipment" :));
    set_property("wear cursed", 1);
}

int remove_equipment(){
    if(shad)
	shad->remove_stats();

    charges--;
    if(charges < 0){
	message("info", 
	  "The ring crumbles",
	  this_player());
	remove();
	return 0;
    }
    message("info", CBOLD + CRED + 
      "You cant take off the ring!" + CRESET,
      this_player());
    return 0;
}

int wear_equipment() {
    object ob;

    message("info", 
      "You feel weak.",
      this_player());

    this_player()->add_penalty(1000);

    return 1;
}


