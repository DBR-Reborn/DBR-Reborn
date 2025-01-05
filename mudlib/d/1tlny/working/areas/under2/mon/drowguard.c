//Drow elf guard -By Schroom for Vishnu

#include <std.h>

inherit MONSTER;

void create()

{
object ob;
	::create();
	set_name("guard");
	set_id( ({"drow", "elf", "guard"}) );
	set("race", "drow-elf");
     set("short", "A Drow-elf Guard");
	set_languages( ({ "drow" }) );
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_long(
	"This is just a test.");	set_body_type("human");
       set_level(10+random(3) );
	set_gender("male");
	set_money("gold", random(50)+5);
new("/d/damned/virtual/long-sword_6.weapon")->move(this_object() );
new("/d/damned/virtual/long-sword_6.weapon")->move(this_object() );
	force_me("wield sword in right hand");
	force_me("wield sword 2 in left hand");
}
