inherit "/std/Object";

int power;

void create() {
  ::create();
  set_id( ({ "oil", "alch oil" }) );
  set_name("oil");
  set_short("A pouch of oil");
  set_long("This is a pouch of oil. The oil was made from some organ of some sort, and the pouch from the skin of that organ.");
  set_weight(5);
  set_value(100);
  return;
}

void init() {
   ::init();
   add_action("apply_func", "apply");
}

int is_oil() { return 1; }

int apply_func(string str) {
   object ob;
  string tmp;

  if(sscanf(str, "%s", tmp) != 1)
    return 0;
  if(present(tmp, this_player()) != this_object())
    return 0;
 
  if((!str) || ((str != "oil") && (str != "oil pouch") && (str != "pouch"))) {
      notify_fail("Apply what?\n");
      return 1;
   }
 
   if(this_player()->query_current_attacker()) {
      write("You cannot do that while in combat!");
      return 1;
   }
  if(this_player()->query_stack("ac_potion") > 2){
        message("info",
                "The oil will have no further effects on you."
                ,this_player());
        return 1;

  }
  message("info", "You apply the oil, and feel more protected."
        ,this_player());


  ob = new("/std/spells/shadows/ac_shadow");

   ob->set_shadow_name("Oil of Protection");
  ob->set_stack_key("ac_potion");
  ob->set_shad_ac(power*3);
  ob->set_expire_message("The oil's effects fade.");
  ob->start_shadow(this_player(), 500 + 2*random(power*10));

  remove();
  return 1;
}

void set_power(int x){power=x;}
int query_oil_power() { return power; }
