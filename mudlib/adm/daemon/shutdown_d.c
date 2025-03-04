#include <std.h>
#include <daemons.h>
#include <security.h>
#include <objects.h>

inherit DAEMON;

object *in_the_know;
int time;
int lock;

void let_everyone_know();

void do_armageddon() {
    if(geteuid(previous_object()) != UID_SHUTDOWN) return;
    call_out("the_end", 60);
    INFORM_D->do_inform("impending_shutdowns",
      "%^RED%^%^BOLD%^Yes...\nIts that time again...\nAre you ready?\n\n"
      "The end of the world is upon us...\n\nThe world is over
populated....\n"
      "But do not worry, the world will return...BUT,"
      "\n%^YELLOW%^you have 30 minutes to prepare.");
    time = 1800;
}

void abort_shutdown() {
    if(geteuid(previous_object()) != UID_SHUTDOWN) return;
    remove_call_out("the_end");
    remove_call_out("the_end_long");
    lock=0;
    INFORM_D->do_inform("impending_shutdowns",
      "%^BOLD%^%^GREEN%^The world has been saved by a God!!!"
     
"\nYou\n\tmay\n\t\tthank\n\t\t\tyour\n\t\t\t\tlucky\n\t\t\t\t\tstars...");
    return;
}

void add_time(int how_much) {
    if(geteuid(previous_object()) != UID_SHUTDOWN) return;
    remove_call_out("the_end");
    remove_call_out("the_end_long");
    time += (how_much*60);
//TLNY2025 ADD for end command not below 6 mins
    if (time <= 360) time = 360;
    call_out("the_end", 60);
    INFORM_D->do_inform("impending_shutdowns",
      "%^YELLOW%^Thunder and lightning flashes across the skies..."
      "\nA God has added %^B_RED%^%^WHITE%^"+how_much+"%^RESET%^YELLOW%^"
      " minutes until the world is destroyed!");
    return;
}

static void the_end() {
  object *who, ob, p;
    int i;
    string *inv, file, file2, file3;
    time -= 60;

    if(time < 61) call_out("end_it", 50);
    else if(time > 600) call_out("the_end_long", 240);
    else call_out("the_end", 60);

    INFORM_D->do_inform("impending_shutdowns",
      "%^BOLD%^%^MAGENTA%^The world will be reborn in %^B_RED%^%^YELLOW%^"
      +time/60+"%^RESET%^%^BOLD%^%^MAGENTA%^ minutes.");
   if(time/60 == 5){
    lock=1;
    INFORM_D->do_inform("impending_shutdowns","%^YELLOW%^MUD LOCK ACTIVATED!");
    INFORM_D->do_inform("impending_shutdowns",
      "\n%^BOLD%^%^MAGENTA%^Type %^CYAN%^tell gamedriver <whatever>%^MAGENTA%^"
      " if you want a free ride to the shop!");   
    }
    let_everyone_know();
	if(time/60 == 3){	
	who = filter_array(users(), "is_player");
	foreach(ob in who) ob->save_player((string)ob->query_name());
    who = users();
		for(i=0; i<sizeof(who); i++){
		p = who[i];	
		//room = environment(p);
		catch(call_other(p, "force_me", "quit"));
		//catch(call_other(room, "add_crash_items"));
		}
	}	
	if(time/60 == 2){
		inv = get_dir("/adm/save/objects/saveroom/sinceboot/+*");
        for (i=0;i<sizeof(inv);i++){
        file = inv[i];
        file2 = replace_string(file,"+","/");
	    file3 = "/adm/save/objects/saveroom/sinceboot/"+file;
       catch(call_other(file2,"add_crash_items"));    
        rm(file3);
       }
    }   
}

static void the_end_long() {
    time -= 240;

    if(time < 61) call_out("end_it", 50);
    else if(time > 600) call_out("the_end_long", 240);
    else call_out("the_end", 60);

    INFORM_D->do_inform("impending_shutdowns",
      "%^BOLD%^%^MAGENTA%^The world will be reborn in %^RESET%^%^B_BLUE%^%^BOLD%^" +(time/60)+"%^RESET%^%^BOLD%^%^MAGENTA%^ minutes.");
    let_everyone_know();
}

static void end_it() {
    time -= 50;
    call_out("shut", 10);
    INFORM_D->do_inform("impending_shutdowns",
    "You should have logged out by now...\n\n\n"
    "%^YELLOW%^%^B_RED%^Your soul is being mangled, if you are still here...\n"
    "%^YELLOW%^%^B_RED%^Final warning, reboot in 10 seconds!!");
    let_everyone_know();

}

static void shut() {
    object *who, ob;
    int i;

    TELL_CLEAN_D->clean_tells();
    who = all_inventory(load_object("/d/standard/freezer"));
    who = filter_array(who, (: call_other :), "is_player");
    foreach(ob in who) ob->save_player((string)ob->query_name());
    who = users();
    for(i=0; i<sizeof(who); i++)
      catch(call_other(who[i], "force_me", "quit"));
    shutdown();
}

int query_time_remaining() { return time; }
int mud_lock() { return lock; }

void notify_armageddon(object ob) {
    if(!ob) return;
    if(!in_the_know) in_the_know = ({ ob });
    else {
        if(member_array(ob, in_the_know) == -1) in_the_know += ({ ob });
    }
}

void clean_up() {
    object *tmp;
    int i;

    if(!in_the_know) return;
    tmp = ({});
    for(i=0; i<sizeof(in_the_know); i++) { 
        if(!in_the_know[i]) continue;
        tmp += ({ in_the_know[i] });
    }
    in_the_know = tmp;
}

void let_everyone_know() {
    int i;

    for(i=0; i<sizeof(in_the_know); i++) {
        if(!in_the_know[i]) continue;
        in_the_know[i]->call_end(time);
    }
}
