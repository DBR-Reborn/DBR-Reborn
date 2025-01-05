//      Be afraid... be VERY afraid...
//                    Written by Aladriel
//             And some stuff and junk........
// Initially written by Aladriel, made cool by TW


#include <std.h>
#define MAXBULLETS 7

inherit OBJECT;

string name;
int ammo;
int maxclip=MAXBULLETS;

void init()
{
  ::init();
    add_action("aiming", "aim");
    add_action("shoot","fire");
    add_action("reload","reload");
}

void create()
{
  ::create();
  ammo=MAXBULLETS;
  set_name("gun");
  set_id( ({ "gun", "handgun"}) );
  set_long(
      "Made of some unknown black metal, this gun is both stylish and effective.\n Directions:\n aim <blah> \n fire \n reload");
  set_short("a semi-automatic handgun");
}

int aiming(string str)
{
  object tp=this_player();
  object vic;
 if (!str)
  {
    message("my_message","Who do you wish to aim at?",tp);
    return 1;
  }



  if (!present(str, environment(this_player())))
  {
    message("my_message","You don't see that player here.\n",tp);
    return 1;
  }

  vic=find_living(str);

  name=str;
  message("other_message","%^BOLD%^%^RED%^A big red dot appears "
          "on "+(string)vic->query_cap_name()+"'s forehead.\n",
          environment(vic));

  return 1;
}

int shoot(string str)
{
  object tp=this_player();
  object vic;

  if (!str)
  {
    message("my_message","Who do you wish to fire at?",tp);
    return 1;
  }

  if(str != name)
  {
    write("You're not aiming at them.");
    return 1;
  }

  vic=find_living(str);

  if(!present(str, environment(this_player())))
  {
    write("That person is not here with you.");
    return 1;
  }

  if(ammo==0)
  {
    write("Your gun goes click - you're out of ammo.");
    message("local_message",""+(string)tp->query_cap_name()+"'s gun goes click - it's empty!",environment(tp),tp);
    return 1;
  }

  message("my_message","You pull the trigger and in slow motion, the bullet flies into "+(string)vic->query_cap_name()+"'s chest!",tp);
  message("local_message",""+(string)tp->query_cap_name()+" fires a round into "+(string)vic->query_cap_name()+"'s chest!",environment(tp),tp);
   vic->add_hp(-100);
   ammo--;
   return 1;
}

int reload(string str)
{
  if(!str){
    write("Reload what?");
    return 1;
  }
  else {
    write("You eject the old clip and jam a new one in!");
message("local_message",""+(string)this_player()->query_cap_name()+" ejects his magazine, and slaps a fresh clip into his gun!",environment(this_player()),this_player());
    ammo=MAXBULLETS;
    return 1;
  }
  return 1;
}
