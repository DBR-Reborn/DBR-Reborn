inherit "/std/weapon";

void create() {
    ::create();
    set("id", ({ "star", "star of k'thach", "k'thach star", "morning-star of k'thach" }));
    set_name("star");
    set("short", "The %^BOLD%^%^YELLOW%^Morning-Star%^RESET%^ of %^BOLD%^%^CYAN%^K'thach%^RESET%^");
    set("long", "This is a truly impressive morning-star. The shaft is gold and encrusted with jewels. The star, which is surprisingly light despite its big diameter and huge spikes, it reflects the sun brilliantly.");
    set_weight(70);
    set_type("two handed flail");
    set_material("blessed laen");
    set_ac(15);
    set_parry_bonus(5);
    set_property("no save", 1);
    set_quality(4);
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_decay_rate(1500);
    set_value(0);
    set_wield( (: call_other, this_object(), "wield_star" :) );
    set_verb("immolate");
}

int wield_star() {

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

