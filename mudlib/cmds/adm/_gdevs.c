#include <std.h>
#include <security.h>

inherit DAEMON;



int cmd_gdevs(string str) {

    string pos, nom;
    object ob;
    int dev_pts;
    int dev;



    if(!archp(previous_object())) return 0;

    if(sscanf(str, "%s %s", nom, str) != 2)

      return notify_fail("Usage: <gdevs [player] ([additional devs]))>\n");

    if(!(ob = find_player(nom = lower_case(nom))))

      return notify_fail(sprintf("Cannot find %s anywhere.\n",capitalize(nom)));

    if(sscanf(str, "%d %s", dev) != 2) {




        seteuid(getuid());

        dev_pts=ob->query_property("dev points");
        ob->set_property("dev points", (dev+dev_pts));

        message("info", sprintf("%s has been given  %d dev points.", capitalize(nom), dev),

          this_player());

        message("info", sprintf("You have been given %d dev points.\n",dev),ob);

        return 1;

    }


}



void help() {

    message("help", "Syntax: <gdevs [player] ([additional devs])>\n\n"

      "Gives additional devs to a player.", this_player());

}
