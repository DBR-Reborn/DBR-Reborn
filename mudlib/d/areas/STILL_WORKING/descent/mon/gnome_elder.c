#include <std.h>

inherit MONSTER;


create() {
  object ob;
	::create();
	set_name("gnome");
	set("race", "gnome");
	set_level(60);
	set_body_type("human");
set_id( ({"gnome elder", "gnome", "man", "elder"}));
set_short("The Gnome Elder");
set_long("This ancient, short man appears to be running the show here. You should probably sit around and listen to what's going on.");
set_skill("melee", 400);
set_skill("axe", 400);
ob = new("/d/damned/virtual/battle-axe_6.weapon");
ob->set_material("metal/raysorite");
  ob->set("id", ({"axe", "demon slayer", "slayer"}) );
  ob->set_short("The legendary 'Demon Slayer' Axe");
  ob->set_long("This is the legendary Demon Slayer, rumored to have been wielded by Bladestorm himself. It is insanely powerful, and is known to be able to cut through the thickest metals like butter. The Demon Blade was forged in the highest heavens by an unknown armourer, who supposedly had to sacrafice his very soul to gain the ability to make a weapon of this power. Rumor has it that the wielder is invincible while wielding this weapon - but that is doubtful.");
  ob->set_property("no decay",1);
  ob->set_property("no add quality",1);
  ob->set_wc(35, "cutting");
  ob->set_wield("You feel unadulterated power wash over you as you wield Demon Slayer!");
  ob->set_unwield("You almost don't want to let go, as the feeling of power leaves you.");
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
set_skill("parry", 350);
set_skill("dodge", 350);
set_skill("attack", 400);
set_property("melee damage", (["crushing" : 60]) );
set_lang_prof("common",10);
force_me("speak common");
	set_speech(10, "common", 
                ({
                "Just recently, a magic ring of some sort appeared on my finger. It came out of nowhere, and believe me, I was quite surprised! A few moments later, I felt a strange... voice in my head tell me that Tinkerfiddle (who, may I add, is a master forger!) of Shards had suggested me as a keeper of the ring! Now, what I'm trying to figure out is, what does this ring do? I sent it off to The Castle for inspection - I'm good friends with the Baron, you see. Then, a day after I got the damned ring and sent it off, the Demons came via gate and invaded our mines! This is an intolerable situation - we are able to repulse them from our settlement, but we need those mines open! I wish someone would help us!"
                }), 0);

}
