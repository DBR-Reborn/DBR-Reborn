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
  write("'You have entered the Cathdedral of this town. Please refrain from excessive talking - our Lord Lidfino sits above us, watching.' The figure pauses for a moment, and takes on more form.\n", environment(this_player()));
  call_out("do_telling3", 6);
  return 1;
}

int do_telling3() { 
  name=this_player()->query_cap_name();
  write("He is an old man, dressed in the white of a member of the Order of Lidfino. 'My name is Augustus Yonatah, and I am the leader of the Order in this town.'\n", environment(this_player()));
  call_out("do_telling4", 6);
  return 1;
}

int do_telling4() { 
  name=this_player()->query_cap_name();
  write("'The fighting begun a couple hours ago. Unfortunately, we've not had a lot of work, as we only see corpses. Some have suggested resurrecting them, but the truth is, well, not just anyone can be raised from the dead.'\n", environment(this_player()));
  call_out("do_telling5", 6);
  return 1;
}

int do_telling5() { 
  name=this_player()->query_cap_name();
  write("'Only people who have begun the path to heroism, or have already stepped upon it, are responsive to soul gating, and that sort of thing.' He sighs. 'A shame. So many lives could have been saved already.'\n", environment(this_player()));
  call_out("do_telling6", 6);
  return 1;
}

int do_telling6() { 
  name=this_player()->query_cap_name();
  write("He peers at you closely for a moment. 'We're all going to die, you know that? Apparently, our Lord in heaven has decreed that the inhabitants of this poor town will just have to die a little sooner.'\n", environment(this_player()));
  call_out("do_telling7", 4);
  return 1;
}

int do_telling7() { 
  name=this_player()->query_cap_name();
  write("The cleric blinks out in a shimmer of light, and your hands fly off the sphere.\n", environment(this_player()));
readin = 0;
  return 1;
}
