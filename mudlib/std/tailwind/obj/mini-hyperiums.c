#include <std.h>
#include <daemons.h>
#include <security.h>
#include <objects.h>
 
inherit OBJECT;

int end_turn();

int end_func();

int start_func();

int playing, money, military, reputation, advantage, infilrate, planets, counter=1;

object player;

string name;

void create() {
  ::create();
    set_name("device");
    set_id( ({ "device", "mini-hyperiums", "mini-hyper", "hyperiums", "hyper" }) );
    set_short("The Mini-Hyperiums Device v2.1");
    set_long("This device is rigged up to play mini-Hyperiums. Type 'info' for help.");
    set_weight(1);
    set_value(1000);
}

void init() {
    ::init();
    add_action("info_func","info");
    add_action("build_func","build");
    add_action("trade_func","trade");
    add_action("attack_func","attack");
    add_action("infil_func","infiltrate");
    add_action("end_func","end");
    add_action("start_func","start");
}

int info_func() {
write("Welcome to Mini-Hyperiums! This game is a highly simplistic version of Hyperiums.\n\nCommands:\n----------\n'start': Begin the game\n'end': End the game\n'build': Build up your military\n'trade': Increase your economic resources\n'attack': Send your forces to take someone over\n'infiltrate': Attempt a stealthy infiltration");
return 1;
}

int end_turn() {


  if(planets>5 && random(3)==2) {
      write("You are attacked by another player! You fight to maintain your planets' security.");
      military-=planets*(random(3)+1);
  }

  if(military<0){
    write("You scream in frustration as your (now) non-existent fleet is unable to protect your planets. You lose.");
    end_func();
    return 1;
  }
  if(money<0){
    write("Your planets are so far in the red, financially, that you have no choice but to quit. You lose.");
    end_func();
    return 1;
  }
  if(planets<0){
    write("You curse loudly as you lose your last planets. You lose.");
    end_func();
    return 1;
  }

  write("Current Stats:\n Money: "+money+"\t\tFleet: "+military+"\nPlanets: "+planets+"\t\tInfiltration: "+infilrate*10+"%\nTurns: "+counter+"\t\tPlayer: "+name);
  counter++;
  money+=(planets*2)-(military/3);
  return 1;
}

int start_func() {
    if(playing){
      write("You're already playing. Please type 'info' for help.");
      return 1;
    }
  write("You begin your game of Mini-Hyperiums.");
  playing=1;
  planets=2;
  player=this_player();
  name=this_player()->query_cap_name();
  return 1;
}

int end_func() {
  if(!playing){
    write("You're not playing at the moment. Please type 'info' for help.");
    return 1;
  }
  write("You end your game of Mini-Hyperiums.");
  money=0;
  military=0;
  reputation=0;
  advantage=0;
  planets=0;
  playing=0;
  infilrate=0;
  counter=0;
  return 1;
}

int build_func() {
  if(!playing){
    write("You're not playing at the moment. Please type 'info' for help.");
    return 1;
  }

  if(money<=10){
    write("Insufficient funds for this action.");
    return 1;
  }

  write("You build up your forces.");

  switch(random(10)){
    case 0:
      write("You purchase some destroyers, cruisers, and scouts. Oh my!");
      military += 5;
      money-=5;
      break;
    case 1:
      write("You make a big purchase, but end off fighting a small attack.");
      military += 2;
      money -= 3;
      break;
    case 2:
      write("You grin at the idea of 5k scouts, but a somewhat serious attack turns their number closer to .5k scouts.");
      military += 1;
      money -= 2;
      break;
    case 3:
      write("You punch in a big order for cruisers.");
      military += 3;
      money -= 3;
      break;
    case 4:
      write("You order the amount of destroyers you want, but the server goes down before you can do the rest.");
      military += 4;
      money -= 4;
      break;
    case 5:
      write("You purchase a ton of anti-drop mines, in time for Bleys' fleet to come in and blow the hell out of most of them.");
      military += 2;
      money -= 3;
      break;
    case 6:
      write("You buy a large fleet, but end up sending most of it to help out one of the admins.");
      military += 3;
      money -= 6;
      break;
    case 7:
      write("You muster 300 armies, only to have the planet infiltrated. Most are on transports, though, so no big loss.");
      military += 4;
      money -= 5;
      break;
    case 8:
      write("You buy an even mix of armies, mines, and fleets.");
      military += 7;
      money -= 7;
      break;
    case 9:
      write("You get some more fleet, but end up wasting it all and more with an alliance war.");
      military -= 2;
      money -= 8;
      break;
  }
  end_turn();
  return 1;
}

int trade_func() {
  if(!playing){
    write("You're not playing at the moment. Please type 'info' for help.");
    return 1;
  }

  write("You decide to trade more with other players.");

  switch(random(10)){
    case 0:
      write("You up your production, but run out of money to trade more.");
      money+=1;
      break;
    case 1:
      write("You find yourself in a cash flow problem, and can only slightly increase trade.");
      money+=2;
      break;
    case 2:
      write("You lower your tax rate, but find it doesn't attract many more imports.");
      money+=1;
      break;
    case 3:
      write("Finally, one of your worthless alliance members sends you some imports.");
      money+=2;
      break;
    case 4:
      write("You try to raise production, but find the server down.");
      break;
    case 5:
      write("You gamble, and raise taxes a bit. No one notices.");
      money+=2;
      break;
    case 6:
      write("You use some spare cash, and raise production and trade moderately.");
      money+=3;
      break;
    case 7:
      write("Examining your current trade situation, you see that some of your planets should be trading with each other. You get a good amount of money for this.");
      money+=4;
      break;
    case 8:
      write("You spend a good amount of time planning a massive economic expansion, and contrary to all expectations, find it actually works!");
      money+=7;
      break;
    case 9:
      write("You hugely increase trade at one planet, but one of your new trading partners infiltrates it. You lose more money than you earned.");
      money-=2;
      planets-=1;
      break;
  }
  end_turn();
  return 1;
}

int attack_func() {
  if(!playing){
    write("You're not playing at the moment. Please type 'info' for help.");
    return 1;
  }

  if(military <10){
    write("You do not have sufficient forces for this action.");
    return 1;
  }

  write("You send off your ships of war to take another planet.");

  switch(random(10)){
    case 0:
      write("You end up attacking a Hyperiums planet. Needless to say, it doesn't work.");
      military-=4;
      break;
    case 1:
      write("Well, the scans didn't indicate the guy had any forces there... too bad his buddy did. You pulled back in time to save most of your guys.");
      military-=3;
      break;
    case 2:
      write("After a valiant fight, you take the planet! A moment later, you find that it is worthless. Stupid newbies.");
      military-=4;
      break;
    case 3:
      write("You send off your entire attack force, and take down the planet. Bombing casualties are high.");
      military-=5;
      planets+=1;
      break;
    case 4:
      write("You think you've found an easy mark, but the 500 drop mines tear apart your attack force on drop. You barely take the planet.");
      military-=6;
      planets+=1;
      break;
    case 5:
      write("The Fleet of Doom (tm) approaches a planet. Bleys' best friend owns it. Figure out what comes next.");
      military-=7;
      break;
    case 6:
      write("After a hard fight, the planet falls to your forces.");
      military-=8;
      planets+=1;
      break;
    case 7:
      write("You beat them down with only moderate resistance.");
      military-=4;
      planets+=1;
      break;
    case 8:
      write("You catch a planet undefended - lucky!");
      planets+=1;
      break;
    case 9:
      write("Your attack leads to intergalactic war. As you can imagine, you end up losing a bit.");
      military-=10;
      break;
  }

  end_turn();
  return 1;
}

int infil_func() {
  if(!playing){
    write("You're not playing at the moment. Please type 'info' for help.");
    return 1;
  }

  if(money<=3*planets){
    write("You need more money to infiltrate.");
    return 1;
  }

infilrate+=1;
  write("You start infiltrating one of your trade partners.");

if(infilrate%10==0){
  switch(random(4)){
    case 0:
      write("Your infiltration is caught!");
      money-=3*planets;
      break;
    case 1:
      write("You take a planet, but enter a small war to keep it.");
      military-=5;
      money-=3*planets;
      planets+=1;
      break;
    case 2:
      write("You make the planet captive, and eventually take it, but the owner drops all trade with you.");
      money-=2 + 3*planets;
      planets+=1;
      break;
    case 3:
      write("You successfully take the planet.");
      money-=3*planets;
      planets+=1;
      break;
  }
infilrate=0;
}
  end_turn();
  return 1;
}
