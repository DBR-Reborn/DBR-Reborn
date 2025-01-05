#include <colors.h>
inherit "/std/glen/undead/base_undead";

object pr_room;

void create() {
    ::create();
    set_change_ownership(0);
    set_combat_chance(160);
    set_can_change_aggr(1);
    return;
}

void copy_body(object ob){
    string *skills;
    int i;

    ::copy_body(ob);
    undead_data["name"] = "skeletal warrior";
    undead_data["ids"] = undead_data["ids"] + ({ "skeletal warrior" });

}

void setup_body(){
    ::setup_body();
    set_property("enhance criticals",
      query_property("enhance criticals") / 2);
    set_max_hp(query_max_hp() * 1 / 4);
    set_hp(query_max_hp());
    set_overall_ac(query_overall_ac() / 4);
    set_skill("melee",
      query_skill("melee") * 3 / 2);
}

int query_num_rounds(){
    int x;
    x = ::query_num_rounds();
    x += 2;
    return x;
}

void reform(){
    move(pr_room);
    message("info", CBOLD + CRED + 
      query_short() + " reforms from dust.",
      all_inventory(environment(this_object())),
      this_object());
}

void die(){
    if(random(100) > 92){
	::die();
	return;
    }
    new_body();
    set_hp(query_max_hp());
    set_mp(query_max_mp());
    pr_room = environment(this_object());
    message("info", CBOLD + CRED + 
      query_short() + " crumbles to dust.",
      all_inventory(environment(this_object())),
      this_object());
    move("/std/glen/rooms/undead_cell");
    call_out("reform", random(query_level()));
}

string query_short(){
    return "Skeletal Warrior of " +undead_data["short"];
}


