/*
   Poison Lore skill.  Enables the player to make poisons from the
   various flora of DarkeMud.
   -Duridian 5/22/96
 
   For an object to be a poison ingredient, it must inherit the
   file /wizards/duridian/poison/poisonous_plant.c

   Modified by Tailwind for the Alchemist Guild
   -Tailwind 6/22/99
*/
 
#include <clock.h>
#define PATH "/std/tailwind/potion/plants/"
 
inherit "/std/skills/skill.c";
 
void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(65);
    set_fast_dev_cost(87);
    set_property("no target", 1);


}
 
void info() {
message("help",
"The resins of the various grasses and plants found in the plains "
"can be used to create various potent potions and chemicals.  Use "
"of this skill enables the player to make potions ingested to induce "
"healing effects.  The maker of potions will need a plant press to extract "
"the resins and vials in which to store the helpful substances.  The "
"potency of potions varies with the kind of plants used to create them "
"and with the skill of the maker.  As it is hard on the eyes to search "
"for plants in the plains, the player must rest a while between "
"subsequent searches.",
this_player());
}
 
void skill_func(object from, object at, string arg) {
   object ob;
   int plant_number = 0;
 

   if(!environment(from)->query_terrain() || capitalize((string)
      environment(from)->query_terrain()) != "P") {
         message("info", "You have to be in the plains to use this skill.",
                                                                   from);
         return;
      }
  if((time() - (int)from->query_last_use("potion lore")) / MINUTE < 10) {
      message("info", "You must wait a little longer before using this
skill again.",
              from);
      return;
   }
 
   from->set_last_use("potion lore");
   seteuid(geteuid(this_object()));
 
   plant_number = random((int)this_player()->query_skill("potion lore")) +
                        ((int)from->query_stats("intelligence") - 20)/10 +
                        (((int)from->query_skill("perception") - 20)/10) -
                        10 + random(21);
 

   if (plant_number <= 0) {
      message("info", "You find no useful plants.", from);
      return;
   }
 
   switch(plant_number) {
      case 1..5: ob = new(PATH+"balsam_weeds"); break;
      case 6..10: ob = new(PATH+"biltecha_mushrooms"); break;
      case 11..15: ob = new(PATH+"black_grass"); break;
      case 16..20: ob = new(PATH+"blue_grass"); break;
      case 21..25: ob = new(PATH+"carshina_twigs"); break;
      case 26..30: ob = new(PATH+"cassia_ash"); break;
      case 31..35: ob = new(PATH+"cinnamon_sticks"); break;
      case 36..40: ob = new(PATH+"frankincense_petals"); break;
      case 41..45: ob = new(PATH+"galbanum_vine"); break;
      case 46..50: ob = new(PATH+"kaveh_blossoms"); break;
      case 51..55: ob = new(PATH+"kilufah_leaves"); break;
      case 56..60: ob = new(PATH+"ktores_sprouts"); break;
      case 61..65: ob = new(PATH+"myrh_seeds"); break;
      case 66..70: ob = new(PATH+"notef_buds"); break;
      case 71..75: ob = new(PATH+"nymph_kisses"); break;
      case 76..80: ob = new(PATH+"onycha_root"); break;
      case 81..85: ob = new(PATH+"pine_combs"); break;
      case 86..90: ob = new(PATH+"saffron_blossoms"); break;
      case 91..95: ob = new(PATH+"stacte_leaves"); break;
      case 96..1000000: ob = new(PATH+"tzari_leaves"); break;
      default: write("Potion Lore BUG!  Mail Tailwind immediately!");
return; break;
   }
 
   message("info", "You search the ground for a moment and find " +
                   ob->query_short() + ", which you pick up.", from);
   message("info", capitalize((string)from->query_name()) +
           " searches the ground and picks up " + ob->query_short() + ".",
            all_inventory(environment(from)), ({ from }));
 
   if(objectp(ob))
      ob->move(from);
   remove();
   return;
}
