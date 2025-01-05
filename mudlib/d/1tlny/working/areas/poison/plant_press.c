/*
   Plant press.  Necessary to make poisons with the poison lore skill.
   by Duridian 4/1/96
*/
 
 
#include <std.h>
 
inherit "/std/Object";
 
void create() {
   ::create();
   set_name("plant press");
   set_id( ({ "press", "plant press" }) );
   set_short("a plant press");
   set_long("This press may be used to extract the essence from plants " +
      "in order to extract the toxic resins for use as poisons.  Use " +
      "'press <what> into <container>' where <what> is what you wish to "
      "press and <container> is what you wish to press it into.");
    set_weight(30);
    set_value(15);
    return;
}
 
void init() {
  ::init();
    add_action("press", "press");
    return;
}
 
int press(string str) {
   string what, what2, color;
   object plant, vial, new_vial, tp;
   int strength, i;
 
   if(!str || sscanf(str, "%s into %s", what, what2) != 2) return 0;
   plant = present(what, this_user());
   vial = present(what2, this_user());
   tp = this_user();
 
   if(!plant) {
      write("You don't have a "+what+".");
      return 1;
   }
   if(!vial) {
      write("You don't have a "+what2+".");
      return 1;
   }
   if(!plant->is_poisonous_plant())  {
      write("You can't press a "+what+".");
      return 1;
   }
   if(vial->query_poison_level()) {
      write("That vial has a poison in it already!");
      return 1;
   }
   if(!vial->is_empty_poison_vial()) {
      write("A "+what2+" can't contain poisons.");
      return 1;
   }

   if(!tp->query_skill("poison lore")) {
      write("You fiddle with the plant press but you are unsure as to how
it works.");
      return 1;
   }
 
   seteuid(geteuid(this_object()));
   strength = plant->query_toxin_level() +
              ((tp->query_skill("poison lore"))/2) +
              (((int)tp->query_stats("dexterity"))/10) +
              (((int)tp->query_stats("intelligence"))/10) -
              10 + random(21);
   if (strength < 1) strength = 1;
 
   new_vial = new("/wizards/duridian/poison/poison_vial");
 
// Add any critical that the plant may cause.
   new_vial->set_crit_type(plant->query_crit_type());
   new_vial->set_crit_level(plant->query_crit_level());
// If there IS a critical, it will be applied to the weapon when the
// poison is applied to the weapon.

 
// Set the poison strength and color.
 
   new_vial->set_poison_level(strength);
 
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
 
   new_vial->set_short("a vial of "+color+" liquid");
   new_vial->set_name("a vial of "+color+" liquid");
   new_vial->set_long("The small vial contains a thick, "+color+"
liquid.");
   new_vial->move(tp);
   write("You press "+(string)plant->query_short()+" into a "+color+"
poison.");
 
   message("info", (string)this_user()->query_cap_name() +
           " presses "+(string)plant->query_short()+" into a "+color+"
liquid.",
           all_inventory(environment(this_user())),
          ({ this_user() }) );
   plant->remove();
   vial->remove();
   return 1;
}

