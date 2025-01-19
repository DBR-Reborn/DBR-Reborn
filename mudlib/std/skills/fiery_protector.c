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

    if(at->query_property("flameoil")){
	message("info", "That shield already has a coating of burning oil on it.", from);
	remove();
	return;
    }

    if(!arg){
	message("info", "You need to specify a pouch of oil.", from);
	remove();
	return;
    }

    ob=present(arg, this_player());

    if(!ob) {
	message("info", "You don't have that pouch of oil.", from);
	remove();
	return;
    }

    if(!ob->is_oil()){
	message("info", "That isn't a pouch of oil from an alchemist.", from);
	remove();
	return;
    }

    message("info", "%^RED%^%^BOLD%^You finish coating the shield with oil!  As you scrape it on the ground, the sparks cause it to ignite!%^RESET%^%^RESET%^", from);
    message("info", "%^RED%^%^BOLD%^" + from->query_cap_name() + " finishes coating his shield with oil.  As " + from->query_subjective() + " scrapes it on the ground, the sparks cause it to ignite!%^RESET%^%^RESET%^", environment(from), ({ from }));
    total=ob->query_oil_power()/2+skill/3;
    at->set("flameoil", total);
    ob->remove();
    if(wizardp(from)) {
	write("Total: " + total);
	write("Time: " + skill);
    }
    call_out("flame_off", skill, at);
    return;
}

void flame_off(object ob){
    message("info", "%^RED%^%^BOLD%^The flaming oil on the shield burns out.%^RESET%^%^RESET%^", environment(ob));
    ob->set("flameoil", 0);
    remove();
    return;
}
