#include <std.h>
#include <security.h>

inherit DAEMON;



int cmd_promote(string str) {

    string pos, nom;
    object ob;
    int dev_pts;
    int dev;



    if(!archp(previous_object())) return 0;

    if(sscanf(str, "%s %s", nom, str) != 2)

      return notify_fail("Usage: <promote [player] ([additional levels]))>\n");

    if(!(ob = find_player(nom = lower_case(nom))))

      return notify_fail(sprintf("Cannot find %s anywhere.\n",capitalize(nom)));

    if(sscanf(str, "%d %s", dev) != 2) {




        seteuid(getuid());

        dev_pts=ob->query_level();
        ob->set_level(dev+dev_pts);

        message("info", sprintf("%s has been given  %d levels.", capitalize(nom), dev),

          this_player());

        message("info", sprintf("You have been given %d additional levels.\n",dev),ob);

        return 1;

    }


}



void help() {

    message("help", "Syntax: <promote [player] ([additional levels])>\n\n"

      "Gives additional levels to a player.", this_player());

}
