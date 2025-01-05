#include <std.h>

inherit OBJECT;

int readin;
string name;
 
void init() {
    ::init();
    add_action("do_feel","feel");
}
 
void create() {
  ::create();
    set_name("crystal");
    set_id( ({ "crystal", "sphere", "crystal sphere" }) );
    set_short("a crystal sphere");
    set_long("At first glance, this appears to be a standard, run of the mill crystal sphere. But as you look more closely, you see colors swirling from within the ball. In fact, you can sense the sheer power locked up within this ball. Perhaps you should 'feel' it?");
    set_weight(999999);
    set_value(0);
}
 
int do_feel(string str) {
  name=this_player()->query_cap_name();
if(!str) { 
 notify_fail("Feel what? Perhaps you mean the crystal sphere?\n");
	return 0;
}
   if(str=="crystal" || "sphere" || "crystal sphere") {
     if(readin==0) {
       readin=1;
       write("You put your hands on the crystal sphere, and amazingly, a ghostly figure explodes in a burst of light next to it.\n", environment(this_player())); 
       call_out("do_telling", 2);
       return 1;
     }
     else {
       write("You are already feeling the sphere.\n");
       return 1;
     }
   }
}
 
int do_telling() {
  name=this_player()->query_cap_name();
  write("The figure begins to speak.\n", environment(this_player()));
  call_out("do_telling2", 2);
  return 1;
}

int do_telling2() { 
  name=this_player()->query_cap_name();
  write("'This is only a minor diocese of The Mace of the Lord. I'm not quite sure why Florence gave me this crystal.' The figure pauses for a moment, and takes on more form.\n", environment(this_player()));
  call_out("do_telling3", 6);
  return 1;
}

int do_telling3() { 
  name=this_player()->query_cap_name();
  write("'As we speak, my men - oh, my name is Edmond Warbringer, by the way - are preparing to fight for Taul on the streets of our beloved city. They will bring much honor to his name, I'm sure,' says the young man.\n", environment(this_player()));
  call_out("do_telling4", 6);
  return 1;
}

int do_telling4() { 
  name=this_player()->query_cap_name();
  write("'The invaders are but a day off, but the men were ready to fight them a month ago, I think. Taul will protect us, and help us win!'\n", environment(this_player()));
  call_out("do_telling5", 6);
  return 1;
}

int do_telling5() { 
  name=this_player()->query_cap_name();
  write("'Most of the civilians have already been evacuated. That coward mayor wanted us _all_ to retreat, but the Militia decided that they might have a fighting chance from a defensive position. With our help, they'll win the battle for sure.'\n", environment(this_player()));
  call_out("do_telling6", 6);
  return 1;
}

int do_telling6() { 
  name=this_player()->query_cap_name();
  write("'We have a secret weapon upon our side. Augustus, the misguided Lidfino lover, has told me that holy weapons will do much damage against the foe. We have already prepared our weapons as such.'\n", environment(this_player()));
  call_out("do_telling7", 4);
  return 1;
}

int do_telling7() { 
  name=this_player()->query_cap_name();
  write("'I am sure I will not need this crystal, but I need to get that woman off my back, so it is now done.' The Mace smiles, and vanishes. A wave of force repels your hands off the sphere.\n", environment(this_player()));
readin = 0;
  return 1;
}
