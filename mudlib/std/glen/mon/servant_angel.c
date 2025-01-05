#include <std.h>
#include <colors.h>

inherit MONSTER;

string EXIT_DIR = "north";
string guild = "tinker";
int has_hb = 0;
int interval = 12;
int pow = 3;

int is_servant_object() { return 1;}

create() {
    ::create();
    set_name("angel");
    set_id( ({ "angel"}) );
    set_short("A humble servant angel");
    set("race", "seraphim");
    set_long(
            "The angel graces you with its mere presence here.");
    set_body_type("winged-humanoid");
    set_level(38);
}

void init() {
    object ob;
    ::init();
    if (!has_hb) {
        has_hb = 1;
        set_max_hp(query_max_hp() * pow+4);
        set_hp(query_max_hp());
        ob = new("/std/spells/shadows/ele_pres_shad");
        ob->set_power(10);
        ob->set_damage(({"holy","holy","holy"}));
        ob->start_shadow(this_object(), 0, "");
        call_out("heal_us", 4);
    }
    return;
}

void set_up(int power){
    pow = power;
    if(pow > 10)
        pow = 10;
    set_level(this_player()->query_level());
}

void set_dur(int dur) {
    call_out("remove_servant", dur);
    return;
}

void remove_servant() {
    object ob;
    message("info", CBOLD + 
            "The noble angel goes on its way.",
            environment());
    remove();
}

int query_flying() { return 1;}

int query_num_rounds(){
    return -40;
}

int living_filter(object who) { return living(who);}

int heal_us() {
    object *inv;
    int i, x;

    call_out("heal_us", 12-pow + random(pow/2));

    inv = filter_array(all_inventory(environment()), "living_filter",
                       this_object());

    for (i = 0; i < sizeof(inv); i++) {
        if (inv[i]->query_hp() < inv[i]->query_max_hp() ||
            inv[i]->query_mp() < inv[i]->query_max_mp()) {
            message("info", CBOLD + "The angel heals you.", inv[i]);
            inv[i]->do_healing((int)inv[i]->calculate_healing());
        }
        if (inv[i]->query_poisoning() > 1) {
            message("info", CBOLD + "The angel removes your poisoning.", inv[i]);
            inv[i]->add_poisoning(-1*inv[i]->query_poisoning()/4);
        }
        if (inv[i]->query_property("bleeding") > 1) {
            message("info", CBOLD + "The angel removes your wounds.", inv[i]);
            inv[i]->set_property("bleeding",inv[i]->query_property("bleeding")/4);
        }
    }
}

