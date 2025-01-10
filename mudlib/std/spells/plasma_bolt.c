inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","plasma bolt");
    set_property("skill","conjuration");
    set_property("casting time",1);
    set_property("base mp cost",12);
    set_property("dev cost", 12);
    set_property("fast dev cost", 20);
    set_property("spell level", 4);
    set_property("moon","warzau");
    set_property("caster message","You cast a plasma bolt at $T.");
    set_property("target message","$C casts a plasma bolt at you!");
    set_property("observer message","$C casts a plasma bolt at $T.");
    set_property("can resist", 2);
    set_property("save mod", "dexterity");
    set_property("spell type",({ "damage" }));
    set_property("must be present", 1);
    set_property("damage types", ([ "plasma" : 12 ]));
    set_property("damage multiplier", 5);
    set_property("combat spell", 1);
    set_property("target type", "living");
    return;
}

void info() {
    message("help",
      "This spell projects a bolt of plasma at the target."
      "\n\n"
      "  'A few burns tends to slow most opponents.'\n"    
      "                                 -Lord Renard\n"
      "\n",
      this_player());
}


