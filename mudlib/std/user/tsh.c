//      /std/user/tsh.c
//      from the Nightmare Mudlib
//      tsh- the TMI-shell or Tru-shel
//      created by Truilkan@TMI 920205
//      bug in $h & $H options fixed by Pallando@Nightmare 930709

#include <adt_defs.h>
#include <commands.h>
#include <tsh.h>
//ADD TLNY
//#include <std.h>
//END


#define DEFAULT_PROMPT "> "
#define MAX_HIST_SIZE  50
#define MIN_HIST_SIZE  20
#define MAX_PUSHD_SIZE 50
//below was private inherit... boggle?
inherit CSTACK_ADT;       /* for pushd and popd */ 
inherit "/std/user/history";
// private inherit CSTACK_ADT;       /* for pushd and popd */

private static string tsh_prompt;
private static int cur, hist_size, pushd_size, custom_prompt;

string do_nicks(string arg);
string do_alias(string arg);
string handle_history(string arg);
int tsh(string file);

//ADD TLNY
 int zexp,znexp,zlexp,znlevel,zlevel,xyz;
   string lp, byz;
//END

void update_prompt() {
tsh_prompt = (string)this_object()->getenv("prompt");
tsh_prompt = !tsh_prompt ? DEFAULT_PROMPT : tsh_prompt + " ";
custom_prompt = (tsh_prompt != DEFAULT_PROMPT);
}

int do_new() {
    string d1, d2;

update_prompt();
/*FIXME
	tsh_prompt = (string)this_object()->getenv("prompt");
	tsh_prompt = !tsh_prompt ? DEFAULT_PROMPT : tsh_prompt + " ";
	custom_prompt = (tsh_prompt != DEFAULT_PROMPT);
*/

//ADD TLNY
    zlevel=this_player()->query_level();
    znlevel=zlevel+1;
    zexp=this_player()->query_exp();
    znexp="/adm/daemon/advance_d"->get_exp(znlevel);
    zlexp=znexp-zexp;

    //attackers = ({});

//END

	d1 = (string)this_object()->getenv("pushd");
	pushd_size = 0;
	if (d1)
		sscanf(d1,"%d",pushd_size);
	if (pushd_size > MAX_PUSHD_SIZE)
		pushd_size = MAX_PUSHD_SIZE;

	d1 = (string)this_object()->getenv("history");
	hist_size = 0;
	if (d1)
		sscanf(d1,"%d",hist_size);
	if (hist_size > MAX_HIST_SIZE)
		hist_size = MAX_HIST_SIZE;
    if (!hist_size)
       hist_size = MIN_HIST_SIZE;
	return 1;
}

int pushd(string arg) {
    string path;

    path = (string)this_object()->get_path();
    if((int)CD->cmd_cd(arg) && cstack::enqueue(path) == -1) {
        cstack::dequeue();
        cstack::enqueue(path);
    }
    return 1;
}

int popd() {
    mixed dir;

    dir = cstack::pop();
    if((int)dir == -1) write("Directory stack is empty.\n");
    else CD->cmd_cd((string)dir);
    return 1;
}

void initialize() {
    string rcfile;

    do_new();
    if(pushd_size) cstack::alloc(pushd_size);
    if(hist_size) history::alloc(hist_size);
    rcfile = user_path((string)this_player()->query_name()) + ".login";
    if(file_size(rcfile) > -1) this_player()->tsh(rcfile);
}

//ADD TLNY
/*
object *query_attackers() {
    if(!attackers) return ({});
    if(!sizeof(attackers)) return ({});
    return attackers;
}
*/
//END
//ADD TLNY2025
string format_spell_name(string spell_name) {
    string formatted_name = replace_string(spell_name, "_", " ");
    string *words = explode(formatted_name, " ");
    for (int i = 0; i < sizeof(words); i++) {
        words[i] = capitalize(words[i]);
    }
    return implode(words, " ");
}
//END

string write_prompt()
{
    string path, prompt, tmp;

    if( custom_prompt )
    {
        prompt = tsh_prompt;
        path = (string)this_player()->get_path();
        tmp = user_path((string)this_player()->query_name());
        tmp = tmp[0 .. strlen(tmp)-2];
/*FIXME
        if(sscanf(path, "/wizards/%s", tmp) == 1)
	    path = "~" + tmp;
*/
/*FIXME
        prompt = replace_string( prompt, "$D", path );
*/

//add TLNY

//TLNY2024 Fixed Prompt TNL
        prompt = replace_string( prompt, "$tnl",
            "" + (((int)"/adm/daemon/advance_d"->get_exp(this_player()->query_level()+1))-(int)this_player()->query_exp()) );


prompt = replace_string( prompt, "$TNL",
            "" + (((int)this_player()->query_exp() - (int)"/adm/daemon/advance_d"->get_exp(this_player()->query_level())) * 100) / ((int)"/adm/daemon/advance_d"->get_exp(this_player()->query_level() + 1) - (int)"/adm/daemon/advance_d"->get_exp(this_player()->query_level())));
//END
        prompt = replace_string( prompt, "$dp",
            "" + (string)this_player()->query_property("dev points") );

        prompt = replace_string( prompt, "$c",
            "" + (string)this_player()->query_internal_encumbrance() );

        prompt = replace_string( prompt, "$mc",
            "" + (string)this_player()->query_max_internal_encumbrance() );
	if(this_player()->query("long term")) {

	  int time_needed = (int)this_player()->query("long term");
	  string formatted_time_needed = sprintf("%d:%02d:%02d",time_needed/3600, (time_needed%3600)/60, time_needed%60);
	  int time_progress = (int)this_player()->query_property("long term progress");
	  string formatted_time_progress = sprintf("%d:%02d:%02d",time_progress/3600, (time_progress%3600)/60, time_progress%60);
	  int time_to_go = time_needed - time_progress;
	  string formatted_time_to_go = sprintf("%d:%02d:%02d",time_to_go/3600, (time_to_go%3600)/60, time_to_go%60);
	  prompt = replace_string( prompt, "$la", "Active" );


//ADD TLNY2025

prompt = replace_string(prompt, "$ls", format_spell_name((string)this_player()->query_property("long term skill name")));

//END
	  //prompt = replace_string( prompt, "$ls", "" + (string)this_player()->query_property("long term skill name") );
	  prompt = replace_string( prompt, "$lt", "" + formatted_time_progress );
	  prompt = replace_string( prompt, "$LT", "" + formatted_time_needed );
	  prompt = replace_string( prompt, "$lr", "" + formatted_time_to_go );
	} else {
	  prompt = replace_string( prompt, "$la", "Not active" );
	  prompt = replace_string( prompt, "$ls", "" );
	  prompt = replace_string( prompt, "$lt", "" );
	  prompt = replace_string( prompt, "$LT", "" );
	  prompt = replace_string( prompt, "$lr", "" );
	
}
/*
if (sizeof((this_player()->query_attackers()-({0})))) {//this_object is more secure here because it specifies us more explicitly
byz = capitalize(this_object()->query_attackers()[0]->query_name());


if (sizeof((this_player()->query_attackers()-({0})))) {//this_object is more secure here because it specifies us more explicitly

byz = capitalize(this_player()->query_attackers()[0]->query_name());

switch((this_object()->query_attackers()[0]-> query_hp()*100)/this_object()->query_attackers()[0]-> query_max_hp()) {
 case 0..15: lp = byz+" is near death"; break;
 case 16..30: lp = byz+" is terribly injured"; break;
 case 31..45: lp = byz+" is badly injured"; break;
 case 46..60: lp = byz+" is hurting"; break;
 case 61..75: lp = byz+" is slightly injured"; break;
 case 76..90: lp = byz+" is in decent shape"; break;
 default: lp = byz+" is in top shape"; break;
            }

*/
//TLNY2025 NEW
//ADD
if(this_player()->query_current_attacker()){
    int max_hp = (int)this_player()->query_attackers()[0]->query_max_hp();
    
    // Check if max_hp is non-zero (even negative values should be allowed for negative health)
    if (max_hp != 0) {

    prompt = replace_string( prompt, "$a", "" + (((int)this_player()->query_attackers()[0]->query_hp() * 100) / max_hp) + "%" );
    } else {
   
        prompt = replace_string( prompt, "$a", "0" );
    }


    prompt = replace_string( prompt, "$A", this_player()->query_attackers()[0]->query_short() );
}
else {
    prompt = replace_string( prompt, "$A", "");
    prompt = replace_string( prompt, "$a", "");
}
//END
//TLNY2022 add
/*
if(this_player()->query_current_attacker()){

         prompt = replace_string( prompt, "$A", this_player()->query_attackers()[0]->query_short() );

        prompt = replace_string( prompt, "$a",
            "" + (((int)this_player()->query_attackers()[0]->query_hp()*100)/(int)this_player()->query_attackers()[0]->query_max_hp())+"%" );
}
else {
prompt = replace_string( prompt, "$A", "");
prompt = replace_string( prompt, "$a", "");
}
*/          

        prompt = replace_string( prompt, "$q",
            "" + (((int)this_player()-> query_hp()*100)/(int)this_player()-> query_max_hp()) );

        prompt = replace_string( prompt, "$Q",
            "" + (((int)this_player()-> query_mp()*100)/(int)this_player()-> query_max_mp()) );


        prompt = replace_string( prompt, "$h",
            "" + (int)this_player()-> query_hp() );
        prompt = replace_string( prompt, "$H",
            "" + (int)this_player()-> query_max_hp() );
        prompt = replace_string( prompt, "$m",
            "" + (int)this_player()-> query_mp() );
        prompt = replace_string( prompt, "$M",
            "" + (int)this_player()-> query_max_mp() );
        prompt = replace_string( prompt, "\\n", "\n" );
        prompt = replace_string( prompt, "$N", lower_case(mud_name()) );
        prompt = replace_string( prompt, "$C", ""+query_cmd_num() );
        prompt += " ";
    } else {
        prompt = DEFAULT_PROMPT;
    }
    message("prompt", prompt, this_object());
    return prompt;
}

nomask string process_input(string arg) {
    if(arg && arg != "") {
      arg = handle_history(arg);
      arg = do_nicks(arg);
      if(objectp(this_object()->query("mirror action")) ||
        pointerp(this_object()->query("mirror action")))
        catch(call_other(this_object()->query("mirror action"), "force_me", do_alias(arg)));
      return do_alias(arg);
    }
    return arg;
}

int tsh(string file) {
   string contents, *lines;
   int j, len, finished;

   if (geteuid(previous_object()) != geteuid()) return 0;
   if (!file) {
      notify_fail("usage: tsh filename\n");
      return 0;
   }
   contents = read_file(resolv_path((string)this_object()->get_path(),file));
   if (!contents) {
      notify_fail("tsh: couldn't read " + file + "\n");
      return 0;
   }
   lines = explode(contents,"\n");
   len = sizeof(lines);
   finished = 0;
   for (j = 0; j < len && !finished; j++) {
    if(!command(lines[j])) {
         write(file + ": terminated abnormally on line #" + (j+1) + "\n");
         write("while doing: " + lines[j] + "\n");
         finished = 1;
      }
   }
   return 1;
}

