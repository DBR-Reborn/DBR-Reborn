//  Wizard:  Khojem
//  Mahogany Ring
//  mahogany_ring.c

inherit "/std/armour";

object shadow;

void create() {
    ::create();
set_name("ring");
set("short", "Shao-tan signet ring");
set("long","This strange black ring is made out of"
" an odd materal.  It has a symbol carved into the "
"top of it...\n"
"...a symbol you've seen someplace before.\n");
    set("id", ({ "ring", "Shao-tan signet ring" }) );
    set_weight(5);
    set("value", 2000);
    set_type("ring");
    set_limbs( ({ "right hand", "left hand" }) );
    set_ac(1);
    set_wear( (: call_other, this_object(), "extra_worn" :) );
    set_remove( (: call_other, this_object(), "extra_remove" :) );
set_material("misc/Onyx");
}

int extra_worn(){
  shadow=clone_object("/wizards/khojem/new/shadow/strength2");
  shadow->start_shadow(this_player());
  return 1;
}

int extra_remove(){
  shadow->external_destruct(shadow);
  return 1;
}
