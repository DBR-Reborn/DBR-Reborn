//    An inheritable object that must be inherited by ALL rooms which wish to save locker objects past
//    reboots.  Handles all functions concerning cloning the lockers and putting them in.
//    DarkeLIB 0.1
//    -Diewarzau 7/29/95

#include "/adm/include/std.h"
#include "/adm/include/daemons.h"
#include "/adm/include/security.h"

inherit "/std/save_room.c";

static int load_status;
void load_lockers();
void create() {
  mapping lockers;
  string *l_keys;
  int i;
  object ob;

  ::create();
  set_property("storage room", 1);
  if(!load_status) 
    delayed_call("load_lockers", 2);

  return;
}

void load_lockers() {
  if(load_status) return;
  load_status = 1;
  SAVE_ITEMS_D->load_lockers(this_object());
  load_status = 2;
  return;
}

int query_is_locker_room() { return 1; }

void update_me() {
  SAVE_ITEMS_D->update_lockers(this_object());
  return;
}

void init() {
  ::init();

  if(!load_status) 
    load_lockers();

  return;
}
