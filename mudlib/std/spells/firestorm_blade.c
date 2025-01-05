inherit "/std/spells/long_term_spell";
inherit "/std/check_brittle";

mapping auto_criticals;

void create() {
    ::create();
    set_property("name","firestorm blade");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",75);
    set_property("dev cost", 90);
    set_property("fast dev cost", 270);
    set_property("spell level", 17);
    set_property("moon","luna");
    set_property("caster message","You begin to imbue the weapon with firestorm damage.");
    set_property("target message","");
    set_property("observer message","$C begins to enchant a weapon.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("prereq", "flame blade");
    return;
}

void info() {
message("help",
"This spell adds firestorm damage to ANY weapon (not just blades). "
"This is a more powerful version of fire blade. "
"Different blade spells with the same element are not allowed on a weapon. "
"The number of times you may cast this spell on a weapon is directly determined by the level of the casters enchantment skill. "
"This is a long-term spell (see help long-term), and may take very much real time to cast. " 
"If you are interrupted while casting, you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
int time;
int mod;
int ctime;

if(!at->is_weapon()) {
    message("info", "You may only cast this spell upon weapons.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}
if(flag) {
    message("info", "You misdirect the enchanting energies and shatter "+
	    "the weapon!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently shatters the weapon.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
}
if((int)at->query_property("firestorm blade") >= (caster->query_skill("enchantment") / 5)) {
    message("info", "Your skill is not high enough to add more firestorm blade spells on this weapon.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}
if((int)at->query_property("flame blade") >= 1 ) {
    message("info", "Different blade spells with the same element are not allowed on a weapon.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}

if((int)at->query_property("firestorm blade") >= 60 ) {
    message("info", "This weapon has reached the max amount of firestorm blade a weapon can have", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}

set_work_message("%^CYAN%^You enchant the weapon.%^RESET%^");
time = 580 + 90*power;
mod = 30+2*props["spell level"];
ctime = (time*mod)/caster->query_skill("enchantment");
if(archp(caster)) {
ctime = 1;
}
start_work(at, caster, ctime, power);
return;
}

void finish_work(object caster, object at, int power) {
mapping auto_criticals; //TLNY2024 Testing of auto criticals
int ench;
int i;
int idx;
mixed tmp;
  mixed val;
  mixed zench;
  string *types;


if(power <= 0) {
message("info", "BUG in Enchanter spell....unable to complete.", environment(caster));
remove();
return;
}
message("info", "You have finished enchanting Firestorm Blade!", caster);
message("info", "Uttering some magical incantations, "+(string)caster->query_cap_name()+" finishes enchanting a weapon with firestorm.", environment(caster), ({ caster }));
ench = (int)at->query_property("firestorm blade");


if(!check_brittle(at, caster, power)) {
remove();
return;
}

if(!ench) {
ench = 0;
}
ench += power;
at->set_property("firestorm blade", ench);
    ench = (int)at->query_wc("fire");
    if(!ench) ench = power+ench;
    else ench += power;
    at->set_wc(((11*power)+ench)+(caster->query_level()/2), "fire");
    ench = 0;
    ench = (int)at->query_wc("impact");
    if(!ench) ench = power+ench;
    else ench += power;
    at->set_wc(((11*power)+ench)+(caster->query_level()/2), "impact");
    caster->add_exp2(1700*power);

//ADD TLNY2024 TEST code overwrites auto criticals and does not add too
/*
auto_criticals = (mapping)at->query_auto_critical();

message("info", (string)auto_criticals, caster);
message("info", "TESTABC", caster);

if (!auto_criticals || !mapp(auto_criticals)) {
    auto_criticals = ([]);
}
    auto_criticals["fire B"] = ((4 * power) + ench) + caster->query_level();
    auto_criticals["impact B"] = ((4 * power) + ench) + caster->query_level();
at->set_auto_critical(auto_criticals);
*/
 //END
/*
//A 
  zench = (mixed)at->query_auto_critical();
  if(!zench) zench = 0;
  if(mapp(zench)) {
    types = DAMAGE_TYPES;
    i = sizeof(types);
    while(i--) {
      if(zench[types[i]])
	zench[types[i]] += power;
      else zench[types[i]] = power;
    }
    at->set_auto_critical(zench);
}
//E 
*/


/*
at->set_property("firestorm blade", ench);
    ench = (int)at->query_wc("fire");
    if(!ench) ench = power*2;
    else ench += power*2;
    at->set_wc(ench, "fire");
    at->set_wc(ench, "impact");
    caster->add_exp2(450*power);
*/
tmp = (mixed)at->query_property("extra long");
if(!tmp) {
tmp = ({ });
}
else if(stringp(tmp)) tmp = ({ tmp });
idx = -1;
i = sizeof(tmp);
while(i--) {
if(pointerp(tmp[i]) && sizeof(tmp[i]) == 2 && eliminate_colour(tmp[i][0]) == "This weapon has Firestorm Blade.") idx = 1;
}
if(idx < 0) {
tmp += ({ ({ "This weapon has %^RED%^%^RED%^Firestorm%^RESET%^ Blade.", "detect magic" }) });
at->set_property("extra long", tmp);
remove();
return;
}
}

