#include <std.h>

inherit WEAPON;

object ob;
int number;
int selector;
int active = 0;

void create() {
    ::create();
    set_ac(0);
    set_name("staff");
    set("id", ({ "staff", "nether staff", "staff of the netherworld" }));
    set_short("%^BOLD%^%^CYAN%^A nether staff%^RESET%^");
    set_long("This is a very intricately designed staff, completely fashioned of a very lightweight dark gray wood with more twists than a world class maze. A stream of soul energy endlessly flows throughout the entire weapon, almost as if this weapon is alive as its own entity and not an ordinary staff of any sort. Voices seem to speak inside your head as you clutch it in your two hands, voices that suggest the deaths of both good and evil at its touch.");
    set_quality(6);
    set_type("two handed staff");
    set_property("no add quality", 1);
    set_property("no decay", 1);
    //set_property("brittle", 200);
    set_property("nethermancer weapon", 1);
    set_weight(20);
    set_material("soulwood");
    set_value(1);
    set_verb("purify");
    return;
}

void init() {
    ::init();
    set_wield((: call_other, this_object(), "weapon_wield" :));
    set_unwield((: call_other, this_object(), "weapon_unwield" :));
}

int weapon_wield() {
    if((string)this_player()->query_class() != "nethermancer") {
	write("The souls within the Nether Staff shock your hands and prevent you from grasping the weapon!");
	return 0;
    }
    write("%^BOLD%^%^RED%^You grasp the Nether Staff in your two hands and it begins to glow %^YELLOW%^fiercely%^RED%^ as you exert control upon its movement!%^RESET%^");
    message("info", "%^BOLD%^%^RED%^"+(string)this_player()->query_cap_name()+" grasps the Nether Staff in his two hands and it begins to glow %^YELLOW%^fiercely%^RED%^ as he exerts control upon its movement!%^RESET%^", environment(this_player()), ({ this_player() }));
    call_out("transformer_func", random(10));
    return 1;
}

int weapon_unwield() {
    write("The weapon ceases its glowing as you remove your hands from the tight grasp about its shaft.");
    return 1;
}

void transformer_func() {
    selector = random(80);
    this_object()->set_hit(0);
    this_object()->add_poisoning(-250);
    if(this_player()->query_current_attacker()) {
	active = 1;
	if(selector < 10) call_out("lifesteal_func", 0);
	if(selector > 9 && selector < 20) call_out("haste_func", 0);
	if(selector > 19 && selector < 30) call_out("bleeding_func", 0);
	if(selector > 29 && selector < 40) call_out("poison_func", 0);
	if(selector > 39 && selector < 50) call_out("stunning_func", 0);
	if(selector > 49 && selector < 60) call_out("essence_func", 0);
	if(selector > 59 && selector < 70) call_out("soultaker_func", 0);
	if(selector > 69) call_out("pain_func", 0);
	return;
    }
    if(!this_player()->query_current_attacker() && active > 0) {
	active = 0;
	message("info", "%^BOLD%^%^CYAN%^The Nether Staff stops glowing and returns to its original state.%^RESET%^", this_player());
	message("info", "%^BOLD%^%^CYAN%^"+(string)this_player()->query_cap_name()+"'s Nether Staff stops glowing and returns to its original state.%^RESET%^", environment(this_player()), ({ this_player() }));
	set_short("%^BOLD%^%^CYAN%^A nether staff%^RESET%^");
	call_out("transformer_func", random(10));
	return;
    }
    if(active < 1) {
	call_out("transformer_func", random(10));
	return;
    }
}

void lifesteal_func() {
    number = random(30);
    this_object()->set_hit((: call_other, "/wizards/diewarzau/obj/misc/vampiric_func", "vampiric_func", 30 :));
    message("info", "%^BOLD%^%^MAGENTA%^Your weapon begins to glow very eerily%^RESET%^", this_player());
    message("info", "%^BOLD%^%^MAGENTA%^"+(string)this_player()->query_cap_name()+"'s weapon begins to glow very eerily%^RESET%^", environment(this_player()), ({ this_player() }));
    set_short("%^BOLD%^%^CYAN%^A nether staff....%^MAGENTA%^it glows eerily%^RESET%^");
    call_out("transformer_func", number);
    return;
}

void haste_func() {
    number = random(30);
    ob = new("/std/spells/shadows/haste_shadow");
    ob->start_shadow(this_player(), number, "");
    message("info", "%^BOLD%^%^ORANGE%^Your weapon begins to shimmer with incredible agressiveness%^RESET%^", this_player());
    message("info", "%^BOLD%^%^ORANGE%^"+(string)this_player()->query_cap_name()+"'s weapon begins to shimmer with incredible agressiveness%^RESET%^", environment(this_player()), ({ this_player() }));
    set_short("%^BOLD%^%^CYAN%^A nether staff....%^ORANGE%^it shimmers agressively%^RESET%^");
    call_out("transformer_func", number);
    return;
}

void bleeding_func() {
    number = random(30);
    ob = new("/std/spells/shadows/weapon_shadow");
    ob->set_extra_wc(([ "bleeding" : 150 ]));
    ob->start_shadow(this_object(), number, "");
    message("info", "%^BOLD%^%^RED%^Your weapon begins to glow the hue of bright fresh blood.%^RESET%^", this_player());
    message("info", "%^BOLD%^%^RED%^"+(string)this_player()->query_cap_name()+"'s weapon begins to glow the hue of bright fresh blood.%^RESET%^", environment(this_player()), ({ this_player() }));
    set_short("%^BOLD%^%^CYAN%^A nether staff....%^RED%^it glows of blood%^RESET%^");
    call_out("transformer_func", number);
    return;
}

void poison_func() {
    number = random(30);
    this_object()->add_poisoning(250);
    message("info", "%^BOLD%^%^GREEN%^Your weapon begins to glow the green color of lethal poison.%^RESET%^", this_player());
    message("info", "%^BOLD%^%^GREEN%^"+(string)this_player()->query_cap_name()+"'s weapon begins to glow the green color of lethal poison.%^RESET%^", environment(this_player()), ({ this_player() }));
    set_short("%^BOLD%^%^CYAN%^A nether staff....%^GREEN%^it glows of disease%^RESET%^");
    call_out("transformer_func", number);
    return;
}

void stunning_func() {
    number = random(30);
    ob = new("/std/spells/shadows/weapon_shadow");
    ob->set_auto_crits(([ "stun D" : 50 ]));
    ob->start_shadow(this_object(), number, "");
    message("info", "%^BOLD%^%^YELLOW%^Your weapon begins to vibrate with a vicious ferocity.%^RESET%^", this_player());
    message("info", "%^BOLD%^%^YELLOW%^"+(string)this_player()->query_cap_name()+"'s weapon begins to vibrate with a vicious ferocity.%^RESET%^", environment(this_player()), ({ this_player() }));
    set_short("%^BOLD%^%^CYAN%^A nether staff....%^YELLOW%^it vibrates viciously%^RESET%^");
    call_out("transformer_func", number);
    return;
}

void essence_func() {
    number = random(30);
    this_object()->set_hit((: call_other, "/wizards/diewarzau/obj/misc/vamp_mp_func", "vampiric_func", 30 :));
    message("info", "%^BOLD%^%^BLUE%^Your weapon begins to shimmer at a notably devious rate.%^RESET%^", this_player());
    message("info", "%^BOLD%^%^BLUE%^"+(string)this_player()->query_cap_name()+"'s weapon begins to shimmer at a notably devious rate.%^RESET%^", environment(this_player()), ({ this_player() }));
    set_short("%^BOLD%^%^CYAN%^A nether staff....%^BLUE%^it shimmers deviously%^RESET%^");
    call_out("transformer_func", number);
    return;
}

void soultaker_func() {
    number = random(30);
    this_object()->set_hit((: call_other, "/wizards/diewarzau/obj/misc/vamp_mphp_func", "vampiric_func", 30 :));
    message("info", "%^BOLD%^%^BLACK%^Your weapon begins to flash the sights of pure darkness.%^RESET%^", this_player());
    message("info", "%^BOLD%^%^BLACK%^"+(string)this_player()->query_cap_name()+"'s weapon begins to flash the sights of pure darkness.%^RESET%^", environment(this_player()), ({ this_player() }));
    set_short("%^BOLD%^%^CYAN%^A nether staff....%^BLACK%^it flashes of darkness%^RESET%^");
    call_out("transformer_func", number);
    return;
}

void pain_func() {
    number = random(30);
    this_object()->set_hit((: call_other, "/std/cythug/shadows/pain_blade_func", "pen_func", 20 :));
    message("info", "%^BOLD%^%^WHITE%^Your weapon begins to swell the look of truly hellish torture.%^RESET%^", this_player());
    message("info", "%^BOLD%^%^WHITE%^"+(string)this_player()->query_cap_name()+"'s weapon begins to swell the look of truly hellish torture.%^RESET%^", environment(this_player()), ({ this_player() }));
    set_short("%^BOLD%^%^CYAN%^A nether staff....%^WHITE%^it swells of torture%^RESET%^");
    call_out("transformer_func", number);
    return;
}
