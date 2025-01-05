/*  HONSPRON 2020
A basement to add bounty’s.
Still Needs work... I can list bounty, but can not add.
*/
//#include "../../daybreak.h"
//#include <std.h>

#define FILE_NAME "/d/damned/data/bounty_list"
#include <security.h>
#include <dirs.h>
#include <clock.h>


inherit "/std/room";

void claim(object killer, object victim);
void bounty_exp(object killer,object victim);
int bounty(string str);
string find_bounty(string nom);
int pay(int amt, string nom, object killer);
string mudtime(int time_sec);


void create() {
	
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  add_exit("d/daybreak/room/shop/tavern", "up");
  set_short("The gold Lion Tavern basement");
  set("long",
  "This is the basement of The Silver Lion Tavern "
  "benches and tables and a bar at the back of the room.  "
  "The room is lit by a few lanterns which hang from the "
  "walls.  Several shady patrons wander about, completely drunk. "
  "You see a shadowy figure in the corner of the room.");
    set_items(
        (["benches":"They are sturdy and are fashioned of wood.",
          "lanterns" : "They are high-quality, but sadly, they look permanently attached.",
          "patrons" : "Several glare at you making you feel uneasy." ]) );

this_object()->reset();
  return;
}



void init() {
    ::init();
    add_action("bounty","bounty");
}


/* Bounty Function - Adds the ability to set and review bounties.
 * Shadowraith 9/26/96
 */
 
// bounty system cleaned and made more user friendly
// Excelsior 9-29-96

void bounty_exp(object killer, object victim) {
   int lvl,exp;
   lvl = victim->query_level();
   switch(lvl) {
     case 1..5: exp=lvl*200; break;
     case 6..10: exp=lvl*500; break;
     case 11..15: exp=lvl*1000; break;
     case 16..20: exp=lvl*2500; break;
     case 21..50: exp=lvl*8000; break;
     default: exp=lvl*1000;
   }
   killer->add_exp(exp);
   claim(killer, victim);
   return;
}

int bounty(string str) {
int amt, nb, asn, adamt, i, j, timer, cktime;
  string nom, com, *fc, name, who, tmp,*list;
  object tp;
  tp=this_player();
  nb = tp->query_class()=="nightblade";
  asn = tp->query_class()=="assassin"; 

  if (!str) return notify_fail("Bounty commands are:\n"
    "bounty list all\nbounty list <name>\nbounty add <amount> to <name>\n"
    "Amount offered is in mithril only and must be more than 10 mithril.\n");
  if ( (sscanf(str,"%s %d to %s", com, amt, nom) != 3) &&
      (sscanf(str,"%s %s", com, nom) != 2) )
    return notify_fail("Type bounty for proper commands.\n");
  tmp = lower_case(nom);
  who = sprintf("%s/%s/%s", DIR_USERS, tmp[0..0], tmp);
  if( (file_size(who + ".o") < 0) && (nom != "all") ) 
    return notify_fail("The guild has never heard of that person.\n");
        if("/d/damned/guilds/join_rooms/nightblade_join"->is_member(who)) return notify_fail("The guild notes your attempt to place"
           " a bounty on one of its members.");
  who = sprintf("%s/%s/", REALMS_DIRS, tmp);
  if( (file_size(who + "workroom.c") >= 0) ) 
    return notify_fail("The guild refuses to accept a contract on a God.\n");
  switch(com) {
    case "list":
      if(!nb && !wizardp(tp)) return notify_fail("A menacing figure "+
        "informs you "+
        "that only member's may review bounties.\n");
      if (nom=="all") {
        message("info", "The following players have bounties on their "
          "heads.\n",tp);
        list = ({});
        fc=explode(read_file(FILE_NAME),"\n");
        for(i=0, j=sizeof(fc); i < j ; i++) {
          sscanf(fc[i],"%s is worth %d on %d",name,adamt,timer);
          list += ({ "%^RED%^"+capitalize(name)+" %^RESET%^is "+
            "worth %^BLUE%^"+adamt+ " %^RESET%^mithril pieces placed on "+
                                                mudtime(timer)+"."});
        }
        tp->more(list); 
        break;
      }
      else
      {
            if (find_bounty(nom) != "none") {
        fc=explode(read_file(FILE_NAME),"\n");
        for(i=0, j=sizeof(fc); i < j ; i++) {
          sscanf(fc[i],"%s is worth %d on %d",name,adamt,timer);
          if(nom == name)
            message("info","%^RED%^"+capitalize(name)+" %^RESET%^is "+
              "worth %^BLUE%^"+adamt+ " mithril%^RESET%^ pieces placed on "+
                                                        mudtime(timer)+".",tp);
          break;
           }
        }
      message("info","%^RED%^"+capitalize(nom)+ "%^RESET%^has no "+
        "bounty.\n");
      break;
      }
    case "add":
      if ((find_bounty(nom) != "none") && 
          (tp->query_money("mithril") >= amt) && (amt >=10) && !nb ) {
             fc=explode(read_file(FILE_NAME),"\n");
             for(i=0, j=sizeof(fc); i < j ; i++)  {
          sscanf(fc[i],"%s is worth %d on %d",name,adamt,timer);
          if(nom == name) {
            adamt += amt;
            tp->add_money("mithril",-amt);
            fc[i] = nom + " is worth " + adamt + " on "+time();
          }
        }
        seteuid(UID_DAMNED_DATA);
        rm(FILE_NAME);
        write_file(FILE_NAME,implode(fc,"\n") );
        seteuid(getuid());
        message("info","The shadowy figure accepts your payment on an "
          "open contract for "+capitalize(nom)+".",tp);
        break;
      }
      if(tp->query_money("mithril") < amt || amt < 10) return
        notify_fail("A figure from the shadows laughs in a chilling manner "
          "as you try to put out a contract without enough mithril.\n");
      if(nb) return
            notify_fail("Guild members may not place contracts.\n");
         seteuid(UID_DAMNED_DATA);
      write_file(FILE_NAME,nom+" is worth "+amt+" on "+time()+"\n");
      seteuid(getuid());
      tp->add_money("mithril",-amt);
      message("info","The shadowy figure accepts your payment on an "+
        "open contract for "+capitalize(nom)+".",tp);
       message("shout", "%^RED%^%^BOLD%^Beware! A bounty has just been placed! Perhaps this time it is on %^CYAN%^%^BOLD%^YOUR%^%^RED%^%^BOLD%^ head!");
      break;
    default:
      notify_fail("Type bounty for commands.\n");
      return 0;
  }
  return 1;
}

void claim(object killer, object victim) {
  string name, nom,*fc;
  int i,j,timer,cktime,adamt;
  nom=victim->query_true_name();
  fc=explode(read_file(FILE_NAME),"\n");
  for(i=0, j=sizeof(fc); i < j ; i++) {
   sscanf(fc[i],"%s is worth %d on %d",name,adamt,timer);
   if(nom == name ) {
     pay(adamt,nom,killer);
     fc[i] = 0;
     seteuid(UID_DAMNED_DATA);
     rm(FILE_NAME);
     write_file(FILE_NAME,implode(fc,"\n") );
     seteuid(getuid());
     return;
   }
  }
  return;
}
string find_bounty(string name)
{
  int i, j, amt;
  string nom, *str;
  
  str = explode(read_file(FILE_NAME),"\n");
  for(i=0, j=sizeof(str); i < j ; i++)
  {
    sscanf(str[i],"%s is worth %d",nom,amt);
    if(nom == name)
       return str[i];
  }
  return "none";
}

int pay (int amt, string nom, object killer)
{
  killer->add_money("mithril",amt);
  message("info","You are paid "+amt+" mithril for the"+
    " assasination of "+capitalize(nom)+".\n",killer);
   "/daemon/inform_d"->do_inform("murders",
   "%^RED%^Bounty:  "+
    "The contract on "+capitalize(nom)+" was executed for "+
    amt+" mithril pieces.");
  return 1;
}

string mudtime(int time_sec) {
    int year, date;
    string tmp;
    string day, month;

    day = DAYS[CURRENT_DAY(time_sec)];
    month = MONTHS[CURRENT_MONTH(time_sec)];
    year = CURRENT_YEAR(time_sec);
    date = CURRENT_DATE(time_sec);
    tmp = sprintf(" %s %s %d, %d",day, month, date, year);
    return tmp;
}

