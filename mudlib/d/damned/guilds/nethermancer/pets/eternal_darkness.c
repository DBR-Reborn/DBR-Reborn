inherit "/std/pet";

object ob;

void create() {
    ::create();
    set_name("eternal darkness");
    set("race", "undead");
    set_combat_chance(120);
    set("id", ({ "darkness", "eternal darkness", "darkness of the netherworld", "eternal darkness of the netherworld", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    //set_change_ownership(0);
    set_carry(500);
    set_save(1);
    set_level(100);
    set_property("enhance criticals", -5);
    set_property("nethermancer pet", 1);
    set_property("pet name", "eternal darkness");
    set_overall_ac(1111);
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness of the Netherworld%^BOLD%^%^RED%^");
    set_long("Before you floating slightly above the ground is the most feared undead creation known to the minds of the universe, the legendary eternal darkness of the netherworld. Comprised of pure darkness and the most damned of damned souls, it looks as it only a truly chosen master of the most elite of nether arts could possibly have binded everything together to create the creature. As it moves, its body expands outwards and the souls become more visible as they orbit the main body at an electrifying speed. Ear splitting wails emanate from all the souls simultaneously along with a tremendous roar from its main face, educating you that it desperately seeks more and more souls and will likely stop at nothing to slay whatever it can to obtain them. With this creature present in front of you, it can only be a matter of time before the netherworld itself breaks open and the world is overrun by everlasting death.");
    set_aggr_status(0);
    ob = new("/d/damned/guilds/nethermancer/misc/krieger_of_sin.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/ed_shield.c");
    ob->set_damage_allowed(25000);
    ob->set_shadow_name("eternal darkness shield");
    ob->start_shadow(this_object(), 2000000000, "");
    ob = new("/std/spells/shadows/ele_pres_shad");
    ob->set_power(5);
    ob->set_damage(({ "infernal", "aether" }));
    ob->set_shadow_name("eternal darkness presence");
    ob->start_shadow(this_object(), 2000000000, "");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    force_me("equip");
    return;
}

void set_up(int pow) {

    if(pow > 6) pow = 6;
    set_max_hp(50000 + 5000*pow);
    set_hp(50000 + 5000*pow);
    set_max_mp(40000 + 4000*pow);
    set_mp(40000 + 4000*pow);
    set_skill("attack", 150*pow);
    set_skill("melee", 150*pow);
    set_skill("blade", 145*pow);
    set_skill("knife", 145*pow);
    set_skill("dodge", 100*pow);
    set_skill("parry", 120*pow);
    set_skill("warcasting", 111*pow);
    set_skill("assassin's magic", 111*pow);
    set_skill("spiritmancy", 111*pow);
    set_skill("necromancy", 111*pow);
    add_spell("ethereal storm", "$A");
    set_spell_level("ethereal storm", pow);
    add_spell("wrath of the magus", "$A");
    set_spell_level("wrath of the magus", pow);
    add_spell("disease bone rot", "$A");
    set_spell_level("disease bone rot", pow);
    add_spell("pain", "$A");
    set_spell_level("pain", pow);
    set_property("melee damage", ([ "reflection" : 75 + (20 * pow), "infernal" : 75 + (20 * pow), "time" : 75 + (20 * pow), "aether" : 75 + (20 * pow), "sonic" : 75 + (20 * pow) ]));
return;
}

void die() {
    message("info", "%^BOLD%^%^RED%^The Eternal Darkness lets out one final hideous roar as it completely explodes and disperses about the air for what seems like a mile in every direction!", environment(this_object()));
    "/d/damned/guilds/nethermancer/misc/ed_d.c"->remove_enemy(this_object()->query_owner());
    ::die();
}
