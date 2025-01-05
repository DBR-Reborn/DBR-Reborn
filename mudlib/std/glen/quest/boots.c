inherit "/std/armour";

void create() {
    ::create();
    set_name("boots");
    set("id", ({ "boots", "ancient boots" }) );
    set("short", "ancient leather boots");
    set("long",
      "These ancient boots look like they are a hundred years old.  "+
      "They seem to have some sort of inherent value to them, but "
      "its hard to tell past all the dirt.  Perhaps if they were shined.  "
    );
    set_weight(120);
    set_value(25);
    set_type("boots");
    set_limbs( ({"left foot", "right foot"}) );
    set_ac(100);
    set_material("leather");
    set_property("brittle",100);
    set_enh_critical(-2);
}

void init() {
    ::init();
    add_action("effect", "shine");
    return;
}

int effect(string str) {
    object ob;

    if((!str) || (str != "boots")) {
	notify_fail("shine what?\n");
	return 1;
    }

    write("You shine "+query_short()+" and you seem to glow!");

    message("info", (string)this_player()->query_cap_name() +
      " shines "+query_short()+" and seems to glow!",
      all_inventory(environment(this_player())), ({ this_player() }) );

    if(this_player()->query_skill("prospecting") > 75)
	return;
    ob = new("/std/spells/shadows/skill_shadow");
    ob->new_skill_bonus("prospecting", 100+random(20));
    ob->start_shadow(this_player(), 200, "You feel somehow more dull");
    return 1;
}




