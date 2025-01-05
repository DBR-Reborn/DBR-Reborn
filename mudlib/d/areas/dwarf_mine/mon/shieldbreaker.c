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
   set_short("["+zlevel+"]Shieldbreaker");
   set_overall_ac(zlevel+15);
    set("gang bang", 1);
    set_name("shieldbreaker");
    set_id( ({ "shieldbreaker","dwarf"}) );
    set("long", @ext The life of a Shieldbreaker is one of honour and blood, sacrifice, and duty to their clan. Each day when they rise, they recite the oaths of loyalty, a litany of the names of their ancestors and the glory of their clan, ending with a pledge to spill the blood of the clan’s enemies. They will then spend several hours servicing their armour and weapons, as is the Dwarf way, sharpening blades to razor-fine edges and polishing armour to a dull shine.
ext);
    set_gender("male");
    set("race", "dwarf");
    set_alignment(0);
    set_wielding_limbs( ({"right hand","left hand"}) );
    set_body_type("human");
    set_overall_ac(zlevel*2);
    set_skill("two handed polearm", zlevel*8);
    set_skill("blade", zlevel*8);
    set_skill("blunt", zlevel*8);
    set_skill("axe", zlevel*8);
    set_skill("block", zlevel*8);
    set_skill("parry", zlevel*8);
    set_skill("shield bash", zlevel*10);
 set_combat_chance(100);
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
   // ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield sword in right hand");
ob = new(OBJ+"dwarven_armour.c")->move(this_object());
ob = new(OBJ+"dwarven_helmet.c")->move(this_object());
ob = new(OBJ+"dwarven_boots.c")->move(this_object());
ob = new(OBJ+"dwarven_shield.c")->move(this_object());
ob = new(OBJ+"dwarven_greaves.c")->move(this_object());
ob = new(OBJ+"dwarven_bracer.c")->move(this_object());
ob = new(OBJ+"dwarven_bracer.c")->move(this_object());
ob = new(OBJ+"dwarven_glove.c")->move(this_object());
ob = new(OBJ+"dwarven_glove.c")->move(this_object());
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
    //ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield axe in right hand");
 ob = new(OBJ+"dwarven_armour.c")->move(this_object());
ob = new(OBJ+"dwarven_helmet.c")->move(this_object());
ob = new(OBJ+"dwarven_boots.c")->move(this_object());
ob = new(OBJ+"dwarven_shield.c")->move(this_object());
ob = new(OBJ+"dwarven_greaves.c")->move(this_object());
ob = new(OBJ+"dwarven_bracer.c")->move(this_object());
ob = new(OBJ+"dwarven_bracer.c")->move(this_object());
ob = new(OBJ+"dwarven_glove.c")->move(this_object());
ob = new(OBJ+"dwarven_glove.c")->move(this_object());
    command("equip");
      break;
case 2:ob = new("/d/damned/virtual/battle-axe_6.weapon");
ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ battle-axe");
    ob -> set("long",
"This weapon is extremely well made. The long, sharp blade is finely "
"balanced. Soft leather is wrapped around the pommel, making the axe "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"cutting");
    ob -> set_wc(zlevel+random(zlevel),"impaling");
    ob -> set_hit_bonus(zlevel);
    //ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield axe in right hand");
    ob = new(OBJ+"dwarven_armour.c")->move(this_object());
ob = new(OBJ+"dwarven_helmet.c")->move(this_object());
ob = new(OBJ+"dwarven_boots.c")->move(this_object());
ob = new(OBJ+"dwarven_shield.c")->move(this_object());
ob = new(OBJ+"dwarven_greaves.c")->move(this_object());
ob = new(OBJ+"dwarven_bracer.c")->move(this_object());
ob = new(OBJ+"dwarven_bracer.c")->move(this_object());
ob = new(OBJ+"dwarven_glove.c")->move(this_object());
ob = new(OBJ+"dwarven_glove.c")->move(this_object());
    command("equip");
      break;
case 3:ob = new("/d/damned/virtual/battle-axe_6.weapon");
ob -> set("short", "%^BOLD%^Dwarven%^RESET%^ battle-axe");
    ob -> set("long",
"This weapon is extremely well made. The long, sharp blade is finely "
"balanced. Soft leather is wrapped around the pommel, making the axe "
"a pleasure to wield.");
    ob -> set_material("metal/"+mtlname);
    ob -> set_wc(zlevel+random(zlevel),"cutting");
    ob -> set_wc(zlevel+random(zlevel),"impaling");
    ob -> set_hit_bonus(zlevel);
   // ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield axe in right hand");
    ob = new(OBJ+"dwarven_armour.c")->move(this_object());
ob = new(OBJ+"dwarven_helmet.c")->move(this_object());
ob = new(OBJ+"dwarven_boots.c")->move(this_object());
ob = new(OBJ+"dwarven_shield.c")->move(this_object());
ob = new(OBJ+"dwarven_greaves.c")->move(this_object());
ob = new(OBJ+"dwarven_bracer.c")->move(this_object());
ob = new(OBJ+"dwarven_bracer.c")->move(this_object());
ob = new(OBJ+"dwarven_glove.c")->move(this_object());
ob = new(OBJ+"dwarven_glove.c")->move(this_object());
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
    //ob -> set_parry_bonus(zlevel);
     ob -> move(this_object());
      force_me("wield hammer in right hand");
 ob = new(OBJ+"dwarven_armour.c")->move(this_object());
ob = new(OBJ+"dwarven_helmet.c")->move(this_object());
ob = new(OBJ+"dwarven_boots.c")->move(this_object());
ob = new(OBJ+"dwarven_shield.c")->move(this_object());
ob = new(OBJ+"dwarven_greaves.c")->move(this_object());
ob = new(OBJ+"dwarven_bracer.c")->move(this_object());
ob = new(OBJ+"dwarven_bracer.c")->move(this_object());
ob = new(OBJ+"dwarven_glove.c")->move(this_object());
ob = new(OBJ+"dwarven_glove.c")->move(this_object());
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
      "The Shieldbreaker raises his shield, blocking your path.\n",
      this_player());
    message("blocking",
      "The Shieldbreaker blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}

varargs void heart_beat(int flag) {
  if(query_current_attacker() && !random(4)) {
    force_me("use shield bash at "+(string)(query_current_attacker()->query_name()));

message("info", (string)this_player()->query_cap_name()+
			" %^B_RED%^uses shield bash%^RESET%^ at "+(string)(query_current_attacker()->query_name()), environment(this_player()),
			({ this_player() }) );

  }
  ::heart_beat(flag);
  return;
}
