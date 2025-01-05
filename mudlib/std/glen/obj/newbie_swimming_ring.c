
#include <clock.h>

inherit "/std/armour";


object shad;

void create() {
    ::create();
    set_name("ring");
    set("id", ({ "ring", "magic ring", "newbie ring" }) );
    set("short", "a magical newbie ring of water walking");
    set("long",
      "This small ring glows with an inner magic of swimming.  "
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
	shad->expire_skill(shad);
    return 1;
}

int wear_equipment() {
    object ob;

    if(this_player()->query_level() > 6){
	message("info", 
	  "Your not a newbie, tough",
	  this_player());
	return 0;
    }

    if(this_player()->query_skill("swimming") > 75){
	message("info", 
	  "Your good enough at swimming, tough",
	  this_player());
	return 0;
    }
    message("info", 
      "You feel better at swimming",
      this_player());

    ob = new("/std/spells/shadows/skill_shadow");
    ob->add_skill("swimming", 100);

    ob->start_shadow(this_player(), 0, "You feel not so good at swimming.");
    shad = ob;
    return 1;
}

