#include <move.h>
#include <daemons.h>

inherit OBJECT;
inherit "/std/locker_logic";

void create() {
::create();
  set_property("no save", 1);
set("id", ({ "forge", "glowing forge" }));
set("id", ({ "forge", "old forge" }));
  set_name("forge");
set_short("An old forge");
set_long("This is an extremely worn and old looking forge, heavily chained to the ground. It has an inscription on its front saying '%^RED%^The Shadowforge%^RESET%^'.");
  set_weight(999999999);
  set_value(100034);
  return;
}

int register_num() { return 2; }
string query_storage_key() { return "null"; }

int query_is_locker() { return 1; }
string query_my_file() { return "null"; }

int move(mixed dest) {
  
  if(query_property("no get") && objectp(dest) && living(dest))
    return MOVE_NOT_ALLOWED;
  return ::move(dest);
}


int restore_locker(string null) {
  set_property("no get", 1);
  return 1;
}

