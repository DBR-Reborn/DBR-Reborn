#include <move.h>
 
inherit "/std/spells/spell";
 
void create() {
    ::create();
    set_property("name","cooking");
    set_property("skill","alchemy");
    set_property("casting time",15);
      set_property("base mp cost",14);
    set_property("dev cost", 14);
    set_property("fast dev cost", 39);
    set_property("spell level", 4);
    set_property("moon","luna");
    set_property("caster message","You take out a pot, and make a yummy dish.");
    set_property("target message","");
    set_property("observer message","$C whips out a pot, and magically makes a yummy dish.");
    set_property("spell type",({  }));
    set_property("no target",1);
    return;
}
 
void info() {
message("help",
"This spell summons some food which can satisfy hunger and help to heal "
"more quickly.  The higher the power, the more satisfying the food.",
this_player());
}
 
void spell_func(object caster, object at, int power, string args, int flag)
{
  object ob;
 
  seteuid(getuid());
  if(flag) {
    message("info", "You misdirect the energies of your spell, mildly "+
            "poisoning yourself.", caster);
    message("info", (string)caster->query_cap_name() +
            " looks a little green.", environment(caster), ({ caster }));
    caster->add_poisoning(45);
 
  }
  ob = new("/std/food");
  ob->set_long("This is an item of alchemistically created food.");
  switch(power + random(4)) {
  case 0..2:
  default:
    ob->set_name("cookie");
    ob->set_id(({ "cookie", "food" }) );
    ob->set_weight(2);
    ob->set_float_value(0.04);
    ob->set_strength(10);
    ob->set_short("A cookie");
    break;
  case 3..4:
    ob->set_name("bread");
    ob->set_id(({ "loaf", "bread", "loaf of bread", "food" }));
    ob->set_weight(10);
    ob->set_float_value(0.35);
    ob->set_strength(15);
    ob->set_short("A loaf of bread");
 
    break;
  case 5..6:
    ob->set_name("pie");
    ob->set_id(({ "pie", "food", "apple pie" }));
    ob->set_weight(23);
    ob->set_float_value(15.0);
    ob->set_strength(20);
    ob->set_short("An apple pie");
    break;
  case 7..8:
    ob->set_name("cake");
    ob->set_id(({ "cake", "food", "chocalate cake" }));
    ob->set_weight(20);
    ob->set_float_value(24.0);
    ob->set_strength(25);
    ob->set_short("A chocalate cake");
    break;
  case 9..100:
    ob->set_name("meal");
    ob->set_id(({ "food", "meal", "complete three-course meal" })); 
    ob->set_weight(35);
    ob->set_float_value(42.0);
    ob->set_strength(40);
    ob->set_short("A complete, three-course meal");
    break;
  }
  message("my_action", "You create "+(string)ob->query_short()+".",
          caster);
  message("other_action", "" + (string)caster->query_cap_name()+
          " creates "+(string)ob->query_short()+".",environment(caster),
          ({ caster }) );
  if((int)ob->move(caster) != MOVE_OK) {
    ob->move(environment(caster));
    message("info", "The food is too heavy for you.", caster);
  }
  remove();
  return;
}
 
