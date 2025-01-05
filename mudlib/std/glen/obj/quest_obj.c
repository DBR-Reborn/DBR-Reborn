// quest object by glen
// only give to worthy, very abuseable
#include <std.h>

inherit OBJECT;

string smsg1, smsg2, smsg3;
string cmd1, cmd2, cmd3;


void create() {
    ::create();
    set_name("prop");
    set_id( ({ "prop"}) );
    set_short("prop");
    set_long(
      "help:\n"+
      "addid <what> - add a name to the object\n" +
      "setshort <what> - sets the short description\n" +
      "setlong <what> - sets the long description\n" +
      "setname <what> - sets the name of the object\n" +
      "setcmd <cmd>:<result> - one word command triggers result test\n" +
      "setcmd2 <cmd>:<result> - one word command triggers result test\n" +
      "setcmd3 <cmd>:<result> - one word command triggers result test\n" +
      "NOTES: the word prop will always be an id for this object\n" +
      "       after you add commands, you must drop and get the object\n" +
      "       before they will work for you.\n"
    );
    set_weight(0);
    set_value(0);
    set_property("no clean", 1);
    set_property("no save", 1);
}

int setshort(string str){
    if(!legendp(this_player()) && !wizardp(this_player()))return 0;
    set_short(str);
    return 1;
}
int setlong(string str){
    if(!legendp(this_player()) && !wizardp(this_player()))return 0;
    set_long(str);
    return 1;
}
int setname(string str){
    if(!legendp(this_player()) && !wizardp(this_player()))return 0;
    set_name(str);
    return 1;
}

int addid(string str){
    if(!legendp(this_player()) && !wizardp(this_player()))return 0;
    set_id(
      query_id() +
      ({str})
    );
    return 1;
}

int msg1(){
    write(smsg1);
    return 1;
}
int msg2(){
    write(smsg2);
    return 1;
}
int msg3(){
    write(smsg3);
    return 1;
}

int setcmd(string str){
    string cmd, what;
    if(!legendp(this_player()) && !wizardp(this_player()))return 0;
    sscanf(str,"%s:%s", cmd, what);
    smsg1 = what;
    cmd1 = cmd;
    write("command : " + cmd);
    write("output : " + what);
    return 1;
}
int setcmd2(string str){
    string cmd, what;
    if(!legendp(this_player()) && !wizardp(this_player()))return 0;
    sscanf(str,"%s:%s", cmd, what);
    smsg2 = what;
    cmd2 = cmd;
    write("command : " + cmd);
    write("output : " + what);
    return 1;
}
int setcmd3(string str){
    string cmd, what;
    if(!legendp(this_player()) && !wizardp(this_player()))return 0;
    sscanf(str,"%s:%s", cmd, what);
    smsg3 = what;
    cmd3 = cmd;
    write("command : " + cmd);
    write("output : " + what);
    return 1;
}

void init() {
    add_action("setname", "setname");
    add_action("setshort", "setshort");
    add_action("setlong", "setlong");
    add_action("addid", "addid");
    add_action("setcmd", "setcmd");
    add_action("setcmd2", "setcmd2");
    add_action("setcmd3", "setcmd3");
    if(cmd1)
	add_action("msg1",cmd1);
    if(cmd2)
	add_action("msg2",cmd2);
    if(cmd3)
	add_action("msg3",cmd3);
}

