#include <std.h>
#include <shao.h>

inherit ROOM;

void init(){
::init();
call_out("case_one",4);
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
set("short","On top of some crates");
set("long","You now stand on top of an old crate"+
" while you peep in the window.\n");
add_exit(PATH+"can1","down");
add_pre_exit_function("down","go_down");
}

int go_down(){
remove_call_out("case_one");
remove_call_out("case_two");
remove_call_out("case_three");
remove_call_out("case_four");
return 1;
}
void case_one(){
write("%^CYAN%^You almost let out a small yelp as you "+
"realize what you are peeking in on....\n");
remove_call_out("case_one");
call_out("case_two",4);
}

void case_two(){
write("%^CYAN%^A young attractive woman is standing "+
"in a large iron bathing tub.....\n");
remove_call_out("case_two");
call_out("case_three",4);
}

void case_three(){
write("%^CYAN%^and she's %^RESET%^%^BOLD%^%^YELLOW%^NAKED!%^RESET%^.\n");
remove_call_out("case_three");
call_out("case_four",3);
}

void case_four(){
write("%^CYAN%^You notice the soapy water in the "+
"bathing tub, and also notice the many "+
"foamy soap suds running down her soft wet skin. "
"You decide in your great wisdom she must be "
"taking a bath....\n");
remove_call_out("case_four");
call_out("case_5", 7);
}

void case_5(){
write("%^CYAN%^From head to toe she is a gift "
"from the Gods.  Her long blond hair flows down "+
"to the small of her back and rests just above "+
"her firm, creamy white bottom.\n");
remove_call_out("case_5");
call_out("case_6",11);
}

void case_6(){
write("%^CYAN%^some soapy bubbles slide down her buttocks "+
"and down the backs of her legs....\n");
remove_call_out("case_6");
call_out("case_7",4);
}

void case_7(){
write("%^CYAN%^As she gracefully caresses her upper body "+
"with a washcloth, she turns to face in your direction.\n");
remove_call_out("case_7");
call_out("case_8",4);
}

void case_8(){
write("%^CYAN%^Now that you can see her face you realize "+
"who you've been watching!  It's Mistress Sabrina, "+
"the shop keeper that runs the house of leather.\n");
remove_call_out("case_8");
call_out("case_9",5);
}

void case_9(){
write("%^CYAN%^As Sabrina rubs the soapy cloth across her "
"tender breasts you notice some sort of mark over one "
"of her sensitive pink nipples....\n");
remove_call_out("case_9");
call_out("case_10",8);
}

void case_10(){
write("%^CYAN%^It looks like a small tattoo...\n"+
"... yes... it is a tattoo of the word "+
"%^YELLOW%^SHADOW%^RESET%^%^CYAN%^.\n"+
"hmmm what could that mean?... an old boyfriend, lover.."+
"or maybe a 'secret password....\n");
remove_call_out("case_10");
call_out("case_11",11);
}

void case_11(){
write("%^CYAN%^As your pondering the meaning "+
"of Sabrina's tattoo you notice her continuing to "
"wash herself...\n"+
"Her hand has moved from her upper body and has "+
"lathered up her well defined abdominals, her hand "
"is now slowly moving....\n");
remove_call_out("case_11");
call_out("case_12", 6);
}

void case_12(){
write("%^CYAN%^.... down between her baby smooth"+
" thighs....");
remove_call_out("case_12");
call_out("ur_busted",6);
}

void ur_busted(){
write("%^RED%^%^BOLD%^City Guard Yells: %^RESET%^%^BOLD%^'"
"Now I got you, ya little peeping pervert!\n"
"Off to the jail with ya mortal....\n");
this_player()->set_paralyzed(100);
this_player()->move_player(PATH+"cell1");
remove_call_out("ur_busted");
}

