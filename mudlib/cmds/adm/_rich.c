#include "move.h"
#include <std.h>
inherit DAEMON;

int
help();

int cmd_rich(string str) {
   object ob, to;
   string what, who, type;
   int i, amount;
    int dummy;
    object *inv;

    if (!stringp(str)) return help();
    dummy = effective_light(this_player());
    if(dummy < -1) {
      write("It is too dark.\n");
      return 1;
   }
   if (sscanf(str,"%s to %s", what, who) != 2) {
      return help();
   }
   to = present(who, environment(this_player()));
   if (!to) {
      notify_fail("Give "+what+" to who?\n");
      return 0;
   }
   ob = present(what, this_player());
   if (!ob) {
      ob = parse_objects(this_player(), what);
      if(!ob) {
          if(sscanf(what, "%d %s", amount, type) !=2) {
              notify_fail("You must have an object to give it away!\n");
              return 0;
          }
          if (amount<0) {
            notify_fail("Yeah, right.\n");
            return 0;
          }
          if(!living(to)) {
            write("You could, but I dont think it would give it back...");
            return 1;
           }
          this_player()->add_money(type, -amount);
          to->add_money(type, amount);
           write("You give " + amount + " " + type + " coins to " +
                  to->query_cap_name() + ".");
           tell_room(environment(this_player()), this_player()->query_cap_name()
           + " gives some money to " + to->query_cap_name() + ".", ({ this_player(), to }) );
          tell_object(to, this_player()->query_cap_name() +
           " gives you " + amount + " " + type + " coins.");
           return 1;
        }
   }
   if (!living(to)) {
      notify_fail("Only living objects can accept items.\n");
      return 0;
   }
   if(to->query_ghost()) {
        notify_fail(to->query_cap_name()+" is unable to hold anything in that state!\n");
        return 0;
    }
    if(!ob->get()) {
        notify_fail("You cannot give that away!\n");
        return 0;
    }
   i = (int) ob->move(to);
   switch(i) {
      case MOVE_OK: {
         write("You give " + ob->query_short() + " to " +
            to->query_cap_name() + ".");
         say(this_player()->query_cap_name()+" gives "+ob->query_short()+
            " to " + to->query_cap_name() + ".", to);
         tell_object(to,this_player()->query_cap_name()+" gives you "+
            ob->query_short() + ".");
         return 1;
         }
      case MOVE_NO_ROOM: {
         notify_fail(to->query_short()+" can't carry any more.\n");
         return 0;
         }
      default: {
         notify_fail("Oops, can't do that.\n");
         return 0;
         }
   }
}

int
help() {
  write("Command: rich\nSyntax: give <item> to <player>\n"+
        "This command will make you give money you dont have\n"+
        "to the player specified.  You must be in the same room for\n"+
        "this to occur.\n"
        "Examples:\n"
        "    rich 400 gold to diewarzau\n");
  return 1;
}
