//    A SHEET of leather.

inherit "/std/Object";

void create() {
  ::create();
  set_id( ({ "leather", "sheet", "skin", "sheet of leather" }) );
  set_name("leather");
  set_short("A sheet of leather");
  set_long(
  "This is the tanned hide of an animal or creature, which may be crafted into "
  "armour.");
  set_weight(35);
  set_value(10);

set_material("leather/normal");
  return;
}

int id(string str) {
  if(::id(str)) return 1;
  if(::id(replace_string(str, query_property("material_name")+" ", ""))) return 1;
  return 0;
}

int query_value() {
  if(this_object()->prop("value")) return (int)this_object()->prop("value");
  else return ::query_value();
}

float query_float_value() {
  if(this_object()->prop("value")) return to_float((int)this_object()->prop("value"));
  else return ::query_float_value();
}

string query_short() {
  return capitalize(article(query_property("new desc") + " leather"));
}

