inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","sword shield");
    set_property("skill","illusionism");
    set_property("casting time",5);
    set_property("base mp cost",22);
    set_property("dev cost", 41);
    set_property("fast dev cost", 98);
    set_property("spell level", 10);
    set_property("moon","ankh");
    set_property("caster message","You cast sword shield at $T.");
    set_property("target message","$C casts sword shield at you.");
    set_property("observer message","$C casts sword shield at $T.");
    set_property("spell type",({ "protection" }));
    set_property("protection types", 
      ([ "cutting" : 12, "impaling" : 12 ]));
    set_property("duration", 240);
    set_property("target type", "living");
    set_property("stack key", "sst shield");
    set_property("stack num", 5);
    set_property("must be present", 1);
    return;
}

void info() {
    message("help",
      "This spell summons a bubble of protection about the target.  "
      "This bubble protects primarily from cutting and stabbing attacks "
      "usually produced by swords.  ",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

    ::spell_func(caster, at, power, args, flag);
    remove();
    return;
}

