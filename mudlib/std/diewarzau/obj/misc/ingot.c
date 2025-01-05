//    An ingot!  You mine them and stuff!

inherit "/std/Object";

int metal;

void add_metal(int i);
void set_metal(int i);
int query_metal();
string query_metal_amount();

void create() {
  ::create();
  set_name("ingot");
  set_id(({ "ingot" }));
  set_long("This ingot can be melted into a weapon blank, or sold for "
  "money.");
  set_short("A ingot");
  set_value(50);
  set_weight(20);
   set_material("metal/iron");
  //set_metal(5);
  return;
}

/*
void check_remove() {
	if(metal <= 0) remove();
}

void set_metal(int i) {
	metal = i;
	if (metal) {
		set_value(metal*10);
		set_weight(metal*4);
	}
	else {
		set_value(0);
		set_weight(1);
	}
	check_remove();
}

void add_metal(int i) {
	metal += i;
	if (metal) {
		set_value(metal*10);
		set_weight(metal*4);
	}
	else {
		set_value(0);
		set_weight(1);
	}
	check_remove();
}

int query_metal() {
	return metal;
}

string query_metal_amount() {
	if (query_metal() <= 0) {
		return "no metal left";
	}
	if (query_metal() == 1) {
		return "pebble size";
	}
	if (query_metal() == 2) {
		return "hand size";
	}
	if (query_metal() == 3) {
		return "small ingot";
	}
	if (query_metal() == 4) {
		return "medium ingot";
	}
	if (query_metal() == 5) {
		return "large ingot";
	}
	if (query_metal() == 6) {
		return "large ingott";
	}
	if (query_metal() > 6) {
		return "large ingot";
	}
}
*/
string query_short() {
	return ::query_short()+" of "+(query_property("material_name"))+" ["+query_weight()+"]";
}


int id(string str) {
  if(::id(str)) return 1;
  if(::id(replace_string(str, query_property("material_name")+" ", ""))) return 1;
  return 0;
}

/*
int query_value() {
  if(this_object()->prop("value")) return (int)this_object()->prop("value");
  else return ::query_value();
}

float query_float_value() {
  if(this_object()->prop("value")) return to_float((int)this_object()->prop("value"));
  else return ::query_float_value();
}
*/
//string query_short() {
 // return capitalize(article(query_property("material_name") + " ingot"));
//}


