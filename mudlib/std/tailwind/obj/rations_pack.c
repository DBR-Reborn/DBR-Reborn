inherit "/std/Object";

int strength;

void create() {
  ::create();
  set_name("pack");
  set_id( ({ "pack", "rations pack", "rations" }) );
  set_short("A pack of rations");
  set_long("This is a cloth pack containing rations which can be used for sustenance on long journeys.  Before eating one, you must 'get' a ration from the pack.");
  set_weight(50);
  set_float_value(2.15);
  call_out("desc_fun", 1);
  return;
}

void desc_fun() {
set_short("A pack of "+query_property("rations left")+" rations");

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
  ob = new("/std/food");
  ob->set_name("rations");
  ob->set_id(({ "ration", "rations"}) );
  ob->set_short("A ration");
  ob->set_long("A ration for travels, which may be eaten");
  ob->set_my_mess("The rations are satisfying.");
  ob->set_your_mess("eats a ration.");
  strength=this_object()->query_property("food strength");
  ob->set_strength(strength);
  if(!ob->id(tmp1)) {
    ob->remove();
    write("There is no '"+str+"' in the pack.");
    return 1;
  }
  set_property("rations left", query_property("rations left")-1);
  write("You grab a ration from the pack. There are "+this_object()->query_property("rations left")+" rations left.");
  ob->move(this_player());
  if(this_object()->query_property("rations left") > 1)
    set_short("A pack of "+this_object()->query_property("rations left")+" rations");
  else if(this_object()->query_property("rations left") == 1)
    set_short("A pack with 1 ration");
  else {
    write("Having taken the last ration from the pack, you discard it.");
    remove();
  }
  set_float_value(query_float_value() - 0.35);
  return 1;
}
