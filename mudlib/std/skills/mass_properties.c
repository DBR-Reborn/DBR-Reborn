inherit "/std/skills/skill.c";

void create() {
::create();
set_stat("intelligence");
set_dev_cost(11);
set_fast_dev_cost(35);
set_property("target type", "living");
set_property("must be present", 1);
}

void info() {
message("help", "This skill allows an Elemental Mage to query an energy mass for various different properties, including its owner, the lores it possesses, and most importantly the number of energy units remaining for usage casting spells. This skill needs only be trained ONE time, its effectiveness does not increase with higher skill.", this_player());
}

void skill_func(object from, object at, string args) {
if(at->query_name() != "energy mass") {
message("info", "You may only use this skill at an energy mass.", from);
remove();
return;
}
message("info", "Using your abilities, you determine the following from the energy mass:", from);
message("info", "", from);
message("info", "The owner of this mass is: %^BLUE%^"+(string)at->query_property("owner name")+"%^RESET%^", from);
message("info", "The element of %^RED%^"+(string)at->query_property("lore name")+"%^RESET%^ is present in this mass.", from);
if(at->query_property("lore name two") != 0) {
message("info", "The element of %^RED%^"+(string)at->query_property("lore name two")+"%^RESET%^ is present in this mass.", from);
}
if(at->query_property("lore name three") != 0) {
message("info", "The element of %^RED%^"+(string)at->query_property("lore name three")+"%^RESET%^ is present in this mass.", from);
}
if(at->query_property("lore name four") != 0) {
message("info", "The element of %^RED%^"+(string)at->query_property("lore name four")+"%^RESET%^ is present in this mass.", from);
}
message("info", "The mass has %^BOLD%^%^YELLOW%^"+at->query_property("energy units")+"%^RESET%^ energy units remaining.", from);
return;
}
