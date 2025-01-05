//           Maxwell's Underground Mud Library
//                    Wolf Guard


#include "/adm/include/std.h"
inherit MONSTER;
object *who_attacked,who2;
int x,i,y,z,t,w;
create() {
    ::create();
   set_name("grey wolf");
   set_id( ({ "wolf"}) );
   set_short("A large grey wolf");
   set_level(40);
   set("long", "The grey wolf looks very strong.");
   set_gender("male");
   set("race", "dog");
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   add_limb("head", "FATAL", 50, 0, 4);
   add_limb("torso", "FATAL", 50, 0, 4);
   add_limb("right leg", "right paw", 35, 0, 4);
   add_limb("right paw", "", 25, 0, 4);
   add_limb("left leg", "left paw", 35, 0, 4);   
   add_limb("left paw ", "", 25, 0, 4);
   add_limb("right rear leg", "right rear paw", 35, 0, 4);
   add_limb("right rear paw", "", 25, 0, 4);
   add_limb("back left leg", "left rear paw", 35, 0, 4);
   add_limb("left rear paw", "", 25, 0, 4);
   set_emotes(10,
     ({ "The wolf growls softly.",
     "The wolf glances at you and drools.",
     "The wolf whines.",
     }),0 );
    set_achats(50,
    ({ "Grey wolf howls!.",
     "Grey wolf snarls!.",
     "Grew wolf bares his teeth!.",
     }) );
   set("aggressive", (: call_other, this_object(), "attack" :) );
   who_attacked = ({});
}
int attack(object who){
   if(who->is_player()) {
    who2  = who;
    call_out("attack2",2,this_player());
   }
return 0;
}
int attack2(){
int y;
    if(present("mikarty")){
//If not attacking anything, do this
  if(y != 1){
    if(this_object()->query_current_attacker() == 0){
      y = 1;
      present("mikarty")->force_me("say Get em' Boy!!");
      tell_room(environment(this_object()),"Mikarty drops the steel "
      "chain.");
      call_out("killer",1,this_object());
      return 1;
    }
  }
//If the wolf is already attacking a player then do this
    present("mikarty")->force_me("say Another one! We are being "
    "invaded!!");
    }
    call_out("killer",2,this_object());    
    return 1;
}
int killer(){
    tell_object(who2,"The wolf leaps for your throat!");
    tell_room(environment(this_object()),"The grey wolf growls and leaps "
   "for "+who2->query_name()+"'s throat.",who2);
    this_object()->force_me("kill "+who2->query_name());
    return 1;
}
void die(object who) {
  object mon,mik,wep1,wep;
  string here;
  here=file_name(environment(this_object()));
  if(present("mikarty")){
     mon=present("mikarty");
     mon->force_me("say You killed my best wolf!");
     mon->force_me("say I shall avenge his death!!");
     switch(random(2)){
      case 0:wep1=new("/wizards/maxwell/objects/weapons/dagger");
             wep1->move(mon);
             wep = wep1->query_name();
             break;
      case 1:wep1=new("/wizards/maxwell/objects/weapons/handaxe");
             wep1->move(mon);
             wep = wep1->query_name();
             break;
     }
//     mon->force_me("throw "+wep+" at "+who->query_name());
//     mon->force_me("kill "+who->query_name());
     i = sizeof(who_attacked);
     x = 0;
     z = i - 1;
    mon->force_me("say The number of values "+sizeof(who_attacked));
  while(x <=z){
    mon->force_me("say Player "+x+" is "
    +who_attacked[x]->query_name());
//If the number of attackers is greater than 1
  if(i > 1){
//   If this is the name of the first attacker
     if(x == 0){
        mon->force_me("say You helped kill my wolf "
        +who_attacked[x]->query_name()+"!!");
     }
//   If this is not the first attacker
     if(x != 0){
//      if this attacker is not equal to the one before
        y = x - 1;
        if(who_attacked[x] != who_attacked[y]){
          switch(random(2)){
             case 0:mon->force_me("say You are resposible for this "
             +who_attacked[x]->query_name()+"!!");
             break;
             case 1:mon->force_me("say I blame you "
             +who_attacked[x]->query_name()+" for his death!!");
             break;
//        Switch end
          }
//      Same Attacker Check End
        }          
//   End of If player is not in position 0 of the array
     }
// End of If there are more than one attackers
  }
//if there is only one attacker  
  if(i == 1){
      mon->force_me("say You are the only one to blame for his death "
      +who_attacked[x]->query_name()+"!!");
  }
//Increase the value of x by 1
  x = x + 1;
//End of While()
  }
 ::die(who);
 return;
//End of present Mikarty Code
  }
//End of WOlf Die Code
}
void kill_ob(object who,int i) {
	::kill_ob(who,i);
	who_attacked += ({who});
}




