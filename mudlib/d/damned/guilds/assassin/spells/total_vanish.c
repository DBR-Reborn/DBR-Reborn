inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("skill", "assassin's magic");
    set_property("casting time", 25);
    set_property("base mp cost", 166);
    set_property("dev cost", 255);
    set_property("fast dev cost", 747);
    set_property("spell level", 34);
    set_property("moon", "luna");
    set_property("caster message", "You call forth considerable magic power in an attempt to completely vanish.");
    set_property("target message", "");
    set_property("observer message", "$C calls forth considerably magic power in an attempt to completely vanish.");
    set_property("spell type",({ }));
    set_property("duration", 120);
    set_property("target type", "living");
    set_property("must be present", 1);
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 200%\n\nThis is a very powerful invisibility magic that can potentially vanish an Assassin completely from sight at all times, and unlike the 'fade' spell it will remain effective even when he or she is engaged in combat and not wear in any way until its duration has ended. Once invisible, the caster will be undetectable to any level of perception that all bystanders can have, with the sole exception being that of having see invisible magics active.\n\nSyntax: 'cast *6 total vanish'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

    seteuid(getuid());
    if(flag) {
	message("info", "You misdirect some of your magic and while the attempt to make yourself invisible was successful, you are also entirely and what seems to be irreversibly blinded!", caster);
	ob = new("/std/spells/shadows/blind_shadow");
	call_out("expire_blind", 100000000, caster, ob);
    }
    if(caster->query_invis()) {
	message("info", "You are already invisible.", caster);
	message("info", ""+(string)caster->query_cap_name() +"'s spell fails.", environment(caster), ({ caster }) );
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    message("info", "%^B_CYAN%^%^WHITE%^Your are entirely vanished from all naked sight!%^RESET%^", caster);
    message("info", ""+(string)caster->query_cap_name()+" entirely vanishes from all naked sight.", environment(caster), ({ caster }));
    ob = new("/std/spells/shadows/imp_invis_shadow");
    ob->set_shadow_name("total vanish");
    ob->start_shadow(caster, props["duration"], "%^B_CYAN%^%^WHITE%^You return to normal from your invisibility.");
    remove();
    return;
}
