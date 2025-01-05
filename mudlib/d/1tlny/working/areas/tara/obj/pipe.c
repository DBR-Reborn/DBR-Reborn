#include <std.h>

inherit OBJECT;
 
int lit, fuel, light_time;
object shadow;

void create() {
  ::create();
    set_name("pipe");
    set_id( ({ "pipe" }) );
    set_short("A pipe");
   set_long("A small wooden pipe, made to smoke tabacco by the "+
   "halflings of Tara.  It is finely crafted, and well formed "+
   "for easy use with smoking tabacco.  It can be refilled if "+
    "you have tabacco, lit, then smoked.");
    set_weight(50);
    set_float_value(200);
    fuel = 0;
    lit = 0;
    shadow = 0;
}
 
void init() {
    add_action("extinguish", "douse");
    add_action("light","light");
    add_action("extinguish","extinguish");
    add_action("refill","refill");
    add_action("smoke","smoke");
}
int refill(string str) {
    object fuelob;
    if (!str || present(str, this_player()) != this_object()) {
        notify_fail("Refuel what?\n");
    }
    if(lit) {
    return notify_fail("You cannot put more tabacco in while the pipe is lit.");
    }

    if (!(fuelob = present("tabacco", this_player()))) {
        notify_fail("Youre out of tabacco!.\n");
    }
    fuel = 2000;
    write ("You put some tabacco into the pipe.\n");
    say(this_player()->query_cap_name()+" puts some tabacco into his pipe.\n",
this_player());
    fuelob->remove();
    set_long("A small wooden pipe made by the halflings of "+
    "Tara.  It is currently filled with tabacco, and can be lit");
    return 1;
}

int light(string str) {
 if(!str || present(str, this_player()) != this_object()) {
        notify_fail("Light what?\n");
        return 0;
}
    if(!fuel) {
    notify_fail("It need's some tabacco.\n");
        return 0;
    }
    if(lit) {
        notify_fail("It is already lit!\n");
        return 0;
    }
    write("You light the pipe, smoke trails from the bowl.\n");
    seteuid(getuid());
    say(this_player()->query_cap_name()+" lights his pipe.\n",
this_player());
    set( "short", "A pipe. (lit)" );
    lit = 1;
    return 1;
}
 
int extinguish(string str) {
    if(!str || present(str, this_player()) != this_object()) {
        notify_fail("Extinguish what?\n");
        return 0;
    }
    if(!lit) {
        notify_fail("The pipe isn't lit!\n");
        return 0;
    }
    write("You put out the pipe.\n");
    say(this_player()->query_cap_name()+" puts out his pipe.\n",
        this_player());
        fuel -= (light_time - time());
    remove_call_out("go_dark");
    lit = 0;
    return 1;
}

int smoke( string str) {
    if(!str || present(str, this_player()) != this_object()) {
        return notify_fail("Smoke what?\n");
    }
    if(!lit) {
    return notify_fail("You cannot smoke the pipe while it is not lit.\n");
}
    write( "%^YELLOW%^You breath in the smoke from the pipe.%^RESET%^" );
    say(this_player()->query_cap_name()+" takes a puff on the pipe." );
    return 1;
}
       
         
void go_dark() {
    fuel = 0;
    if(living(environment(this_object())))
        tell_object(environment(this_object()), "Your finish off your tabacco.\n");
    set_long("The pipe has no tabacco.\n");
    set_destroy();
    set_value(10);
    lit = 0;
}
