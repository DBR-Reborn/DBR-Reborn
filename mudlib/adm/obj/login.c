#include <config.h> 
#include <news.h>
#include <flags.h>
#include <security.h> 
#include <daemons.h> 
#include <objects.h>
 
static private int __CrackCount; 
static private string __Name; 
static private object __Player; 
static string tmp;
 
static void logon();
static void get_name(string str);
static void get_password(string str);
static private int locked_access();
static private int check_password(string str);
static private int valid_site(string ip);
static private int is_copy();
static void disconnect_copy(string str, object ob);
static private void exec_user();
static void new_user(string str);
static void choose_gender(string str);
static void enter_email(string str);
static void enter_real_name(string str);
static void idle();
static void receive_message(string cl, string msg);
static private void internal_remove();

void remove();

void create() { 
    seteuid(UID_ROOT); 
    __Name = ""; 
    __CrackCount = 0; 
    __Player = 0; 
  } 
 
static void logon() { 
    string name;

    call_out("idle", LOGON_TIMEOUT); 
    if(catch(__Player = new(OB_USER))) { 
        message("logon", "Someone appears to be messing with the user object.\n", this_object()); 
        message("logon", "Please try again in a few minutes.\n", this_object()); 
        internal_remove();
        return; 
    }
    message("logon", read_file(WELCOME), this_object()); 
    message("logon", sprintf("\nLP Mud Driver: %s \nMudlib: %s %s\n", version(), mudlib(), mudlib_version()), this_object()); 
    message("logon", "\nLogin (enter your handle for new players): \n", this_object());
    
    input_to("get_name");
}

static void get_name(string str) { 
    if(!str || str == "") { 
        message("logon", "\nInvalid entry.  Please try again.\n", this_object()); 
        internal_remove();
        return; 
      } 
    __Name = lower_case(str); 
    if((int)master()->is_locked()) { 
        message("logon", read_file(LOCKED_NEWS), this_object()); 
        if(locked_access()) 
          message("logon", "\n    >>> Access allowed <<<\n", this_object()); 
        else { 
            message("logon", "\n    >>> Access denied <<<\n", this_object()); 
            internal_remove();
            return; 
	  } 
      } 
    if((int)SHUT_D->mud_lock()) { 
        message("logon", read_file(MUD_LOCKED_NEWS), this_object()); 
        if(locked_access()) 
          message("logon", "\n    >>> Access allowed <<<\n",this_object());

        else { 
          message("logon", "\n    >>> Access denied <<<\n", this_object());

          internal_remove();
        return; 
     }
      } 
    if(!user_exists(__Name)) {
      if(!((int)BANISH_D->valid_name(__Name))) { 
        INFORM_D->do_inform("watch_register",
          "[%^YELLOW%^%^BOLD%^SECURITY%^RESET%^] "+__Name+" -> "+
          query_ip_number()+ " banished name violation.");
            message("logon", sprintf("\n%s is not a valid name choice for %s.\n", 
              capitalize(__Name), mud_name()), this_object()); 
            message("logon", sprintf("Names must be alphabetic characters no " 
	      "longer than %d letters,\nand no less than %d letters.\n", 
              MAX_USER_NAME_LENGTH, MIN_USER_NAME_LENGTH), this_object()); 
            message("logon", "\nPlease enter another name: ", this_object()); 
            input_to("get_name"); 
            return; 
	  } 
        if(!((int)BANISH_D->allow_logon(__Name, query_ip_number()))) { 
            message("logon", read_file(REGISTRATION_NEWS), this_object()); 
            INFORM_D->do_inform("watch_register",
              "[%^YELLOW%^%^BOLD%^SECURITY%^RESET%^] "+__Name+" -> "+
              query_ip_number()+ " site-ban violation, registration message sent.");
            internal_remove();
            return; 
	  } 
        message("logon", sprintf("Do you really wish %s to be your name? (y/n) ", 
          capitalize(__Name)), this_object()); 
        input_to("new_user"); 
        return; 
      } 
    if(!((int)BANISH_D->allow_logon(__Name, query_ip_number()))) { 
        message("logon", read_file(BANISHED_NEWS), this_object()); 
        internal_remove();
        return; 
      } 
    message("logon", "Password: ", this_object()); 
    input_to("get_password", I_NOECHO | I_NOESC); 
  } 
 
static void get_password(string str) { 
    if(!str || str == "") { 
        message("logon", "\nYou must enter a password.  Try again later.\n", 
          this_object()); 
        internal_remove();
        return; 
      } 

      if(!check_password(str)) { 
        message("logon", "\nInvalid password.\n", this_object()); 
        //TODO: this would be a security vulnerability. People can just reconnect before the count fail. needs to be persisted to the user obj per try and multi thread aware. -Parnell 2018
        if(++__CrackCount > MAX_PASSWORD_TRIES) {
            INFORM_D->do_inform("watch_register",
              "[%^YELLOW%^%^BOLD%^SECURITY%^RESET%^] "+__Name+" -> "+
              query_ip_number()+ " password crack count exceed.");
            message("logon", "No more attempts allowed.\n", this_object()); 
            internal_remove();
            return; 
	  } 
        seteuid(UID_LOG); 
        log_file("watch/logon", sprintf("%s from %s\n", __Name, query_ip_number())); 
        seteuid(getuid()); 
        destruct(__Player);
        __Player = new(OB_USER);
        message("logon", "Password: ", this_object()); 
        input_to("get_password", I_NOECHO | I_NOESC); 
        return; 
      }

    if(!is_copy()) 
      exec_user();
  } 
 
static private int locked_access() { 
    int i; 
    
    if((int)BANISH_D->is_guest(__Name)) return 1; 
    i = sizeof(LOCKED_ACCESS_ALLOWED); 
    while(i--)
      if(member_group(__Name, LOCKED_ACCESS_ALLOWED[i])) {
        return 1; 
      }        
    return 0; 
  } 
 
static private int check_password(string str) { 
    string pass; 
 
    master()->load_player_from_file(__Name, __Player); 
    pass = (string)__Player->query_password();
//++++++++++DEBUG
//message("logon","Entered password "+ crypt(str, "BOB")[3..] + " existing password " + pass, this_object());
//+++++++++++DEBUG
    if(pass != crypt(str,pass)) return 0; 
    return 1;
  } 
 
static private int valid_site(string ip) { 
    string a, b; 
    string *miens; 
    int i; 
 
    if(!(i = sizeof(miens = (string *)__Player->query_valid_sites()))) return 1; 
    while(i--) { 
        if(ip == miens[i]) return 1; 
        if(sscanf(miens[i], "%s.*s", a) && sscanf(ip, a+"%s", b)) return 1; 
      } 
    return 0; 
  } 
 
static private int is_copy() { 
    object ob; 
 
    if(!(ob = find_player(__Name))) return 0; 
    if(interactive(ob)) { 
        message("logon", "\nThere currently exists an interactive copy of you.\n", 
          this_object()); 
        message("logon", "Do you wish to take over this interactive copy? (y/n) ", 
          this_object()); 
        input_to("disconnect_copy", I_NORMAL, ob); 
        return 1; 
      } 
    seteuid(UID_LOG); 
    log_file("enter", "EXEC:"+
      __Name+
      ":"+ctime(time())+"\n"
      );
    seteuid(getuid()); 
    if(exec(ob, this_object())) ob->restart_heart(); 
    else message("logon", "Problem reconnecting.\n", this_object()); 
    internal_remove();
    return 1; 
  } 
 
static void disconnect_copy(string str, object ob) { 
    object tmp; 
 
    if((str = lower_case(str)) == "" || str[0] != 'y') { 
        message("logon", "\nThen please try again later!\n", this_object()); 
        internal_remove();
        return; 
      } 
    message("info", "You are being taken over by hostile aliens!", ob); 
    exec(tmp = new(OB_USER), ob); 
    exec(ob, this_object()); 
    destruct(tmp); 
    message("logon", "\nAllowing login.\n", ob); 
    internal_remove();
  } 
 
static private void exec_user() { 
    if(MULTI_D->query_prevent_login(__Name)) { 
        internal_remove();
        return; 
      } 
    __Player->set_name(__Name); 
    if(!exec(__Player, this_object())) { 
        message("logon", "\nProblem connecting.\n", this_object()); 
        internal_remove();
        return; 
      } 
    __Player->setup();
    if(!wizardp(__Player) && (int)master()->is_locked())
        INFORM_D->do_inform("watch_register",
          "[%^YELLOW%^%^BOLD%^SECURITY%^RESET%^] "+__Name+" -> "+
          query_ip_number()+ " Mudlock Violation.");
    __Player = 0; 
    destruct(this_object()); 
  } 
 
static void new_user(string str) { 
    if((str = lower_case(str)) == "" || str[0] != 'y') { 
        message("logon", "\nOk, then enter the name you really want: ", this_object()); 
        input_to("get_name"); 
        return; 
      } 
    seteuid(UID_LOG); 
    log_file("new_players", sprintf("%s : %s : %s", query_ip_number(), __Name,  
      ctime(time()))+"\n");
    seteuid(getuid());
message("logon", "Set a password for the first time:", this_object());
 input_to("new_pass");
return;
}
//====================
static void new_pass(string str){
    

    tmp = str;
    if (strlen(tmp)<5) {
	message("login","Your new password must have more than 5 characters.\n",this_object());
	message("login","Re-enter new password:",this_object());
	input_to("new_pass");
    }
    printf("\nType your password again to confirm your password:");
    input_to("npass2");
 }

nomask static void npass2(string pass) {
    if (pass != tmp) {
        message("logon","\nThe passwords must match.\n",this_object());
	message("logon","Re-enter new password:",this_object());
	input_to("new_pass");
    }
    pass = crypt(pass,0);
//++++++++++DEBUG
    message("logon","Crypted pass is "+ pass + "\n", this_object());
//++++++++++DEBUG
    __Player->set_password(pass);
    message("logon","\nPassword set!\n",this_object());
 
//------------------------------------------------------
    message("logon", "\nWhat gender do you wish? (male or female): ",
          this_object());
    input_to("choose_gender");
    return;
  } 
 
static void choose_gender(string str) { 
    if(str != "male" && str != "female") { 
        message("logon", "\nAll characters must be either male or female.\n",
          this_object()); 
        message("logon", "Gender: ", this_object()); 
        input_to("choose_gender"); 
        return; 
      } 
    __Player->set_gender(str); 
    message("logon", 
	"Welcome to DayBreak Ridge Reborn\n"
	"If you do not have an email address\n"
	"You can still play, but you must talk to an arch.\n"
     "You can login as a temp char and immediately contact an arch.\n\n"
        "Email: ", this_object());
    input_to("enter_email"); 
  } 
 
static void enter_email(string str) { 
    string a, b; 
 
    if(!str || str == "" || sscanf(str, "%s@%s", a, b) != 2) { 
        message("logon", "\nEmail must be in the form user@host.\nEmail: ", 
          this_object()); 
        input_to("enter_email"); 
        return; 
      } 

// TLNY2020 removed duplicate email log out.
   
 if(EMAIL_D->check_dup_email(str, __Name)) {
      message("logon", "That email address is already in use.\n"
                       +sprintf("The player using it is: %s", 
        (string)EMAIL_D->query_player(str))+"\n", this_object());
     // internal_remove();
     __Player->set_email(str); 
    message("logon", "\n", 
      this_object()); 
    input_to("enter_real_name"); 
    }

    __Player->set_email(str); 
    message("logon", "\nReal name (optional): ", 
      this_object()); 
    input_to("enter_real_name"); 
  } 
 
static void enter_real_name(string str) { 
    if(!str || str == "") str = "Unknown"; 
    __Player->set_rname(str); 
    seteuid(UID_LOG); 
    log_file("enter", sprintf("%s (new player): %s\n", __Name, ctime(time()))); 
    seteuid(getuid()); 
    exec_user(); 
  } 
 
static void idle() { 
    message("logon", "\nLogin timed out.\n", this_object()); 
    internal_remove();
  } 
 
static void receive_message(string cl, string msg) { 
    if(cl != "logon") return; 
    receive(msg); 
  } 

static private void internal_remove() {
    if(__Player && !interactive(__Player) && !environment(__Player))
      destruct(__Player);
    destruct(this_object());
}

void remove() {
    if(geteuid(previous_object()) != UID_ROOT) return;
    internal_remove();
}
