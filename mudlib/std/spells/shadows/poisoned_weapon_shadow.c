#include <security.h>

inherit "/std/spells/shadows/weapon_shadow";

int poison_strength = 0;

void set_poison_strength(int x){
    poison_strength = x;
}

int query_poison_strength(){
    return poison_strength;
}

