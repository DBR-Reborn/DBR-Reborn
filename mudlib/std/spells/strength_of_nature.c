inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

string damtype;

void create() {
    ::create();
    set_property("name","strength of nature");
    set_property("skill","environmental bonding");
    set_property("casting time",1);
    set_property("base mp cost",1);
    set_property("dev cost",75);
    set_property("fast dev cost",190);
    set_property("spell level", 15);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast strength of nature at $T.");
    set_property("target message","");
    set_property("observer message","$C casts strength of nature at $T.");
    set_property("spell type",({"protection"}));
    set_property("duration", 120);
    set_property("duration", 300);
    set_property("must be present", 1);
    set_property("target type", "any");
    set_property("stack key", "strength of nature");
    set_property("stack num", 3);
    return;
}

void info() {
message("help",
"This spell uses some charge from a jewel to temporarily enhance your armour. The type of enhancement depends upon the type of jewel used. \n Syntax: cast *<pow> power of nature at <jewel>\n Ex: cast *2 power of nature at jewel\n",
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
  object ob, weap, weapontochant;

  if(!(at->is_battery())) {
    message("info", "You must cast this spell at a jewel.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  if(flag) {
    message("info", "The jewel goes boom in your face. Guess you blew that one.", caster);
    message("info", (string)at->query_cap_name() + " watches in dismay as his jewel explodes.", environment(caster),
          ({ caster, at }));
    at->remove();
    remove();
    return;
  }
  seteuid(getuid());
  staff_set(at->query_material());
  message("info", "You expend power from the jewel to protect yourself.", caster);
    set_property("protection types", ([ damtype : 200 ]) );
// Fairly important - does the charge stuff. Call set_up() so if the jewel looks diff now, it'll show it.
  at->subtract_charge(random(4)+power);
  at->set_up();
  at=caster;
  ::spell_func(caster, at, power, args, flag);
  remove();
  return;
}
