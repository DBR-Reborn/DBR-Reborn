// gate guard
// 

inherit "/std/monster";

object ob;

void create() {
     ::create();
     set_name("Governor");
     set("id", ({"governor"}) );
     set_level(30);
     set("short", "The governor of Munitio");
     set("long", "The governor is a rather short and squat man, not quite fat, but very stocky. He is dressed in shining armour and appears quite capable of defending himself.");
     set("race", "high-man");
     set_skill("parry", 80);
     set_skill("two handed staff", 95);
     set_skill("dodge", 70);
     set_property("handedness", "left hand");
     set_gender("male");
     set_body_type("humanoid");
     set_languages( ({ "common" }) );
     set("aggressive", 0);
      ob = new("/d/damned/virtual/quarter-staff_6.weapon");
      ob->set_short("Staff of the Metal Warrior");
      ob->set_long("The Staff of the Metal Warrior is the weapon of choice for many who are a part of the evil 'Metal Warrior' organization. It does damage which is truly considered unworldly.");
      ob->set_material("metal/steel");
      ob->set_wc(25, "disruption");
      ob->move(this_object());
     force_me("wield staff in left hand and right hand");
  ob = new("/d/damned/virtual/breast-plate.armour");
  ob->set_material("metal/steel");
  ob->move(this_object());
  ob = new("/d/damned/virtual/plate-greaves.armour");
  ob->set_material("metal/steel");
  ob->move(this_object());
  ob = new("/d/damned/virtual/plate-bracer.armour");
  ob->set_material("metal/steel");
  ob->move(this_object());
  ob = new("/d/damned/virtual/plate-bracer.armour");
  ob->set_material("metal/steel");
  ob->move(this_object());
  ob = new("/d/damned/virtual/taces.armour");
  ob->set_material("metal/steel");
  ob->move(this_object());
  ob = new("/d/damned/virtual/metal-boots.armour");
  ob->set_material("metal/steel");
  ob->move(this_object());
  ob = new("/d/damned/virtual/gauntlet.armour");
  ob->set_material("metal/steel");
  ob->move(this_object());
  ob = new("/d/damned/virtual/gauntlet.armour");
  ob->set_material("metal/steel");
  ob->move(this_object());
  ob = new("/d/damned/virtual/metal-visor.armour");
  ob->set_material("metal/steel");
  ob->move(this_object());
  ob = new("/d/damned/virtual/robe.armour");
  ob->set_material("cloth");
  ob->move(this_object());
  ob = new("/d/damned/virtual/tabard.armour");
  ob->set_short("The Tabard of the Iron Warrior");
  ob->set_long("This tabard has a picture of a warrior dressed all in metal.");
  ob->set_material("leather");
  ob->move(this_object());
  force_me("equip");
set_lang_prof("common",10);
force_me("speak common");
     set_speech(10, "common", ({
          "What are you doing in my garden?",
	  "Get out of here you filthy swine!"
     }),0);
     set_emotes(10, ({
          "The governor glares at you"
	}),0 );
}
