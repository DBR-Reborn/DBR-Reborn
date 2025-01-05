// orc soldier

#include <std.h>
inherit MONSTER;

void create() {
   string var;
   ::create();
   set_name("half-orc soldier");
   set("id", ({"soldier", "half-orc"}) );
   set_level(14);
    switch(random(4)) {
            case 0: var = "An ugly orc soldier"; break;
            case 1: var = "A stinky orc soldier"; break;
            case 2: var = "An angry orc soldier"; break;
            case 3: var = "A fat orc soldier"; break;
    }
    this_object()->set("short", var);
   set("long",
   "You see a member of the half-orc army.  Just another generic "
   "stupid looking half-orc fairly well armed."
   );
   set("race", "half-orc");
   set_gender("male");
   set_body_type("human");
    switch(random(4)){
      case 0:new("/d/damned/virtual/war-hammer_3.weapon")->
                 move(this_object());
             force_me("wield hammer in right hand and left hand");
             break;
      case 1:new("/d/damned/virtual/long-sword_3.weapon")->
                 move(this_object());
             force_me("wield sword in right hand");
             break;
      case 2:new("/d/damned/virtual/halberd_3.weapon")->
                 move(this_object());
             force_me("wield halberd in right hand and left hand");
             break;
      case 3:new("/d/damned/virtual/morning-star_3.weapon")->
                 move(this_object());
             force_me("wield morning star in right hand");
             break;
    }
    switch(random(4)){
      case 0:new("/d/damned/virtual/leather-vest.armour")->
                 move(this_object());
             force_me("wear vest");
             new("/d/damned/virtual/leather-boots.armour")->
                 move(this_object());
             force_me("wear boots");
             break;
      case 1:new("/d/damned/virtual/breast-plate.armour")->
                 move(this_object());
             force_me("wear plate");
             new("/d/damned/virtual/gauntlet.armour")->
                 move(this_object());
             force_me("wear gauntlet");
             break;
      case 2:new("/d/damned/virtual/scale-mail.armour")->
                 move(this_object());
             force_me("wear scale mail");
             new("/d/damned/virtual/great-helm.armour")->
                 move(this_object());
             force_me("wear helm");
             break;
      case 3:new("/d/damned/virtual/leather-pants.armour")->
                 move(this_object());
             force_me("wear pants");
             new("/d/damned/virtual/leather-vest.armour")->
                 move(this_object());
             force_me("wear vest");
             break;
      }
//    money=new("std/obj/coins");
//    money->set_money("silver",(random(50)+50));
//    money->move(this_object());
    set_emotes(3, ({
        "The orc paces in circles.",
        "The orc burps.",
        "The orc yawns.",
      }),1);
}

