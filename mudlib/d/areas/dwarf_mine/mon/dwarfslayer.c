#include <std.h>
#include <dirs.h>
#include "../a1.h"
inherit MONSTER;
string mtlname;

void create() {
int zlevel;
   object money;
   object ob;
   ::create();
    zlevel = (30+random(4));
   set_level(zlevel);
   set_short("["+zlevel+"]Dwarf Slayer");
   set_overall_ac(zlevel*2);
    set_name("slayer");
    set("gang bang", 1);
    set_id( ({ "slayer","dwarf", "dwarf slayer" }) );
    set_gender("male");
    set("race", "dwarf");
    set_alignment(0);
   set("long", "A Dwarf Slayer is the ultimate Dwarf warrior, the perfect personification of death and destruction, and bringer of doom to the enemies of their race."); 
    set_skill("axe", zlevel*8);
    set_skill("blunt", zlevel*8);
    set_wielding_limbs( ({"right hand","left hand"}) );
    set_body_type("human");
 switch(random(3)){
      case 0:mtlname="mithril";break;
      case 1:mtlname="elrodnite";break;
      case 2:mtlname="platnite";break;
    }

    switch(random(3)){
case 0:ob = new("/d/damned/virtual/battle-axe_6.weapon");
ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ battle-axe");
    ob -> set("long",
"This weapon is extremely well made. The long, sharp blade is finely "
"balanced. Soft leather is wrapped around the pommel, making the axe "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"cutting");
    ob -> set_wc(zlevel+random(zlevel),"impaling");
    ob -> set_hit_bonus(zlevel);
	ob->set_property("no decay",1);
    //ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield axe in right hand");
    ob = new("/d/damned/virtual/hammer_6.weapon");
ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ hammer");
    ob -> set("long",
"This weapon is extremely well made. The huge, blunt hammer is finely "
"balanced. Soft leather is wrapped around the pommel, making the hammer "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"crushing");
    ob -> set_wc(zlevel+random(zlevel),"impact");
    ob -> set_hit_bonus(zlevel);
	ob->set_property("no decay",1);
    //ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield hammer in left hand");
    //new(OBJ+"misc/metal")->move(this_object());
      break;
case 1:ob = new("/d/damned/virtual/hammer_6.weapon");
ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ hammer");
    ob -> set("long",
"This weapon is extremely well made. The huge, blunt hammer is finely "
"balanced. Soft leather is wrapped around the pommel, making the hammer "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"crushing");
    ob -> set_wc(zlevel+random(zlevel),"impact");
    ob -> set_hit_bonus(zlevel);
	ob->set_property("no decay",1);
    //ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield hammer in right hand");
    ob = new("/d/damned/virtual/battle-axe_6.weapon");
ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ battle-axe");
    ob -> set("long",
"This weapon is extremely well made. The long, sharp blade is finely "
"balanced. Soft leather is wrapped around the pommel, making the axe "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"cutting");
    ob -> set_wc(zlevel+random(zlevel),"impaling");
    ob -> set_hit_bonus(zlevel);
	ob->set_property("no decay",1);
   // ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield axe in left hand");
      break;
case 2:ob = new("/d/damned/virtual/hand-axe_6.weapon");
ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ hand-axe");
    ob -> set("long",
"This weapon is extremely well made. The long, sharp blade is finely "
"balanced. Soft leather is wrapped around the pommel, making the axe "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"cutting");
    ob -> set_wc(zlevel+random(zlevel),"impaling");
    ob -> set_hit_bonus(zlevel);
	ob->set_property("no decay",1);
   // ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield axe in right hand");
        ob = new("/d/damned/virtual/hand-axe_6.weapon");
ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ hand-axe");
    ob -> set("long",
"This weapon is extremely well made. The long, sharp blade is finely "
"balanced. Soft leather is wrapped around the pommel, making the axe "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"cutting");
    ob -> set_wc(zlevel+random(zlevel),"impaling");
    ob -> set_hit_bonus(zlevel);
	ob->set_property("no decay",1);
    //ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield axe in left hand");
    //new(OBJ+"metal")->move(this_object());
    //new(OBJ+"metal")->move(this_object());
      move(this_object());
      break;
}
    money=new("std/obj/coins");
    money->set_money("gold",(random(10)+10));
    money->move(this_object());
}

void init()
{
    ::init();
    //add_action("no","north");
    //add_action("no","east");
    //add_action("no","west");
    //add_action("no","enter");
    //add_action("no","northeast");
    //add_action("no","northwest");
}

int no()
{
    if(archp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
else
    message("blocking",
      "The Slayer raises his weapon, blocking your path.\n",
      this_player());
    message("blocking",
      "The Slayer blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}
