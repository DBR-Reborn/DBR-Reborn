inherit ROOM;

int query_under_water() { return 1; }

void create() {
   ::create();
   set("short", "Underwater");
   set("long", "You are totally submerged in water and no air pockets are within site.  "
       "The water is somewhat clear but your view is limited.  Various forms of "
       "aquatic life are abundant in the area.");
   set_smell("default", "You smell nothing while your nostrils are filled with water.");
   set_listen("default", "You hear nothing but gurgling and bubbling sounds.");

}
void init() {
   ::init();
   call_out("damage_living",5);
}

void damage_living() {
   object *living, *tmp;
   int i;

   tmp = all_inventory(this_object());
   living = filter_array(tmp, "test_living", this_object());
   if(!tmp || !sizeof(tmp)) return;
   for(i=0; i < sizeof(living); i++) {
      living[i]->add_hp(-1*(100+to_int(living[i]->query_internal_encumbrance()/
         10)));
      message("info","%^BOLD%^BLUE%^You are drowning!%^RESET%^",living[i]);
   }
   remove_call_out("damage_living");
   call_out("damage_living",5);
   return;
}

int test_living(object ob) {
  if(ob->is_player() && !ob->query_breath_holding() && 
    !ob->query("water breathing")) return 1;
  return 0;
}
