#include <colors.h>
inherit "/std/glen/undead/base_undead";

object pr_room;

void create() {
    ::create();
    set_change_ownership(0);
    set_combat_chance(220);
    set_can_change_aggr(1);
    return;
}

void copy_body(object ob){
    string *skills;
    int i;

    ::copy_body(ob);
    undead_data["name"] = "skeletal lord";
    undead_data["ids"] = undead_data["ids"] 
    + ({ "skeletal lord", "lord" });

}

void setup_body(){
    mapping md;
    string  *mdk;
    int     i = 0;
    int     total;
    ::setup_body();
    set_property("enhance criticals",
      query_property("enhance criticals") - 2);
    set_overall_ac(query_overall_ac() * 4 / 3);
    set_skill("melee",
      query_skill("melee") * 5 / 2);
    set_skill("attack",
      query_skill("attack") * 2);

    md = query_property("melee damage");
    mdk = keys(md);
    for(i = 0; i < sizeof(mdk); i++){
	md[mdk[i]] = md[mdk[i]] * 2;
	total += md[mdk[i]];
    }
    md["cold"] = total / sizeof(mdk);
    md["cutting"] = total;
}

int query_num_rounds(){
    int x;
    x = ::query_num_rounds();
    x += 5;
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
    if(random(100) > 85){
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
    call_out("reform", query_level() + random(query_level()));
}

string query_short(){
    return "Skeletal Lord of " +undead_data["short"];
}


