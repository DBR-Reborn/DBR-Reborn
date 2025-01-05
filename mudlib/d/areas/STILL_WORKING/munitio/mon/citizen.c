#include <std.h>

inherit MONSTER;

int levelrange=random(1)+10;
int urchin;

create() {
	::create();
	set_name("citizen");
	set("race", "human");
	set_level(levelrange);
	set_body_type("human");
switch(random(6)) {
case 0:
set_gender("male");
set_id( ({"citizen", "blacksmith"}));
set_short("An oppressed blacksmith");
set_long("This poor man is brutally oppressed by the guards and governor of this town. He now works making weaponry and armour for the highest bidder. Naturally, he sees very little of the profit.");
case 1:
  set_gender("female");
set_id( ({"citizen", "woman", "abusee"}));
set_short("An abused woman");
set_long("This young woman could have been beautiful if not for the large bruises and cuts on her face and body. Maybe a guard did this to her! Or maybe, it was her husband, tired of a long day of oppression, with no one else to take it out on.");
break;
case 2:
  set_gender("male");
set_id( ({"citizen", "child", "starvee"}));
set_short("A starving child");
set_long("This little kid hasn't had food for a whole day. You would offer him some, but he probably doesn't take food from strangers. You feel really guilty, and look at your full belly with some remorse.");
break;
case 3:
  set_gender("female");
set_id( ({"citizen", "child", "starvee"}));
set_short("A starving child");
set_long("This little kid hasn't had food for a whole day. You would offer him some, but he probably doesn't take food from strangers. You feel really guilty, and look at your full belly with some remorse.");
break;
case 4:
  set_gender("female");
set_id( ({"citizen", "woman", "old woman", "hag", "old hag"}));
set_short("An old woman");
set_long("This old woman has no family or friends, they having been killed by the evil guards and governor of Munitio. What animals!");
break;
case 5:
  set_gender("male");
set_id( ({"citizen", "urchin", "kid", "poor kid", "little kid"}));
     set("short", "A poor little kid");
     set("long", "The kid is clothed in rags and staring greedily at your wallet. You wonder if the people here have been driven to theft as a means to live.");
     set_skill("pick pocket",50);
urchin=1;
break;
}
set("aggressive", 0);
}

void catch_tell(string str) {
  string a,b;
  object ob1;
  object ob2;
    if(urchin==1){
    if(sscanf(str, "%s enters.",a) ==1){
    a = lower_case(a);
    ob1 = present(a, environment(this_object()));
      force_me("use pick pocket at "+a);
  }
}
  
  return;
}
