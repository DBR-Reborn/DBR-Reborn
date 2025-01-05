inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

string damtype;

void create() {
    ::create();
    set_property("name","nature's fury");
    set_property("skill","environmental control");
    set_property("casting time",1);
    set_property("base mp cost",1);
    set_property("dev cost",200);
    set_property("fast dev cost",450);
    set_property("spell level", 34);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast nature's fury at $T.");
    set_property("target message","");
    set_property("observer message","$C casts nature's fury at $T.");
    set_property("spell type",({ "area damage" }));
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("target type", "any");
    set_property("damage multiplier", 12.5);
    set_property("can resist", 1);
    return;
}

void info() {
message("help",
"This spell does damage to an area. The type of damage depends on the type of jewel used in casting the spell. It does more damage than environmental forces, but also drains much more power out of the jewel.\n"
"Syntax: cast *<pow> nature's fury at <jewel>\n"
"Ex: cast *2 nature's fury at jewel\n",
this_player());
}


void staff_set(string gemmaterial){
    switch(gemmaterial){
    case "/diamond":
	damtype="holy";
	break;
    case "/ruby":
	damtype="fire";
	break;
    case "/emerald":
	damtype="crushing";
	break;
    case "/sapphire":
	damtype="vacuum";
	break;
    case "/jade":
	damtype="aether";
	break;
    case "/obsidian":
	switch(random(4)){
          case 0:
            damtype="time";
          break;
          case 1:
            damtype="reflection";
          break;
          case 2:
            damtype="radiation";
          break;
          case 3:
            damtype="vacuum";
          break;
          case 4:
            damtype="aether";
          break;
        }
        break;
    case "/amethyst":
	damtype="time";
	break;
    case "/turquoise":
	  damtype="cold";
	break;
    case "/onyx":
	  damtype="infernal";
        break;
    case "/quartz":
      switch(random(4)){
        case 0:
          damtype="electricity";
        break;
        case 1:
          damtype="fire";
        break;
        case 2:
          damtype="cold";
        break;
        case 3:
          damtype="acid";
        break;
        case 4:
          damtype="stress";
        break;
      }
	break;
   case "/glass":
      switch(random(2)){
        case 0:
          damtype="impaling";
        break;
        case 1:
          damtype="crushing";
        break;
        case 2:
          damtype="cutting";
        break;
     }
    break;
    }
    return;
}


void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;
  
  if(flag) {
    message("info", "You move your hand the wrong way, and the jewel turns to dust.", caster);
    message("info", (string)at->query_cap_name() +" sighes as a jewel turns to dust in his hands!", environment(caster),
          ({ caster, at }));
    at->remove();
    remove();
    return;
  }
  seteuid(getuid());

  at->subtract_charge(random(6)+3*power);
  at->set_up();


staff_set(at->query_material());

    set_property("damage types", ([ damtype : 40, damtype+" #2" : 40, damtype+" #3": 40 ]));

::spell_func(caster, at, power, 0, 0);
  remove();
  return;

}



