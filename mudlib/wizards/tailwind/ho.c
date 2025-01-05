//  Wizard:   Khojem
//  Monster:  Wood-Elf Vixen
//  File:     whore.c
//  Modified by Tailwind for the Thieves Guild.

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
    set_level(4);
    set_short("A prostitute standing near the bed");
    set_long(@TEXT
Standing before you is a young woman. She wears a tiny blouse, exposing a large portion of her cleavage and midriff, and an even smaller miniskirt, revealing long, shapely legs. You'd be very surprised if she was wearing anything under it. You do know that she would be willing to give you sex galore for a relatively small price.
TEXT);
    set("race", "high-man");
    set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("melee", 20);
    set_skill("dodge", 20);
    set_stats("dexterity", 90);
    set_stats("intelligence", 100);
    set_skill("perception",70);
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
This is a jet black top. It is fashioned from leather, and hides very little of her massive tits. The whore notices your interest in her, and walks over to you. Smirking an evil little smirk, she takes one of your hands, and places it on her exposed breast, and begins to make you rub it. They are firm, and you know they would be a treat in some situations. The whore looks down at your crotch, and her smirk gets bigger. "I can see you enjoyed that - for 50 gold, you can get much, much more."
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
    amt = ((int)this_player()->query_money("gold") - steal_amt);
    if(amt < 0) {
      write("That's not enough, buddy, she says. Come back when you have 50 gold coins. \n");
      say(" "+this_player()->query_cap_name()+" is told he doesn't have enough money by the whore. \n");
      return 1;
    }
    write(@TEXT
You pay the prostitute, and lie down, waiting for her services.
She smiles. It's an evil little smile, and you can tell she plans on enjoying this little trist immensely.

The first thing that comes off is her blouse. With a rather vicious move, she rips the tiny thing off, revealing a black lacy bra, and her two pale breasts.

Noticing your erection, her smile grows larger.

Next off is the skirt. She unfastens the clasp of the skirt, and lets it fall to the ground in a pale blue pile. Grinning that large evil grin, she jumps atop of you, and begins to grind her groin against yours as hard as she can.

After a bit, she stops, apparently sensing that your now massive erection will not get any larger. The whore moves back a bit. Now sitting on your legs, she undoes your shirt, giving light kisses to your chest when she is done.

Before you know it, your pants are off. You don't even know how she did it with her sitting on top of them, but you know one thing - she's in bra and panties, and you're in nothing but your knickers.

Then, in another glorious moment, she removes her undergarments, giving you a view of the sexiest body you have seen in a long, long time.

You remove your boxers, and wait, expectantly. Oddly enough, she rises, and stands next to the bed.

You get up, wondering what happened. She smirks, and pushes you back onto the bed, flat against your back. It is at that point she bends starts to suck your large penis, moving her tongue all around it, enjoying its taste. You feel a few drops of semen come out, and she drinks them eagerly.


In a second, your thought is answered, as the prostitute puts a hand on each of your shoulders, pushes her self up, and wraps her legs around your waist, shoving your large penis into her vagina as hard as she can.

You flop onto the bed, and begin to screw her with all your might. Her pussy is soft, and her breasts firm. Incredibly, her lithe body is quite strong, and she is able to show you quite a few sexual positions that you weren't even aware were possible, let alone pleasuring.

After twenty minutes of non-stop fucking, she starts to moan, and you feel yourself ejaculate into her. Spewing the sticky white stuff with almost unthinkable strength, your penis dispenses a full load of cum into her. You feel her vaginal cavity fill up with semen. The moans turn into screams off pleasure.

When you finally stop, you pull out, your penis completely flaccid. The girl, completely exhausted, rolls to the side of the bed, and off of it. You follow suit, and the two of you dress.

She whispers in your ear, "Any time, baby. Your cock fits me perfectly." She then resumes to stand in her position by the bed, waiting for another customer. Maybe even you.

TEXT);
    say("The whore goes at it with "+this_player()->query_cap_name()+" .");
    this_player()->add_money("gold",steal_amt);
    if(!random(50)) {
      write("Your wallet feels a little lighter. Odd."); 
      say("You notice the prostitute palm something from "+
      " "+this_player()->query_cap_name()+" wallet. ");
    }
    return 1;
  }
}
