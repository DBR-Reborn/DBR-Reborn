inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

string damtype;
string stat;

void create() {
    ::create();
    set_property("name","spirit of nature");
    set_property("skill","environmental bonding");
    set_property("casting time",1);
    set_property("base mp cost",1);
set_property("dev cost", 40);
set_property("fast dev cost", 125);
set_property("spell level", 9);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast spirit of nature, and feel the essence of the planet stream into you, your weapon, and your armour.");
    set_property("target message","");
    set_property("observer message","You notice that a multi-colored hue of light is streaming into $C as he uses the spirit of nature.");
    set_property("spell type",({"stat mod", "protection"}));
    set_property("duration", 120);
    set_property("duration", 300);
    set_property("must be present", 1);
    set_property("target type", "any");
    set_property("stack key", "spirit of nature");
    set_property("stack num", 1);
    return;
}

void info() {
message("help",
"This spell allows a Shaman to use the spirit within a jewel to empower him, his weapon, and his armour. The bonuses he receives are dependent upon the type of jewel used. \n Syntax: cast *<pow> spirit of nature at <jewel> with <weapon>\n Ex: cast *2 spirit of nature at jewel with staff\n",
this_player());
}

void remove_stack(object at) {
  if(!objectp(at)) return;
  at->set("spirit of nature", 0);
  remove();
  return;
}

string rand_stat(){
  string blah;
  switch(random(6)){
    case 0:
      blah="strength";
      break;
    case 1:
      blah="constitution";
      break;
    case 2:
      blah="dexterity";
      break;
    case 3:
      blah="wisdom";
      break;
    case 4:
      blah="intelligence";
      break;
    case 5:
      blah="charisma";
      break;
  }
  return blah;
}

void staff_set(string gemmaterial){
    switch(gemmaterial){
    case "/diamond":
	damtype="holy";
        stat="intelligence";
	break;
    case "/ruby":
	damtype="fire";
        stat="wisdom";
	break;
    case "/emerald":
	damtype="crushing";
        stat="strength";
	break;
    case "/sapphire":
	damtype="vacuum";
        stat="dexterity";
	break;
    case "/jade":
	damtype="aether";
        stat="charisma";
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
      stat=rand_stat();
      break;
    case "/amethyst":
	damtype="time";
        stat="constitution";
	break;
    case "/turquoise":
	damtype="cold";
        stat="dexterity";
	break;
    case "/onyx":
	damtype="infernal";
        stat="wisdom";
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
     stat=rand_stat();
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
     stat=rand_stat();
     break;
  }
  return;
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob, weap, weapontochant;

weapontochant = present(lower_case(args), caster);
  
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
  if(!args || !(weap = present(lower_case(args), caster))) {
    if(!args)
      message("info", "You must supply a weapon to be imbued with the forces of nature.",
          caster);
    else
      message("info", "You have no '"+args+"'.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

ob = new("/std/spells/shadows/weapon_shadow");
if(!check_stack(weap, ob)) {
    message("info", "You may only cast this spell once upon a weapon.",
      caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
else if((int)caster->query("spirit of nature") >= 1) {
    message("info", "You cannot put any more spirit of nature spells upon yourself.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
{
  caster->set("spirit of nature", 1);
  call_out("remove_stack", props["duration"], caster);
  weap = present(lower_case(args), caster);
  staff_set(at->query_material());
  message("info", "You expend power from the jewel to infuse yourself with the spirit of nature.", caster);
  ob->set_extra_wc(([ damtype : 5*power ]));
  ob->set_auto_crits(([ damtype + "C" : 2*power ]));
  ob->start_shadow(weap, props["duration"], "%^CYAN%^A spirit of nature spell wears off the weapon.");
  set_property("protection types", ([ damtype : 100 ]) );
// Fairly important - does the charge stuff. Call set_up() so if the jewel looks diff now, it'll show it.
  at->subtract_charge(random(2)+power);
  at->set_up();
  at=caster;
  set_property("stat dice", "2D2");
  set_property("stats", ({ stat }) );
  ::spell_func(caster, at, power, args, flag);
  remove();
  return;
}
}
