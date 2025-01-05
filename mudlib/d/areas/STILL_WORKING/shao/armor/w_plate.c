//  Wizard:  Khojem
//  rag shirt
//  rag_shirt.c

inherit "/std/armour";

void create() {
    ::create();
set_name("black torso armor");
set("id",({"torso shell","black shell","black torso shell",
"black shell plate", "shell"}) );
set("short","A massive black torso-shell");
set("long","A full torso shell, made from some "
"blackened scorched metal.  The craftsmanship is "
"unsurpassed and it looks almost indestructable.  "
"A large symbol has been carved into an additional "
"metal plate covering the upper chest section of the shell.  "
"Although it appears to offer unsurpassed protection it also"
" looks very heavy.\n");
set_weight(200);
    set_value(1);
    set_type("metal torso");
    set_limbs( ({ "torso", "right arm", "left arm" }) );
set_ac(80);
        set_ac(50, "aether");
        set_ac(50, "depression");
        set_ac(50, "acid");
        set_ac(50, "vacuum");
        set_ac(50, "fire");
        set_ac(50, "cold");
        set_ac(50, "impact");
        set_ac(50, "stress");
        set_ac(50, "strike");
        set_ac(50, "electricity");
        set_ac(50, "time");
        set_ac(50, "crushing");
        set_ac(50, "disruption");
        set_ac(50, "holy");
        set_ac(50, "plasma");
        set_ac(50, "infernal");
set_material("metal/mithril");
}
