inherit "/std/Object";





void create() {
  ::create();
  set_weight(2);
  set_value(10);
  //set_id(({ "key", id, "temporary key", temp  }) );
  set_long("This is a temporary key made of a soft metal.");
  set_name("key");
  return;
}


void set_key_id(string id, string desc, object ob) {

//id = tmp;
  //set_name(query_property("new ids"));
  //ob->set_name("key");
  set_id(({ "key", id, "temporary key", }) );

//set_key_id(query_property("new ids"));
    //set_key_id((string)ob->query_property("new ids"));
  set_property("uses", 0);
  return;
}

void init() {
  ::init();
  add_action("pre_func", "unlock");
  return;
}


int pre_func(string str) {
  int uses;
  string what, key;
  object ob;

  uses = query_property("uses");
  if(sscanf(str, "%s with %s", what, key) != 2) return 0;
  if(present(key, this_player()) != this_object()) return 0;
  ob = present(what, environment(this_player()));
  if(ob && !this_object()->id((string)ob->query_key())) return 0;
  else if(!ob && !this_object()->id((string)environment(this_player())->
				    query_key(what))) return 0;
  uses++;
  if(uses > 20 && random(100) < uses*3) {
    write("Your temporary key breaks!");
    remove();
    return 1;
  }
  set_property("uses", uses);
  return 0;
}

    
