#include <std.h>
#include <daemons.h>
#include <security.h>
#include <objects.h>
 
inherit OBJECT;

string name;

int do_activate(string);

void create() {
  ::create();
    set_name("device");
    set_id( ({ "device", "death gamble", "death gamble device" }) );
    set_short("The Death Gamble Device");
    set_long("This ancient device was made a very long time ago by a bored Wizard Lord. By 'activate'ing it, you can play a random game of chance. You have a five in six chance of living, and a one in six chance of dying. Best used with a friend in gambling scenarios.");
    set_weight(1);
    set_value(1000);
}

void init() {
    ::init();
    add_action("do_activate","activate");
}

int do_activate(string str) {
   if(str=="death gamble" || "device" || "death gamble device") {
       write("DEBUG TEST.",environment(this_player()));
name=this_player()->query_cap_name();
switch(random(6)) {
case 0:
say(name+" activates the Death Gamble Device, and exhales as nothing happens.\n", environment(this_player()));
       write("You activate the Death Gamble Device, and exhale as nothing happens.\n",
environment(this_player())); 
    break;

case 1:
say(name+" activates the Death Gamble Device. Nothing happens.\n", environment(this_player()));
write("You activate the Death Gamble Device. Nothing happens.\n", environment(this_player())); 
    break;

case 2:
say(name+" activates the Death Gamble Device. He grins, as his life remains intact.\n", environment(this_player()));
       write("You activate the Death Gamble Device. You grin as your life remains intact.\n",
environment(this_player())); 
    break;

case 3:
say(name+" activates the Death Gamble Device. Suddenly... nothing happens!\n", environment(this_player()));
       write("You activate the Death Gamble Device. Suddenly... nothing happens!.\n",
environment(this_player())); 
    break;

case 4:
say(name+" activates the Death Gamble Device. Luck is with " +name+ ", and he lives.\n", environment(this_player()));
       write("You activate the Death Gamble Device. Luck is with you, and you live.\n",
environment(this_player())); 
    break;

case 5:
say(name+" activates the Death Gamble Device. Suddenly, he explodes!\n", environment(this_player()));
       write("You activate the Death Gamble Device. Suddenly, you explode! YOU LOSE SUCKER!.\n",
environment(this_player())); 
this_player()->add_hp(-99999);
    break;
}
}
}
