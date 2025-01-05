#include <security.h>
#include "/wizards/tailwind/tailwind.h";
#include "/wizards/tailwind/monk.h";

inherit "/std/spells/shadows/shadow";
inherit "/std/tailwind/monk_funs";

// Skill mods
#define L1SPP (skill_level/7 + 1)   // 1-15
#define L1SP (skill_level/15 + 1)   // 1-7
#define L1SM (-8 + skill_level/20)  // -8 - -3
#define L2SPP (skill_level/5 + 1)   // 1-21
#define L2SP (skill_level/10 + 1)   // 1-11
#define L2SM (-5 + skill_level/20)  // -5 - 0

// WC Mods
#define L1WCPP (skill_level/10+1)      // 1-11
#define L1WCP (skill_level/15+1)       // 1-7
#define L2WCPP (skill_level/5+1)      // 1-21
#define L2WCP (skill_level/8+1)       // 1-13

string style;            // which style 
object who_shadowed;     // who shadowed
int skill_level;         // % skill in style
int style_level;         // 1, 2, 3, etc
int dam_mod;             // damage mod
int extra_attack_mod;    // % mod that will get extra attack
string* crit_types;      // crit types for style
mapping skill_mods;      // skill mods
mapping melee_mods;      // melee mods

// Defined in the specific style file
string* monk_messages(object from, object at, int which);
string* monk_crit_types();

// Defined locally
void execute_style_attack();
int extra_style_attack();
string* monk_crit_levels(int);
int monk_damage(int);
void set_attack_lev1(string);
void set_attack_lev2(string);
void set_defense_lev1(string);
void set_defense_lev2(string);
void set_misc_lev1(string);
void set_misc_lev2(string);

void create() {
  crit_types = ({});
  skill_mods = ([]);
  melee_mods = ([]);
  return;
}

int start_shadow(object ob) {
  if(!objectp(ob)) return 0;
  seteuid(UID_SHADOW);
  begin_shadow(ob);
  seteuid(getuid());
  return 1;
}

void end_style(string s) {
  if(s != style) {
    next_shadow()->end_style(s);
    return;
  }
  message("info", IC+"You finish using style "+style+"."+RC, who_shadowed);
  remove();
}

void end_styles(int lev)
{
  next_shadow()->end_styles(lev);  // End others
  if(style_level >= lev)
  {
    message("info", IC+"You finish using style "+style+"."+RC, who_shadowed);
    remove();
  }
}

void set_who_shadowed(object pl)
{ who_shadowed = pl; }

void set_skill_level(int sk)
{
  // Only adds up to 100%
  if(sk < 100) skill_level = sk; 
  else skill_level = 100;
}

void set_style_level(int lev) { style_level = lev; }

void set_extra_attack_mod(int mod)
{ extra_attack_mod = mod; }

void set_dam_mod(int mod) { dam_mod = mod; }

void set_style(string s) { style = s; }

// Set Attack
void set_attack(string s)
{
  switch(style_level)
  {
    case 1: set_attack_lev1(s); break;
    case 2: set_attack_lev2(s); break;
    default: break;
  }
}

void set_attack_lev1(string s)
{
  if(s == "hard")
  {
    skill_mods["melee"] = L1SPP;
    skill_mods["martial arts"] = L1SM;
    skill_mods["attack"] = L1SP;
    skill_mods["iron fist"] = L1SP;
    skill_mods["fists of fury"] = L1SP;
    skill_mods["focus element"] = L1SM;
    skill_mods["warrior spirit"] = L1SP;
    melee_mods = ([ "crushing" : L1WCPP, "impact" : L1WCP ]);
  }
  else if(s == "med")
  {
    skill_mods["melee"] = L1SP;
    skill_mods["martial arts"] = L1SP;
    skill_mods["attack"] = L1SP;
    skill_mods["break limb"] = L1SP;
    melee_mods = ([ "crushing" : L1WCP, "impact" : L1WCP, "strike" : L1WCP ]);
  }
  else if(s == "soft")
  {
    skill_mods["melee"] = L1SM;
    skill_mods["martial arts"] = L1SPP;
    skill_mods["iron fist"] = L1SM;
    skill_mods["fists of fury"] = L1SM;
    skill_mods["break limb"] = L1SPP;
    skill_mods["focus element"] = L1SP;
    skill_mods["warrior spirit"] = L1SP;
    skill_mods["kaijutsu"] = L1SP;
    melee_mods = ([ "impact" : L1WCP, "strike" : L1WCPP ]);
  }
}

void set_attack_lev2(string s)
{
  if(s == "hard")
  {
    skill_mods["melee"] = L2SPP;
    skill_mods["martial arts"] = L2SM;
    skill_mods["attack"] = L2SP;
    skill_mods["iron fist"] = L2SP;
    skill_mods["fists of fury"] = L2SP;
    skill_mods["focus element"] = L2SM;
    skill_mods["warrior spirit"] = L2SP;
    melee_mods = ([ "crushing" : L2WCPP, "impact" : L2WCP ]);
  }
  else if(s == "med")
  {
    skill_mods["melee"] = L2SP;
    skill_mods["martial arts"] = L2SP;
    skill_mods["attack"] = L2SP;
    skill_mods["break limb"] = L2SP;
    melee_mods = ([ "crushing" : L2WCP, "impact" : L2WCP, "strike" : L2WCP ]);
  }
  else if(s == "soft")
  {
    skill_mods["melee"] = L2SM;
    skill_mods["martial arts"] = L2SPP;
    skill_mods["iron fist"] = L2SM;
    skill_mods["fists of fury"] = L2SM;
    skill_mods["break limb"] = L2SPP;
    skill_mods["focus element"] = L2SP;
    skill_mods["warrior spirit"] = L2SP;
    skill_mods["kaijutsu"] = L2SP;
    melee_mods = ([ "impact" : L2WCP, "strike" : L2WCPP ]);
  }
}

void set_defense(string s)
{
  switch(style_level)
  {
    case 1: set_defense_lev1(s); break;
    case 2: set_defense_lev2(s); break;
    default: break;
  }
}

void set_defense_lev1(string s)
{
  if(s == "hard")
  {
    skill_mods["parry"] = L1SPP;
    skill_mods["dodge"] = L1SM;
    skill_mods["adrenal defense"] = L1SM;
    skill_mods["resist stun"] = L1SPP;
  }
  else if(s == "med")
  {
    skill_mods["parry"] = L1SP;
    skill_mods["dodge"] = L1SP;
  }
  else if(s == "soft")
  {
    skill_mods["parry"] = L1SM;
    skill_mods["dodge"] = L1SPP;
    skill_mods["adrenal defense"] = L1SP;
    skill_mods["resist stun"] = L1SM;
  }
}

void set_defense_lev2(string s)
{
  if(s == "hard")
  {
    skill_mods["parry"] = L2SPP;
    skill_mods["dodge"] = L2SM;
    skill_mods["adrenal defense"] = L2SM;
    skill_mods["resist stun"] = L2SPP;
  }
  else if(s == "med")
  {
    skill_mods["parry"] = L2SP;
    skill_mods["dodge"] = L2SP;
  }
  else if(s == "soft")
  {
    skill_mods["parry"] = L2SM;
    skill_mods["dodge"] = L2SPP;
    skill_mods["adrenal defense"] = L2SP;
    skill_mods["resist stun"] = L2SM;
  }
}

void set_misc(string s)
{
  switch(style_level)
  {
    case 1: set_misc_lev1(s); break;
    case 2: set_misc_lev2(s); break;
    default: break;
  }
}

void set_misc_lev1(string s)
{
  if(s == "hard")
  {
    skill_mods["swimming"] = L1SP;
    skill_mods["stealth"] = L1SP;
  }
  else if(s == "med")
  {
    skill_mods["perception"] = L1SP;
    skill_mods["swimming"] = L1SP;
    skill_mods["stealth"] = L1SP;
    skill_mods["consider"] = L1SP;
    skill_mods["meditation"] = L1SP;
  }
  else if(s == "soft")
  {
    skill_mods["perception"] = L1SPP;
    skill_mods["invisibility art"] = L1SP;
    skill_mods["meditation"] = L1SP;
  }
}

void set_misc_lev2(string s)
{
  if(s == "hard")
  {
    skill_mods["swimming"] = L2SP;
    skill_mods["stealth"] = L2SP;
  }
  else if(s == "med")
  {
    skill_mods["perception"] = L2SP;
    skill_mods["swimming"] = L2SP;
    skill_mods["stealth"] = L2SP;
    skill_mods["consider"] = L2SP;
    skill_mods["meditation"] = L2SP;
  }
  else if(s == "soft")
  {
    skill_mods["perception"] = L2SPP;
    skill_mods["invisibility art"] = L2SP;
    skill_mods["meditation"] = L2SP;
  }
}

int query_using_style() { return 1; }

string query_style() { return style; }

int query_using_style_name(string s)
{
  if(style == s)
    return 1;
  return(next_shadow()->query_using_style_name(s));
}

string query_style_name(int i)
{
  if(style_level == i)
    return style;
  return(next_shadow()->query_style_name(i));
}

int query_using_style_level(int lev)
{
  int ret;
  if(lev == 1 && member_array(style, LEV1STYLES) >= 0)
    ret = 1;
  else if(lev == 2 && member_array(style, LEV2STYLES) >= 0)
    ret = 1;
  else 
    ret = next_shadow()->query_using_style_level(lev);
  return ret;
}

void execute_style_attack()
{
  string *messages, *crit_levels; // Messages and Crit Level
  object* attackers;              // Attackers
  object at;                      // Who attacking
  int which;                      // if negative, no attack, else 0-150
  int dam;                        // damage to do based on which
  int i,j;                        // counter

  if(monk_has_heavy_armour(who_shadowed))
  {
    message("info",IC+"Your amour is too heavy to continue using a style!"+RC,
            who_shadowed);
    delayed_call("end_styles", 0, 1);
    return;
  }

  if(!monk_has_limbs(who_shadowed))
  {
    message("info",IC+"You do not have the required limbs to use a style!"+RC,
            who_shadowed);
    delayed_call("end_styles", 0, 1);
    return;
  }

  attackers = who_shadowed->query_attackers();
  which = extra_style_attack();

  if(wizardp(who_shadowed) && (string)who_shadowed->getenv("MONKTRACE") == "on")
    message("info","Which: "+which,who_shadowed);

  if(sizeof(attackers) > 0 && which >= 0)
  {
    at = attackers[0];
  
    messages = monk_messages(who_shadowed, at, which);
    crit_levels = monk_crit_levels(which);
    crit_types = monk_crit_types();
    dam = monk_damage(which);

    // Display messages
    message("my_combat", messages[0], who_shadowed);
    message("other_combat", messages[1], at);
    message("other_combat", messages[2], 
            all_inventory(environment(who_shadowed)), ({ who_shadowed, at }) );

    if(wizardp(who_shadowed) && (string)who_shadowed->getenv("MONKTRACE") == "on")
      message("info","Style Damage: "+dam,who_shadowed);

    // Do Damage
	at->do_damage((string)at->return_target_limb(who_shadowed), dam);
  
    // Do crits
    i = sizeof(crit_levels);
    while(i--)
    {
      j = random(sizeof(crit_types));
      do_critical(who_shadowed, at, crit_types[j]+" "+crit_levels[i]);
      if(wizardp(who_shadowed) && 
         (string)who_shadowed->getenv("MONKTRACE") == "on")
        message("info","Crit: "+crit_types[j]+" "+crit_levels[i],who_shadowed);
    }
  }
  next_shadow()->execute_style_attack();  // Call other shadows
}

int extra_style_attack()
{ 
  int chance;
  chance = (skill_level/4)+15;    // 15 - 40% w/o mod
  chance += extra_attack_mod;     // add mod

  if(wizardp(who_shadowed) && (string)who_shadowed->getenv("MONKTRACE") == "on")
    message("info","Chance: "+chance,who_shadowed);
  
  if(chance < random(100))
    return -1;

  // skill +/- 20 + dam_mod
  return(skill_level + random(40) - 20 + dam_mod);   
}

int monk_damage(int which)
{
  int ret;       // return damage
  if(style_level == 1)
    ret = which/3 + random(which/10)*3 + random(10);
  else if(style_level == 2)
    ret = which/2 + random(which/8)*3 + random(10) * 2;
  else
    ret = 0;
  return ret;
} 

string* monk_crit_levels(int which)
{
  string *ret;     // return 
  ret = ({ });
  switch(which + (style_level-1)*20)
  {
    case 0..30: ret=({ "A" }); break;
    case 31..50: ret=({ "B" }); break;
    case 51..60: ret=({ "C" }); break;
    case 61..70: ret=({ "D" }); break;
    case 71..80: ret=({ "A", "B" }); break;
    case 81..90: ret=({ "B", "C" }); break;
    case 91..100: ret=({ "E" }); break;
    case 101..110: ret=({ "C", "C" }); break;
    case 111..120: ret=({ "C", "D" }); break;
    case 121..130: ret=({ "A", "B", "C" }); break;
    case 131..140: ret=({ "B", "C", "C" }); break;
    case 141..150: ret=({ "C", "D", "D" }); break;
    case 151..160: ret=({ "C", "D", "E" }); break;
    case 161..1000: ret=({ "D", "D", "E" }); break;
  }
  return ret;
}

int query_skill(string what) {
  int ret;
  ret = (int)next_shadow()->query_skill(what);
  if(skill_mods[what])
    ret += skill_mods[what];
  return ret;
}

mixed query_property(string what) {
  mapping tmp;     // return from other shadows
  mapping ret;     // return mapp
  int i;           // counter
  string* mkeys;   // keys of melee damages

  if(what == "melee damage")
  {
    ret = allocate_mapping(20);
    mkeys = keys(melee_mods);
    i = sizeof(mkeys);
    while(i--) 
      ret[mkeys[i]] = melee_mods[mkeys[i]];

    tmp = (mapping)next_shadow()->query_property("melee damage");
    if(!tmp || !mapp(tmp))
      return ret;
 
    mkeys = keys(tmp);
    i = sizeof(mkeys);
    while(i--)
    {
       if(ret[mkeys[i]]) ret[mkeys[i]] += tmp[mkeys[i]];
       else ret[mkeys[i]] = tmp[mkeys[i]];
    }
    return ret;
  }
  return next_shadow()->query_property(what);
}

