//    by Glen
//    derived from diewarzaus spell scroll

#include <colors.h>
#include <daemons.h>

inherit WEAPON;

string spell;
int spell_pow;
static object ele_shad;
static object skill_shad;

int create_skill = 50;

void set_create_skill(int x){
    create_skill = x;
}
int query_create_skill(){ return create_skill; }

void create() {
    ::create();
    spell = 0;
    spell_pow = 0;
    ele_shad = 0;
    set_long("Thisvial of acid of acid was meant to be thrown "+
      "at foes.");
    set_short("A vial of acid");
    set_id(({ "vial", "acid vial", "acid", "alch acid" }));
    set_name("vial");
    set_weight(2);
    set_value(0);
    set_throwable(1);
    return;
}


string query_short(){ return "A vial of acid"; }

void set_spell(string sp, int pow) {
    spell = sp;
    spell_pow = pow;
    return;
}

void do_thrown(object from, object at){
    int x;
    message("info",
      CBOLD + "SPLASH " + CRESET +
      at->query_name() + " is hit with a vial of acid, "+
      "screams of pain follow as his flesh burns and melts.",
      all_inventory(environment(from)), ({ at, from }));
    message("info",
      CBOLD + "SPLASH " + CRESET +
      from->query_name() + " hit you with a vial of acid, "+
      "your flesh is melting off!",
      at, from);
    message("info",
      CBOLD + "SPLASH " + CRESET +
      "The acid vial hit " + at->query_name(),
      from, at);
    DAMAGE_D->init_cont_damage(at, create_skill / 10 + 1, create_skill,
      "%^MAGENTA%^The acid burns you!");
    x = at->query_property("bleeding");
    x += create_skill / 4;
    at->set_property("bleeding", x);
    remove();
}

int __Wield(string str){
  string what, hand1;
  if(sscanf(str, "%s in %s", what, hand1) ==2 && (what == "vial" || what=="acid vial" || what=="acid")){
    write("You can't wield vials of acid.");
    return 1;
  }
  else
    ::__Wield(str);
}
