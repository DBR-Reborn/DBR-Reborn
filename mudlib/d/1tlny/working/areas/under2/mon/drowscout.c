//Drow elf scout -by Schroom for Vishnu

#include <std.h>

inherit MONSTER;

create()
{
object ob;

   ::create();
	set_name("scout");
	set_id( ({ "elf", "drow", "scout" }) );
    set_short("A Drow-elf Scout");
	set("race", "drow-elf");
	set_languages(({ "drow" }) );
	set_wielding_limbs( ({ "right hand" }) );
	set_long(
	"The elf seems to be taking a break from looking for intruders."
	" If he was standing he'd probably reach six feet tall. His skin "
	"is pale. And his piercing blue eyes stare into nothingness.");
	set_body_type("human");
	set_level(8+random(2) );
	set_gender("male");
	set_emotes(5,
		({
		  "The scout looks up, doesn't notice you, then goes back to resting.",
		  "The scout stands up, stretches his legs, then sits back down.",
		  "The scout yawns.",
		}), 0);
	set_money("gold", random(20)+15);
new("/d/damned/virtual/long-sword_5.weapon")->move(this_object());
	force_me("wield sword in right hand");
}
