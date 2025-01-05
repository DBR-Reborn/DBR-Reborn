//  Wizard:   Khojem
//  Monster:  Wood-Elf Vixen
//  File:     whore.c
//  Modified by Tailwind for the New Shards Area.

#include <std.h>

inherit MONSTER;

varargs void say_this(string str, object whom);

void init() {
  ::init();
  add_action("go_feel","screw");
  add_action("go_feel","fuck");
  add_action("go_feel","caress");
  add_action("go_feel","do");
  add_action("do_look","look");
}
 
void create() {
  object money;
  ::create();
    set_name("prostitute");
    set_id( ({ "prostitute", "whore", "hooker" }) );
    set_level(20);
    set_short("A prostitute standing near the bed");
    set_long(@TEXT
Standing before you is a young woman. She wears a tiny blouse, exposing a large portion of her cleavage and midriff, and an even smaller miniskirt, revealing long, shapely legs. You'd be very surprised if she was wearing anything under it. You do know that she would be willing to give you sex galore for a relatively small price.
TEXT);
    set("race", "human");
    set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_wimpy(50);
    set_alignment(-100);
    set_languages(({"common", "elvish", "drow", "middle-english" }));
    set_emotes(1, ({
          "The prostitute looks at you hungrily.",
          "The whore licks you.",
          "The hooker gives you a back rub.",
          "The prostitute looks at you and slowly caresses her lips with her tongue.",
        }),0);

    set_speech(1,"common",({ 
          "Oh!  You're just what I've been waiting for!",
          "Come on inside.",
          "Give it to me, baby.",
        }),0);
}

varargs void say_this(string str, object whom) {
    string your_lang;

  if(objectp(whom))
    your_lang = (string)whom->query_primary_lang();
  if(your_lang && stringp(your_lang) &&
    (int)this_object()->query_lang_prof(your_lang)
      >= 8) force_me("speak "+your_lang);
  else force_me("speak common");
  force_me("say "+str);
  return;
}
int do_look(string str) {
  if(str=="blouse"){
    write(@TEXT
This is a jet black top. It is fashioned from leather, and hides very little of her massive tits. The whore notices your interest in her, and walks over to you. Smirking an evil little smirk, she takes one of your hands, and places it on her exposed breast, and begins to make you rub it. They are firm, and you know they would be a treat in some situations. The whore looks down at your crotch, and her smirk gets bigger. "I can see you enjoyed that - for 50 mithril, you can get much, much more."
TEXT);
      say(this_player()->query_cap_name()+" admires the dancer's "+
        "lingerie.\n");
    return 1;
}
if(str=="skirt"){
    write(@TEXT
You take a close look at the hooker's skirt. It, like the blouse, is made of leather, and is jet black. It hides pratically nothing, which is a good thing - the whore's lightly tanned legs are a sight to behold. The prostitute realizes you are checking her out, and drops the skirt, revealing a pair of skimpy panties. "And it only gets better, baby," she laughs, as she pulls her skirt back on.
TEXT);
      say(this_player()->query_cap_name()+" admires the dancer's "+
        "lingerie.\n");
     return 1;
    }

  return 0;
} 

int go_feel(string str){
  int flag, amt, steal_amt;
   
  flag = 0;
  switch(str){
    case "prostitute"   : flag=1; break;
    case "whore"   : flag=1; break; 
    case "hooker"   : flag=1; break;    
    case "breast"  : flag=1; break; 
    case "butt"    : flag=1; break; 
    case "legs"    : flag=1; break;
    case "pussy"    : flag=1; break;
    default        :  return 0;
  }
  if(flag) {
    steal_amt = (50) * -1;
    amt = ((int)this_player()->query_money("mithril") - steal_amt);

    if(this_player()->query_gender()=="female" ) {
      write("The whore tells you: I don't do women, honey. \n");
       return 1;
    }

    if(amt < 0) {
      write("That's not enough, buddy, she says. Come back when you have 50 mithril coins. \n");
      say(" "+this_player()->query_cap_name()+" is told he doesn't have enough money by the whore. \n");
      return 1;
    }
    write(@TEXT
The whore smiles as you hand her your money. "Let's see what kind of wood you've got, big boy."

She guides you over to the bed, and motions for you to lay on it. You do.

With experience far and above anything you've ever seen, she takes off your clothing, and leaves it on the floor. You gawk in amazement as she removes her top, revealing her huge breasts. Her skirt falls to the floor, as if on its own volition.

She jumps on the bed, clad only in bra and panties, and rolls on top of you. She grins, and gives you a light kiss on the lips. She continues to do this down your chest, until she gets to your (somewhat small) cock, and pushes it inside her mouth.

She spends a few minutes sucking, and soon, you've gotten a full erection. She puts her face out of your groin, laughs, and goes, "Lemme give you something you'll like even more, sexy." She slips out of her bra and panties, revealing everything in its full glory.

Grabbing your chest, she shoves herself forward. She eases backwards, pushing you inside of her.

She moans, and the two of you go at it for a long time. Finally, when you are obviously tired and out of stamina, she disengages. She looks just as fresh as when she started.

"Not bad, big boy." The two of you dress again, and she returns to her position near the bed, waiting for her next customer.
TEXT);
    say("The whore goes at it with "+this_player()->query_cap_name()+" .");
    this_player()->add_money("mithril",steal_amt);
    if(!random(50)) {
      write("Your wallet feels a little lighter. Odd."); 
      say("You notice the prostitute palm something from "+
      " "+this_player()->query_cap_name()+" wallet. ");
    }
    return 1;
  }
}
