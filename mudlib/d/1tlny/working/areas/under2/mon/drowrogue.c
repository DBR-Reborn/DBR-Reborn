//Drow elf rouge -By Schroom for Vishnu

#include <std.h>

inherit MONSTER;

void create () {
	::create();
       set_name("rogue");
     set_id( ({"drow", "elf", "rogue"}) );
        set_short("A Drow-elf Rogue");
       set("race", "drow-elf");
      set_languages( ({"drow-elf"}) );
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_long(
	"This lean Drow wanders about aimlessly.  His blood ridden sword is"
	"wielded in his left hand, with a small shield protecting the other side"
	"of his body. He seems to be looking for trouble."
);
	set_body_type("human");
    set_level(9);
	set_gender("male");
	set_money("gold", random(10)+10);
new("/d/damned/virtual/large-shield.armour")->move(this_object());
new("/d/damned/virtual/long-sword_3.weapon")->move(this_object());
	force_me("wield sword in left hand");
force_me("wear shield on right hand");
}
