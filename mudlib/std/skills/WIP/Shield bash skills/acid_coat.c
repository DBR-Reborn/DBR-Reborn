inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(28);
    set_fast_dev_cost(87);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
    message("help",
      "The Royal-Infantry specializes in highly-effective combat tactics. Putting flaming oil on a shield for maximum shield bashing potential is one of those tactics. By doing this, the infantryman can burn his enemy and his enemy's equipment, doing lots of horrible damage. The strength of the pouch of oil helps to determine how much fire damage is done. Oil can be applied to a shield fairly quickly, but it also wears off fast as well. One application consumes one pouch of oil. It must be oil from an alchemist!\nSyntax: use fiery protector at <shield> with <oil pouch>\nExample: use fiery protector at shield with oil",
      this_player());
}

void skill_func(object from, object at, string arg) {
    object ob;
    int skill = props["skill level"];
    int total;

    if(!(at->id("shield"))) {
	message("info", "You must use this skill on a shield.", from);
	remove();
	return;
    }

if(at->query("acidcoated")){
	message("info", "That shield already has a coating of acid active on it. You cannot acid coat a shield more than once at a time.", from);
	remove();
	return;
    }

    if(!arg){
	message("info", "You need to specify an acid vial.", from);
	remove();
	return;
    }

    ob=present(arg, this_player());

    if(!ob) {
	message("info", "You don't have that acid vial.", from);
	remove();
	return;
    }

    if(!ob->id("acid vial")){
	message("info", "That isn't an acid vial.", from);
	remove();
	return;
    }

    message("info", "%^GREEN%^%^BOLD%^You finish coating the shield with acid!%^RESET%^%^RESET%^", from);
    message("info", "%^GREEN%^%^BOLD%^" + from->query_cap_name() + " finishes coating his shield with acid!%^RESET%^%^RESET%^", environment(from), ({ from }));
    total=ob->query_create_skill()/2+skill/3;
    at->set("acidcoated", total);
    ob->remove();
    if(wizardp(from)) {
	write("Total: " + total);
    }
    remove();
    return;
}

