#include <std.h>

inherit MONSTER;

create() {
  ::create();
    set_name("guard");
    set_id( ({"guard", "drow"}));
     set_short("Drow City Guard");
     set("race", "undead");
    set_long(
"This wraith stands in front of the east exit.  It is a horrible creature which is black in color, and vaguely man-shaped.");

    set_body_type("human");
    set_level(18);
    set_skill("melee", 60);
    set_skill("dodge", 70);
    set_skill("parry", 80);
    set_exp(1000000);
    set_overall_ac(40);
	set("aggressive", (: call_other, this_object(), "race_check" :) );
    set_skill("block", 75);
    set_stats("strength", 300);
    set_max_hp(1200);
    set_hp(1200);
    set_property("handedness", "right hand");
    new("/d/damned/virtual/long-sword_5.weapon")->
      move(this_object());
    new("/d/damned/virtual/large-shield.armour")->
      move(this_object());
    new("/d/damned/virtual/chain-vest.armour")->
      move(this_object());
    new("/d/damned/virtual/iron-greaves.armour")->
      move(this_object());
    new("/d/damned/virtual/iron-bracer.armour")->
      move(this_object());
    new("/d/damned/virtual/iron-bracer.armour")->
      move(this_object());
    force_me("wear vest");
    force_me("wield sword in right hand");
    force_me("wear shield on left hand");
    force_me("wear greaves");
    force_me("wear bracer 2 on right arm");
    force_me("wear bracer on left arm");
}

int sign_filter(object item){
  if(item->id("merchant insignia")) return 1;
}

int race_check() {
  int gld;
  string p_name;
  object join_room, *inv;

  inv = filter_array(all_inventory(this_player()), "sign_filter",
        this_object());
  if(sizeof(inv)) {
	force_me("kill "+(string)this_player()->query_cap_name());
  return 0;
}

if((string)this_player()->query_race() !="drow"){
	write("The drow guard says in Broken Common: Only drow may enter the city.");
return 1;
}
}
