inherit OBJECT;

void create() {
    ::create();
    set_name("morphing orb");
    set("id",({"morphing orb","orb"}) );
    set("short","a morphing orb");
    set("long","Rub the orb and make a wish to be me.");
    set_value(0);
}

void init() {
    ::init();
    add_action("do_morph","morph");
}

int do_morph(string str) {
    object caster,ob;
    caster = this_player();
    if(!str){ 
	this_player()->remove_shadow();
	message("info","You remove a mask.", caster);
	return 1;}
    this_player()->remove_shadow();
    message("info","You transform into "+str+".", caster);
    ob = new("/std/spells/shadows/a_trans_shadow");
    ob->set_new_short(str);
    ob->set_new_cap(str);
    ob->start_shadow(caster, 0, "");
    return 1;
}

