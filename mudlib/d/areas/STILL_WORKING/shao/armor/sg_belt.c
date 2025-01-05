//  Wizard:  Khojem
//  Leather Belt
//  leather_belt.c

#include <shao.h>
inherit "/std/armour";

void init(){
::init();
add_action("look_buckle","look");
}
void create() {
    ::create();
    set_name("leather belt");
set("id", ({"shao-tan guards belt","belt","leather belt"}) );
    set("short", "a leather belt");
set("long", "A black leather belt.\n"
"The brass belt buckle has a symbol molded onto it.\n");
    set_weight(20);
    set_value(3);
    set_type("belt");
    set_ac(5);
        set_ac(0, "aether");
        set_ac(0, "depression");
        set_ac(1, "acid");
        set_ac(1, "vacuum");
        set_ac(2, "fire");
        set_ac(2, "cold");
        set_ac(2, "impact");
        set_ac(1, "stress");
        set_ac(1, "strike");

        set_ac(1, "electricity");
        set_ac(0, "time");
        set_ac(3, "crushing");
        set_ac(1, "disruption");
        set_ac(0, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
    set_material("misc/leather");
    set_limbs( ({ "torso" }) );
}
int look_buckle(string str){

if(!str){
notify_fail("look at what?");
return 0;
}
if(present("shao-tan guards belt", this_player())){
if(str == "buckle" || str == "belt buckle" ||
str == "mithril buckle"){
write("A symbol has been carved into the buckle of this belt...\n");
return 1;
}
if(str == "symbol"){
write(" %^RED%^##########\n"
"%^RED%^##   %^RESET%^BOLD%^**   %^RESET%^%^RED%^##\n"
" %^RED%^## %^RESET%^%^BOLD%^*%^RED%^**%^RESET%^%^BOLD%^* %^RESET%^%^RED%^##\n"
"  %^RED%^## %^RESET%^%^BOLD%^** %^RESET%^%^RED%^##\n"
"   %^RED%^##  ##\n"
"    %^RED%^####\n"
"     %^RED%^##\n");
return 1;
}
else{
return 0;
}
}
}
