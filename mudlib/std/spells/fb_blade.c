inherit "/std/spells/long_term_spell";
inherit "/std/check_brittle";

//string* auto_criticals;
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
/*
if((int)at->query_property("firestorm blade") >= (caster->query_skill("enchantment") / 5)) {
    message("info", "Your skill is not high enough to add more firestorm blade spells on this weapon.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}
*/
if((int)at->query_property("flame blade") >= 1 ) {
    message("info", "Different blade spells with the same element are not allowed on a weapon.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}
/* //TLNY2024 Temp remove to debug
if((int)at->query_property("firestorm blade") >= 60 ) {
    message("info", "This weapon has reached the max amount of firestorm blade a weapon can have", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
}
*/
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
int ench;
//int i, auto_crit_size;
int idx;
mixed tmp;
//mixed auto_crit_size;
mapping auto_criticals, new_auto_criticals;
//string *keys;
mixed *keys, *auto_crit_array;
int i, auto_crit_size;

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
    at->set_wc(((10*power)+ench)+(caster->query_level()/2), "fire");
    ench = (int)at->query_wc("impact");
    if(!ench) ench = power;
    else ench += power;
    at->set_wc(((8*power)+ench)+(caster->query_level()/2), "impact");
    caster->add_exp2(1700*power);

//ADD

auto_criticals = at->query_auto_critical();
if (auto_criticals && pointerp(auto_criticals)) {
    message("info", "auto_criticals is an array", caster);
    auto_crit_size = sizeof(auto_criticals);
    for(i=0; i<auto_crit_size; ++i) {
        message("info", auto_criticals[i], caster);
    //message("info", sprintf("Existing critical: %s with value %d", keys[i], auto_criticals[keys[i]]), caster);
    }
}

//A2
// Query existing auto_criticals
auto_crit_array = at->query_auto_critical();
if (!auto_crit_array || !pointerp(auto_crit_array)) {
    auto_crit_array = ({});  // Initialize as an empty array if it's null
}

// Convert the array into a mapping
auto_criticals = ([]);
for (i = 0; i < sizeof(auto_crit_array); i++) {
    string critical_name = auto_crit_array[i];
    string property_name = "critical_value_" + critical_name;  // Construct property name
    int value = at->query_property(property_name);  // Query the property

    // Debug output to check property name and value
    message("info", sprintf("Querying property: %s, Value: %d", property_name, value), caster);

    // Store in mapping
    auto_criticals[critical_name] = value;
}

// Debug to confirm conversion
keys = keys(auto_criticals);
auto_crit_size = sizeof(keys); // Initialize auto_crit_size here
for (i = 0; i < auto_crit_size; i++) {
    message("info", sprintf("Existing critical: %s with value %d", keys[i], auto_criticals[keys[i]]), caster);
}

// Initialize a new mapping to store all criticals
new_auto_criticals = ([]);

// Preserve all existing criticals dynamically
keys = keys(auto_criticals);
auto_crit_size = sizeof(keys); // Ensure auto_crit_size is defined here as well
for (i = 0; i < auto_crit_size; i++) {
    new_auto_criticals[keys[i]] = auto_criticals[keys[i]];
}

// Add or update specific criticals (e.g., "fire B" and "fire C")
new_auto_criticals["fire B"] = ((4 * power) + ench) + caster->query_level();
new_auto_criticals["fire C"] = ((4 * power) + ench) + caster->query_level();

// Debug to confirm the final mapping before setting it
keys = keys(new_auto_criticals);
auto_crit_size = sizeof(keys); // Initialize auto_crit_size again
for (i = 0; i < auto_crit_size; ++i) {
    message("info", sprintf("Final critical: %s with value %d", keys[i], new_auto_criticals[keys[i]]), caster);
}

// Set the updated mapping back to the object
at->set_auto_critical(new_auto_criticals);
//E2

   // auto_criticals = auto_criticals[i];

    //auto_criticals["fire B"] = ((4 * power) + ench) + caster->query_level();
   // auto_criticals["impact B"] = ((4 * power) + ench) + caster->query_level();
//auto_criticals += ({"fire B" : 10, "impact B" : 10,});
//at->set_auto_critical(auto_criticals);
//END

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
