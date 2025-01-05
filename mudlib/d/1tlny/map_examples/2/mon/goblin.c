#include "../a1.h"

inherit "/std/monster";
string mtlname;
string damage1;
string damage2;
string quality;
int zlevel;
   object ob;

void create() {
   ::create();

switch(random(14)){
      case 0:mtlname="iron";break;
      case 1:mtlname="steel";break;
      case 2:mtlname="boernerine";break;
      case 3:mtlname="mcgrail";break;
      case 4:mtlname="neorolite";break;
      case 5:mtlname="catoetine";break;
      case 6:mtlname="raysorite";break;
      case 7:mtlname="inniculmoid";break;
      case 8:mtlname="elrodnite";break;
      case 9:mtlname="mithril";break;
      case 10:mtlname="platnite";break;
      case 11:mtlname="mabril";break;
      case 12:mtlname="iysaughton";break;
      case 13:mtlname="laen";break;
    }
    switch(random(3)){
      case 0:damage1="crushing";break;
      case 1:damage1="cutting";break;
      case 2:damage1="impaling";break;      
      case 3:damage1="impact";break;
      case 4:damage1="stress";break;
      case 5:damage1="fire";break;
      case 6:damage1="cold";break;
      case 7:damage1="vacuum";break;
      case 8:damage1="electricity";break;
      case 9:damage1="disruption";break;
      case 10:damage1="plasma";break;

    }
    switch(random(3)){
      case 0:damage2="crushing";break;
      case 1:damage2="cutting";break;
      case 2:damage2="impaling";break;
      case 3:damage2="impact";break;
      case 4:damage2="stress";break;
      case 5:damage2="fire";break;
      case 6:damage2="cold";break;
      case 7:damage2="vacuum";break;
      case 8:damage2="electricity";break;
      case 9:damage2="disruption";break;
      case 10:damage2="plasma";break;

    }
switch(random(7)){
      case 0:quality="5";break;
      case 1:quality="6";break;
      case 2:quality="6";break;
      case 3:quality="6";break;
      case 4:quality="6";break;
      case 5:quality="6";break;
      case 6:quality="6";break;
      case 7:quality="6";break;
    }

   zlevel = (18+random(4));

   set_level(zlevel);

   set_overall_ac(zlevel*2);
   set_property("magic resistance", zlevel*3);
   set_skill("resist stun", zlevel+zlevel+zlevel);
   set_melee_damage(([ damage2: zlevel, damage1 : zlevel, "crushing" : zlevel ]));


    set_name("sinister goblin");
    set("id",({"sinister","goblin","sinister goblin"}));
    set_level(zlevel);
    set("aggressive",1);
    set("gang bang", 1);
    add_money("silver",random(20)+10);
    set("short","["+zlevel+"]Sinister Goblin");
    set("long","strong Goblin");
    set("race","monster");
    set_gender("neuter");
    add_limb("head","FATAL",185,0,5);
    add_limb("body","NON FATAL",185,0,5);
    add_limb("right arm","NON FATAL",185,0,5);
    add_limb("right hand","NON FATAL",185,0,5);
    add_limb("left arm","NON FATAL",185,0,5);
    add_limb("left hand","NON FATAL",185,0,5);
    add_limb("left leg","NON FATAL",185,0,5);
    add_limb("left foot","NON FATAL",185,0,5);
    add_limb("right leg","NON FATAL",185,0,5);
    add_limb("right foot","NON FATAL",185,0,5);
    add_wielding_limb("right hand");
  set_speed(100);
  set_moving(1);

/*    
    set_skill("axe", zlevel*11);
    set_skill("two handed blade", zlevel*11);
    set_skill("two handed blunt", zlevel*11);
    set_skill("two handed flail", zlevel*11);
    set_skill("two handed polearm", zlevel*11);
    set_skill("two handed staff", zlevel*11);
    set_skill("blade", zlevel*11);
    set_skill("blunt", zlevel*11);
    set_skill("knife", zlevel*11);
    set_skill("flail", zlevel*11);
*/

    //set_skill("shield bash", zlevel*8);
    set_skill("reverse stroke", zlevel*8);
    set_skill("combo", zlevel*8); //Whirlwind
    set_skill("block", zlevel*8);
    set_skill("parry", zlevel*8);
    set_skill("melee", zlevel*8);
    set_skill("attack", zlevel*8);
    set_skill("defense", zlevel*8);
    set_skill("dodge", zlevel*8);

}

