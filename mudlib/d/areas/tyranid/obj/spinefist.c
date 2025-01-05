#include <std.h>

inherit "/std/weapon";
int CRITS;

create() {
    string str;
    ::create();
    set_ac(3);
    set("id", ({ "fist", "spinefist" }));
    set_name("spinefist");
    set("short", "Spinefist");
    set("long",
      "A spherical creature bearing at least a superficial resemblance\n"
      +"to a stone-skinned sea urchin with dozens of needle-sharp chitin\n"
      +"spines radiating from it.  An unusual feature is a slender tendril\n"
      +"of pale sponge-like material that emerges from the chitin shell\n"
      +"somewhat like a limp tail.\n");
    set_type("knife");
    set_quality(5);
    set_property("no decay",1);
    set_property("no add quality",1);
    set_wc(16, "impaling");
    set_verb("skewer");
    set_hit_bonus(10);
    set_parry_bonus(10);
    set("skill level",70);
    set_weight(250);
    set_value(1500);
    set_material("/misc/chitin");
    set_wield( (: call_other, this_object(), "wield_spinefist" :) );
    set_unwield(
      "Almost as if sensing your desire to be rid of it, the Spinefist's\n"
      +"chitin plates unfold, freeing your hand.  As you withdraw your hand\n"
      +"from the alien thing, the slender tendril connecting it to your\n"
      +"lungs withdraws from you, leaving a curiously bloodless wound.");
    CRITS = 0;
    set_property("enchantment", 1);
    str = ({ ({
	"If you 'exhale' violently, you can increase this weapon's potency\n"
	+"for a time.\n",
	"detect magic"}) });
    set_property("extra long", str);
    set_hit( (: call_other, this_object(), "weapon_hit" :));
    return;
}

int wield_spinefist()
{
    message("atmosphere",
      "The chitin plates of the Spinefist flower open and dozens of\n"
      +"slender tendrils reach out from the moist interior, snaring\n"
      +"your fingers and drawing your hand inside.  The plates then\n"
      +"close, enfolding your hand in sticky warmth and firmly seating\n"
      +"the weapon on your fist.  Just as you begin to relax after this\n"
      +"alien experience, the slender tail-like tendril whips up and\n"
      +"darts toward you, piercing your chest and imbedding its tip in\n"
      +"your lungs!!!\n",
      this_player());
    this_player()->add_hp(-(20+random(20)));
    return 1;
}

void init()
{
    ::init();
    add_action("exhale","exhale");
}

int exhale()
{
    if (CRITS == 1) {
	message("info",
	  "The Spinefist is already pumped up.  Try again later.\n",
	  this_player());
	return 1;
    }
    if (CRITS == 2) {
	message("info",
	  "Your lungs haven't recovered from your last effort.  Try again later.\n",
	  this_player());
	return 1;
    }
    message("info",
      "You take a deep breath, and covering your mouth and nose exhale as\n"
      +"forcefully as you can.  Blinding pain fills your chest as oxygen\n"
      +"and blood flood down the connecting tendril to the Spinefist.  It\n"
      +"puffs up noticeably, the spines extending several inches and glistening\n"
      +"dangerously.\n",
      this_player());
    message("info",
      capitalize(this_player()->query_name()) 
      +"takes a deep breath and then doubles over in a very unhealthy\n"
      +"sounding coughing fit.\n",
      environment(this_player()),
      this_player());
    this_player()->add_hp(-(100+random(200)));
    do_critical(this_player(),this_player(),"stress C");
    CRITS = 1;
    delayed_call("inhale",240+random(120));
    return 1;
}

int inhale()
{
    if (this_object()->query_wielded()) {
	message("info",
	  "Having exhausted the energy in your blood and low on oxygen, the\n"
	  +"Spinefist begins to tire.  It sags back to its original volume and\n"
	  +"its spines dull noticeably.\n",
	  this_object()->query_wielded());
    }
    CRITS = 2;
    delayed_call("clear_crits",480+random(240));
    return 1;
}

int clear_crits()
{
    CRITS = 0;
    return 1;
}

int weapon_hit(object attacker) 
{
    int flag;
    if (CRITS == 1) {
	do_critical(environment(),attacker,"impaling C");
	return 10;
    }
    else return 0;
}
