#include <std.h>

inherit ARMOUR;

object ob;
int number;
int selector;
int active = 0;

void create() {
    ::create();
    set_ac(0);
    set_name("robe");
    set("id", ({ "robe", "nether robe", "robe of the netherworld" }));
    set_short("%^BOLD%^%^CYAN%^A nether robe%^RESET%^");
    set_long("This is a glowing inscripted robe the likes of which you have never seen in the realm of Daybreak Ridge. The numerous runes covering it carry artistry as if they were inscribed by a being not of the mortal world, and the fabric is unlike any that can be created from skinning even the most powerful of beasts. A shimmering aura of souls surrounds the entirety of the clothing, seemingly creating a potent bond with the wearer providing him with great power as it touches their body.");
    set_type("robe");
    set_limbs(({ "torso", "left hand", "right hand", "left arm", "right arm", "right leg", "left leg", "right foot", "left foot", "head" }));
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_weight(20);
    set_material("soulskin");
    set_value(1);
    return;
}

void init() {
    ::init();
    set_wear((: call_other, this_object(), "robe_wear" :));
    set_remove((: call_other, this_object(), "robe_remove" :));
}

int robe_wear() {
    if((string)this_player()->query_class() != "nethermancer") {
	write("The souls surrounding the Nether Robe jolt your entire body with devastating energy and force you to immediately take it off!");
	return 0;
    }
    write("%^BOLD%^%^BLUE%^You place the Nether Robe around your body and watch as it begins to shimmer. Numerous active souls orbiting the robe create a powerful bond with you, granting you incredible protection and power!%^RESET%^");
    message("info", "%^BOLD%^%^BLUE%^"+(string)this_player()->query_cap_name()+" places the Nether Robe around his body and watches as it begins to shimmer. Numerous active souls orbiting the robe create a powerful bond with him, granting him incredible protection and power!%^RESET%^", environment(this_player()), ({ this_player() }));
 //   call_out("transformer_func", random(10));
    return 1;
}

int robe_remove() {
    write("As you remove the robe from your body, you suddenly feel inferior from the souls encircling it terminating their bond with you."); 
    return 1;
}

//void transformer_func() {
 //   selector = random(40);
//    this_player()->set("no stun", 0);
//    if(this_player()->query_current_attacker()) {
//	active = 1;
//	if(selector < 10) call_out("healing_func", 0);
//	if(selector > 9 && selector < 20) call_out("antistun_func", 0);
//	if(selector > 19 && selector < 30) call_out("phys_shield_func", 0);
//	if(selector > 29) call_out("crit_shield_func", 0);
//	return;
 //   }
//    if(!this_player()->query_current_attacker() && active > 0) {
//	active = 0;
//	message("info", "%^BOLD%^%^CYAN%^The Nether Robe ceases its shimmering and reverts back to normal.%^RESET%^", this_player());
//	message("info", "%^BOLD%^%^CYAN%^"+(string)this_player()->query_cap_name()+"'s Nether Robe ceases its shimmering and reverts back to normal.%^RESET%^", environment(this_player()), ({ this_player() }));
//	set_short("%^BOLD%^%^CYAN%^A nether robe%^RESET%^");
//	call_out("transformer_func", random(10));
//	return;
//    }
//    if(active < 1) {
//	call_out("transformer_func", random(10));
//	return;
//    }
//}

//void healing_func() {
//    number = random(30);
//    ob = new("/std/spells/shadows/auto_heal_shad");
 //   ob->set_perc(100);
 //   ob->set_power(10);
//    ob->start_shadow(this_player(), number, "");
 //   message("info", "%^BOLD%^%^BLUE%^Your robe begins to give off extremely radiant pulses of light.%^RESET%^", this_player());
//    message("info", "%^BOLD%^%^BLUE%^"+(string)this_player()->query_cap_name()+"'s robe begins to give off extremely radiant pulses of light.%^RESET%^", environment(this_player()), ({ this_player() }));
//    set_short("%^BOLD%^%^CYAN%^A nether robe....%^BLUE%^it pulses of life%^RESET%^");
 //   call_out("transformer_func", number);
//    return;
//}

//void antistun_func() {
//    number = random(30);
 //   this_player()->set("no stun", 1);
 //   message("info", "%^BOLD%^%^MAGENTA%^Your robe begins to flash with an absolutely incredible ferocity.%^RESET%^", this_player());
//    message("info", "%^BOLD%^%^BLUE%^"+(string)this_player()->query_cap_name()+"'s robe begins to flash with an absolutely incredible ferocity.%^RESET%^", environment(this_player()), ({ this_player() }));
 //   set_short("%^BOLD%^%^CYAN%^A nether robe....%^MAGENTA%^it flashes ferociously%^RESET%^");
 //   call_out("transformer_func", number);
//    return;
//}

//void phys_shield_func() {
//    number = random(30);
//    ob = new("/d/damned/guilds/nethermancer/misc/robe_phys_shield");
 //   ob->set_damage_allowed(1000000);
 //   ob->start_shadow(this_player(), number, "");
//    message("info", "%^BOLD%^%^GREEN%^A powerful aura of soul energy emanates from your robe and shields your entire skin!%^RESET%^", this_player());
//   message("info", "%^BOLD%^%^GREEN%^A powerful aura of soul energy emanates from "+(string)this_player()->query_cap_name()+"'s robe and shields his entire skin!%^RESET%^", environment(this_player()), ({ this_player() }));
 //   set_short("%^BOLD%^%^CYAN%^A nether robe....%^GREEN%^it is orbited by powerful soul energy%^RESET%^");
 //   call_out("transformer_func", number);
 //   return;
//}

//void crit_shield_func() {
 //   number = random(30);
  //  ob = new("/d/damned/guilds/nethermancer/misc/robe_crit_shield");
  //  ob->set_damage_allowed(1000000);
  //  ob->start_shadow(this_player(), number, "");
  //  message("info", "%^BOLD%^%^RED%^A mass of souls exerts a stranglehold about your robe creating a devastating barrier.%^RESET%^", this_player());
  //  message("info", "%^BOLD%^%^RED%^A mass of souls exerts a stranglehold about "+(string)this_player()->query_cap_name()+"'s robe creating a devastating barrier.%^RESET%^", environment(this_player()), ({ this_player() }));
 //   set_short("%^BOLD%^%^CYAN%^A nether robe....%^RED%^it appears chokingly wrapped in souls%^RESET%^");
 //   call_out("transformer_func", number);
 //   return;
//}
