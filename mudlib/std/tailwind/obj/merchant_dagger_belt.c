inherit "/std/Object";


void create() {
  ::create();
  set_name("belt");
  set_id( ({ "daggers", "dagger belt", "belt" }) );
  set_short("A belt of daggers");
set_long("This is a leather belt used for holding daggers.  You can "
"'take' one in order to wield or throw it. You cannot put more daggers into the belt.");
  set_weight(50);
  set_float_value(2.15);
  call_out("desc_fun", 1);
  return;
}

void desc_fun() {
set_short("A belt of "+query_property("daggers left")+" daggers");

return;
}

void init() {
  ::init();
  add_action("get_pick", "take");
  add_action("get_pick", "get");
  return;
}

int get_pick(string str) {
  string tmp1, tmp2;
  object ob;

  if(sscanf(str, "%s from %s", tmp1, tmp2) != 2) return 0;
  if(present(tmp2, this_player()) != this_object()) return 0;
  seteuid(getuid());
  ob = new("/d/damned/virtual/dagger_6.weapon");
  if(!ob->id(tmp1)) {
    ob->remove();
    write("There is no '"+str+"' on the belt.");
    return 1;
  }
  set_property("daggers left", query_property("daggers left")-1);
  write("You grab a dagger from the belt. There are "+this_object()->query_property("daggers left")+" daggers left.");
  ob->set_material(query_property("dagger material"));
  ob->move(this_player());
  if(this_object()->query_property("daggers left") > 1)
    set_short("A belt of "+this_object()->query_property("daggers left")+" daggers");
  else if(this_object()->query_property("daggers left") == 1)
    set_short("A belt with 1 dagger");
  else {
    write("Having taken the last dagger, you discard the belt.");
    remove();
  }
  set_float_value(query_float_value() - 0.35);
  return 1;
}
