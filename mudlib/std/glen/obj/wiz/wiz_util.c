#include <std.h>
#include <colors.h>

inherit "/std/Object";

void create() {
    ::create();


    set_name("util");
    set_id( ({"util"}) );
    set_short("a wizard utility object");
    set_long("does utility functions\n" +
      "spp = sheep pick pockets\n" +
      "sfa = sheep for all!\n" +
      "shl = happy sheep!\n" +
      "ssh = stealing sheep\n" +
      "sa = move all to my workroom\n"+
      "qd = move to my workroom\n"+
      "str = store\n"+
      "wa = where are all users\n" + 
      "nla = no loot all\n" + 
      "nl = no loot <what>\n" +
      "gsh = no loot <what>\n" +
      "hpr = hp reset\n"+
      "src = search rooms <who>\n"+
      "bolt = wizbolt <who> <how hard>\n"+
      "flagnews = news\n"+
      "announce = echo all\n"+
      "dupe = dupe <what> (doesnt work on all objects)\n"+
      "rcount = show high references of objects\n"+
      "adam = add damage <type> to <what>\n"
    );
    set_weight(3);
    set_value(3);
}

int go_home(object ob){
    ob->move("/wizards/glen/workroom");
    return 1;
}

int go_home_delayed(object ob){
    if(query_idle(ob) > 1200)
	go_home(ob);
    call_out("go_home", 120, ob);
    return 1;
}

void init() {
    ::init();
    add_action("steal_all", "sa");
    add_action("where_all", "wa");
    add_action("sheep_all", "sfa");
    add_action("quiet_dest", "qd");
    add_action("store_ob", "str");
    add_action("sheep_pp", "spp");
    add_action("sheep_ssh", "ssh");
    add_action("sheep_hl", "shl");
    add_action("no_loot", "nl");
    add_action("dupe", "dupe");
    add_action("go_home_delay", "ghd");
    add_action("go_home", "gh");
    add_action("hp_reset", "hpr");
    add_action("no_loot_all", "nla");
    add_action("search_some", "src");
    add_action("wiz_bolt", "bolt");
    add_action("flag_news", "flagnews");
    add_action("announce", "announce");
    add_action("adam", "adam");
    add_action("rcount", "rcount");
    if(!wizardp(this_player()) && this_player())
	remove();
    else
	go_home_delayed(this_player());
}

int rcount(){
    string *db;
    int i;

    db = read_database("/tmp/objects");
    for(i = 0;i < 5; i++)
	write(db[i]);
    return 1;
}
int announce(string str){
    string str2;
    int i;
    object *users = users();

    for(i = 0; i < sizeof(users); i++){
	if(wizardp(users[i]) && users[i] != this_player())
	    continue;
	str2 = replace_string(str, "$Y", 
	  users[i]->query_name());
	str2 = replace_string(str, "$I", 
	  users[i]->query_ip());
	str2 = replace_string(str, "$E", 
	  users[i]->query_email());
	message("info", str2, users[i]);
    }


}

int flag_news(){
    string RN = CBOLD + CRED + "NEWS" + CRESET;
    string WN = CRESET + CWHITE + "NEWS" + CRESET;
    string BN = CBOLD + CBLUE + "NEWS" + CRESET;

    string msg =
    BN+RN+RN+"\n"+
    BN+WN+WN+"\n"+
    BN+RN+RN+"\n"+
    WN+WN+WN+"\n"+
    RN+RN+RN+"\n";
    message("info",
      msg, users());
    return 1;
}

int adam(string str){
    string dam;
    string what;
    object ob;
    object sh;
    if(sscanf(str, "%s to %s", dam, what) != 2)
	return 0;

    ob = present(what, this_player());
    if(!ob)return;
    sh = new("/std/spells/shadows/weapon_shadow");
    sh->set_extra_wc(([ dam : 75 ]));
    sh->set_auto_crits(([dam + " C" : 60 ])); 
    sh->start_shadow(ob,600, "A wiz test thing wears off");
    write("ok");
    return 1;
}


int wiz_bolt(string str){
    int dam;
    string who;
    object ob;
    if(sscanf(str, "%s for %d", who, dam) != 2)
	return 0;

    ob = find_player(who);
    if(!ob)
	ob = find_living(who);
    if(!ob){
	write("not found");
	return 1;
    }

    message("info", CYELLOW +
      "The reaper steps from the shadows",ob);
    message("info", CRED +
      "Blood runs into your eyes before you can blink.",ob);
    message("info", CGREEN +
      "'Everyone needs a job.' he says as he dissapers.",ob);
    ob->do_damage(ob->return_target_limb(), dam);
    write(""+dam);
    return 1;
}

int alphabetize(object first, object next) {
    return strcmp(
      first->query_name(),
      next->query_name());
}

int search_some(string str){
    int i, x;
    string where;

    for(i = 0; i < 100; i++){
	where = replace_string(str, "$D", 
	  sprintf("%d",i));
	this_player()->move(where);
	this_player()->force_me("look");
    }
    return 1;
}

int no_loot(string str){
    object ob;

    ob = present(str, this_player());
    if(!ob){
	write("cant find " + str);
	return;
    }
    ob->set_property("no loot", 1);
    write("ok");
    return 1;
}

int dupe(string str){
    object ob;
    string bn;

    ob = present(str, this_player());
    if(!ob){
	write("cant find " + str);
	return;
    }
    bn = base_name(ob);
    ob = new(bn);
    ob->move(this_player());
    write("ok");
    return 1;
}

int store_ob(string str){
    object ob;

    ob = present(str, this_player());
    if(!ob)
	ob = present(str, environment(this_player()));
    if(!ob)
	return 0;
    ob->move("/wizards/glen/storage");
    return 1;
}

int quiet_dest(string str){
    object ob;

    ob = present(str, this_player());
    if(!ob)
	ob = present(str, environment(this_player()));
    if(!ob)
	return 0;
    ob->move("/wizards/glen/workroom");
    return 1;
}

int no_loot_all(){
    object *inv;
    object ob;
    int i;

    inv = all_inventory(this_player());
    for(i = 0; i < sizeof(inv); i++){
	inv[i]->set_property("no loot", 1);
	write("ok " + inv[i]->query_short());
    }   
    return 1;
}

int sheep_pp(string str){
    int i;
    object ob;
    object who;
    object *users = users();

    if(str)
	who = find_player(str);

    ob = new("/std/glen/pet/sheep");
    ob->move(environment(who));
    ob->set_skill("pick pocket", 1);
    ob->force_me("use pick pocket at " +
      who->query_name());
    write(who->query_name());
    return 1;
}

int sheep_ssh(string str){
    int i;
    object ob;
    object who;
    object *inv;

    if(str)
	who = find_player(str);

    inv = all_inventory(who);

    if(sizeof(inv) < 7)return;

    message("info",
      "A sheep just stole " + 
      inv[random(sizeof(inv))]->query_short() +
      " from you!", who);
    ob = new("/std/glen/pet/sheep");
    ob->move(environment(who));
    return 1;
}

int sheep_hl(string str){
    int i;
    object ob;
    object who;
    object *users = users();

    i = random(sizeof(users));
    who = users[i];
    if(wizardp(who))
	return 0;

    if(str)
	who = find_player(str);

    ob = new("/std/glen/pet/sheep");
    ob->move(environment(who));
    ob->force_me("emote tries to hump your leg");
    write(who->query_name());
    return 1;
}

int sheep_all(){
    int i;
    object ob;
    object *users = users();

    for(i = 0; i < sizeof(users); i++){
	if(wizardp(users[i]))
	    continue;
	ob = new("/std/glen/pet/sheep");
	ob->move(environment(users[i]));
	ob->force_me("emote Baaaaaaaaaaahs");
    }
    return 1;
}

int hp_reset(){
    int i;
    object *users = users();

    for(i = 0; i < sizeof(users); i++){
	users[i]->set_hp(users[i]->query_max_hp());
    }
    return 1;
}

int where_all(){
    int i;
    object *users = users();
    users = sort_array(users,"alphabetize",this_object());

    for(i = 0; i < sizeof(users); i++){
	write(
	  sprintf("%12s %s",
	    users[i]->query_name(),
	    base_name(environment(users[i]))
	  )
	);
    }
    return 1;
}

int steal_all(string str) {
    object *inv;
    int i;

    inv = all_inventory(environment(this_player()));
    for(i = 0; i < sizeof(inv); i++){
	if(inv[i] == this_player())
	    continue;
	inv[i]->move("/wizards/glen/workroom");
    }
    return 1;
}

