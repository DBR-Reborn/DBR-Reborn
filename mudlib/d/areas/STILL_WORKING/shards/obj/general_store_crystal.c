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
  write("'My message must be quick, as the invaders are approaching quickly.' The figure pauses for a moment, and takes on more form.\n", environment(this_player()));
  call_out("do_telling3", 6);
  return 1;
}

int do_telling3() { 
  name=this_player()->query_cap_name();
  write("'My name is Blackwind Raddix,' says the man. 'I am proprietor of this general store.' He gestures around him. 'As you can see, we are quite empty now.'\n", environment(this_player()));
  call_out("do_telling4", 6);
  return 1;
}

int do_telling4() { 
  name=this_player()->query_cap_name();
  write("'Pretty much all the supplies are being used by the defenders of this town, the Militia. Some men are preparing their boats, so perhaps we can get help from overseas.'\n", environment(this_player()));
  call_out("do_telling5", 6);
  return 1;
}

int do_telling5() { 
  name=this_player()->query_cap_name();
  write("'I've heard tales of an Empire, and a Kingdom in a far-off land. Even if, by some miracle, they do get word of our plight, it will be long after anyone can help us.'\n", environment(this_player()));
  call_out("do_telling6", 6);
  return 1;
}

int do_telling6() { 
  name=this_player()->query_cap_name();
  write("'The Arch-Mages are preparing to open a series of magic gates to this alleged continent. They are timed to go off 20 years after today, so perhaps someone can see what has happened here, and take steps to prevent it from occurring again.'\n", environment(this_player()));
  call_out("do_telling7", 4);
  return 1;
}

int do_telling7() { 
  name=this_player()->query_cap_name();
  write("The storekeeper fades away. Your hands are repulsed from the sphere.\n", environment(this_player()));
readin = 0;
  return 1;
}
