inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "black vision");
    set_property("skill", "vision magic");
    set_property("casting time", 10);
    set_property("base mp cost", 28);
    set_property("dev cost", 30);
    set_property("fast dev cost", 99);
    set_property("spell level", 4);
    set_property("moon", "warzau");
    set_property("caster message", "You cast %^BOLD%^%^BLACK%^black vision%^RESET%^ at $T.");
    set_property("target message", "$C casts %^BOLD%^%^BLACK%^black vision%^RESET%^ at you.");
    set_property("observer message", "$C casts %^BOLD%^%^BLACK%^black vision%^RESET%^ at $T.");
    set_property("must be present", 1);
    set_property("target type", "living");
    set_property("duration", 300);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: None\n\nThis spell when cast allows an Assassin to significantly empower the vision of either him or herself or the vision of another living target. Note however that this spell will NOT allow the target to see the invisible, other magics are required to perform that feat as well. The power of this spell determines both duration and the ability to see through area effect darkness magics of similar powers.\n\nSyntax: 'cast *6 black vision at zed'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

    if(flag) {
	message("info", "You inadvertently reverse the effects of your spell and instead blind "+(string)at->query_cap_name()+"!", caster);
	message("info", (string)caster->query_cap_name()+" inadvertently instead of aiding your vision blinds you!", at);
	ob = new("/std/spells/shadows/blind_shadow");
	ob->start_shadow(at);
	call_out("expire_blind", 80, at, ob);
	return;
    }
    ob = new("/std/spells/shadows/dvision_shadow");
    ob->set_max(10);
    ob->set_shadow_name("black vision");
    ob->start_shadow(at, props["duration"], "%^CYAN%^A black vision spell wears off.%^RESET%^");
    remove();
    return;
}

void expire_blind(object at, object shad) {
    if(at) {
	message("info", "%^BOLD%^%^WHITE%^You have regained your normal vision.%^RESET%^", at);
    }
    if(shad) {
	shad->external_destruct(shad);
    }
    return;
}
