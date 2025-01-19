inherit "/std/spells/long_term_spell";
inherit "/std/check_brittle";

void create() {
    ::create();
    set_property("name","vacid weapon");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",85);
    set_property("dev cost", 125);
    set_property("fast dev cost", 375);
    set_property("spell level", 24);
    set_property("moon","luna");
    set_property("caster message","You begin to imbue the weapon with vacid damage.");
    set_property("target message","");
    set_property("observer message","$C begins to enchant a weapon.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("prereq", "icy weapon");
    return;
}

void info() {
message("help",
"This spell adds vacid damage to ANY weapon. "
"This is a more powerful version of icy weapon. "
"Different weapon spells with the same element are not allowed on a weapon. "
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
    message("info", "The spell fizzles, costing double mp.", caster);
    caster->add_mp(-1* props["mp cost"]);
    remove();
    return;
  }
/*
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
*/
if((int)at->query_property("vacid weapon") >= (caster->query_skill("enchantment") / 5)) {
    message("info", "Your skill is not high enough to add more vacid weapon spells on this weapon.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}
if((int)at->query_property("icy weapon") >= 1 ) {
    message("info", "Different weapon spells with the same element are not allowed on a weapon.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}

if((int)at->query_property("vacid weapon") >= 60 ) {
    message("info", "This weapon has reached the max amount of vacid weapon that a weapon can have", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}

set_work_message("%^CYAN%^You enchant the weapon.%^RESET%^");
time = 1000 + 80*power;
mod = 30+2*props["spell level"];
ctime = (time*mod)/caster->query_skill("enchantment");
if(archp(caster)) {
ctime = 1;
}
start_work(at, caster, ctime, power);
return;
}

void finish_work(object caster, object at, int power) {
int ench;
int i;
int idx;
mixed tmp;
string* auto_criticals;

if(power <= 0) {
message("info", "BUG in Enchanter spell....unable to complete.", environment(caster));
remove();
return;
}
message("info", "You have finished enchanting Vacid Weapon!", caster);
message("info", "Uttering some magical incantations, "+(string)caster->query_cap_name()+" finishes enchanting a weapon with vacid.", environment(caster), ({ caster }) );
	  
ench = (int)at->query_property("vacid weapon");

if(caster->query_skill("enchantment") >=150) {
if(!check_brittle(at, caster, power*2)) {
remove();
return;
} else { if(!check_brittle(at, caster, power)) {
remove();
return;
} } }

if(!ench) {
ench = 0;
}

//ADD
if(caster->query_skill("enchantment") >=150) {
if((int)at->query_property("vacid weapon") <= 1 ) {
auto_criticals = at->query_auto_critical();

auto_criticals += ({"cold A", "crushing A"});

at->set_auto_critical(auto_criticals);
}}
//END

ench += power;
at->set_property("vacid weapon", ench);

    ench = 0;
    ench = (int)at->query_wc("cold");
    if(!ench) ench = power+ench;
    else ench += power;
    at->set_wc(((8*power)+ench)+(caster->query_level()/2), "cold");
    ench = 0;
    ench = (int)at->query_wc("crushing");
    if(!ench) ench = power+ench;
    else ench += power;
    at->set_wc(((8*power)+ench)+(caster->query_level()/2), "crushing");
    caster->add_exp2(2400*power);

/*
at->set_property("vacid weapon", ench);
    ench = (int)at->query_wc("cold");
    if(!ench) ench = power*2;
    else ench += power*2;
    at->set_wc(ench, "cold");
    at->set_wc(ench, "crushing");
    caster->add_exp2(500*power);
*/
tmp = (mixed)at->query_property("extra long");
if(!tmp) {
tmp = ({ });
}
else if(stringp(tmp)) tmp = ({ tmp });
idx = -1;
i = sizeof(tmp);
while(i--) {
if(pointerp(tmp[i]) && sizeof(tmp[i]) == 2 && eliminate_colour(tmp[i][0]) == "This weapon has Vacid Weapon.") idx = 1;
}
if(idx < 0) {
tmp += ({ ({ "This weapon has %^BOLD%^%^CYAN%^Vacid%^RESET%^ Weapon.", "detect magic" }) });
at->set_property("extra long", tmp);
remove();
return;
}
}

