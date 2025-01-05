//    Bag of holding.

inherit "/std/bag_logic";

int lock_container(string null) { return 0; }

int unlock_container(string null) { return 0; }

void create() {
  ::create();
  set_name("bag");
  set_id(({ "bag", "bag of holding", "large bag of holding", "large bag" }));
  set_short("a large bag of holding");
   set("long",@ext This bag of holding may be used to store items, adding no weight to you.

Anything in this bag will not be saved when you quit. It will drop on the ground please make sure that you take all contents out of the bag before you log out or everything in this bag will be droped on the ground and lost forever if not claimed from the bag when you leave
ext);
  set_weight(100);
  set_max_internal_encumbrance(3000);
  set_value(56000);
  set_property("no steal", 1);
  return;
}

/*
mixed query_property(string str) {
  if(str != "no save") return ::query_property(str);
  if(all_inventory(this_object()) &&
    sizeof(all_inventory(this_object()))) return 1;
  return 0;
}
*/
