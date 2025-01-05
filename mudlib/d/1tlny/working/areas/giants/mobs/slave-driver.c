// This dude is gona have a damn whip as soon as I
// code it, oh and some other gear too...
// And some skills too...

#include <std.h>
#include <giants_paths.h>
inherit MONSTER;

void create() {
       string var;
       int HPBASE, LEV;
       object ob;

       HPBASE = 100;

       ::create();
       seteuid(geteuid());
       set_name("slave-driver");
       set("id", ({"slave-driver", "slave driver", "driver" }) );
       set_languages( ({ "common" }) );
       set_level(10 + random(4));
       switch(random(3)) {
               case 0: var = "A muscular slave-driver"; break;
               case 1: var = "A greater-orc slave driver"; break;
               case 2: var = "A huge slave-driver"; break;
       }
       this_object()->set("short", var);
       set("long", @EndText
This is one of the feared quarry slave-drivers.
With a strong voice and a whip, he commands the
slaves when they work.
EndText
);
       this_object()->set("race", "greater-orc");
       set_gender("male");
       set_body_type("human");
       set_wielding_limbs( ({"right hand", "left hand"}) );
       set_class("fighter");
       
       set_hp(HPBASE * (int)this_player()->query_level());
       set_max_hp(HPBASE * (int)this_player()->query_level());
       
       LEV = (int)this_player()->query_level();
       set_skill("flail", LEV*9);
       set_skill("blade", LEV*9);
       set_skill("dual attack", LEV*7);
       set_skill("offhand training", LEV*7);
       set_skill("resist stun", LEV*4);
       set_skill("attack", LEV*8);
       set_skill("dodge", LEV*7);
       set_skill("parry", LEV*8);
       set_skill("reverse stroke", LEV*5);
       set_skill("perception", LEV*8);
       set_skill("melee", LEV*7);
       
       set("aggressive", 0);
       set("gang bang", 1);
       ob = new(MOBS_PATH+"whip.c");
       ob -> move(this_object());
       command("wield whip in right hand");
       ob = new("/d/damned/virtual/short-sword_5.weapon");
       ob -> move(this_object());
       command("wield sword in left hand");
       ob = new("/d/damned/virtual/leather-pants.armour");
       ob -> move(this_object());
       command("wear pants");
       ob = new("/d/damned/virtual/leather-jacket.armour");
       ob -> move(this_object());
       command("wear jacket");
       ob = new("/d/damned/virtual/leather-bracer.armour");
       ob -> move(this_object());
       ob = new("/d/damned/virtual/leather-bracer.armour");
       ob -> move(this_object());
       command("wear bracer on right arm");
       command("wear bracer 2 on left arm");

       set_emotes(1, ({
"A slave-driver yells at one of the slaves for not working hard enough.",
"A slave-driver grunts.",
"A slave driver lets his whip smash above the head of a slave to inspire him to work more" }), 0 );
}

void catch_tell(string str) {
       string a;
       if(sscanf(str, "%sattacks Slave!", a) == 1) {
               call_out("kill_them", 1, a);
               return;
       }
}

void kill_them(string who) {
       force_me("speak common");
       force_me("say Noone kills my slaves, prepare to meet your doom!");
       force_me("grin "+CAP(who));
       force_me("kill "+who);
       return;
}

int chk_my_mob() {
       return 1;
}

