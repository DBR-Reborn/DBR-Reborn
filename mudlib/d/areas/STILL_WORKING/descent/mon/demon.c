#include <std.h>

inherit MONSTER;

int levelrange=random(10) + 40;

create() {
	::create();
	set_name("demon");
	set_id( ({"demon", "warrior", "lord", "seargent"}));
	set("race", "demon");
	set_level(levelrange);
	set_body_type("winged-humanoid");
  set_property("physical resistance",
               ([ "default" : 80, "raysorite" : -30, "holy" : "-50" ]));
switch(random(5)) {
case 0:
set_short("A demon warrior");
set_long("This demon is not so old by demon standards, probably only 500 years or so, you can tell. Still, he is a tough-looking bastard, with big sharp teeth, red skin, and claws that could probably rip you to bits. Seven feet of killing machine, to summarize.");
break;
case 1:
set_short("A demon warrior");
set_long("This demon is not so old by demon standards, probably only 500 years or so, you can tell. Still, he is a tough-looking bastard, with big sharp teeth, red skin, and claws that could probably rip you to bits. Seven feet of killing machine, to summarize.");
break;
case 2:
set_short("A demon warrior");
set_long("This demon is not so old by demon standards, probably only 500 years or so, you can tell. Still, he is a tough-looking bastard, with big sharp teeth, red skin, and claws that could probably rip you to bits. Seven feet of killing machine, to summarize.");
break;
case 3:
set_short("A demon seargent");
set_long("One of the more senior officers of the demon army, the demon seargent is quite gruff and tough. Every so often, he smacks one of his useless subordinates, cursing them for their failures. You know you don't want to mess with this guy, especially because he's seven feet tall and really strong-looking.");
break;
case 4:
set_short("A demon lord");
set_long("This particular demon looks very old and experienced. A necklace of human skulls rests from his neck, some obviously from children and babies. He shouts commands at his subordinates, but other than that, is somewhat quiet. He carries no weapon or armor, but his tough skin and razor claws will probably see him through the day, besides the fact that he is eight feet tall and buff as hell.");
}
set("aggressive", 1);
set_skill("parry", 275);
set_skill("dodge", 275);
set_skill("melee", 350);
set_skill("attack", 350);
set_property("melee damage", (["crushing" : 80]) );
}
