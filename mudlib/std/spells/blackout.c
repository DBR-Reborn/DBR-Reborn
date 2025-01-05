inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "blackout");
    set_property("skill", "vision magic");
    set_property("casting time", 5);
    set_property("base mp cost", 80);
    set_property("dev cost", 122);
    set_property("fast dev cost", 360);
    set_property("spell level", 18);
    set_property("moon","warzau");
    set_property("caster message", "%^BOLD%^%^MAGENTA%^You invoke a powerful blinding magic upon $T.%^RESET%^");
    set_property("target message", "%^BOLD%^%^MAGENTA%^$C invokes a powerful blinding magic upon you!%^RESET%^");
    set_property("observer message", "%^BOLD%^%^MAGENTA%^$C invokes a powerful blinding magic upon $T.%^RESET%^");
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("can resist", 1);
    set_property("damage multiplier", 6+this_player()->query_level() );
    set_property("duration", 20);
    set_property("target type", "living");
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 150%\n\nThis spell when cast attempts to render a designated living target blind of all vision. Unlike the lesser 'eye seal' spell, if successful the blind will also cause severe penalties to all skills for its duration enabling for greater success chances in assassinations and landing hits in combat among other things. The duration however is relatively short, meaning such gruesome skill penalties will often not hamper the target to the point of needing to relog unless cast with excessively high power, which affects both the success chance and the duration alike.\n\nSyntax: 'cast *6 blackout at fireknife'", this_player()); 
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    object ob;

    if(flag) {
	message("info", "You accidentally direct the blinding magic at yourself!", at);
	at = caster;
    }
    if(at->query_is_blind()){
	message("info", (string)at->query_cap_name()+" is already blinded.", at);
	remove();
	return;
    }
    seteuid(getuid());
ob = new("/std/spells/shadows/stat_shadow_new");
    ob = new("/std/spells/shadows/blind_shadow");
    ob->set_shadow_name("blackout");
    ob->start_shadow(at);
    call_out("remove_blind", props["duration"], ob, at);
    if(!flag)
	message("info", "%^BOLD%^%^WHITE%^Your vision is rendered completely blind!%^RESET%^", at);
    return;
}

void remove_blind(object ob, object at) {
    if(at)
	message("info", "%^BOLD%^%^WHITE%^You have regained your normal vision.", at);
    if(ob)
	ob->external_destruct(ob);
    return;
}


