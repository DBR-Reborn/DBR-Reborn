inherit "/std/pet";

object ob;

void create() {
    ::create();
    set_name("death dragon");
    set("race", "dragon");
    set_combat_chance(120);
    set("id", ({ "dragon", "undead dragon", "death dragon", "great dragon", "great undead dragon", "great death dragon", "dragon of death", "undead" }));
    set_body_type("dragon");
    set_attack(1);
    set_can_change_aggr(1);
    //set_change_ownership(0);
    set_carry(500);
    set_carry(0);
    set_save(1);
    set_level(77);
    set_property("enhance criticals", -3);
    set_property("nethermancer pet", 1);
    set_property("pet name", "death dragon");
    set_overall_ac(750);
    set_short("%^MAGENTA%^Great Undead Dragon%^BOLD%^%^RED%^");
    set_property("pet short", "%^MAGENTA%^Great Undead Dragon%^BOLD%^%^RED%^");
    call_out("nether_form_check", 0);
    set_long("What can only be described as the largest and most ferocious looking dragon you have ever seen now stands on four legs before your eyes. Its red and purple scales look as if they could serve as knives in their own right, and the footlong claws on its feet could probably shred through stainless steel. The entirety of its ten foot tall body is glowing with a bright cyan aura which serves as a powerful energy shield to help ward off even the nastiest of offensive assaults. Judging from the shield and the numerous souls endlessly floating throughout its mouth, this towering creature is unquestionably the product of absolutely incredible magic.");
    set_aggr_status(0);
    ob = new("/d/damned/guilds/nethermancer/misc/shield_shadow");
    ob->set_damage_allowed(10000);
    ob->set_shadow_name("death dragon shield");
    ob->start_shadow(this_object(), 2000000000, "");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    return;
}

void nether_form_check() {
    if(this_object()->query_property("nether form")) set_short(""+this_object()->query_property("pet short")+" %^BOLD%^%^GREEN%^(%^CYAN%^nether form%^GREEN%^)%^RED%^");
}

void set_up(int pow) {

    if(pow > 6) pow = 6;
    set_max_hp(17000 + 1700*pow);
    set_hp(17000 + 1700*pow);
    set_max_mp(15750 + 1575*pow);
    set_mp(15750 + 1575*pow);
    set_skill("attack", 85*pow);
    set_skill("melee", 85*pow);
    set_skill("dodge", 64*pow);
    set_skill("parry", 73*pow);
    set_skill("necromancy", 77*pow);
    add_spell("dark breath", "$A");
    set_spell_level("dark breath", pow);
    set_property("melee damage", ([ "crushing" : 60 + (16 * pow), "cutting" : 60 + (16 * pow), "acid" : 60 + (16 * pow), "infernal" : 60 + (16 * pow) ]));
return;
}

void shield_func() {
    ob->heal_damage();
    call_out("shield_func", 60);
}
