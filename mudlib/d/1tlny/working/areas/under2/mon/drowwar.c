//Drow warrior -By Schroom for Vishnu

#include <std.h>
inherit MONSTER;

void create()
{
object ob;
	::create();
     set_name("warrior");
       set_id( ({ "drow", "drow-elf", "drow elf", "elf", "warrior" }) );
	set("race", "drow");
       set("short", "A Drow-elf Warrior");
	set_languages( ({ "drow" }) );
	set_wielding_limbs( ({ "right hand", "left hand"}) );
	set_long(
	"The elf warrior stands before you with a massive sword wielded"
	" in both hands.  His muscles buldge, along with a vein in his"
	" forehead. The drow warriors are known for the excellent"
	" fighting skills."
	);
	set_body_type("human");
	set_level(12+random(2));
	set_gender("male");
		set_money("gold", random(200)+50);

    ob = new("d/damned/virtual/two-handed-sword_3.weapon");
    ob->move(this_object());
    ob->set_wc(5, "fire");
	force_me("wield sword in right hand and left hand");
}
