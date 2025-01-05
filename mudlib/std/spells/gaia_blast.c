inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

string damtype;

void create() {
    ::create();
    set_property("name","gaia blast");
    set_property("skill","environmental control");
    set_property("casting time",1);
    set_property("base mp cost",1);
    set_property("dev cost",30);
    set_property("fast dev cost",90);
    set_property("spell level", 5);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast gaia blast at $T.");
    set_property("target message","");
    set_property("observer message","$C casts gaia blast at $T.");
    set_property("spell type",({ "damage" }));
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("target type", "living");
    set_property("damage multiplier", 3);
    set_property("can resist", 1);
    return;
}

void info() {
message("help",
"This spell does damage to a target. The type of damage depends on the type of jewel used in casting the spell.\n"
"This spell will drain the jewel used. Be careful.\n"
"Syntax: cast *<pow> gaia blast at <target> with <jewel>\n"
"Ex: cast *2 gaia blast at guard with jewel\n",
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
  object ob, jewel;

jewel = present(lower_case(args), caster);
  
  if(flag) {
    message("info", "You move your hand the wrong way, and the jewel turns to dust.", caster);
    message("info", (string)at->query_cap_name() +" sighes as a jewel turns to dust in his hands!", environment(caster),
          ({ caster, at }));
    jewel = present(lower_case(args), caster);
    jewel->remove();
    remove();
    return;
  }
  seteuid(getuid());
  if(!args || !(jewel = present(lower_case(args), caster))) {
    if(!args)
      message("info", "You must supply a jewel to cast this spell.",
          caster);
    else
      message("info", "You have no '"+args+"'.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
else
{
  jewel = present(lower_case(args), caster);
  jewel->subtract_charge(random(3)+power);
  jewel->set_up();


staff_set(jewel->query_material());

    set_property("damage types", ([ damtype : 60 ]));

::spell_func(caster, at, power, 0, 0);
  remove();
  return;
}
}



