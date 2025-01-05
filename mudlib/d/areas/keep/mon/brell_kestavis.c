#include <std.h>
#include "../keep.h"

inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("brell");
    set_level(111);
    set_max_hp(180000);
    set_hp(180000);
    set_max_mp(250000);
    set_mp(250000);
    set_property("enhance criticals", -12);
    set_property("aggressive", 1);
    set_property("gang bang", 1);
    set_property("see invis", 1);
    set_combat_chance(120);
    set("id", ({ "brell", "brell kestavis", "demon", "rift lord", "lord of the rift", "lord of the demon rift", "demon rift lord", "demon lord" }));
    set_short("[111]Brell Kestavis, Lord of the Demon Rift");
    set_long("Armed with piercing blood red eyes and acidic drool dripping from his huge mouth, the legendary Demon Lord Brell Kestavis looks nothing like an ordinary member of his kin. He is second only to Owedquar himself in the order of darkness, and is rumored to possess even more destructive black magic than his sovereign. The huge axe resting comfortably in his right hand looks as if it can chop down the largest tree in the realm with a single swoop, and he swings it with incredible ferocity. As he hovers in the air upon the opening of his huge wings, you wonder what you ever did to deserve this.");
    set("race", "demon");
    set_gender("male");
    set_body_type("humanoid");
    set_alignment(-1199);
    set_skill("parry", 500);
    set_skill("dodge", 500);
    set_skill("perception", 2000);
    set_skill("concentrate", 1000);
    set_skill("reverse stroke", 2000);
    set_skill("owedquar's will", 1000);
    set_skill("attack", 800);
    set_skill("axe", 800);
    set_skill("melee", 800);
    set_skill("martial arts", 800);
    add_spell("terra pain", "$A");
    set_spell_level("terra pain", 6);
    ob = new(WEAP+"halcyon_axe.c");
    ob->move(this_object());
    force_me("equip");
    force_me("use concentrate");
    return;
}

void init() {
    ::init();
    tell_room(environment(this_object()), "%^BOLD%^%^WHITE%^The Necromancer glows bright red and reveals his true colors!%^RESET%^");
    tell_room(environment(this_object()), "");
    tell_room(environment(this_object()), "Brell Kestavis shouts: %^RED%^Prepare to die foolish mortal. I, Brell Kestavis, Grand Lord of the Demon Plane shall bring your life to a swift and final end. Prepare yourself well, for Owedquar is going to greet you at the Gates of Hell!%^RESET%^");
}

void die() {
    tell_room(environment(this_object()), "Brell Kestavis shouts: %^RED%^Impudent fools! My death means absolutely nothing to the grand scheme of Owedquar. As long as this axe retains the curse, the master will remain forever immortal. That mendicant would rather read a book than dispel ancient magic anyway.%^RESET%^");
    tell_room(environment(this_object()), "");
    tell_room(environment(this_object()), "%^YELLOW%^Lightning flashes across the room as the life force of the Demon Lord escapes his body, blinding your sight and deafening your ears for a few seconds until everything clears.%^RESET%^");
    tell_room(environment(this_object()), "");
    ::die();
}
