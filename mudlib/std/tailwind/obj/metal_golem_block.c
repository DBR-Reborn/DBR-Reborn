inherit "/std/Object";

void create() {
  ::create();
  set_id( ({ "block", "metal golem block", "metal block", "golem block" }) );
  set_name("block");
  set_short("A metal golem block");
  set_long("This is a metal golem block. It's a large hunk of metal that Alchemists can make metal golem bodies from.");
  set_weight(5);
  return;
}


int id(string str) {
  if(::id(str)) return 1;
  if(::id(replace_string(str, query_property("material_name")+" ", "")))
return 1;
  return 0;
}


int query_value() {
  if(this_object()->prop("value")) return
(int)this_object()->prop("value");
  else return ::query_value();
}

float query_float_value() {
  if(this_object()->prop("value")) return
to_float((int)this_object()->prop("value"));
  else return ::query_float_value();
}

string query_short() {
  return capitalize(article(query_property("material_name") + " golem block"));
}
