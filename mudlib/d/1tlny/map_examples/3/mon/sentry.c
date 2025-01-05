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
    zlevel = (25+random(5));
   set_level(zlevel);
   set_short("["+zlevel+"]Dwarven Sentry");
   set_overall_ac(zlevel+15);
    set("gang bang", 1);
    set_name("sentry");
    set_id( ({ "sentry","dwarf"}) );
    set("long", "This Sentry is watching over the quarry");
    set_gender("male");
    set("race", "dwarf");
    set_alignment(0);
    set_wielding_limbs( ({"right hand","left hand"}) );
    set_body_type("human");
    set_overall_ac(zlevel+random(zlevel));
    set_skill("two handed polearm", zlevel*8);
    set_skill("blade", zlevel*8);
    set_skill("blunt", zlevel*8);
    set_skill("axe", zlevel*8);
 switch(random(3)){
      case 0:mtlname="mithril";break;
      case 1:mtlname="elrodnite";break;
      case 2:mtlname="platnite";break;
    }
    switch(random(5)){
case 0:ob = new("/d/damned/virtual/broad-sword_6.weapon");
    ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ longsword");
    ob -> set("long",
"This weapon is extremely well made. The long, sharp blade is finely "
"balanced. Soft leather is wrapped around the pommel, making the sword "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"cutting");
    ob -> set_wc(zlevel+random(zlevel),"impaling");
    ob -> set_hit_bonus(zlevel);
    ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield sword in right hand");
ob = new(OBJ+"dwarven_armour.c")->move(this_object());
ob = new(OBJ+"dwarven_helmet.c")->move(this_object());
ob = new(OBJ+"dwarven_boots.c")->move(this_object());
    command("equip");
      break;
case 1:ob = new("/d/damned/virtual/battle-axe_6.weapon");
ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ battle-axe");
    ob -> set("long",
"This weapon is extremely well made. The long, sharp blade is finely "
"balanced. Soft leather is wrapped around the pommel, making the axe "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"cutting");
    ob -> set_wc(zlevel+random(zlevel),"impaling");
    ob -> set_hit_bonus(zlevel);
    ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield axe in right hand");
 ob = new(OBJ+"dwarven_armour.c")->move(this_object());
ob = new(OBJ+"dwarven_helmet.c")->move(this_object());
ob = new(OBJ+"dwarven_boots.c")->move(this_object());
    command("equip");
      break;
case 2:new(OBJ+"pick-axe.c")->move(this_object());
      force_me("wield pick in right hand and left hand");
    ob = new(OBJ+"dwarven_armour.c")->move(this_object());
ob = new(OBJ+"dwarven_helmet.c")->move(this_object());
ob = new(OBJ+"dwarven_boots.c")->move(this_object());
    command("equip");
      break;
case 3:new(OBJ+"pick.c")->move(this_object());
      force_me("wield pick in right hand and left hand");
    ob = new(OBJ+"dwarven_armour.c")->move(this_object());
ob = new(OBJ+"dwarven_helmet.c")->move(this_object());
ob = new(OBJ+"dwarven_boots.c")->move(this_object());
    command("equip");
      break;
case 4:ob = new("/d/damned/virtual/hammer_6.weapon");
ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ hammer");
    ob -> set("long",
"This weapon is extremely well made. The huge, blunt hammer is finely "
"balanced. Soft leather is wrapped around the pommel, making the hammer "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"crushing");
    ob -> set_wc(zlevel+random(zlevel),"impact");
    ob -> set_hit_bonus(zlevel);
    ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield hammer in right hand");
 ob = new(OBJ+"dwarven_armour.c")->move(this_object());
ob = new(OBJ+"dwarven_helmet.c")->move(this_object());
ob = new(OBJ+"dwarven_boots.c")->move(this_object());
    command("equip");
    break;
    }
    money=new("std/obj/coins");
    money->set_money("gold",(random(50)+20));
    money->move(this_object());
}

void init()
{
    ::init();
    add_action("no","north");
    //add_action("no","east");
    //add_action("no","west");
    add_action("no","enter");
    add_action("no","northeast");
    add_action("no","northwest");
}

int no()
{
    if(wizardp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
else
    message("blocking",
      "The Sentry raises his weapon, blocking your path.\n",
      this_player());
    message("blocking",
      "The Sentry blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}
