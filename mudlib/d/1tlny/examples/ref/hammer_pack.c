inherit "/std/Object";

int picks_left;

void create() {
  ::create();
  set_name("hammers");
  set_id( ({ "hammers", "hammer pack", "pack" }) );
  set_short("A pack containing 5 hammers");
  picks_left = 5;
  set_long(
"This is a pack used for holding throwing axes.  It is small "
"enough to sling over one shoulder.  You can 'take' hammers from "
"it if you want to throw one or wield one.");
  set_weight(50);
  set_float_value(2.15);
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
  ob = new("/d/damned/virtual/hammer_3.weapon");
  if(!ob->id(tmp1)) {
    ob->remove();
    write("There is no '"+str+"' on the belt.");
    return 1;
  }
  picks_left--;
  write("Ok.");

  ob->move(this_player());
  if(picks_left > 1)
    set_short(sprintf("A belt of %d hammers", picks_left));
  else if(picks_left == 1)
    set_short("A belt with 1 hammer on it");
  else {
    write("Having taken the last hammer, you discard the pack.");
    remove();
  }
  set_float_value(query_float_value() - 0.35);
  return 1;
}
