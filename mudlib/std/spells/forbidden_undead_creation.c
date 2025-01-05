inherit "/std/spells/spell";

object ob;

void create() {
    ::create();
    set_property("name", "forbidden undead creation");
    set_property("skill", "orb manipulation");
    set_property("duration", "permanent");
    set_property("casting time", 400);
    set_property("base mp cost", 1098);
    set_property("dev cost", 12500);
    set_property("fast dev cost", 38700);
    set_property("spell level", 60);
    set_property("caster message", "You engage in the ultimate ritual of undead creation.");
    set_property("target message", "");
    set_property("observer message", "$C engages in the ultimate ritual of undead creation.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("info", "This is the highest level spell available to the Nethermancer Guild. With this magic, the most dedicated and disciplined of the profession can call forth the most powerful pet in all of Daybreak Ridge, the legendary Eternal Darkness! In order to do so however, a massive amount of souls must be united within a soul orb, the orb must be finalized with the spell 'forbidden orb finalization' before attempting this spell, and a rare artifact called the Owedquarian Diamond must be in the casters direct inventory. After it has been created, the Eternal Darkness will be a permanent pet that will follow any orders given by its creator (ask the pet for 'help' if necessary for info). The powerful super pet may be toggled aggressive at any time, but its ownership may never be transferred regardless of circumstances. As with other undead creation magics, the soul orb will be destroyed upon success of this spell. When casting the spell, no argument need be supplied for only one pet may be made with this magic."+
      "\n\nSyntax: 'cast *6 forbidden orb finalization at orb'\n\nNOTE: A Nethermancer may only own one Eternal Darkness at any given time due to its incredible power.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    if(power > 6) power = 6;

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(at->query_property("soul orb finalize") < 1) {
	message("info", "The soul orb has not yet been finalized and cannot be transformed into an undead.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "%^BOLD%^%^RED%^You inadvertently misdirect the energy and remove the soul orb's finalization!", caster);
	at->set_property("soul orb finalize", 0);
	at->set_short("A soul orb");
	remove();
	return;
    }
    if(at->query_property("eternal darkness souls") < 1) {
	message("info", "This orb is not finalized with an eternal darkness soul.", caster);
	remove();
	return;
    }
    if(!present("owedquarian diamond", this_player())) {
	message("info", "You do not possess the Owedquarian Diamond required to create the Eternal Darkness.", caster);
	remove();
	return;
    }
    if(member_array(caster->query_true_name(), "/d/damned/guilds/nethermancer/misc/ed_d.c"->query_enemies()) != -1) {
	message("info", "You already own an Eternal Darkness thus may not create another until it perishes.", caster);
	remove();
	return;
    }
    ob = new("/d/damned/guilds/nethermancer/pets/eternal_darkness.c");
    message("shout", "\n%^BOLD%^%^BLACK%^The skies turn pitch black and the sun is completely enveloped in a total eclipse, creating a black star symbolic of pure evil.%^RESET%^", users());
    call_out("ed_message", 10);
    ob->set_up(power);
    ob->set_owner((string)caster->query_name());
    present("owedquarian diamond", caster)->remove();
    at->remove();
    remove();
    return;
}

void ed_message() {
    message("shout", "\n%^BOLD%^%^BLACK%^A flashing pillar of energy emanates from the black sun, speeding towards the realm of Daybreak Ridge with sickening poise and velocity.%^RESET%^", users());
    call_out("ed_message_two", 10);
}
void ed_message_two() {
    message("shout", "\n%^BOLD%^%^BLACK%^The powerful dark energy culminates itself into a single dense sphere as it touches its target, the sphere covering the soul orb of a legendary Nethermancer.%^RESET%^", users());
    call_out("ed_message_three", 10);
}
void ed_message_three() {
    message("shout", "\n%^BOLD%^%^WHITE%^The soul orb explodes outwards, and the energy disperses all across the land blinding the eyes of even the most distant individuals from the Nethermancer. When the flash clears, a roar touching the ears of those same people pierces their souls as it is the roar of the now awakened Eternal Darkness of the Netherworld!%^RESET%^", users());
    message("info", "%^BOLD%^%^MAGENTA%^The orb shatters as its soul radiply expands outward, forming itself into the %^BOLD%^%^RED%^Eternal Darkness%^MAGENTA%^!%^RESET%^", this_player());
    message("info", "%^BOLD%^%^MAGENTA%^"+(string)this_player()->query_cap_name()+"'s orb shatters as its soul radiply expands outward, forming itself into the %^BOLD%^%^RED%^Eternal Darkness%^MAGENTA%^!%^RESET%^", environment(this_player()), ({ this_player() }));
    ob->move(environment(this_player()));
    this_player()->set_property("has eternal darkness", 1);
    "/d/damned/guilds/nethermancer/misc/ed_d.c"->add_enemy(this_player()->query_true_name());
}
