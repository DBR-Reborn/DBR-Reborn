#include <clock.h>
#include <colors.h>

inherit "/std/armour";
inherit "/std/loose_autoload";

object shad;

int charges = 30;

void create() {
    ::create();
    set_name("ring");
    set("id", ({ "ring"}) );
    set("short", "a sleek dark ring");
    set("long",
      "This dark ring is featureless.  You can't determine the material." );
    set_weight(5);
    set_value(0);
    set_property("no save", 1);
    set_type("ring");
    set_limbs( ({"left hand", "right hand"}) );
    set_ac(5);
    set_material("Ghast Bone");
    set_property("brittle",100);
    set_wear((: call_other,this_object(), "wear_equipment" :));
    set_remove((: call_other,this_object(), "remove_equipment" :));
}


int remove_equipment(){
    return 1;
}

int wear_equipment() {
    object ob;

    charges--;

    if(charges < 0){
	remove();
	write("What ring?");
	return;
    }
    if(random(5) == 3){
	message("info",
	  "The ring turns into a shadow creature, "+
	  "that bites your hands off!",
	  this_player());
	this_player()->cripple_limb("left hand", "sever");
	this_player()->cripple_limb("right hand", "sever");
    }
    if(random(5) == 2){
	message("info",
	  "The ring turns into a shadow creature, "+
	  "that bites your feet off!",
	  this_player());
	this_player()->cripple_limb("left foot", "sever");
	this_player()->cripple_limb("right foot", "sever");
    }
    message("info",
      "As you wear the ring, your soul turns dark.  "+
      "The shadows meld with you.  ",
      this_player());

    if(!this_player()->query_invis()){
	ob = new("/std/spells/shadows/invis_shadow");
	ob->start_shadow(this_player(), 100, 
	  "You return from the shadows"); 
    }

    return 1;
}
