/*
   Plant press.  Necessary to make poisons with the poison lore skill.
   by Duridian 4/1/96

   Altered by Tailwind for the Alchemist Guild
   by Tailwind 6/22/99
*/
 
 
#include <std.h>
 
inherit "/std/Object";
 
void create() {
   ::create();
   set_name("pestle");
   set_id( ({ "mortar", "pestle", "mortar and pestle" }) );
   set_short("a mortar and pestle");
   set_long("The mortar and pestle can be used to grind out herbs " +
      "for their chemical properties.  Use 'grind <what> into <container>' " +
      "where <what> is what you wish to press and <container> is"
      "what you wish to press it into - u.");
    set_weight(30);
    set_value(100);
    return;
}
 
void init() {
  ::init();
    add_action("grind", "grind");
    return;
}
 
int grind(string str) {
   string what, what2, color;
   object plant, vial, new_vial, tp;
   int strength, i;
 
   if(!str || sscanf(str, "%s into %s", what, what2) != 2) return 0;
   plant = present(what, this_player());
   vial = present(what2, this_player());
   tp = this_player();

   if(!plant) {
      write("You don't have a "+what+".");
      return 1;
   }
   if(!vial) {
      write("You don't have a "+what2+".");
      return 1;
   }
   if(!plant->is_potion_plant())  {
      write("You can't grind a "+what+".");
      return 1;
   }
   if(vial->query_potion_level()) {
      write("That vial has a potion in it already!");
      return 1;
   }
   if(!vial->is_empty_potion_vial()) {
      write("A "+what2+" can't contain potions.");
      return 1;
   }

   if(!tp->query_skill("potion lore")) {
      write("You fiddle with the plant press but you are unsure as to how
it works.");
      return 1;
   }
 
   seteuid(geteuid(this_object()));
   strength = plant->query_toxin_level() +
              ((tp->query_skill("potion lore"))/2) +
              (((int)tp->query_stats("dexterity"))/10) +
              (((int)tp->query_stats("intelligence"))/10) -
              10 + random(21);
   if (strength < 1) strength = 1;
 
   new_vial = new("/std/tailwind/potion/potion_vial");
 

// Set the poison strength and color.
 
   switch(strength) {
      case 1..15: color = "clear"; break;
      case 16..30: color = "cloudy"; break;
      case 31..45: color = "white"; break;
      case 46..60: color = "light gray"; break;
      case 61..75: color = "dark gray"; break;
      case 76..90: color = "black"; break;
      case 91..105: color = "dark brown"; break;
      case 106..120: color = "light brown"; break;
      case 121..135: color = "purple"; break;
      case 136..150: color = "lavender"; break;
      case 151..165: color = "light pink"; break;
      case 166..180: color = "dark blue"; break;
      case 181..195: color = "light blue"; break;
      case 196..210: color = "dark green"; break;
      case 211..225: color = "light green"; break;
      case 226..240: color = "bright yellow"; break;
      case 241..255: color = "orange"; break;
      case 256..270: color = "red"; break;
      case 271..285: color = "dark red"; break;
      case 286..1000: color = "blood red"; break;
   }
   new_vial->set_potion_level(strength);
   new_vial->set_short("a vial of "+color+" liquid");
   new_vial->set_name("a vial of "+color+" liquid");
   new_vial->set_long("The small vial contains a thick liquid.");
   new_vial->move(tp);
   write("You press "+(string)plant->query_short()+" into a "+color+" potion.");
 
   message("info", (string)this_player()->query_cap_name() +
           " presses "+(string)plant->query_short()+" into a "+color+" liquid.",
           all_inventory(environment(this_player())),
          ({ this_player() }) );
   plant->remove();
   vial->remove();

   return 1;
 }
