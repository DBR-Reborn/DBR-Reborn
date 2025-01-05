#include <std.h>

inherit MONSTER;

int levelrange=random(5)+10;

create() {
	::create();
	set_name("aristocracy");
	set("race", "human");
	set_level(levelrange);
	set_body_type("human");
switch(random(5)) {
case 0:
  set_gender("male");
set_id( ({"citizen", "noble"}));
set_short("An oppressive noble");
set_long("This rich nobleman is brutally oppressing the blacksmiths and their families with the guards of this town. He works them to make weaponry and armour for the highest bidder. Naturally, he sees most of the profit, and the smiths see none.");
case 1:
  set_gender("female");
set_id( ({"citizen", "woman", "bitch"}));
set_short("A haughty noblewoman");
set_long("This fancily dressed noblewoman may look sexy, but you can tell from the look in her eyes that she is a first-grade bitch. She doesn't like you much, either.");
break;
case 2:
  set_gender("male");
set_id( ({"citizen", "child", "brat"}));
set_short("A pompous child of the aristocracy");
set_long("This well-dressed boy runs around making noise. Some guards try to shush him, but he silences them with threats like, 'That his father will fire them.' This little punk is a real brat.");
break;
case 3:
  set_gender("female");
set_id( ({"citizen", "child", "devil"}));
set_short("A devilish little girl");
set_long("This little girl wears beautiful robes of the finest make, but acts like a devil. She kicks guards in the shins, screams, and generally makes a nuisance of herself.");
break;
case 4:
  set_gender("female");
set_id( ({"citizen", "woman", "old matron", "matron"}));
set_short("An old matron");
set_long("This old matron is the head of one of the ruling families here. She rules with an iron-hand, and has ordered many an innocent blacksmith to his death. You hate her.");
break;
}
set("aggressive", 0);
}
