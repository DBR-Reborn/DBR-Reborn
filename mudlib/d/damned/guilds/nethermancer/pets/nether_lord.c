inherit "/std/pet";

object ob;

void create() {
    ::create();
    set_name("nether lord");
    set("race", "undead");
    set_combat_chance(120);
    set("id", ({ "lord", "nether lord", "lord of the arts", "lord of the nether arts", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    //set_change_ownership(0);
    set_carry(500);
    set_save(1);
    set_level(80);
    set_property("enhance criticals", -3);
    set_property("nethermancer pet", 1);
    set_property("pet name", "nether lord");
    set_overall_ac(800);
    set_short("%^BLUE%^Lord of the Nether Arts%^BOLD%^%^RED%^");
    set_property("pet short", "%^BLUE%^Lord of the Nether Arts%^BOLD%^%^RED%^");
    call_out("nether_form_check", 0);
    set_long("Standing before you wearing a devilish red and black robe as well as a hood looking even more menacing, this indeed looks as if it may be a sorcerer of the highest magical order. Grasped by both hands is a glowing staff made of no wood you have ever seen nor heard of, its glow fiercely increasing the closer you get to the magus. Not a single thing can be seen through the area that the hood covers, not even the slightest trace of an eye. However you know as well as anyone that this master warlock can see you as clearly as it can see the sun on a bright summer day."); 
    set_aggr_status(0);
    ob = new("/d/damned/guilds/nethermancer/misc/ancient_staff.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/lord_robe.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/lord_hood.c");
    ob->move(this_object());
    set_skill("concentrate", 200);
    force_me("use concentrate");
    force_me("equip");
    return;
}

void nether_form_check() {
    if(this_object()->query_property("nether form")) set_short(""+this_object()->query_property("pet short")+" %^BOLD%^%^GREEN%^(%^CYAN%^nether form%^GREEN%^)%^RED%^");
}

void set_up(int pow) {

    if(pow > 6) pow = 6;
    set_max_hp(20000 + 2000*pow);
    set_hp(20000 + 2000*pow);
    set_max_mp(18000 + 1800*pow);
    set_mp(18000 + 1800*pow);
    set_skill("attack", 90*pow);
    set_skill("melee", 90*pow);
    set_skill("dodge", 68*pow);
    set_skill("parry", 78*pow);
    set_skill("owedquar's will", 81*pow);
    set_skill("warcasting", 81*pow);
    set_skill("channelling", 81*pow);
    add_spell("fumble shield", "$(ME)");
    set_spell_level("fumble shield", pow);
    add_spell("storm of ages", "$A");
    set_spell_level("storm of ages", pow);
    add_spell("age", "$A");
    set_spell_level("age", pow);
    set_property("melee damage", ([ "crushing" : 63 + (17 * pow), "infernal" : 63 + (17 * pow), "time" : 63 + (17 * pow), "radiation" : 63 + (17 * pow) ]));
return;
}
