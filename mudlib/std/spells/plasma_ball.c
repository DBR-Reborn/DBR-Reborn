inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","plasma ball");
    set_property("skill","conjuration");
    set_property("must be present", 1);
    set_property("casting time",5);
    set_property("base mp cost",20);
    set_property("dev cost", 67);
    set_property("fast dev cost", 170);
    set_property("spell level", 14);
    set_property("moon","warzau");
    set_property("caster message","You cast a plasma ball.");
    set_property("target message","$C casts a plasma ball at you!");
    set_property("observer message","$C cast a plasma ball.");
    set_property("spell type",({ "damage" }));
    set_property("can resist", 2);
    set_property("save mod", "dexterity");
    set_property("damage types", ([ "plasma" : 50 ]));
    set_property("damage multiplier", 10);
    set_property("combat spell", 1);
    set_property("target type", "living");
    return;
}

void info() {
    message("help",
      "This spell projects a ball of plasma at the target."
      "\n\n"
      "  'Some foes will fall so fast, its not worth using my sword.\n"    
      "                                 -Lord Renard\n",
      this_player());
}


