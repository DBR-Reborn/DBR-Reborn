inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","plasma burst");
    set_property("skill","conjuration");
    set_property("casting time",9);
    set_property("base mp cost",91);
    set_property("dev cost", 173);
    set_property("fast dev cost", 340);
    set_property("spell level", 32);
    set_property("moon","warzau");
    set_property("caster message",
      "You scream out a spell of ultimate power, and a plasma typhoon "+
      "engulfs the room.");
    set_property("target message",
      "$C screams out a spell, and the heavens open up, raining plasma "+
      "upon you in a torrential storm.");
    set_property("observer message",
      "$C screams a spell out, and the sky rains down a hail of plasma "+
      "upon the room.");
    set_property("spell type",({ "area damage" }));
    set_property("must be present", 1);
    set_property("damage types", ([ "plasma" : 45, "plasma #2" : 45, "plasma #3" : 45 ]));
    set_property("damage multiplier", 20);
    set_property("combat spell", 1);
    set_property("no target", 1);
    return;
}

void info() {
    message("help",
      "A massive burst of plasma radiates from you hitting all in the area."
      "\n\n"
      "  'Some believe quantity of troops matters most.\n"    
      "   I disagree, it is the quality of your troops.'\n"
      "                                 -Lord Renard\n"
      "\n",
      this_player());
}

