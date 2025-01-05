#include <std.h>

inherit MONSTER;

int levelrange=random(10) + 50;

create() {
    object ob;
    ::create();
    set_name("gnome");
    set("race", "gnome");
    set_level(levelrange);
    set_body_type("human");
    set_id( ({"gnome", "gnome guard", "guard"}));
    set_short("A Gnomish guard");
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
    set_skill("parry", 275);
    set_skill("dodge", 275);
    set_skill("attack", 350);
}
