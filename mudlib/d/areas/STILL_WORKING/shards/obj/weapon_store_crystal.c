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
  write("'My father showed me how to use this crystal, to record a message for people who may come later.' The figure pauses for a moment, and takes on more form.\n", environment(this_player()));
  call_out("do_telling3", 6);
  return 1;
}

int do_telling3() { 
  name=this_player()->query_cap_name();
  write("The speaker is but a little girl, barely 16!\n", environment(this_player()));
  call_out("do_telling4", 6);
  return 1;
}

int do_telling4() { 
  name=this_player()->query_cap_name();
  write("'You were probably expecting my father, right? I'm sorry to tell you this, but he's dead. He was killed in the fighting two blocks away.'\n", environment(this_player()));
  call_out("do_telling5", 6);
  return 1;
}

int do_telling5() { 
  name=this_player()->query_cap_name();
  write("'In a manner of minutes, I, too, will join him and my mother.' She pulls out a wicked looking knife. 'In his last breaths, he commanded me to tell the sphere that the foes show remarkable vulnerability to holy attacks. I suppose if you can find weaponry that has been blessed by a member of the Order of Lidfino, you'll be in good shape.'\n", environment(this_player()));
  call_out("do_telling6", 6);
  return 1;
}

int do_telling6() { 
  name=this_player()->query_cap_name();
  write("She takes the knife, and holds it high above her head, in two hands. 'They will not take me alive, to be their slave.' Suddenly, she plunges it downward!\n", environment(this_player()));
  call_out("do_telling7", 4);
  return 1;
}

int do_telling7() { 
  name=this_player()->query_cap_name();
  write("Blessedly, the figure winks out, before you see the terrible suicide of this brave young woman. Your hands find their way off the crystal.\n", environment(this_player()));
readin = 0;
  return 1;
}
