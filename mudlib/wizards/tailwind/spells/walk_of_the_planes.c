#include <colors.h>
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","walk of the planes");
    set_property("skill","environmental bonding");
    set_property("casting time",4);
    set_property("base mp cost",27);
    set_property("dev cost",105);
    set_property("fast dev cost",210);
    set_property("spell level", 20);
    set_property("moon","luna");
    set_property("caster message", "You cast walk of the planes.");
    set_property("target message","");
    set_property("observer message", "$C casts walk of the planes.");
    set_property("spell type",({  }));
    set_property("duration", 0);
    set_property("must be present", 1);
    set_property("target type", "living");
    return;
}

void info() {
    message("help",
      "Shamen, in their eternal bond with nature, sometimes become aware of other natural environments in different planes. This spell enables them to reach such places. You must be on a world map to cast this spell.\nSyntax: cast *<power> walk of the planes at <target> with <underworld/elemental/overworld>\nExample: cast *4 walk of the planes at erwos with elemental",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    object ob;
    string ow_room = "/d/damned/virtual/room_8_9.world";
    string uw_room = "/d/damned/virtual/room_15_15.underworld";
    string elem_room = "/d/damned/virtual/room_9_9.elemental";
    string toroom;

    ob = environment(at);

        write("CHECK 0");
    if(flag){
	message("info", CBOLD + CRED + "You go somewhere you didn't expect!",at);
	at->move("/std/diewarzau/rooms/warp");
	remove();
	return;
    }

    if(args != "elemental" && args !="underworld" && args !="overworld"){
	message("info","That is not a valid plane to travel to.", at);
        return;
    }

    if(!ob->query_terrain()){
       message("info","You are not on a world map.", at);
       return;
    }

        write("CHECK 1");

    switch(args){
      case "underworld":
        toroom=uw_room;
        break;
      case "overworld":
        toroom=ow_room;
        break;
      case "elemental":
        toroom=elem_room;
        break;
      default:
        write("BUG! Inform TW if you see this message!");
        toroom=ow_room;
        break;
     }

        write("CHECK 2");

     at->move(toroom);

        write("CHECK 3");

    message("info",
      CBOLD + CGREEN + "You begin to walk forward for some strange reason. You close your eyes for a moment.\n\tAnd find yourself elsewhere." + CRESET,
      caster);
    message("info",
      CBOLD + CGREEN + at->query_cap_name() + " begins to walk away, and fades away as he does so."
      + CRESET, all_inventory(ob));

        write("CHECK 4");

    remove();
    return;
}