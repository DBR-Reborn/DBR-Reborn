// gate guard
// 

inherit "/std/monster";

object ob;

void create() {
    ::create();
    set_name("Guard");
    set("id", ({"guard"}) );
    set_level(20);
    set("short", "A Munitio Guard");
    set("long", "The guard stands at attention, enforcing the laws of Munitio");
    set("race", "high-man");
    set_skill("parry", 80);
    set_skill("two handed polearm", 80);
    set_property("handedness", "left hand");
    set_gender("male");
    set_body_type("humanoid");
    set_languages( ({ "common" }) );
    set("aggressive", 0);
    ob=new("/d/damned/virtual/glaive_6.weapon");
    ob->set_material("metal/steel");
    ob->move(this_object());
    force_me("wield glaive in left hand and right hand");
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
    set_speech(1, "common", ({
	"Welcome to Munitio!",
	"May I kindly remind you to behave yourself!"
      }),0);
    set_emotes(1, ({
	"The guard looks around and nods to himself."
      }),0 );
}

void catch_tell(string str) {
    string a,b;
    object ob1;
    object ob2;
    if(sscanf(str, "%s attacks %s", a, b) ==2){
	a = lower_case(a);
	b= lower_case(b);
	ob1 = present(a, environment(this_object()));
	ob2= present(b, environment(this_object()));
	if(!ob1 || !ob2) return;
	if(ob1->query_name() != "guard") {
	    force_me("kill "+a);
	    return;
	}
    }
}
