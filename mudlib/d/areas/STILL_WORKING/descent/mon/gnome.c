#include <std.h>

inherit MONSTER;

int levelrange=random(10) + 45;

create() {
  object ob;
	::create();
	set_name("gnome");
	set("race", "gnome");
	set_level(levelrange);
	set_body_type("human");
switch(random(5)) {
case 0:
set_id( ({"gnome", "gnome man", "man"}));
set_short("A Gnomish man");
set_long("This is a short little Gnomish man. He has a light stubble beard, and appears to be quite aggravated. You wonder what could be wrong.");
set_skill("melee", 350);
break;
case 1:
set_id( ({"gnome", "gnome woman", "woman"}));
set_short("A Gnomish woman");
set_long("This plump Gnome woman is probably a mother of many wonderful and mischevious young Gnomes. Your eyes water at the thought of cute little Gnome children playing happily together. She notices you looking at her, and gives a sad smile.");
set_skill("melee", 350);
break;
case 2:
set_id( ({"gnome", "gnome boy", "boy"}));
set_short("A Gnomish boy");
set_long("Gnome children tend to be the mischevious, playful sort, and this cute little boy proves to be no exception. You watch as he terrorizes everyone around him with his well-meaning antics, and smile.");
set_skill("melee", 300);
break;
case 3:
set_id( ({"gnome", "gnome girl", "girl"}));
set_short("A Gnomish girl");
set_long("This teenage Gnome girl is just starting to grow up in the world. She conducts herself with an elegant and regal poise. You guess she will probably go far in life as long as she sets her goals right.");
set_skill("melee", 300);
break;
case 4:
set_id( ({"gnome", "gnome warrior", "warrior"}));
set_short("A Gnomish warrior");
set_long("Gnomes, to be honest, are not known as the greatest warriors in the world. This one looks quite comptent, though, so you fear him greatly. He has metal armor and a sharp axe.");
set_skill("axe", 350);
ob = new("/d/damned/virtual/battle-axe_6.weapon");
ob->set_material("metal/raysorite");
ob->move(this_object());
force_me("wield axe in left hand");
ob = new("/d/damned/virtual/breast-plate.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/plate-greaves.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/plate-bracer.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/plate-bracer.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/taces.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/metal-boots.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/gauntlet.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/gauntlet.armour");
ob->move(this_object());  
ob = new("/d/damned/virtual/metal-visor.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/robe.armour");
ob->set_material("cloth");
ob->move(this_object());
ob = new("/d/damned/virtual/tabard.armour");
ob->set_material("leather");
ob->move(this_object());
  force_me("equip");
}
set_skill("parry", 275);
set_skill("dodge", 275);
set_skill("attack", 350);
set_property("melee damage", (["crushing" : 60]) );
}
