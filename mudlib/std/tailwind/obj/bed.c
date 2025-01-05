// A bed. -TW 03/04/01
#include <move.h>
#include <daemons.h>

inherit "/std/Object";
inherit "/std/locker_logic";

int sitting=0;

void init() {
  ::init();
  add_action("lay_func", "lay");
  return;
}

void create() {
  ::create();
  set_property("no save", 1);
  set_id( ({ "bed" }) );
  set_name("bed");
  set_short("A bed");
  set_long("This is a twin bed. You can lay on it.");
  set_weight(1);
  set_value(0);
  return;
}


int lay_func(string str) {
    if(!str || str != "on bed") {
	return 0;
    }
if(this_player()->query_body_position() == "standing"){
    write("You jump on the bed and lie down.");
    say(this_player()->query_cap_name()+" sits on the bed and begins to rest.", this_player());
    this_player()->set_body_position("resting");
}
else{
    write("You're already off your feet.");
}
    return 1;
}


// int register_num() { return 1; }
string query_storage_key() { return "misc"; }

int query_is_locker() { return 1; }
string query_my_file() { return "bed"; }

int move(mixed dest) {
  if(query_property("no get") && objectp(dest) && living(dest))
    return MOVE_NOT_ALLOWED;
  return ::move(dest);
}

int restore_locker(string null) {
  return 1;
}

int is_furniture() {return 1;}
