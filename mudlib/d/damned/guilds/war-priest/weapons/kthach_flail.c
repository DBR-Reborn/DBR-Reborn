inherit "/std/weapon";

void create() {
    ::create();
    set("id", ({ "flail", "flail of faith", "faith flail", "footman's-flail of faith" }));
    set_name("flail");
    set("short", "The %^BOLD%^%^YELLOW%^Footman's-Flail%^RESET%^ of %^BOLD%^%^CYAN%^K'thach%^RESET%^");
    set("long", "This is a truly impressive footman's-flail. The shaft is gold and encrusted with jewels. The flail, which is surprisingly light despite its 2 foot length, reflects the sun brilliantly.");
    set_weight(70);
    set_type("flail");
    set_material("blessed laen");
    set_ac(15);
    set_parry_bonus(5);
    set_property("no save", 1);
    set_quality(4);
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_decay_rate(1500);
    set_value(0);
    set_wield( (: call_other, this_object(), "wield_flail" :) );
    set_verb("immolate");
}

int wield_flail() {

   if(this_player()->is_player() && (int)this_player()->query_level() < 19) {
     write("%^BOLD%^%^CYAN%^Only War-Priests of level 19 or higher may use this holy weapon.");
    return 0;
}

   if((string)this_player()->query_class() != "war-priest") {
      write("%^BOLD%^%^CYAN%^Only War-Priests may use this holy weapon.");
    return 0;
  }
return 1;
}

