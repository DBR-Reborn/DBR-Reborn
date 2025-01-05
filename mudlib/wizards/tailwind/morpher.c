// Stoney's morphing mask
// original idea by Helios
// Modded by Tailwind
inherit "std/armour";

void create() {
::create();
set_name("lucky charm");
set("id",({"charm","morpher","lucky charm","trinket"}) );
set("short","a lucky charm");
set("long","Nothing but a golden trinket, you can sense that this lucky charm is indeed very lucky. Try 'morph'ing with it.");
set_type("helmet");
set_material("metal/gold");
set_ac(25);
set_limbs( ({"right hand"}) );
set_weight(25);
set_value(0);

}

void init() {
    ::init();
    add_action("do_morph","morph");
}

int do_morph(string str) {

    object caster,ob;
caster = this_player();
    if(!str) return 0;
message("info","You transform into "+str+".", caster);
  ob = new("/std/spells/shadows/a_trans_shadow");
message("info","%^BOLD%^%^CYAN%^"+(string)caster->query_cap_name()+" transforms into a "+str+".", environment(caster), caster);
    ob->set_new_short(str);
    ob->set_new_cap(str);
    ob->start_shadow(caster, 300000000, "%^BOLD%^%^RED%^The mask goes back "
    "to being shaped like nothing as the changeling flesh "
    "settles.");

return 1;
}
