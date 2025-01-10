inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","plasma hail");
    set_property("skill","conjuration");
    set_property("casting time",3);
    set_property("base mp cost",42);
    set_property("dev cost", 90);
    set_property("fast dev cost", 250);
    set_property("spell level",16);
    set_property("moon","warzau");
    set_property("caster message","You cast a plasma hail.");
    set_property("target message","$C casts a plasma hail!");
    set_property("observer message","$C casts a plasma hail.");
    set_property("spell type",({ "area damage" }));
    set_property("must be present", 1);
    set_property("can resist", 2);
    set_property("save mod", "dexterity");
    set_property("damage types", ([ "plasma" : 25, "plasma #2" : 20, "plasma #3" : 15 ]));
    set_property("damage multiplier", 9);
    set_property("combat spell", 1);
    set_property("no target", 1);
    return;
}

void info() {
    message("help",
      "This spell conjures a hail of plasma shards to strike all enemies!"
      "\n\n"
      "  'It gives my men great confidence to see fire rain upon our foes..\n"    
      "                                 -Lord Renard\n"
      "\n",

      this_player());
}


