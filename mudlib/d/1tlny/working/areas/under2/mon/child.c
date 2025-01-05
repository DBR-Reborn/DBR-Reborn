//Drow elf child -Schroom for Vishnu

#include <std.h>
inherit MONSTER;

void create() 
{
	object ob;
	::create();
	set_name("Drow elf kid");
	set("id", ({"drow", "elf", "kid"}) );
	set_level(5+random(2));
     set("short", "Drow-elf Kid");
	set("long",
 "The child stands before you about three feet tall "
    "and scowls as u have entered "
"His place of dwelling without invitation.  "
    "Quickly, he forgets you are there, and he goes back "
	"to whatever task he was performing."
	);
set("race", "drow-elf");
	set_gender("male");
	set_skill("knife", 15);
	set_skill("dodge", 10);
	set_body_type("human");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_emotes(5,
	 ({
	  "The drow scampers about busily.",
	  "The child looks at you, then turns back to his work.",
	}), 0);
	ob = new("/d/damned/virtual/dagger_5.weapon");
	ob->move(this_object());
	force_me("wield dagger in right hand");
}
