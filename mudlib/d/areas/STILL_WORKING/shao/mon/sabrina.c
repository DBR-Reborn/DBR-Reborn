#include <shao.h>
inherit "/std/npc_shop";

void init(){
::init();
add_action("check_out","check");
add_action("ask_room","ask");
add_action("give_sab","give");
}

void create() {
object ob;

   ::create();
   set_name("sabrina");
set("id",({"mistress sabrina","shopkeeper","shop keeper","sabrina",
"mistress","cheeks"}));
   add_money("gold", 5000);
   set_level(40);
//She's young, and probably shouldn't be level 40, but 
//she's a shop keeper, and I want to make sure it will
//be DAM hard for a player to kill her.
   set_exp(3000000);
   set_property("enhance criticals", -10);
   set_hp(200000);
   set_max_hp(200000);
set("short","Mistress Sabrina");
   set("long",
"Sabrina is a young female human.\n"
"Her soothing blue eyes, and long flowing blond hair "
"only complement her attractive smile and appealing "
"curves.  Every inch of her 5'1 body is firm and toned, "
"you wish you could check out every inch of her, but you "
"suspect that skinning corpses and crafting leather isn't "
"the only thing her hands are capable of, so you don't "
"want to offend her.\n");
   set_gender("female");
   set_body_type("human");
   set("race", "human");
   set_property("melee damage", ([ "crushing" : 99]));
   set_combat_chance(80);
set_skill("knife",300);
//High knife skill due to fact she is a leather
//crafter and has been useing them since a very young
//age... 
set_property("ambidextry",1);
set_stats("dexterity",250);
set_skill("dual attack",150);
set_skill("stalk",50);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin", "dwarvish",
                "drow", "pix", "treefolk", "vr'krr", "middle-english",
		            "catfolk", "ogryn" }));
set("storage room",PATH+"leather_store");
   set("markup", 60);
set_wielding_limbs( ({"right hand", "left hand"}) );
   set("no sell", 1);
ob = new(ARMOR_PATH+"l_bra");
   ob->move(this_object());
   ob = new("d/damned/virtual/studded-leather-glove.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/studded-leather-glove.armour");
   ob->move(this_object());
ob = new(ARMOR_PATH+"l_thong");
   ob->move(this_object());
ob = new(ARMOR_PATH+"l_boot");
ob->move(this_object());
ob = new(ARMOR_PATH+"l_boot");
ob->move(this_object());
force_me("wear boot on right foot");
force_me("wear boot 2 on left foot");
ob = new(WEAP_PATH+"juggler_knife");
ob->move(this_object());
ob = new(WEAP_PATH+"juggler_knife");
ob->move(this_object());
force_me("wield knife in left hand");
force_me("wield knife 2 in right hand");
force_me("wear bra");
   force_me("wear glove on left hand");
   force_me("wear glove 2 on right hand");
force_me("wear thong");
force_me("speak common");
}
int check_out(string str){

if(this_player()->query_ghost()){
write("You should check your body before you do "
"much of anything else...*cough* casper");
return 1;
}
if(!str){
notify_fail("You know you want to check "
"something... and have a suspicious feeling "
"you want to 'check out her......'\n");
return 0;
}
if(str == "out" || str == "her"){
write("Her beauty leaves you numb, but you "
"manage to gather yourself and come to the conclusion"
" that you want to <check out her> <whatever>");
return 1;
}
if(str == "out her"){
write("You think to yourself :\n"
"'WTF do I want to check out???'\n"
"could the words I'm searching for be something "
"like :\n"
"'<check out her eyes> ?\n");
return 1;
}
if(str == "out her eyes"){
write("You quickly glance at her face to face...\n"
"Her eyes are a deep and soothing shade of blue, "
"you could get lost in them for the rest of your life, "
"except you decide you had better look in anther direction "
"before she notices you checking her out...\n"
"you think 'hmmmm her OTHER BODY PARTS are very "
"attractive too!.\n");
return 1;
}
if(str == "out her body"){
write("As non-chalantly as possible you check out her "
"firm and toned body from head to toe...\n"
"\n"
"Her silky soft legs, rock hard stomach, generous "
"and perky chest, and her firm yet shapely ass.");
say("You notice "+this_player()->query_name()+
" checking out Sabrina from head to toe...\n",this_player());
return 1;
}
if(str == "out her legs" || str == "out her soft legs" || str == "out her silky soft legs"){
write(
"Her legs are slender and firm, peeking a bit higher up "
"you can almost amagine how smooth her creamy white thighs"
" would feel...*cough* on either side of your face...\n");
say(this_player()->query_name()+" was just checking "
"out Sabrina's legs...",this_player());
return 1;
}
if(str == "out her pussy" || str == "out her mound" || str == "out her bush" ||
str == "out her crotch" || str == "out her clit" || str == "out her beaver" ||
str == "out her sntatch" || str == "out her box"){
if(this_player()->query_name()=="hood"){
write("You glance down between her legs, and begin to "
"dream up perverted little fantasies...");
say(this_player()->query_name()+" was just "
"looking at Sabrina's crotch... what a pervert!",
this_player());
force_me("look at hood");
force_me("say and what do you think your looking at?");
force_me("smirk hood");
force_me("drop thong");
force_me("say Hood, why don't you come into the back room "
"and have a better look...\n");
return 1;
}
write("You glance down between her legs, and begin to "
"dream up perverted little fantasies...");
say(this_player()->query_name()+"'s eys are looking "
"right between Sabrina's legs at her crotch... what a pervert",
this_player());
force_me("slap "+this_player()->query_name());
force_me("say What the fuck do you think your looking at??!!");
force_me("say well honey, you'll have a good view "+
"in a few seconds... FROM THE FLOOR!");
force_me("yell I'm going to skin you alive "+this_player()->query_name());
force_me("kill "+this_player()->query_name());
force_me("tell hood "+this_player()->query_name()+" is about to die");
return 1;
}
if(str == "out her butt" || str == "out her ass" ||
str == "out her behind" || str == "out her tush" ||
str == "out her bottom"||str=="out her cheeks"){
write("two perfectly firm cheeks, truely a butt "
"to admire.  She even has a small tattoo on one cheek...\n");
say(this_player()->query_name()+" was just TOTALY "
"checking out Sabrina's ass!  What a pervert..."
"actually he does seem to have nice taste.\n",this_player());
return 1;
}
if(str == "out her tattoo"){
write("You squint a bit, but aren't able to "
"read her tattoo while she is wearing her thong.\n"
"\n"
"...if only you knew a way to make her remove it...");
say("You notice "+this_player()->query_name()+
" staring at Sabrina's butt.\n");
force_me("say ummmm what are you doing?");
force_me("ponder");
force_me("say where you trying to read my tattoo?");
force_me("say well I'll tell you right now, if you\n"+
"want to see my tattoo, I'll have to pull my thong\n"+
"down so you can read it.  That will cost you\n"+
"500 gold...\n");
force_me("say if you want to see it, just 'give 500 gold to sabrina'");
return 1;
}
}
int give_sab(string str){
if(!str){
notify_fail("give what to who??");
return 0;
}
if(str == "500 gold to sabrina"){
if(this_player()->query_money("gold")>499){
this_player()->add_money("gold", -500);
write("You give 500 gold to Sabrina.");
force_me("nod "+this_player()->query_name());
write("Sabrina turns to face away from you and bends over.\n"
"She reaches behind and lowers her thong, giving "
"you a perfect view of her bare ass...\n"
"You also have a perfect view of her tattoo wich reads:\n"
"'sex me up'\n");
return 1;
}
}
}

int ask_room(string str){
if(!str){
notify_fail("ask <who> about <what>?");
return 0;
}
if(str == "sabrina"){
write("Ask sabrina ABOUT what?");
return 1;
}
if(str == "sabrina about" || str == "about"){
write("You think that maybe what your trying to "
"do is 'ask sabrina about <topic>'");
return 1;
}
if(str == "sabrina about the back room"||
str == "sabrina about back room"||
str == "sabrina about south room"){
force_me("whisper "+this_player()->query_name()+
" ohhh the back room");
return 1;
}
}
int query_num_rounds() { return 3; }

string query_element() { return "vacid"; }
