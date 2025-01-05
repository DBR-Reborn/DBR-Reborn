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
  write("'Is this thing on? Damned magic devices.' The figure pauses for a moment, and takes on more form.\n", environment(this_player()));
  call_out("do_telling3", 6);
  return 1;
}

int do_telling3() { 
  name=this_player()->query_cap_name();
  write("'I'll take the risk in assuming it is,' says the speaker, a tall, handsome warrior.  'I'm Captain Leon Ascon of the Shards Militia, and we have an enemy force coming upon us in about,' he looks up at the sky, 'About three hours.'\n", environment(this_player()));
  call_out("do_telling4", 6);
  return 1;
}

int do_telling4() { 
  name=this_player()->query_cap_name();
  write("'That fool, Uoloren, thought we should abandon the city.' He snorts. 'Trust a cowardly woman to think such a thing. I've received reports that the invaders are twenty feet tall, and have muscles of mithril - she must have, too, and believed them.' He bursts out laughing.\n", environment(this_player()));
  call_out("do_telling5", 6);
  return 1;
}

int do_telling5() { 
  name=this_player()->query_cap_name();
  write("'The crystals are on time lock to vanish, then appear 50 years after the recording. I imagine my successor will find it to be quite a surprise when a big crystal ball plops onto his desk from nowhere.' He smirks.\n", environment(this_player()));
  call_out("do_telling6", 6);
  return 1;
}

int do_telling6() { 
  name=this_player()->query_cap_name();
  write("'Paranoia, I tell you. Sheer paranoia. It's probably nothing more than a little goblin raid that the clans couldn't handle. Of course - did she think a bunch of overgrown warrior-wannabes could stand up to a determined band of goblins? NOT THOSE WIMPS!' he laughs heartily. 'Well, the crystal is finally running out of time, so I must leave you. Good luck!'\n", environment(this_player()));
  call_out("do_telling7", 4);
  return 1;
}

int do_telling7() { 
  name=this_player()->query_cap_name();
  write("The bragging captain disappears, and your hands fly off of the sphere. You guess he was a bit wrong in his predictions of the battle - and the foe he would face.\n", environment(this_player()));
readin = 0;
  return 1;
}
