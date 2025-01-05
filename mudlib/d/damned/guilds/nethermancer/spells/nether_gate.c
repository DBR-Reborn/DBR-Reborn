inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "nether gate");
    set_property("skill", "nether magic");
    set_property("casting time", 55);
    set_property("base mp cost", 102);
    set_property("dev cost", 88);
    set_property("fast dev cost", 269);
    set_property("spell level", 15);
    set_property("moon","luna");
    set_property("caster message", "You attempt to open a portal to a plane within the Netherworld!");
    set_property("target message","");
    set_property("observer message", "$C attempts to open a portal to a plane within the Netherworld.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("duration", 60);
    return;
}

void info() {
    message("help", "This magic enables a Nethermancer to use the power contained within a nexus to open a gateway to a distant plane within the Netherworld where he or she may store various undead creations that they make throughout their endeavours. In order to open this plane however, a charged nexus must be present within the room and its entire charge must be expended to create the actual portal. The nexus does not have to be at its maximum charge, but it still must be at least 75% full for the spell to succeed. Upon teleportation to the plane, the caster has 1 minute to do his or her buisness with storing or removing existing pets through the exit back to where teleportion occurred from before he/she is forced back out. When casting this spell, the nexus will always serve as the target in the syntax.\n\nSyntax: 'cast *6 nether gate at nexus'\n\nNOTE: This spell will not work on the unlimited nexus in the guild hall. Also the skill 'undead suggestion' is required to make undead pets enter the gate.", this_player());
}

int undead_filter(object who, object caster) {
    if(!living(who)) return 0;
    if((string)who->query_owner() != (string)caster->query_name()) return 0;
    return 1;
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object room, *inv;
    object ob;

    room = find_object_or_load(sprintf("/d/damned/virtual/%s.undead", (string)caster->query_name()));
    if(!at->query_property("nexus class")) {
	message("info", "This spell may only be cast upon a nexus.", caster);
	remove();
	return;
    }
    if(at->query_property("guild nexus") > 0) {
	message("info", "This nexus cannot be used to create a gateway to your nether plane.", caster);
	remove();
	return;
    }
    if(at->query_property("charge remaining") < ((at->query_property("charge cap")) - (at->query_property("charge cap")/4))) {
	message("info", "This nexus is not charged high enough to successfully create a strong enough portal to reach your nether plane.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "You inadvertently disperse all of the charge within the nexus as well as relieve yourself of all remaining magic power!", caster);
	at->set_property("charge remaining", 0);
	caster->set_mp(0);
	remove();
	return;
    }
    at->set_property("charge remaining", 0);
    message("info", "%^BOLD%^%^CYAN%^You successfully create a nether gate leading to your nether plane!%^RESET%^", caster);
    message("info", "%^BOLD%^%^CYAN%^"+(string)caster->query_cap_name()+" successfully creates a nether gate leading to his nether plane!%^RESET%^", environment(caster), ({ caster }));
    room->open_exit(environment(caster), props["duration"]);
    ob = new("/d/damned/guilds/nethermancer/misc/nether_gate.c");
    ob->set_property("gate location", base_name(room));
    ob->move(environment(caster));
    remove();
    return;
}

