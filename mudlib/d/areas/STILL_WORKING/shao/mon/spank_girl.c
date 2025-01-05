//  Wizard:   Khojem
//  Monster:  Wood-Elf Child
//  File:     child.c

#include <std.h>

inherit MONSTER;

int bent;
int spanked;


void init(){
::init();
add_action("spank_me","spank");
add_action("bend_knee","bend");
}


create() {
    ::create();
    set_name("weretiger girl");
    set_id( ({ "girl","school girl","weretiger","weretiger girl",
	"weretiger school girl" }) );
    set_level(1);
    set_short("weretiger school-girl");
    set_long("This teenaged feline's outfit leads you "
      "to believe she is a geniune school girl.  "
      "Probably enrolled in Shao-tan's school for the "
      "rich, since most citizens of the city are poor "
      "and have children that work and hunt with no time for "
      "school.\n");
    set("race", "weretiger");
    set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 1]));
    set_skill("melee", 2);
    set_skill("dodge", 2);
    set_skill("parry", 2);
    set_wimpy(30);
    set_max_hp(10);
    set_hp(10);
    set_alignment(50);
    set_languages(({ "rachk","common" }));
    set_lang_prof("rachk",10);
    set_lang_prof("common",10);
    set_emotes(5, ({
	"The school girl smiles at you innocently.",
	"The school girl blushes and twirls her hair.",
	"The teenage weretiger lowers her head in embarassment",
	"The school girl rubs her tender back side.",
      }),0);
    set_speech(5,"rachk",({ 
	"I got in touble at school, I've been a naughty girl.",
	"My teacher spanked me, and then sent me home.",
	"I don't like getting spanked..."
      }),0);
}

int bend_knee(string str){
if(!str){
notify_fail("You bend over and kiss your...\n"
"errr maybe you want to 'bend <someone> over your knee'?");
return 0;
}
if(!spanked){
if(str == "girl" || str == "school girl" || str ==
"weretiger school girl" || str == "weretiger girl") {
notify_fail("bend her 'over what?'");
return 0;
}
if(str == "girl over my knee" || str == 
"school girl over my knee" || str == 
"weretiger over my knee" || str ==
"weretiger girl over my knee" || str ==
"weretiger school girl over my knee") {
write("You over power the school girl and "
"with a lot of fuss and a bit of a struggle "
"you manage to get her over your knee.\n");
bent++;
return 1;
}
write("The school girl is suspicious of you, "
"and her stinging bottom provides a constant reminder "
"to stand well out of your reach.\n");
return 1;
}
}
int spank_me(string str){
if(!str) {
notify_fail("You spank your monkey");
return 0;
}
if(str == "girl" || str == "school girl" || str ==
"weretiger school girl" || str == "weretiger girl") {
if(!bent){
write("The school girl dodges your swat.\n"
"You think that maybe you should bend her over "
"your knee first.\n");
return 1;
}
if((string)this_player()->query_cap_name()=="hood") {
write("You swat the school girl's bottom...\n"
"the blow lands with a loud thud.\n"
"the school girl says : 'Ouch! please Mistress Caitlyn "
"no more... I'm sorry for what ever I did...'\n"
"You continue to spank the school girl and after "
"much sobbing and tears you loosen your hold.\n"
"The school girl gets back to her feet and pouts "
"as she wipes her tears.");
return 1;
}
write("You spank the school girl as she "
"kicks, screams and bucks her hips in efforts "
"to get free.  After much sobbing and tears you "
"loosen your grip and let her stand up.  She "
"begins to pout and turns her back to you.\n");
return 1;
}
}
