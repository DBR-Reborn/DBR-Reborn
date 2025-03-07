//	/bin/adm/_end.c
//    	from the Nightmare mudlib
//	admin command to load armageddon
//	created by Descartes of Borg

#include <std.h>
#include <security.h>
#include <objects.h>
#include <rooms.h>
#include <daemons.h>

inherit DAEMON;

int cmd_end(string str) {
    object ob;
    int mins, current_time;

    if(str == "abort") {
	seteuid(UID_SHUTDOWN);
SHUT_D->abort_shutdown();
	seteuid(getuid());
write("Ok.");
// write("Temporarily Disabled, Please do not delay or abort ends. -Traer");
	return 1;
    }


if(str)
if(sscanf(str,"add %d",mins) == 1) {
//if(mins > 0)
// {write("Please do not delay or abort ends. -Traer");
// return 1;
// }
	seteuid(UID_SHUTDOWN);
	SHUT_D->add_time(mins);
	seteuid(getuid());
    write("Ok. Time left is " + (SHUT_D->query_time_remaining()) + " secounds.");
	return 1;
    }



    if(!archp(previous_object())) return 0;
     if(this_player()->query_forced()) return 0;
    ob = new(OB_SHUT);
    ob->move(ROOM_START);
    seteuid(UID_SHUTDOWN);
    catch(call_other(SHUT_D, "do_armageddon"));
    seteuid(getuid());
    write("Ok.\n");
    log_file("game_log", "Armageddon loaded by "+this_player()->query_name()+": "+ctime(time())+"\n");
    return 1;
}

int help()
{
    write( @EndText
Syntax: end
Effect: Starts the armageddon process.
See also: shutdown

"end abort" aborts the shutdown.
"end add <time>" adds <time> minutes to the countdown.
EndText
    );
    return 1;
}
