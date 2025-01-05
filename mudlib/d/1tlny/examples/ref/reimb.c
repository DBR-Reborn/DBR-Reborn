//reimb.c coder:Byon
inherit "/std/weapon";

       create() {
       ::create();
       set_ac(6);
    set("id", ({"dagger", "knife"}));
    set_short("Reimbursement dagger");
    set_long("This blade is given out to people byon feels sorry for.");
    set_type("knife");
    set_quality(6);
    set_material("metal/dextrolite");
    set_property("no decay", 1);
       set_property("no add quality", 1);
       set_property("poisoning", 5);
       set_weight(15);
       set_value(30);
    set_wc(30, "cutting");
      set_property("enchantment", 4);
      set_property("flame blade", 3);
    set_wc(30, "electricity");
    set_wc(30, "fire");
    set_wc(30, "cold");
    set_verb("devastate");
}
