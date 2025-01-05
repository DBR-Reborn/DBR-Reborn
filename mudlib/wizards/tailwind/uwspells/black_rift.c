#include <colors.h>
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","black rift");
    set_property("skill","rifting");
    set_property("casting time",4);
    set_property("base mp cost",100);
    set_property("dev cost",200);
    set_property("fast dev cost",450);
    set_property("spell level", 45);
    set_property("moon","luna");
    set_property("caster message", "You cast black rift at $T. A pulsing black rift opens.");
    set_property("target message","You see a black rift open before you, made by $C.");
    set_property("observer message", "$C casts black rift, and a pulsing black rift opens before $T.");
    set_property("spell type",({  }));
    set_property("duration", 0);
    set_property("must be present", 1);
    set_property("target type", "living");
    return;
}

void info() {
    message("help",
      "This spell enables a demon master to open a black rift between our world and the world of the demons - and vica versa. The target of the spell will walk through this rift.",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    string troom;
    object ob = environment(caster);
    string ow_room = "/d/damned/virtual/room_8_9.world";
    string uw_room = "/d/damned/virtual/room_15_15.underworld";

//    at = caster;

    if(flag){
	message("info", CBOLD + CRED +
	  "You go somewhere you didn't expect!",at);
	at->move("/std/diewarzau/rooms/warp");
	remove();
	return;
    }

    if(!ob->query_terrain()){
	message("info","You are not on the world map.",
	  at);
    }
    if(ob->query_is_overworld())
	at->move(uw_room);
    else
    if(ob->query_is_underworld())
	at->move(ow_room);
    else {
	message("info","You are not on the world map.",
	  at);
	remove();
	return;
    }

    message("info",
      CBOLD + CGREEN + "You walk through the rift, and emerge in a far different place." + CRESET,
      caster);
    message("info",
      CBOLD + CGREEN + at->query_short() + " steps through the rift and walks out of this plane!"
      + CRESET, all_inventory(ob));
    remove();
    return;
}

