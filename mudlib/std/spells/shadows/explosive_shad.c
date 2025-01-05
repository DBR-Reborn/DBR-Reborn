//    by Glen

#include <colors.h>

inherit "/std/spells/shadows/weapon_shadow";

int pow;

void set_power(int x){ 
    pow = x;
}

string query_short(){
    return next_shadow()->query_short() + 
    " <" + CBOLD + CRED + "EXPLOSIVE" + CRESET + ">";
}

void do_thrown(object from, object at){
    mapping mp;
    string *keys;
    string limb;
    int i, damage, prot;
    int x = 0;
    message("info",
      CBOLD + CMAGENTA + "BOOM " + CRESET +
      at->query_cap_name() + " is hit with an exploding weapon!",
      all_inventory(environment(from)), ({ at, from }));
    message("info",
      CBOLD + CMAGENTA + "BOOM " + CRESET +
      from->query_cap_name() + " hit you with an exploding weapon, that hurts!",
      at, from);
    message("info",
      CBOLD + CMAGENTA + "BOOM " + CRESET +
      "The weapon hit " + at->query_cap_name(),
      from, at);

    mp = query_all_wc();
    keys = keys(mp);

    for(i = 0; i < sizeof(keys); i++)
	x += query_wc(keys[i]);

    x += query_property("hit bonus") * 3;

    x += query_property("enhance criticals") * 50;


    for(i = 0; i < pow; i++){
	damage = x;
	limb = at->return_target_limb();
	prot = at->query_current_protection(limb, "stress") / 2;
	message("info",
	  CBOLD + CMAGENTA + 
	  "Your " + limb + " is fragged!",
	  at, from);
	if(damage > prot)
	    at->do_damage(at->return_target_limb(), damage - prot);

	if(random(100) < 3*pow)
	    damage *= 2;
	at->do_damage(at->return_target_limb(), damage / (1 + random(9)));
	if(wizardp(from))
	    message("info", "damage: " + damage, from);
    }

    who_shadowed->move("/std/glen/rooms/weapon_death");
    remove();
}

