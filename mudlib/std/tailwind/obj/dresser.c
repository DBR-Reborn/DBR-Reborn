// A dresser. -TW 03/04/01
#include <move.h>
#include <daemons.h>

inherit "/std/Object";
inherit "/std/locker_logic";

int sitting=0;

void init() {
  ::init();
  add_action("sit_func", "sit");
  return;
}

void create() {
  ::create();
  set_property("no save", 1);
  set_id( ({ "dresser" }) );
  set_name("dresser");
  set_short("A dresser");
  set_long("This is a dresser. You store clothing in it. Except that you don't wear clothing. Oh well.");
  set_weight(1);
  set_value(0);
  return;
}


int sit_func(string str) {
    if(!str || str != "on dresser") {
	return 0;
    }
    write("The dresser doesn't want to be sat upon. It must not like you.");
    return 1;
}


// int register_num() { return 1; }
string query_storage_key() { return "misc"; }

int query_is_locker() { return 1; }
string query_my_file() { return "dresser"; }

int move(mixed dest) {
  if(query_property("no get") && objectp(dest) && living(dest))
    return MOVE_NOT_ALLOWED;
  return ::move(dest);
}

int restore_locker(string null) {
  return 1;
}

int is_furniture() {return 1;}
