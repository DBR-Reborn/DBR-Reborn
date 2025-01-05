#include <std.h>

inherit MONSTER;


   object ob;

create() {
  ::create();
    set_name("newbie");
    set_id( ({ "newbie", "clown" }) );
    set_short("[1]newbie clown");
    set_long("A newbie stands here like a silly clown in his colourful armour");
    set_level(1);
   set_body_type("human");
   set("race", "human");
   set_gender("male");
   set_alignment(-100);
    set_max_hp(50);
    set_hp(50);
    set_skill("melee", 0);
    set_skill("dodge", 0);
   set_skill("parry", 0);
   set_skill("attack", 0);
    set_stats("strength", 4);
    set_stats("dexterity", -500);
    set_stats("constitution", -200);
    new("d/1tlny/loot/newbie_robe.c")->
      move(this_object());
command("equip");
    
add_money("silver", 100 + random(100));
}


